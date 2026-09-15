#include "mcc_generated_files/system/system.h"
#include <stdbool.h>

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
#define BTN_SW7     PORTBbits.RB5  // Stop
#define BTN_SW4     PORTBbits.RB2  // Start
#define BTN_SW8     PORTBbits.RB6  // Valf / Tahliye

// -----------------------------------------------------------------------------
// EEPROM ADRES TANIMLARI
// PIC18F46Q43 Data EEPROM başlangıç taban adresi: 0x380000
// -----------------------------------------------------------------------------
#define EEPROM_BASE_ADDR   0x380000UL
#define EEPROM_ADDR_BAR    0x00
#define EEPROM_ADDR_FARK   0x01

// -----------------------------------------------------------------------------
// KESME İLE PAYLAŞILAN GLOBAL DEĞİŞKENLER
// -----------------------------------------------------------------------------
volatile uint8_t tahliye_saniye = 0;
volatile uint8_t tahliye_active = 0;

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

// -----------------------------------------------------------------------------
// PIC18F46Q43 DONANIMSAL NVM EEPROM OKUMA / YAZMA FONKSİYONLARI
// -----------------------------------------------------------------------------
uint8_t EEPROM_Oku(uint16_t offset) {
    uint32_t tamAdres = EEPROM_BASE_ADDR + offset;

    NVMADRU = (uint8_t)((tamAdres >> 16) & 0x3F);
    NVMADRH = (uint8_t)((tamAdres >> 8) & 0xFF);
    NVMADRL = (uint8_t)(tamAdres & 0xFF);

    NVMCON1bits.CMD = 0x00; // Byte Read komutu
    NVMCON0bits.GO = 1;     // Okumayı başlat
    while (NVMCON0bits.GO); // Tamamlanmasını bekle

    return NVMDATL;
}

void EEPROM_GuvenliYaz(uint16_t offset, uint8_t veri) {
    // Ömür koruma: Aynı veri zaten varsa yazma işlemini pas geç
    if (EEPROM_Oku(offset) == veri) {
        return;
    }

    uint32_t tamAdres = EEPROM_BASE_ADDR + offset;

    NVMADRU = (uint8_t)((tamAdres >> 16) & 0x3F);
    NVMADRH = (uint8_t)((tamAdres >> 8) & 0xFF);
    NVMADRL = (uint8_t)(tamAdres & 0xFF);

    NVMDATL = veri;

    NVMCON1bits.CMD = 0x03; // DFM / EEPROM Byte Write komutu

    // NVM Kilit Açma Dizisi (Unlock Sequence)
    uint8_t gie_durum = INTCON0bits.GIE;
    INTCON0bits.GIE = 0;    // Yazma anında kesmeleri kapat

    NVMLOCK = 0x55;
    NVMLOCK = 0xAA;
    NVMCON0bits.GO = 1;     // Yazmayı başlat

    while (NVMCON0bits.GO); // Donanımsal yazma bitene kadar bekle (yaklaşık 4 ms)

    NVMCON1bits.CMD = 0x00; // Komutu temizle
    INTCON0bits.GIE = gie_durum; // Kesmeleri eski durumuna getir
}

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

// 0-9 arasında onlar basamağı (AFF1 ve AFF3) söner, 10+ olunca yanar
void Display_UpdateCounters(uint8_t ust, uint8_t alt) {
    uint8_t d1 = (ust >= 10) ? DIGIT_MAP[(ust / 10) % 10] : DISPLAY_BLANK;
    uint8_t d2 = DIGIT_MAP[ust % 10];

    uint8_t d3 = (alt >= 10) ? DIGIT_MAP[(alt / 10) % 10] : DISPLAY_BLANK;
    uint8_t d4 = DIGIT_MAP[alt % 10];

    Display_WriteRaw(d1, d2, d3, d4);
}

