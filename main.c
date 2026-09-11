#include "mcc_generated_files/system/system.h"

// -----------------------------------------------------------------------------
// DONANIM REGISTER PİNLERİ
// -----------------------------------------------------------------------------
#define SCK_PIN     LATCbits.LATC3
#define SDO_PIN     LATCbits.LATC4
#define LATCH_PIN   LATCbits.LATC5

#define DISPLAY_BLANK   0x00 // Segmentleri söndürme maskesi

// Ortak Katot Rakam Haritası (0 - 9)
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

// 0 - 9999 Arası Sayıyı Displaye Basma
void Display_WriteNumber(uint16_t val) {
    if (val > 9999) val = 9999;

    uint8_t d1 = DIGIT_MAP[(val / 1000) % 10]; // AFF1 (Binler)
    uint8_t d2 = DIGIT_MAP[(val / 100) % 10];  // AFF2 (Yüzler)
    uint8_t d3 = DIGIT_MAP[(val / 10) % 10];   // AFF3 (Onlar)
    uint8_t d4 = DIGIT_MAP[val % 10];          // AFF4 (Birler)

    Display_WriteRaw(d1, d2, d3, d4);
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

void start(uint16_t ustLim, uint16_t altLim){
    D3_SetHigh();
    
    int val = hatBasinci();
    
    if(val>altLim && val<ustLim){
        POMPA_SetHigh();
    }
    else{
        POMPA_SetLow();
    }


    D3_SetLow();
}

void stop(){
    D2_SetHigh();
}

void tahliye(){
    D2_SetLow();
    VALF_SetHigh();

    for (uint8_t i = 0; i < 15; i++) {
        __delay_ms(1000);
    }

    VALF_SetLow();
    stop();
}

int hatBasinci(){
    uint16_t raw_adc = Read_AN0();
    // 0-4095 ham değeri 0-99 aralığına ölçekle-> /4 ile 0-25 arasında değer elde edilir
    uint8_t val = (uint8_t)((raw_adc * 99UL) / 4095UL)/4;
    // Üst Display (AFF1 - AFF2)
        uint8_t d1 = DIGIT_MAP[(val / 10) % 10];
        uint8_t d2 = DIGIT_MAP[val % 10];

        // Alt Displayler kapalı (AFF3: DISPLAY_BLANK, AFF4: DISPLAY_BLANK)
    Display_WriteRaw(d1, d2, DISPLAY_BLANK, DISPLAY_BLANK);

    return val;
}


int main(void) {
    SYSTEM_Initialize();

    // Pin ayarları
    ANSELCbits.ANSELC3 = 0;
    ANSELCbits.ANSELC4 = 0;
    ANSELCbits.ANSELC5 = 0;
    TRISCbits.TRISC3 = 0;
    TRISCbits.TRISC4 = 0;
    TRISCbits.TRISC5 = 0;

    TRISAbits.TRISA0 = 1;
    ANSELAbits.ANSELA0 = 1;

    SCK_PIN = 0;
    SDO_PIN = 0;
    LATCH_PIN = 0;

     stop();

    while (1) {

        (void)hatBasinci();

        if(SW2_GetValue() == 0)
        {
            start(8,3);
        }

        if (SW4_GetValue() == 0)
        {
            start(15,10);
        }
        if(SW7_GetValue() == 0)
        {
            tahliye();
        }
        if(SW8_GetValue() == 0)
        {
            stop();
        }
        
    }

    return 0;
}
