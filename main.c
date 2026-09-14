#include "mcc_generated_files/system/system.h"

// -----------------------------------------------------------------------------
// DONANIM REGISTER PİNLERİ
// -----------------------------------------------------------------------------
#define SCK_PIN     LATCbits.LATC3
#define SDO_PIN     LATCbits.LATC4
#define LATCH_PIN   LATCbits.LATC5

// Buton Girişleri (MCC: RB0=SW2, RB1=SW3, RB3=SW5, RB4=SW6)
#define BTN_SW2     PORTBbits.RB0  // Üst Sayaç AZALT
#define BTN_SW5     PORTBbits.RB3  // Üst Sayaç ARTIR
#define BTN_SW3     PORTBbits.RB1  // Alt Sayaç AZALT
#define BTN_SW6     PORTBbits.RB4  // Alt Sayaç ARTIR

// -----------------------------------------------------------------------------
// ORTAK KATOT 7-SEGMENT DİZİSİ (0 - 9)
// Bit Sırası: [DP, g, f, e, d, c, b, a]
// -----------------------------------------------------------------------------
const uint8_t DIGIT_MAP[] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};

#define DISPLAY_BLANK 0x00

void Shift_Byte(uint8_t val) {
    for (int8_t i = 7; i >= 0; i--) {
        SCK_PIN = 0;
        SDO_PIN = (val >> i) & 0x01;
        __delay_us(2);

        SCK_PIN = 1;
        __delay_us(2);
        SCK_PIN = 0;
    }
}

void Display_WriteRaw(uint8_t aff1, uint8_t aff2, uint8_t aff3, uint8_t aff4) {
    Shift_Byte(aff4);
    Shift_Byte(aff3);
    Shift_Byte(aff2);
    Shift_Byte(aff1);

    LATCH_PIN = 0;
    __delay_us(2);
    LATCH_PIN = 1;
    __delay_us(5);
    LATCH_PIN = 0;
}

void Display_UpdateCounters(uint8_t ust, uint8_t alt) {
    // Üst Sayaç (00 - 99) -> AFF1, AFF2
    uint8_t d1 = DIGIT_MAP[(ust / 10) % 10];
    uint8_t d2 = DIGIT_MAP[ust % 10];

    // Alt Sayaç (00 - 99) -> AFF3, AFF4
    uint8_t d3 = DIGIT_MAP[(alt / 10) % 10];
    uint8_t d4 = DIGIT_MAP[alt % 10];

    Display_WriteRaw(d1, d2, d3, d4);
}

void Display_UpdatePressure(uint8_t pressure, uint8_t alt) {
    uint8_t d1 = DIGIT_MAP[(pressure / 10) % 10];
    uint8_t d2 = DIGIT_MAP[pressure % 10];
    uint8_t d3 = DIGIT_MAP[(alt / 10) % 10];
    uint8_t d4 = DIGIT_MAP[alt % 10];

    Display_WriteRaw(d1, d2, d3, d4);
}

void Display_UpdatePressureOnly(uint8_t pressure) {
    uint8_t d1 = DIGIT_MAP[(pressure / 10) % 10];
    uint8_t d2 = DIGIT_MAP[pressure % 10];

    Display_WriteRaw(d1, d2, DISPLAY_BLANK, DISPLAY_BLANK);
}

int hatBasinci(void);

// -----------------------------------------------------------------------------
// AN0 (RA0) OKUMA FONKSİYONU
// -----------------------------------------------------------------------------
uint16_t Read_AN0(void) {
    #if defined(ADCC_Initialize) || defined(_ADCC_H)
        // MCC Melody ADCC kütüphanesi aktifse:
        return ADCC_GetSingleConversion(channel_ANA0);
    #else
        // Doğrudan Register Seviyesinde Okuma (MCC eklenmemiş olsa bile çalışır):
        ADPCH = 0x00;           // Kanal seçimi: RA0 / ANA0
        ADCON0bits.ON = 1;      // ADC Açık
        __delay_us(10);         // Örnekleme kondansatörü şarj süresi (Acquisition time)
        
        ADCON0bits.GO = 1;      // Dönüşümü başlat
        while (ADCON0bits.GO);  // Dönüşüm bitene kadar bekle

        return ((uint16_t)((ADRESH << 8) | ADRESL)); // 12-bit ham ADC değeri
    #endif
}

void stop(){
    POMPA_SetLow();
    D2_SetHigh();
}