void Display_UpdatePressure(uint8_t pressure, uint8_t alt) {
    uint8_t d1 = (pressure >= 10) ? DIGIT_MAP[(pressure / 10) % 10] : DISPLAY_BLANK;
    uint8_t d2 = DIGIT_MAP[pressure % 10];
    
    uint8_t d3 = (alt >= 10) ? DIGIT_MAP[(alt / 10) % 10] : DISPLAY_BLANK;
    uint8_t d4 = DIGIT_MAP[alt % 10];

    Display_WriteRaw(d1, d2, d3, d4);
}

int hatBasinci(void);

// -----------------------------------------------------------------------------
// AN0 (RA0) OKUMA FONKSİYONU
// -----------------------------------------------------------------------------
uint16_t Read_AN0(void) {
    #if defined(ADCC_Initialize) || defined(_ADCC_H)
        return ADCC_GetSingleConversion(channel_ANA0);
    #else
        ADPCH = 0x00;           // Kanal seçimi: RA0 / ANA0
        ADCON0bits.ON = 1;      // ADC Açık
        __delay_us(10);         // Acquisition süresi
        
        ADCON0bits.GO = 1;      // Dönüşümü başlat
        while (ADCON0bits.GO);  // Dönüşüm bitene kadar bekle

        return ((uint16_t)((ADRESH << 8) | ADRESL));
    #endif
}

void stop(void) {
    POMPA_SetLow();
    VALF_SetLow();
    D2_SetHigh();
    D1_SetLow();
    D3_SetLow();
}

// -----------------------------------------------------------------------------
// BANT ARALIĞI KONTROLÜ (WINDOW COMPARATOR)
// -----------------------------------------------------------------------------
void start(uint16_t ustLim, uint16_t altLim) {
    D2_SetLow();
    D1_SetHigh();
    
    int val = hatBasinci();

    if (val >= altLim && val <= ustLim) {
        POMPA_SetHigh();
    } 
    else {
        POMPA_SetLow();
    }
}

// -----------------------------------------------------------------------------
// TIMER0 DONANIM AYARI (1 Saniye Kesmesi İçin)
// -----------------------------------------------------------------------------
void Timer0_Init(void) {
    T0CON0 = 0x10;       // 16-bit timer modu (EN = 0)
    T0CON1 = 0x48;       // Clock: Fosc/4, Prescaler: 1:256
    
    TMR0H = 0x0B;        // 3036 Preload
    TMR0L = 0xDC;

    PIR3bits.TMR0IF = 0;
    PIE3bits.TMR0IE = 1; // Kesme yetkisi
}

void tahliye_baslat(void) {
    D2_SetLow();
    D3_SetHigh();
    VALF_SetHigh();

    tahliye_saniye = 0;
    tahliye_active = 1;

    TMR0H = 0x0B;
    TMR0L = 0xDC;
    PIR3bits.TMR0IF = 0;
    T0CON0bits.EN = 1;   // Timer0 ON
}

void tahliye_durdur(void) {
    tahliye_active = 0;
    tahliye_saniye = 0;
    T0CON0bits.EN = 0;   // Timer0 OFF
    stop();
}

int hatBasinci(void) {
    uint16_t raw_adc = Read_AN0();
    uint8_t val = (uint8_t)(((raw_adc * 99UL) / 4095UL) / 4);
    return val;
}

