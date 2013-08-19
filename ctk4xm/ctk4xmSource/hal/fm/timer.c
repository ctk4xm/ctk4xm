/**
 *  @file timer.c
 *  @brief Module that drive Timer - Freescale Microcontroller
 *  @date 19/08/2013
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

#include "hal/timer.h"

#ifdef FREESCALE

/**
 * @brief Set Count Timer
 */
void _hal_timerSetCount(uint valueCounter)
{
	// 2000 us / 0.2 us = 10.000
	TPM1MODH = 0x27;
	TPM1MODL = 0x10;

	// CLKS[B:A] =  01 --> BUSCLK
	// PS[2:0]   = 010 --> % 4
	// @ 5 MHz --> 0.2 us
	TPM1SC = 0b00001010;
}

/**
 * @brief Clear and Enabled Timer Interrupt
 */
void _hal_timerInterruptEnable()
{
	TPM1SC |= TPM1SC_TOIE_MASK;
}

/**
 * @brief Clear Timer Interrupt Flag
 */
void _hal_timerClearInterruptFlag()
{
	TPM1SC &= ~(TPM1SC_TOF_MASK);
}

/**
 * @brief Init Timer
 */
void _hal_timerStart()
{

}

/**
 * @brief Stop Timer
 */
void _hal_timerStop()
{

}

#endif