void start(uint16_t ustLim, uint16_t altLim){
    D2_SetLow();
    D1_SetHigh();
    
    int val = hatBasinci();
    Display_UpdatePressureOnly((uint8_t)val);
    
    if(val >= altLim && val <= ustLim){
        POMPA_SetHigh();
    }
    else{
        POMPA_SetLow();
    }


    D1_SetLow();
}


void tahliye(){
    D2_SetLow();
    D3_SetHigh();
    VALF_SetHigh();

    for (uint8_t i = 0; i < 60; i++) {
        if(SW7_GetValue() == 0) {break; stop();}
        __delay_ms(250);
    }

    VALF_SetLow();
    D3_SetLow();

    stop();

}

int hatBasinci(){
    uint16_t raw_adc = Read_AN0();
    // 0-4095 ham değeri 0-99 aralığına ölçekle-> /4 ile 0-25 arasında değer elde edilir
    uint8_t val = (uint8_t)((raw_adc * 99UL) / 4095UL)/4;
    return val;
}



int main(void) {
    SYSTEM_Initialize();

    // Çıkış pinleri başlangıç durumu
    SCK_PIN = 0;
    SDO_PIN = 0;
    LATCH_PIN = 0;

    int8_t BarBasinci = 0;
    int8_t FarkBasinci = 0;

    // Buton önceki durum kayıtları (Kenar tetikleme için)
    uint8_t prev_sw2 = 1;
    uint8_t prev_sw5 = 1;
    uint8_t prev_sw3 = 1;
    uint8_t prev_sw6 = 1;
    uint8_t counter_mode = 0;
    uint8_t counter_timeout = 0;
    uint8_t pompa_control_active = 0;

    // Başlangıçta üst displayde gerçek hat basıncını göster
    Display_UpdatePressure((uint8_t)hatBasinci(), (uint8_t)FarkBasinci);

    stop();

    while (1) {
        uint8_t curr_sw2 = BTN_SW2;
        uint8_t curr_sw5 = BTN_SW5;
        uint8_t curr_sw3 = BTN_SW3;
        uint8_t curr_sw6 = BTN_SW6;

        uint8_t guncelle = 0;
        uint8_t bar_button_pressed = 0;


        // ------Bar basıncı belirle------
        // SW5: Üst Sayaç ARTIR (Düşen kenar tespiti)
        if (prev_sw5 == 1 && curr_sw5 == 0) {
            BarBasinci++;
            if (BarBasinci > 25) BarBasinci = 25;
            bar_button_pressed = 1;
            guncelle = 1;
        }

        if (prev_sw2 == 1 && curr_sw2 == 0) {
            BarBasinci--;
            if (BarBasinci < 0) BarBasinci = 0;
            bar_button_pressed = 1;
            guncelle = 1;
        }

        // SW6: Alt Sayaç ARTIR
        if (prev_sw6 == 1 && curr_sw6 == 0) {
            FarkBasinci++;
            if (FarkBasinci > 25) FarkBasinci = 25;
            guncelle = 1;
        }

        // SW3: Alt Sayaç AZALT
        if (prev_sw3 == 1 && curr_sw3 == 0) {
            FarkBasinci--;
            if (FarkBasinci < 0) FarkBasinci = 0;
            guncelle = 1;
        }

        // Önceki durumları güncelle
        prev_sw2 = curr_sw2;
        prev_sw5 = curr_sw5;
        prev_sw3 = curr_sw3;
        prev_sw6 = curr_sw6;

        if (guncelle) {
            if (bar_button_pressed) {
                counter_mode = 1;
                counter_timeout = 0;
                Display_UpdateCounters((uint8_t)BarBasinci, (uint8_t)FarkBasinci);
            }
            else {
                Display_UpdatePressure((uint8_t)hatBasinci(), (uint8_t)FarkBasinci);
            }
        }

        if (counter_mode) {
            if (counter_timeout < 50) {
                counter_timeout++;
            }

            if (counter_timeout >= 50) {
                counter_mode = 0;
                Display_UpdatePressure((uint8_t)hatBasinci(), (uint8_t)FarkBasinci);
            }
        }
        else if (!guncelle) {
            Display_UpdatePressure((uint8_t)hatBasinci(), (uint8_t)FarkBasinci);
        }

        if (SW4_GetValue() == 0) {
            pompa_control_active = 1;
        }

        if (SW7_GetValue() == 0) {
            pompa_control_active = 0;
            stop();
        }

        if (SW8_GetValue() == 0) {
            pompa_control_active = 0;
            tahliye();
        }

        if (pompa_control_active) {
            start((uint16_t)BarBasinci, (uint16_t)FarkBasinci);
        }
        

        __delay_ms(20); // Debounce gecikmesi

    }

    return 0;
}
