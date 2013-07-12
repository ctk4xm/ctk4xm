/**
 *  @file core.h
 *  @brief General CTK4XM API Specifications
 *  @date 10/07/2013
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

#ifndef CORE_H_
#define CORE_H_

/**
 * Microcontroller Platform Select
 */
#define	TIM

/**
 * Standard MSP430 Include
 */
#include <msp430.h>

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

/**
 * @brief Stop Watchdog Timer
 */
void stopWatchdogTimer();

/**
 * @brief Configure DCO Frequency
 */
void configureDCOFrequency1MHz();

/**
 * @brief Configure DCO Frequency 8 MHz
 */
void configureDCOFrequency8MHz();

/**
 * @brief Configure DCO Frequency 12 MHz
 */
void configureDCOFrequency12MHz();

/**
 * @brief Configure DCO Frequency 16 MHz
 */
void configureDCOFrequency16MHz();

/**
 * @brief Enable Interrupts
 */
void enableInterrupts();

/**
 * @brief Disable Interrupts
 */
void disableInterrupts();

/**
 * @brief Entry Low Power Mode 0
 */
void entryLowPowerMode0();

#endif
