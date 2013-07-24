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

#include "config.h"

/**
 * @brief Select Internal Clock
 * @param frequencyMHz MCU Frequency in MHz
 */
void coreSelectInternalClock(uchar frequencyMHz);

/**
 * @brief Select External Clock
 */
void coreSelectExternalClock();

/**
 * @brief Stop Watchdog Timer
 */
void coreStopWatchdogTimer();

/**
 * @brief Enable Interrupts
 */
void coreEnableInterrupts();

/**
 * @brief Disable Interrupts
 */
void coreDisableInterrupts();

/**
 * @brief Entry Low Power Mode
 */
void coreEntryLowPowerMode();

#endif
