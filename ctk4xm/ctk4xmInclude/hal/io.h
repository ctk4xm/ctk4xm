/**
 *  @file io.h
 *  @brief Module that controls the I/O pins
 *  @date 11/07/2013
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

#ifndef IO_HAL_H_
#define IO_HAL_H_

#include "config.h"

/**
 * @brief Configure Digital Output Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void _hal_ioDigitalOutput(vuchar *portDirection, uchar pinMask);

/**
 * @brief Configure Digital Input Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void _hal_ioDigitalInput(vuchar *portDirection, uchar pinMask);

/**
 * @brief Read Digital Pin
 * @param port Port
 * @param pinMask Pin
 * @return Value Digital Read
 */
uchar _hal_ioDigitalRead(vuchar *port, uchar pinMask);

/**
 * @brief Write Digital Pin
 * @param port Port
 * @param pinMask Pin
 * @param level Level Pin
 */
void _hal_ioDigitalWrite(vuchar *port, uchar pinMask, uchar level);

/**
 * @brief Pull-Up Pin Configuration
 * @param portDirection Port
 * @param pinMask Pin
 * @param state Enabled or Disabled
 */
void _hal_ioDigitalPullUp(vuchar *portDirection, uchar pinMask, uchar state);

/**
 * @brief Pull-Down Pin Configuration
 * @param portDirection Port
 * @param pinMask Pin
 */
void _hal_ioDigitalPullDown(vuchar *portDirection, uchar pinMask, uchar state);

/**
 * @brief Select I/O Function Pin
 * @param port Port
 * @param pinMask Pin
 */
void _hal_ioSelectFunction(vuchar *port, uchar pinMask, uchar function);

/**
 * @brief Interrupt Pin Configuration
 * @param port Port
 * @param pinMask Pin
 */
void _hal_ioDigitalInterrupt(vuchar *port, uchar pinMask, uchar state);

/**
 * @brief Interrupt Transition Pin Configuration
 * @param port Port
 * @param pinMask Pin
 */
void _hal_ioDigitalSelectInterruptTransition(vuchar *port, uchar pinMask, uchar transition);

/**
 * @brief Test Pin Pending Interrupt
 * @param port Port
 * @param pinMask Pin
 * @return Value Pending Interrupt
 */
uint _hal_ioDigitalIsPendingInterrupt(vuchar *port, uchar pinMask);

/**
 * @brief Clear Pin Pending Interrupt
 * @param port Port
 * @param pinMask Pin
 */
void _hal_ioDigitalClearPendingInterrupt(vuchar *port, uchar pinMask);

#endif