int main(void) {
    SYSTEM_Initialize();

    SCK_PIN = 0;
    SDO_PIN = 0;
    LATCH_PIN = 0;

    // PIC18F46Q43 Dahili EEPROM'dan başlangıç değerlerini çek
    int8_t BarBasinci = (int8_t)EEPROM_Oku(EEPROM_ADDR_BAR);
    int8_t FarkBasinci = (int8_t)EEPROM_Oku(EEPROM_ADDR_FARK);

    // EEPROM boşsa (0xFF gelirse) veya mantıksız bir değerse varsayılan değerleri yükle
    if (BarBasinci > 25 || BarBasinci < 0) {
        BarBasinci = 10;
    }
    if (FarkBasinci > 25 || FarkBasinci < 0 || FarkBasinci >= BarBasinci) {
        FarkBasinci = 5;
    }

    uint8_t prev_sw2 = 1;
    uint8_t prev_sw5 = 1;
    uint8_t prev_sw3 = 1;
    uint8_t prev_sw6 = 1;
    uint8_t counter_mode = 0;
    uint8_t counter_timeout = 0;
    uint8_t pompa_control_active = 0;

    Timer0_Init();
    INTCON0bits.GIE = 1;

    Display_UpdatePressure((uint8_t)hatBasinci(), (uint8_t)FarkBasinci);
    stop();

    while (1) {
        uint8_t curr_sw2 = BTN_SW2;
        uint8_t curr_sw5 = BTN_SW5;
        uint8_t curr_sw3 = BTN_SW3;
        uint8_t curr_sw6 = BTN_SW6;

        uint8_t guncelle = 0;

        // SW5: Üst Sayaç (Üst Limit) ARTIR
        if (prev_sw5 == 1 && curr_sw5 == 0) {
            BarBasinci++;
            if (BarBasinci > 25) BarBasinci = 25;
            guncelle = 1;
        }

        // SW2: Üst Sayaç (Üst Limit) AZALT
        if (prev_sw2 == 1 && curr_sw2 == 0 && (BarBasinci >= (FarkBasinci + 2))) {
            BarBasinci--;
            if (BarBasinci < 0) BarBasinci = 0;
            guncelle = 1;
        }

        // SW6: Alt Sayaç (Alt Limit) ARTIR
        if (prev_sw6 == 1 && curr_sw6 == 0 && (FarkBasinci < (BarBasinci - 1))) {
            FarkBasinci++;
            if (FarkBasinci > 25) FarkBasinci = 25;
            guncelle = 1;
        }

        // SW3: Alt Sayaç (Alt Limit) AZALT
        if (prev_sw3 == 1 && curr_sw3 == 0) {
            FarkBasinci--;
            if (FarkBasinci < 0) FarkBasinci = 0;
            guncelle = 1;
        }

        prev_sw2 = curr_sw2;
        prev_sw5 = curr_sw5;
        prev_sw3 = curr_sw3;
        prev_sw6 = curr_sw6;

        // Ayar butonlarına her basışta 2 saniyelik kayıt sayacını sıfırla
        if (guncelle) {
            counter_mode = 1;
            counter_timeout = 0;
        }

        // MERKEZİ EKRAN YÖNETİMİ & EEPROM YAZMA
        if (counter_mode) {
            Display_UpdateCounters((uint8_t)BarBasinci, (uint8_t)FarkBasinci);
            counter_timeout++;

            // Butonlardan el çekildikten tam 2 saniye sonra (100 * 20ms = 2000ms)
            if (counter_timeout >= 100) {
                counter_mode = 0;

                // NVM EEPROM'a güvenli şekilde kaydet
                EEPROM_GuvenliYaz(EEPROM_ADDR_BAR, (uint8_t)BarBasinci);
                EEPROM_GuvenliYaz(EEPROM_ADDR_FARK, (uint8_t)FarkBasinci);
            }
        }
        else {
            Display_UpdatePressure((uint8_t)hatBasinci(), (uint8_t)FarkBasinci);
        }

        // SW4: START
        if (SW4_GetValue() == 0) {
            if (tahliye_active) {
                tahliye_durdur();
            }
            pompa_control_active = 1;
        }

        // SW7: STOP
        if (SW7_GetValue() == 0) {
            pompa_control_active = 0;
            if (tahliye_active) {
                tahliye_durdur();
            } else {
                stop();
            }
        }

        // SW8: TAHLİYE
        if (SW8_GetValue() == 0) {
            if (!tahliye_active) {
                pompa_control_active = 0;
                stop();
                tahliye_baslat();
            }
        }

        // Pompa Gerçek Zamanlı Kontrolü
        if (pompa_control_active) {
            start((uint16_t)BarBasinci, (uint16_t)FarkBasinci);
        }

        __delay_ms(20);
    }
    
    return 0;
}
