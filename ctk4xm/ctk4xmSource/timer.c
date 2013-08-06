/**
 *  @file timer.c
 *  @brief Module that drive Timer
 *  @date 06/08/2013
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

#include "timer.h"
#include "hal/timer.h"

/**
 * @brief Set Count Timer
 */
void timerSetCount(uint valueCounter)
{
	_hal_timerSetCount(valueCounter);
}

/**
 * @brief Clear and Enabled Timer Interrupt
 */
void timerInterruptEnable()
{
	_hal_timerInterruptEnable();
}

/**
 * @brief Clear Timer Interrupt Flag
 */
void timerClearInterruptFlag()
{
	_hal_timerClearInterruptFlag();
}

/**
 * @brief Init Timer
 */
void timerStart()
{
	_hal_timerStart();
}

/**
 * @brief Stop Timer
 */
void timerStop()
{
	_hal_timerStop();
}
