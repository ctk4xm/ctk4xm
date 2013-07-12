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
void pinDigitalOutput(vuchar *portDirection, uchar pinMask)
{
	_hal_pinDigitalOutput(portDirection, pinMask);
}

/**
 * @brief Configure Digital Input Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void pinDigitalInput(vuchar *portDirection, uchar pinMask)
{
	_hal_pinDigitalInput(portDirection, pinMask);
}

/**
 * @brief Enabled Pull-Up Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void pinDigitalEnabledPullUp(vuchar *portDirection, uchar pinMask)
{
	_hal_pinDigitalEnabledPullUp(portDirection, pinMask);
}

/**
 * @brief Enabled Pull-Down Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void pinDigitalEnabledPullDown(vuchar *portDirection, uchar pinMask)
{
	_hal_pinDigitalEnabledPullDown(portDirection, pinMask);
}

/**
 * @brief Disabled Digital Pull-Up Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void pinDigitalDisabledPullUp(vuchar *portDirection, uchar pinMask)
{
	_hal_pinDigitalDisabledPullUp(portDirection, pinMask);
}

/**
 * @brief Disabled Digital Pull-Down Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void pinDigitalDisabledPullDown(vuchar *portDirection, uchar pinMask)
{
	_hal_pinDigitalDisabledPullDown(portDirection, pinMask);
}

/**
 * @brief Read Digital Pin
 * @param port Port
 * @param pinMask Pin
 * @return Value Digital Read
 */
uchar pinDigitalRead(vuchar *port, uchar pinMask)
{
	return _hal_pinDigitalRead(port, pinMask);
}

/**
 * @brief Write Digital Pin On
 * @param port Port
 * @param pinMask Pin
 */
void pinDigitalWriteOn(vuchar *port, uchar pinMask)
{
	_hal_pinDigitalWriteOn(port, pinMask);
}

/**
 * @brief Write Digital Pin Off
 * @param port Port
 * @param pinMask Pin
 */
void pinDigitalWriteOff(vuchar *port, uchar pinMask)
{
	_hal_pinDigitalWriteOff(port, pinMask);
}

/**
 * @brief Write Digital Toggle Pin
 * @param port Port
 * @param pinMask Pin
 */
void pinDigitalWriteToggle(vuchar *port, uchar pinMask)
{
	_hal_pinDigitalWriteToggle(port, pinMask);
}

/**
 * @brief Select I/O Function Pin
 * @param port Port
 * @param pinMask Pin
 */
void pinSelectIOFunction(vuchar *port, uchar pinMask)
{
	_hal_pinSelectIOFunction(port, pinMask);
}

/**
 * @brief Select Primary Function Pin
 * @param port Port
 * @param pinMask Pin
 */
void pinSelectPrimaryFunction(vuchar *port, uchar pinMask)
{
	_hal_pinSelectPrimaryFunction(port, pinMask);
}

/**
 * @brief Select Secondary Function Pin
 * @param port Port
 * @param pinMask Pin
 */
void pinSelectSecondaryFunction(vuchar *port, uchar pinMask)
{
	_hal_pinSelectSecondaryFunction(port, pinMask);
}

/**
 * @brief Wait Level Pin int pinPulsador
 * @param port Port
 * @param pinNo Pin
 * @param typePulse Pulse Type
 * @param typeFlanco Type Flanco
 * @param timeOff Time Off
 * @param timeOn Time On
 * @return Value Digital Read
 */
uchar waitLevelPin(vuchar *port, uchar pinNo, uchar typePulse, uchar typeFlanco, uchar timeOff, uchar timeOn)
{
	return _hal_waitLevelPin(port, pinNo, typePulse, typeFlanco, timeOff, timeOn);
}

/**
 * @brief Enable Pin Interrupt
 * @param port Port
 * @param pinMask Pin
 */
void pinDigitalEnableInterrupt(vuchar *port, uchar pinMask)
{
	_hal_pinDigitalEnableInterrupt(port, pinMask);
}

/**
 * @brief Disable Pin Interrupt
 * @param port Port
 * @param pinMask Pin
 */
void pinDigitalDisableInterrupt(vuchar *port, uchar pinMask)
{
	_hal_pinDigitalDisableInterrupt(port, pinMask);
}

/**
 * @brief Enable Pin High Low Transition Interrupt
 * @param port Port
 * @param pinMask Pin
 */
void pinDigitalSelectHighLowTransitionInterrupt(vuchar *port, uchar pinMask)
{
	_hal_pinDigitalSelectHighLowTransitionInterrupt(port, pinMask);
}

/**
 * @brief Enable Pin Low High Transition Interrupt
 * @param port Port
 * @param pinMask Pin
 */
void pinDigitalSelectLowHighTransitionInterrupt(vuchar *port, uchar pinMask)
{
	_hal_pinDigitalSelectLowHighTransitionInterrupt(port, pinMask);
}

/**
 * @brief Test Pin Pending Interrupt
 * @param port Port
 * @param pinMask Pin
 * @return Value Pending Interrupt
 */
uint pinDigitalIsPendingInterrupt(vuchar *port, uchar pinMask)
{
	return _hal_pinDigitalIsPendingInterrupt(port, pinMask);
}

/**
 * @brief Clear Pin Pending Interrupt
 * @param port Port
 * @param pinMask Pin
 */
void pinDigitalClearPendingInterrupt(vuchar *port, uchar pinMask)
{
	_hal_pinDigitalClearPendingInterrupt(port, pinMask);
}
