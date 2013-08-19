/**
 *  @file core.c
 *  @brief General CTK4XM API Specifications - Freescale Microcontroller
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

#include "hal/core.h"

#ifdef FREESCALE

/**
 * @brief Select Internal Clock
 * @param frequencyMHz MCU Frequency in MHz
 */
void _hal_coreSelectInternalClock(uchar frequencyMHz)
{
	// FLL Engaged Internal Reference --> 243MHz
	ICGC1 = 0x08;

	// Set Frequency Selected
	switch(frequencyMHz)
	{
		case 1:
			// N=4(000) R=8(011) 1.110.857,14 Hz
			ICGC2 = 0b00000011;
			break;

		case 8:
			// N=16(110) R=4(010) 8.886.857,14 Hz
			ICGC2 = 0b01100010;
			break;

		case 12:
			// N=12(100) R=2(001) 13.330.285,71 Hz
			ICGC2 = 0b01000001;
			break;

		case 16:
			// N=8(010) R=1(000) 17.773.714,29 Hz
			ICGC2 = 0b00100000;
			break;

		default:
			// N=16(110) R=4(010) 8.886.857,14 Hz
			ICGC2 = 0b01100010;
			break;
	}

	// Wait FLL Engaged
	while(!(ICGS1 & ICGS1_LOCK_MASK));
}

/**
 * @brief Select External Clock
 */
void _hal_coreSelectExternalClock()
{
	// FEE - FLL Engaged External Reference
	ICGC1 = 0b01111000;
	ICGC2 = 0b00110000;

	// Wait FLL Engaged
	while(!(ICGS1 & ICGS1_LOCK_MASK));
}

/**
 * @brief Stop Watchdog Timer
 */
void _hal_coreStopWatchdogTimer()
{
	SOPT_COPE = 0;
}

/**
 * @brief Enable Interrupts
 */
void _hal_coreEnableInterrupts()
{
	asm(cli);
}

/**
 * @brief Disable Interrupts
 */
void _hal_coreDisableInterrupts()
{
	asm(sei);
}

/**
 * @brief Entry Low Power Mode
 */
void _hal_coreEntryLowPowerMode()
{

}

#endif
