/**
 *  @file config.h
 *  @brief General CTK4XM API Configurations
 *  @date 23/07/2013
 *  @version 1.0.0
 *
 *  C Toolkit For X Microcontroller
 *  Copyright (C) 2013 Leandro Perez Guatibonza
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CONFIG_H_
#define CONFIG_H_

/**
 * Microcontroller Platform Select
 */
#define	TIM

/**
 * General Include Definition Section
 */
#ifdef TIM

/**
 * Standard MSP430 Include
 */
#include <msp430.h>

#endif

#ifdef FREESCALE

/**
 * Standard Freescale Include
 */
#include "derivative.h"
/**
 * Standard Enabled Interrupt Macro
 */
#include <hidef.h>

/**
 * Mask Bit 0
 */
#define BIT0		0x01

/**
 * Mask Bit 1
 */
#define BIT1		0x02

/**
 * Mask Bit 2
 */
#define BIT2		0x04

/**
 * Mask Bit 3
 */
#define BIT3		0x08

/**
 * Mask Bit 4
 */
#define BIT4		0x10

/**
 * Mask Bit 5
 */
#define BIT5		0x20

/**
 * Mask Bit 6
 */
#define BIT6		0x40

/**
 * Mask Bit 7
 */
#define BIT7		0x80

#endif

/**
 * Pins Definition Section
 */
#ifdef TIM

	// 7-Seg Module Pins Definition
	#define DISPLAY7SEG_A 		&P1OUT,BIT0
	#define DISPLAY7SEG_B 		&P1OUT,BIT1
	#define DISPLAY7SEG_C 		&P1OUT,BIT2
	#define DISPLAY7SEG_D 		&P1OUT,BIT3
	#define DISPLAY7SEG_E 		&P1OUT,BIT4
	#define DISPLAY7SEG_F 		&P1OUT,BIT5
	#define DISPLAY7SEG_G 		&P1OUT,BIT6
	#define DISPLAY7SEG_SRCLK 	&P2OUT,BIT0
	#define DISPLAY7SEG_SRDAT 	&P2OUT,BIT1

	// LCD Module Pins Definition
	#define RS_LCD				&P2OUT,BIT0
	#define E_LCD				&P2OUT,BIT1
	#define D4_LCD				&P2OUT,BIT2
	#define D5_LCD				&P2OUT,BIT3
	#define D6_LCD				&P2OUT,BIT4
	#define D7_LCD				&P2OUT,BIT5

#endif

#ifdef FREESCALE

	// 7-Seg Module Pins Definition
	#define DISPLAY7SEG_A 		&PTBD,BIT0
	#define DISPLAY7SEG_B 		&PTBD,BIT1
	#define DISPLAY7SEG_C 		&PTBD,BIT2
	#define DISPLAY7SEG_D 		&PTBD,BIT3
	#define DISPLAY7SEG_E 		&PTBD,BIT4
	#define DISPLAY7SEG_F 		&PTBD,BIT5
	#define DISPLAY7SEG_G 		&PTBD,BIT6
	#define DISPLAY7SEG_SRCLK 	&PTAD,BIT0
	#define DISPLAY7SEG_SRDAT 	&PTAD,BIT1

	// LCD Module Pins Definition
	#define RS_LCD				&PTAD,BIT7
	#define E_LCD				&PTAD,BIT6
	#define D4_LCD				&PTAD,BIT5
	#define D5_LCD				&PTAD,BIT4
	#define D6_LCD				&PTAD,BIT3
	#define D7_LCD				&PTAD,BIT2

#endif

/**
 * Type Definition Unsigned Integer
 */
typedef unsigned int uint;

/**
 * Type Definition Unsigned Char
 */
typedef unsigned char uchar;

/**
 * Type Definition Unsigned Long
 */
typedef unsigned long ulong;

/**
 * Type Definition Volatile Unsigned Char
 */
typedef volatile unsigned char vuchar;

/**
 * DCO Frequency Constant
 */
#define DCO_FREQ	1000000

/**
 * CPU IDX Constant
 */
#define IDX			1

/**
 * Frequency Timer Constant
 */
#define FRECTIM		DCO_FREQ/IDX

/**
 * Period Timer Constant
 */
#define PERTIM		1/FRECTIM

/**
 * ADC Channel 0 Constant
 */
#define ADC_CH0		0

/**
 * ADC Channel 1 Constant
 */
#define ADC_CH1		1

/**
 * ADC Channel 2 Constant
 */
#define ADC_CH2		2

/**
 * ADC Channel 3 Constant
 */
#define ADC_CH3		3

/**
 * ADC Channel 4 Constant
 */
#define ADC_CH4		4

/**
 * ADC Channel 5 Constant
 */
#define ADC_CH5		5

/**
 * ADC Channel 6 Constant
 */
#define ADC_CH6		6

/**
 * ADC Channel 7 Constant
 */
#define ADC_CH7		7

/**
 * ADC Internal Temperature Channel Constant
 */
#define ADC_CHTEMP	10

#endif
