/**
 *  @file ctk4xm.c
 *  @brief Main Program
 *  @date 10/09/2013
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
 *
 *  @mainpage C Toolkit For X Microcontroller
 *  This page resumes the CTK4XM API
 *  @par General Group
 *  @par Pheripherals Group
 *  @par External Group
 */

/**
 * Application Include
 */
#include "ctk4xmApp.h"

/**
 * Configurations Include
 */
#include "config.h"

/*
 * @brief Main Program
 * @param void Void
 */
void main(void)
{
	application();
}

/**
 * @brief Interrupt Service Routine Port 1
 */
#pragma vector = PORT1_VECTOR
__interrupt void PORT1_ISR (void)
{
	isrPort1();
}

/**
 * @brief Interrupt Service Routine Port 2
 */
#pragma vector = PORT2_VECTOR
__interrupt void PORT2_ISR (void)
{
	isrPort2();
}

/**
 * @brief Interrupt Service Routine ADC 10-bit
 */
#pragma vector = ADC10_VECTOR
__interrupt void ADC10_ISR (void)
{
	isrAdc10();
}

/**
 * @brief Interrupt Service Routine SCI TX
 */
#pragma vector = USCIAB0TX_VECTOR
__interrupt void USCIAB0TX_ISR (void)
{
	isrSci0Tx();
}

/**
 * @brief Interrupt Service Routine SCI TX
 */
#pragma vector = USCIAB0RX_VECTOR
__interrupt void USCIAB0RX_ISR (void)
{
	isrSci0Rx();
}

/**
 * @brief Interrupt Service Routine Timer 0 Channel 1
 */
#pragma vector = TIMER0_A1_VECTOR
__interrupt void TIMER0CH1_ISR (void)
{
	isrTimer0Ch1();
}

/**
 * @brief Interrupt Service Routine Timer 0 Channel 0
 */
#pragma vector = TIMER0_A0_VECTOR
__interrupt void TIMER0CH0_ISR (void)
{
	isrTimer0Ch0();
}

/**
 * @brief Interrupt Service Routine WatchDog Timer
 */
#pragma vector = WDT_VECTOR
__interrupt void WDT_ISR (void)
{
	isrWDT();
}

/**
 * @brief Interrupt Service Routine Comparator A
 */
#pragma vector = COMPARATORA_VECTOR
__interrupt void CMPA_ISR (void)
{
	isrComparatorA();
}

/**
 * @brief Interrupt Service Routine Timer 1 Channel 1
 */
#pragma vector = TIMER1_A1_VECTOR
__interrupt void TIMER1CH1_ISR (void)
{
	isrTimer1Ch1();
}

/**
 * @brief Interrupt Service Routine Timer 1 Channel 0
 */
#pragma vector = TIMER1_A0_VECTOR
__interrupt void TIMER1CH0_ISR (void)
{
	isrTimer1Ch0();
}

/**
 * @brief Interrupt Service Routine NMI
 */
#pragma vector = NMI_VECTOR
__interrupt void NMI_ISR (void)
{
	isrNMI();
}
