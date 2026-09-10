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

int main(void) {
    SYSTEM_Initialize();

    // Çıkış pinleri başlangıç durumu
    SCK_PIN = 0;
    SDO_PIN = 0;
    LATCH_PIN = 0;

    int8_t ust_sayac = 0;
    int8_t alt_sayac = 0;

    // Buton önceki durum kayıtları (Kenar tetikleme için)
    uint8_t prev_sw2 = 1;
    uint8_t prev_sw5 = 1;
    uint8_t prev_sw3 = 1;
    uint8_t prev_sw6 = 1;

    // Ekranı ilk değerlerle başlat
    Display_UpdateCounters(ust_sayac, alt_sayac);

    while (1) {
        uint8_t curr_sw2 = BTN_SW2;
        uint8_t curr_sw5 = BTN_SW5;
        uint8_t curr_sw3 = BTN_SW3;
        uint8_t curr_sw6 = BTN_SW6;

        uint8_t guncelle = 0;

        // SW5: Üst Sayaç ARTIR (Düşen kenar tespiti)
        if (prev_sw5 == 1 && curr_sw5 == 0) {
            ust_sayac++;
            if (ust_sayac > 99) ust_sayac = 0;
            guncelle = 1;
        }

        // SW2: Üst Sayaç AZALT
        if (prev_sw2 == 1 && curr_sw2 == 0) {
            ust_sayac--;
            if (ust_sayac < 0) ust_sayac = 99;
            guncelle = 1;
        }

        // SW6: Alt Sayaç ARTIR
        if (prev_sw6 == 1 && curr_sw6 == 0) {
            alt_sayac++;
            if (alt_sayac > 99) alt_sayac = 0;
            guncelle = 1;
        }

        // SW3: Alt Sayaç AZALT
        if (prev_sw3 == 1 && curr_sw3 == 0) {
            alt_sayac--;
            if (alt_sayac < 0) alt_sayac = 99;
            guncelle = 1;
        }

        // Önceki durumları güncelle
        prev_sw2 = curr_sw2;
        prev_sw5 = curr_sw5;
        prev_sw3 = curr_sw3;
        prev_sw6 = curr_sw6;

        if (guncelle) {
            Display_UpdateCounters((uint8_t)ust_sayac, (uint8_t)alt_sayac);
            //LATEbits.LATE2 = !LATEbits.LATE2; // Her tuş basımında D1 LED durum değiştirir
        }

        __delay_ms(20); // Debounce gecikmesi
    }

    return 0;
}