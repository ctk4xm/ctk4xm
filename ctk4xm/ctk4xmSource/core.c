/**
 *  @file core.c
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

#include "core.h"
#include "hal/core.h"

/**
 * @brief Select Internal Clock
 * @param frequencyMHz MCU Frequency in MHz
 */
void coreSelectInternalClock(uchar frequencyMHz)
{
	_hal_coreSelectInternalClock(frequencyMHz);
}

/**
 * @brief Select External Clock
 */
void coreSelectExternalClock()
{
	_hal_coreSelectExternalClock();
}

/**
 * @brief Stop Watchdog Timer
 */
void coreStopWatchdogTimer()
{
	_hal_coreStopWatchdogTimer();
}

/**
 * @brief Enable Interrupts
 */
void coreEnableInterrupts()
{
	_hal_coreEnableInterrupts();
}

/**
 * @brief Disable Interrupts
 */
void coreDisableInterrupts()
{
	_hal_coreDisableInterrupts();
}

/**
 * @brief Entry Low Power Mode
 */
void coreEntryLowPowerMode()
{
	_hal_coreEntryLowPowerMode();
}
