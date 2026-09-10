/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.1.1
*/

/*
© [2026] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 aliases
#define AN0_TRIS                 TRISAbits.TRISA0
#define AN0_LAT                  LATAbits.LATA0
#define AN0_PORT                 PORTAbits.RA0
#define AN0_WPU                  WPUAbits.WPUA0
#define AN0_OD                   ODCONAbits.ODCA0
#define AN0_ANS                  ANSELAbits.ANSELA0
#define AN0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define AN0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define AN0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define AN0_GetValue()           PORTAbits.RA0
#define AN0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define AN0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define AN0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define AN0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define AN0_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define AN0_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define AN0_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define AN0_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set RA2 aliases
#define DAC_TRIS                 TRISAbits.TRISA2
#define DAC_LAT                  LATAbits.LATA2
#define DAC_PORT                 PORTAbits.RA2
#define DAC_WPU                  WPUAbits.WPUA2
#define DAC_OD                   ODCONAbits.ODCA2
#define DAC_ANS                  ANSELAbits.ANSELA2
#define DAC_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define DAC_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define DAC_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define DAC_GetValue()           PORTAbits.RA2
#define DAC_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define DAC_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define DAC_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define DAC_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define DAC_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define DAC_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define DAC_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define DAC_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RA4 aliases
#define POMPA_TRIS                 TRISAbits.TRISA4
#define POMPA_LAT                  LATAbits.LATA4
#define POMPA_PORT                 PORTAbits.RA4
#define POMPA_WPU                  WPUAbits.WPUA4
#define POMPA_OD                   ODCONAbits.ODCA4
#define POMPA_ANS                  ANSELAbits.ANSELA4
#define POMPA_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define POMPA_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define POMPA_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define POMPA_GetValue()           PORTAbits.RA4
#define POMPA_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define POMPA_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define POMPA_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define POMPA_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define POMPA_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define POMPA_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define POMPA_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define POMPA_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set RA5 aliases
#define VALF_TRIS                 TRISAbits.TRISA5
#define VALF_LAT                  LATAbits.LATA5
#define VALF_PORT                 PORTAbits.RA5
#define VALF_WPU                  WPUAbits.WPUA5
#define VALF_OD                   ODCONAbits.ODCA5
#define VALF_ANS                  ANSELAbits.ANSELA5
#define VALF_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define VALF_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define VALF_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define VALF_GetValue()           PORTAbits.RA5
#define VALF_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define VALF_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define VALF_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define VALF_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define VALF_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define VALF_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define VALF_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define VALF_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set RB0 aliases
#define SW2_TRIS                 TRISBbits.TRISB0
#define SW2_LAT                  LATBbits.LATB0
#define SW2_PORT                 PORTBbits.RB0
#define SW2_WPU                  WPUBbits.WPUB0
#define SW2_OD                   ODCONBbits.ODCB0
#define SW2_ANS                  ANSELBbits.ANSELB0
#define SW2_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define SW2_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define SW2_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define SW2_GetValue()           PORTBbits.RB0
#define SW2_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define SW2_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define SW2_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define SW2_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define SW2_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define SW2_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define SW2_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define SW2_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set RB1 aliases
#define SW3_TRIS                 TRISBbits.TRISB1
#define SW3_LAT                  LATBbits.LATB1
#define SW3_PORT                 PORTBbits.RB1
#define SW3_WPU                  WPUBbits.WPUB1
#define SW3_OD                   ODCONBbits.ODCB1
#define SW3_ANS                  ANSELBbits.ANSELB1
#define SW3_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define SW3_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define SW3_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define SW3_GetValue()           PORTBbits.RB1
#define SW3_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define SW3_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define SW3_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define SW3_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define SW3_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define SW3_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define SW3_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define SW3_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RB2 aliases
#define SW4_TRIS                 TRISBbits.TRISB2
#define SW4_LAT                  LATBbits.LATB2
#define SW4_PORT                 PORTBbits.RB2
#define SW4_WPU                  WPUBbits.WPUB2
#define SW4_OD                   ODCONBbits.ODCB2
#define SW4_ANS                  ANSELBbits.ANSELB2
#define SW4_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define SW4_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define SW4_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define SW4_GetValue()           PORTBbits.RB2
#define SW4_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define SW4_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define SW4_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define SW4_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define SW4_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define SW4_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define SW4_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define SW4_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RB3 aliases
#define SW5_TRIS                 TRISBbits.TRISB3
#define SW5_LAT                  LATBbits.LATB3
#define SW5_PORT                 PORTBbits.RB3
#define SW5_WPU                  WPUBbits.WPUB3
#define SW5_OD                   ODCONBbits.ODCB3
#define SW5_ANS                  ANSELBbits.ANSELB3
#define SW5_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define SW5_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define SW5_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define SW5_GetValue()           PORTBbits.RB3
#define SW5_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define SW5_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define SW5_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define SW5_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define SW5_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define SW5_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define SW5_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define SW5_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RB4 aliases
#define SW6_TRIS                 TRISBbits.TRISB4
#define SW6_LAT                  LATBbits.LATB4
#define SW6_PORT                 PORTBbits.RB4
#define SW6_WPU                  WPUBbits.WPUB4
#define SW6_OD                   ODCONBbits.ODCB4
#define SW6_ANS                  ANSELBbits.ANSELB4
#define SW6_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SW6_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SW6_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SW6_GetValue()           PORTBbits.RB4
#define SW6_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SW6_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SW6_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SW6_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SW6_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define SW6_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define SW6_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define SW6_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RB5 aliases
#define SW7_TRIS                 TRISBbits.TRISB5
#define SW7_LAT                  LATBbits.LATB5
#define SW7_PORT                 PORTBbits.RB5
#define SW7_WPU                  WPUBbits.WPUB5
#define SW7_OD                   ODCONBbits.ODCB5
#define SW7_ANS                  ANSELBbits.ANSELB5
#define SW7_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define SW7_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define SW7_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define SW7_GetValue()           PORTBbits.RB5
#define SW7_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define SW7_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define SW7_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define SW7_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define SW7_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define SW7_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define SW7_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define SW7_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set RB6 aliases
#define SW8_TRIS                 TRISBbits.TRISB6
#define SW8_LAT                  LATBbits.LATB6
#define SW8_PORT                 PORTBbits.RB6
#define SW8_WPU                  WPUBbits.WPUB6
#define SW8_OD                   ODCONBbits.ODCB6
#define SW8_ANS                  ANSELBbits.ANSELB6
#define SW8_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define SW8_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define SW8_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define SW8_GetValue()           PORTBbits.RB6
#define SW8_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define SW8_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define SW8_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define SW8_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define SW8_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define SW8_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define SW8_SetAnalogMode()      do { ANSELBbits.ANSELB6 = 1; } while(0)
#define SW8_SetDigitalMode()     do { ANSELBbits.ANSELB6 = 0; } while(0)

// get/set RB7 aliases
#define ICSPDAT_TRIS                 TRISBbits.TRISB7
#define ICSPDAT_LAT                  LATBbits.LATB7
#define ICSPDAT_PORT                 PORTBbits.RB7
#define ICSPDAT_WPU                  WPUBbits.WPUB7
#define ICSPDAT_OD                   ODCONBbits.ODCB7
#define ICSPDAT_ANS                  ANSELBbits.ANSELB7
#define ICSPDAT_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define ICSPDAT_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define ICSPDAT_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define ICSPDAT_GetValue()           PORTBbits.RB7
#define ICSPDAT_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define ICSPDAT_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define ICSPDAT_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define ICSPDAT_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define ICSPDAT_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define ICSPDAT_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define ICSPDAT_SetAnalogMode()      do { ANSELBbits.ANSELB7 = 1; } while(0)
#define ICSPDAT_SetDigitalMode()     do { ANSELBbits.ANSELB7 = 0; } while(0)

// get/set RC1 aliases
#define PWM1_TRIS                 TRISCbits.TRISC1
#define PWM1_LAT                  LATCbits.LATC1
#define PWM1_PORT                 PORTCbits.RC1
#define PWM1_WPU                  WPUCbits.WPUC1
#define PWM1_OD                   ODCONCbits.ODCC1
#define PWM1_ANS                  ANSELCbits.ANSELC1
#define PWM1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define PWM1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define PWM1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define PWM1_GetValue()           PORTCbits.RC1
#define PWM1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define PWM1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define PWM1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define PWM1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define PWM1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define PWM1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define PWM1_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define PWM1_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set RC2 aliases
#define PWM2_TRIS                 TRISCbits.TRISC2
#define PWM2_LAT                  LATCbits.LATC2
#define PWM2_PORT                 PORTCbits.RC2
#define PWM2_WPU                  WPUCbits.WPUC2
#define PWM2_OD                   ODCONCbits.ODCC2
#define PWM2_ANS                  ANSELCbits.ANSELC2
#define PWM2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define PWM2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define PWM2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define PWM2_GetValue()           PORTCbits.RC2
#define PWM2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define PWM2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define PWM2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define PWM2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define PWM2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define PWM2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define PWM2_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define PWM2_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC3 aliases
#define SCK_TRIS                 TRISCbits.TRISC3
#define SCK_LAT                  LATCbits.LATC3
#define SCK_PORT                 PORTCbits.RC3
#define SCK_WPU                  WPUCbits.WPUC3
#define SCK_OD                   ODCONCbits.ODCC3
#define SCK_ANS                  ANSELCbits.ANSELC3
#define SCK_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SCK_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SCK_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SCK_GetValue()           PORTCbits.RC3
#define SCK_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SCK_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define SCK_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define SCK_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define SCK_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define SCK_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define SCK_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define SCK_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 aliases
#define SD0_TRIS                 TRISCbits.TRISC4
#define SD0_LAT                  LATCbits.LATC4
#define SD0_PORT                 PORTCbits.RC4
#define SD0_WPU                  WPUCbits.WPUC4
#define SD0_OD                   ODCONCbits.ODCC4
#define SD0_ANS                  ANSELCbits.ANSELC4
#define SD0_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SD0_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SD0_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SD0_GetValue()           PORTCbits.RC4
#define SD0_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SD0_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SD0_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define SD0_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define SD0_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define SD0_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define SD0_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define SD0_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC5 aliases
#define LATCH_TRIS                 TRISCbits.TRISC5
#define LATCH_LAT                  LATCbits.LATC5
#define LATCH_PORT                 PORTCbits.RC5
#define LATCH_WPU                  WPUCbits.WPUC5
#define LATCH_OD                   ODCONCbits.ODCC5
#define LATCH_ANS                  ANSELCbits.ANSELC5
#define LATCH_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define LATCH_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define LATCH_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define LATCH_GetValue()           PORTCbits.RC5
#define LATCH_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define LATCH_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define LATCH_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define LATCH_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define LATCH_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define LATCH_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define LATCH_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define LATCH_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 aliases
#define TX_TRIS                 TRISCbits.TRISC6
#define TX_LAT                  LATCbits.LATC6
#define TX_PORT                 PORTCbits.RC6
#define TX_WPU                  WPUCbits.WPUC6
#define TX_OD                   ODCONCbits.ODCC6
#define TX_ANS                  ANSELCbits.ANSELC6
#define TX_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define TX_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define TX_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define TX_GetValue()           PORTCbits.RC6
#define TX_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define TX_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define TX_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define TX_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define TX_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define TX_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define TX_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define TX_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 aliases
#define RX_TRIS                 TRISCbits.TRISC7
#define RX_LAT                  LATCbits.LATC7
#define RX_PORT                 PORTCbits.RC7
#define RX_WPU                  WPUCbits.WPUC7
#define RX_OD                   ODCONCbits.ODCC7
#define RX_ANS                  ANSELCbits.ANSELC7
#define RX_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RX_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RX_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RX_GetValue()           PORTCbits.RC7
#define RX_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RX_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RX_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define RX_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define RX_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define RX_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define RX_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define RX_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

// get/set RD4 aliases
#define STOP_TRIS                 TRISDbits.TRISD4
#define STOP_LAT                  LATDbits.LATD4
#define STOP_PORT                 PORTDbits.RD4
#define STOP_WPU                  WPUDbits.WPUD4
#define STOP_OD                   ODCONDbits.ODCD4
#define STOP_ANS                  ANSELDbits.ANSELD4
#define STOP_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define STOP_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define STOP_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define STOP_GetValue()           PORTDbits.RD4
#define STOP_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define STOP_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define STOP_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define STOP_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define STOP_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define STOP_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define STOP_SetAnalogMode()      do { ANSELDbits.ANSELD4 = 1; } while(0)
#define STOP_SetDigitalMode()     do { ANSELDbits.ANSELD4 = 0; } while(0)

// get/set RD5 aliases
#define TAHLIYE_TRIS                 TRISDbits.TRISD5
#define TAHLIYE_LAT                  LATDbits.LATD5
#define TAHLIYE_PORT                 PORTDbits.RD5
#define TAHLIYE_WPU                  WPUDbits.WPUD5
#define TAHLIYE_OD                   ODCONDbits.ODCD5
#define TAHLIYE_ANS                  ANSELDbits.ANSELD5
#define TAHLIYE_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define TAHLIYE_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define TAHLIYE_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define TAHLIYE_GetValue()           PORTDbits.RD5
#define TAHLIYE_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define TAHLIYE_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define TAHLIYE_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define TAHLIYE_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define TAHLIYE_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define TAHLIYE_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define TAHLIYE_SetAnalogMode()      do { ANSELDbits.ANSELD5 = 1; } while(0)
#define TAHLIYE_SetDigitalMode()     do { ANSELDbits.ANSELD5 = 0; } while(0)

// get/set RD6 aliases
#define START_TRIS                 TRISDbits.TRISD6
#define START_LAT                  LATDbits.LATD6
#define START_PORT                 PORTDbits.RD6
#define START_WPU                  WPUDbits.WPUD6
#define START_OD                   ODCONDbits.ODCD6
#define START_ANS                  ANSELDbits.ANSELD6
#define START_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define START_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define START_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define START_GetValue()           PORTDbits.RD6
#define START_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define START_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define START_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define START_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define START_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define START_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define START_SetAnalogMode()      do { ANSELDbits.ANSELD6 = 1; } while(0)
#define START_SetDigitalMode()     do { ANSELDbits.ANSELD6 = 0; } while(0)

// get/set RD7 aliases
#define EMSTOP_TRIS                 TRISDbits.TRISD7
#define EMSTOP_LAT                  LATDbits.LATD7
#define EMSTOP_PORT                 PORTDbits.RD7
#define EMSTOP_WPU                  WPUDbits.WPUD7
#define EMSTOP_OD                   ODCONDbits.ODCD7
#define EMSTOP_ANS                  ANSELDbits.ANSELD7
#define EMSTOP_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define EMSTOP_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define EMSTOP_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define EMSTOP_GetValue()           PORTDbits.RD7
#define EMSTOP_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define EMSTOP_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define EMSTOP_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define EMSTOP_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define EMSTOP_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define EMSTOP_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define EMSTOP_SetAnalogMode()      do { ANSELDbits.ANSELD7 = 1; } while(0)
#define EMSTOP_SetDigitalMode()     do { ANSELDbits.ANSELD7 = 0; } while(0)

// get/set RE0 aliases
#define D1_TRIS                 TRISEbits.TRISE0
#define D1_LAT                  LATEbits.LATE0
#define D1_PORT                 PORTEbits.RE0
#define D1_WPU                  WPUEbits.WPUE0
#define D1_OD                   ODCONEbits.ODCE0
#define D1_ANS                  ANSELEbits.ANSELE0
#define D1_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define D1_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define D1_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define D1_GetValue()           PORTEbits.RE0
#define D1_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define D1_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define D1_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define D1_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define D1_SetPushPull()        do { ODCONEbits.ODCE0 = 0; } while(0)
#define D1_SetOpenDrain()       do { ODCONEbits.ODCE0 = 1; } while(0)
#define D1_SetAnalogMode()      do { ANSELEbits.ANSELE0 = 1; } while(0)
#define D1_SetDigitalMode()     do { ANSELEbits.ANSELE0 = 0; } while(0)

// get/set RE1 aliases
#define D2_TRIS                 TRISEbits.TRISE1
#define D2_LAT                  LATEbits.LATE1
#define D2_PORT                 PORTEbits.RE1
#define D2_WPU                  WPUEbits.WPUE1
#define D2_OD                   ODCONEbits.ODCE1
#define D2_ANS                  ANSELEbits.ANSELE1
#define D2_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define D2_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define D2_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define D2_GetValue()           PORTEbits.RE1
#define D2_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define D2_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define D2_SetPullup()          do { WPUEbits.WPUE1 = 1; } while(0)
#define D2_ResetPullup()        do { WPUEbits.WPUE1 = 0; } while(0)
#define D2_SetPushPull()        do { ODCONEbits.ODCE1 = 0; } while(0)
#define D2_SetOpenDrain()       do { ODCONEbits.ODCE1 = 1; } while(0)
#define D2_SetAnalogMode()      do { ANSELEbits.ANSELE1 = 1; } while(0)
#define D2_SetDigitalMode()     do { ANSELEbits.ANSELE1 = 0; } while(0)

// get/set RE2 aliases
#define D3_TRIS                 TRISEbits.TRISE2
#define D3_LAT                  LATEbits.LATE2
#define D3_PORT                 PORTEbits.RE2
#define D3_WPU                  WPUEbits.WPUE2
#define D3_OD                   ODCONEbits.ODCE2
#define D3_ANS                  ANSELEbits.ANSELE2
#define D3_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define D3_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define D3_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define D3_GetValue()           PORTEbits.RE2
#define D3_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define D3_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define D3_SetPullup()          do { WPUEbits.WPUE2 = 1; } while(0)
#define D3_ResetPullup()        do { WPUEbits.WPUE2 = 0; } while(0)
#define D3_SetPushPull()        do { ODCONEbits.ODCE2 = 0; } while(0)
#define D3_SetOpenDrain()       do { ODCONEbits.ODCE2 = 1; } while(0)
#define D3_SetAnalogMode()      do { ANSELEbits.ANSELE2 = 1; } while(0)
#define D3_SetDigitalMode()     do { ANSELEbits.ANSELE2 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/