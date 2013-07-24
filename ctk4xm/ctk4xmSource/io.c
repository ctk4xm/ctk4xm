/**
 *  @file io.c
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

#include "io.h"
#include "hal/io.h"

/**
 * @brief Configure Digital Output Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void ioDigitalOutput(vuchar *portDirection, uchar pinMask)
{
	_hal_ioDigitalOutput(portDirection, pinMask);
}

/**
 * @brief Configure Digital Input Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void ioDigitalInput(vuchar *portDirection, uchar pinMask)
{
	_hal_ioDigitalInput(portDirection, pinMask);
}

/**
 * @brief Read Digital Pin
 * @param port Port
 * @param pinMask Pin
 * @return Value Digital Read
 */
uchar ioDigitalRead(vuchar *port, uchar pinMask)
{
	return _hal_ioDigitalRead(port, pinMask);
}

/**
 * @brief Write Digital Pin
 * @param port Port
 * @param pinMask Pin
 * @param level Level Pin
 */
void ioDigitalWrite(vuchar *port, uchar pinMask, uchar level)
{
	_hal_ioDigitalWrite(port, pinMask, level);
}

/**
 * @brief Pull-Up Pin Configuration
 * @param portDirection Port
 * @param pinMask Pin
 * @param state Enabled or Disabled
 */
void ioDigitalPullUp(vuchar *portDirection, uchar pinMask, uchar state)
{
	_hal_ioDigitalPullUp(portDirection, pinMask, state);
}

/**
 * @brief Pull-Down Pin Configuration
 * @param portDirection Port
 * @param pinMask Pin
 */
void ioDigitalPullDown(vuchar *portDirection, uchar pinMask, uchar state)
{
	_hal_ioDigitalPullDown(portDirection, pinMask, state);
}

/**
 * @brief Interrupt Pin Configuration
 * @param port Port
 * @param pinMask Pin
 */
void ioDigitalInterrupt(vuchar *port, uchar pinMask, uchar state)
{
	_hal_ioDigitalInterrupt(port, pinMask, state);
}

/**
 * @brief Select I/O Function Pin
 * @param port Port
 * @param pinMask Pin
 */
void ioSelectFunction(vuchar *port, uchar pinMask, uchar function)
{
	_hal_ioSelectFunction(port, pinMask, function);
}

/**
 * @brief Interrupt Transition Pin Configuration
 * @param port Port
 * @param pinMask Pin
 */
void ioDigitalSelectInterruptTransition(vuchar *port, uchar pinMask, uchar transition)
{
	_hal_ioDigitalSelectInterruptTransition(port, pinMask,transition);
}

/**
 * @brief Test Pin Pending Interrupt
 * @param port Port
 * @param pinMask Pin
 * @return Value Pending Interrupt
 */
uint ioDigitalIsPendingInterrupt(vuchar *port, uchar pinMask)
{
	return _hal_ioDigitalIsPendingInterrupt(port, pinMask);
}

/**
 * @brief Clear Pin Pending Interrupt
 * @param port Port
 * @param pinMask Pin
 */
void ioDigitalClearPendingInterrupt(vuchar *port, uchar pinMask)
{
	_hal_ioDigitalClearPendingInterrupt(port, pinMask);
}
