/* 
 * File:   config.h
 * Author: Phil Glazzard
 *
 * Created on 02 July 2020, 14:10
 */

#ifndef CONFIG_H
#define	CONFIG_H


// PIC16F690 Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select bit (MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include<stdbool.h>
#define _XTAL_FREQ 4000000
#define DIAGNOSTIC_LED PORTAbits.RA2   // pin 17
#define SERIAL_DATA PORTCbits.RC4       // pin 6
#define SHIFT_CLOCK PORTCbits.RC5       // pin 5
#define LATCH_CLOCK PORTCbits.RC6       // pin 8
#define WE PORTCbits.RC7                // pin 9    // active low
#define TX PORTBbits.RB7        // TX pin 10 of 16F690
#define HI 1
#define LO 0
#define LSB 0
#define MSB 1
#define uchar unsigned char
#define uint unsigned int
const uint OUTPUT_EN = 0 ;
const uint INPUT_EN = 32768;

#endif	/* CONFIG_H */

