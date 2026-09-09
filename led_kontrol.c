#include <xc.h>

// -----------------------------------------------------------------------------
// KONFİGÜRASYON AYARLARI (Dahili 64 MHz HFINTOSC)
// -----------------------------------------------------------------------------
#pragma config FEXTOSC = OFF           // Harici osilatör kapalı
#pragma config RSTOSC  = HFINTOSC_64MHZ // Dahili 64 MHz osilatör
#pragma config WDTE    = OFF           // Watchdog kapalı
#pragma config MCLRE   = EXTMCLR       // Harici MCLR açık
#pragma config LVP     = ON            // Low-Voltage Programming açık

#define _XTAL_FREQ 64000000

// -----------------------------------------------------------------------------
// LED TANIMLAMALARI (RE0, RE1, RE2)
// -----------------------------------------------------------------------------
#define LED_D1_LAT          LATEbits.LATE0
#define LED_D2_LAT          LATEbits.LATE1
#define LED_D3_LAT          LATEbits.LATE2

#define LED_D1_Toggle()     (LED_D1_LAT ^= 1)
#define LED_D2_Toggle()     (LED_D2_LAT ^= 1)
#define LED_D3_Toggle()     (LED_D3_LAT ^= 1)

// -----------------------------------------------------------------------------
// SİSTEM REGİSTER AYARLARI (Şemaya Birebir Uygun)
// -----------------------------------------------------------------------------
void SYSTEM_Initialize(void) {
    // ======================== PORT A ========================
    // RA0 (Pin 19): AIN0 Analog Giriş
    // RA2 (Pin 21): DAC1 Çıkışı
    // RA3 (Pin 22): Boş
    // RA4 (Pin 23): POMPA Dijital Çıkış
    // RA5 (Pin 24): VALF Dijital Çıkış
    LATA   = 0x00;
    TRISA  = 0b00000001;        // RA0 giriş, diğerleri çıkış
    ANSELA = 0b00000101;        // RA0 (AIN0) ve RA2 (DAC1) analog, diğerleri dijital

    // ======================== PORT B ========================
    // RB0..RB6 (Pin 8-11, 14-16): Butonlar (P+, D+, START, P-, D-, STOP, TAHLİYE)
    // Tümü GND'ye bastığı için Dahili Pull-Up (WPUB) ŞARTTIR.
    LATB   = 0x00;
    TRISB  = 0b01111111;        // RB0..RB6 giriş (RB7 ICSPDAT)
    ANSELB = 0x00;              // Tümü dijital giriş
    WPUB   = 0b01111111;        // RB0..RB6 dahili pull-up'lar devrede

    // ======================== PORT C ========================
    // RC0 (Pin 32): LATCH (595 RCLK) - Çıkış
    // RC1 (Pin 35): SDO (595 SER)   - Çıkış
    // RC2 (Pin 36): SCK (595 SRCLK) - Çıkış
    // RC6 (Pin 44): TX1             - Çıkış
    // RC7 (Pin 1) : RX1             - Giriş
    LATC   = 0x00;
    TRISC  = 0b10000000;        // RC7 giriş, diğerleri çıkış
    ANSELC = 0x00;              // Tümü dijital

    // ======================== PORT D ========================
    // RD0..RD3: PWM1, PWM2 ve kontrol hatları (Çıkış)
    // RD4..RD7 (Pin 2-5): TEST_STOP, TAHLIYE, POMPA_TEST, EMSTOP (Giriş)
    LATD   = 0x00;
    TRISD  = 0b11110000;        // RD4..RD7 giriş, RD0..RD3 çıkış
    ANSELD = 0x00;              // Tümü dijital

    // ======================== PORT E ========================
    // RE0 (Pin 25): D1 LED (R29 üzerinden) - Çıkış
    // RE1 (Pin 26): D2 LED (R30 üzerinden) - Çıkış
    // RE2 (Pin 27): D3 LED (R31 üzerinden) - Çıkış
    LATE   = 0x00;
    TRISE  = 0b11111000;        // RE0, RE1, RE2 Çıkış (0), diğerleri giriş
    ANSELE = 0x00;              // RE0, RE1, RE2 Dijital pin
}

// -----------------------------------------------------------------------------
// ANA DÖNGÜ (Flip-Flop Çalışması)
// -----------------------------------------------------------------------------
void main(void) {
    SYSTEM_Initialize();

    // Başlangıç durumu: D1 Açık, D2 ve D3 Kapalı
    LED_D1_LAT = 1;
    LED_D2_LAT = 0;
    LED_D3_LAT = 0;

    while (1) {
        // Durumları tersleyerek karşılıklı flip-flop geçişi:
        // (D1 yanarken D2 ve D3 söner; sonra D1 sönerken D2 ve D3 yanar)
        LED_D1_Toggle();
        LED_D2_Toggle();
        LED_D3_Toggle();

        __delay_ms(500); // 500 ms bekleme
    }
}
