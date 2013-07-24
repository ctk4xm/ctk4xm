/**
 *  @file io.h
 *  @brief Module that controls the I/O pins
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

#ifndef IO_H_
#define IO_H_

#include "config.h"
#include "delay.h"

#define 	OFF					0
#define 	ON					1
#define 	TOOGLE				2
#define 	DISABLED			0
#define 	ENABLED				1
#define 	PRIMARY				1
#define 	SECONDARY			2
#define 	LOW_TO_HIGH			0
#define 	HIGH_TO_LOW			1

/**
 * @brief Configure Digital Output Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void ioDigitalOutput(vuchar *portDirection, uchar pinMask);

/**
 * @brief Configure Digital Input Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void ioDigitalInput(vuchar *portDirection, uchar pinMask);

/**
 * @brief Read Digital Pin
 * @param port Port
 * @param pinMask Pin
 * @return Value Digital Read
 */
uchar ioDigitalRead(vuchar *port, uchar pinMask);

/**
 * @brief Write Digital Pin
 * @param port Port
 * @param pinMask Pin
 * @param level Level Pin
 */
void ioDigitalWrite(vuchar *port, uchar pinMask, uchar level);

/**
 * @brief Pull-Up Pin Configuration
 * @param portDirection Port
 * @param pinMask Pin
 * @param state Enabled or Disabled
 */
void ioDigitalPullUp(vuchar *portDirection, uchar pinMask, uchar state);

/**
 * @brief Pull-Down Pin Configuration
 * @param portDirection Port
 * @param pinMask Pin
 */
void ioDigitalPullDown(vuchar *portDirection, uchar pinMask, uchar state);

/**
 * @brief Select I/O Function Pin
 * @param port Port
 * @param pinMask Pin
 */
void ioSelectFunction(vuchar *port, uchar pinMask, uchar function);

/**
 * @brief Interrupt Pin Configuration
 * @param port Port
 * @param pinMask Pin
 */
void ioDigitalInterrupt(vuchar *port, uchar pinMask, uchar state);

/**
 * @brief Interrupt Transition Pin Configuration
 * @param port Port
 * @param pinMask Pin
 */
void ioDigitalSelectInterruptTransition(vuchar *port, uchar pinMask, uchar transition);

/**
 * @brief Test Pin Pending Interrupt
 * @param port Port
 * @param pinMask Pin
 * @return Value Pending Interrupt
 */
uint ioDigitalIsPendingInterrupt(vuchar *port, uchar pinMask);

/**
 * @brief Clear Pin Pending Interrupt
 * @param port Port
 * @param pinMask Pin
 */
void ioDigitalClearPendingInterrupt(vuchar *port, uchar pinMask);

#endif
