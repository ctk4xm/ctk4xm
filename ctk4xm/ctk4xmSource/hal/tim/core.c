/**
 *  @file core.c
 *  @brief General CTK4XM API Specifications - Texas Instrument Microcontroller
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

#include "hal/core.h"

#ifdef TIM

/**
 * @brief Select Internal Clock
 * @param frequencyMHz MCU Frequency in MHz
 */
void _hal_coreSelectInternalClock(uchar frequencyMHz)
{
	// Set Frequency Selected
	switch(frequencyMHz)
	{
		case 1:
			BCSCTL1 = CALBC1_1MHZ;
			DCOCTL = CALDCO_1MHZ;
			break;

		case 8:
			BCSCTL1 = CALBC1_1MHZ;
			DCOCTL = CALDCO_1MHZ;
			break;

		case 12:
			BCSCTL1 = CALBC1_1MHZ;
			DCOCTL = CALDCO_1MHZ;
			break;

		case 16:
			BCSCTL1 = CALBC1_1MHZ;
			DCOCTL = CALDCO_1MHZ;
			break;

		default:
			BCSCTL1 = CALBC1_1MHZ;
			DCOCTL = CALDCO_1MHZ;
			break;
	}
}

/**
 * @brief Select External Clock
 */
void _hal_coreSelectExternalClock()
{

}

/**
 * @brief Stop Watchdog Timer
 */
void _hal_coreStopWatchdogTimer()
{
	WDTCTL = WDTPW + WDTHOLD;
}

/**
 * @brief Enable Interrupts
 */
void _hal_coreEnableInterrupts()
{
	_enable_interrupts();
}

/**
 * @brief Disable Interrupts
 */
void _hal_coreDisableInterrupts()
{
	_disable_interrupts();
}

/**
 * @brief Entry Low Power Mode
 */
void _hal_coreEntryLowPowerMode()
{
	__low_power_mode_0();
}

#endif
