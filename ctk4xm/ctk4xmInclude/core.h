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
 */
void coreSelectInternalClock();

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
