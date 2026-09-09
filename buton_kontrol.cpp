#include <xc.h>

// -----------------------------------------------------------------------------
// KONFİGÜRASYON AYARLARI (64 MHz Dahili Osilatör)
// -----------------------------------------------------------------------------
#pragma config FEXTOSC = OFF
#pragma config RSTOSC  = HFINTOSC_64MHZ
#pragma config WDTE    = OFF
#pragma config MCLRE   = EXTMCLR
#pragma config LVP     = ON

#define _XTAL_FREQ 64000000

// -----------------------------------------------------------------------------
// LED TANIMLARI (Port E)
// -----------------------------------------------------------------------------
#define LED_D1_LAT          LATEbits.LATE2
#define LED_D2_LAT          LATEbits.LATE1
#define LED_D3_LAT          LATEbits.LATE0

// -----------------------------------------------------------------------------
// 7 ADET BUTON TANIMI (Port B - Girişler)
// -----------------------------------------------------------------------------
#define SW2                 PORTBbits.RB0   // SW2A: P+
#define SW3                 PORTBbits.RB1   // SW3A: D+
#define SW4                 PORTBbits.RB2   // SW4A: START
#define SW5                 PORTBbits.RB3   // SW5A: P-
#define SW6                 PORTBbits.RB4   // SW6A: D-
#define SW7                 PORTBbits.RB5   // SW7A: STOP
#define SW8                 PORTBbits.RB6   // SW8A: TAHLİYE (ICSPCLK)

// -----------------------------------------------------------------------------
// SİSTEM REGISTER AYARLARI
// -----------------------------------------------------------------------------
void SYSTEM_Initialize(void) {
    // PORT A
    LATA   = 0x00;
    TRISA  = 0b00000001;        // RA0 analog giriş (AIN0), diğerleri çıkış
    ANSELA = 0b00000101;        // RA0 ve RA2 analog

    // PORT B (7 Buton Girişi: RB0 - RB6)
    LATB   = 0x00;
    TRISB  = 0b01111111;        // RB0..RB6 Giriş (1), RB7 ICSPDAT
    ANSELB = 0x00;              // Port B'nin tümü dijital giriş
    WPUB   = 0b01111111;        // 7 butonun tamamı için Dahili Pull-Up AKTİF

    // PORT C
    LATC   = 0x00;
    TRISC  = 0b10000000;        // RC7 giriş, diğerleri çıkış
    ANSELC = 0x00;

    // PORT D
    LATD   = 0x00;
    TRISD  = 0b11110000;        // RD4..RD7 giriş, RD0..RD3 çıkış
    ANSELD = 0x00;

    // PORT E (D1, D2, D3 LED'leri)
    LATE   = 0x00;
    TRISE  = 0b11111000;        // RE0, RE1, RE2 çıkış (0)
    ANSELE = 0x00;              // Dijital mod
}

// -----------------------------------------------------------------------------
// BUTON KONTROL DÖNGÜSÜ
// -----------------------------------------------------------------------------
void main(void) {
    SYSTEM_Initialize();

    while (1) {
        if (SW4 == 0 || SW6 == 0 || SW3 == 0) {
            LED_D1_LAT = 1;
        } else {
            LED_D1_LAT = 0;
        }

        if (SW7 == 0 || SW5 == 0) {
            LED_D2_LAT = 1;
        } else {
            LED_D2_LAT = 0;
        }

        if (SW2 == 0 || SW8 == 0) {
            LED_D3_LAT = 1;
        } else {
            LED_D3_LAT = 0;
        }
    }
}
