/**
 *  @file io-fm.h
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

#include "core.h"
#include "delay.h"

#ifdef FREESCALE

/**
 * @brief Configure Digital Output Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void _hal_pinDigitalOutput(vuchar *portDirection, uchar pinMask);

/**
 * @brief Configure Digital Input Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void _hal_pinDigitalInput(vuchar *portDirection, uchar pinMask);

/**
 * @brief Enabled Pull-Up Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void _hal_pinDigitalEnabledPullUp(vuchar *portDirection, uchar pinMask);

/**
 * @brief Enabled Pull-Down Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void _hal_pinDigitalEnabledPullDown(vuchar *portDirection, uchar pinMask);

/**
 * @brief Disabled Digital Pull-Up Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void _hal_pinDigitalDisabledPullUp(vuchar *portDirection, uchar pinMask);

/**
 * @brief Disabled Digital Pull-Down Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void _hal_pinDigitalDisabledPullDown(vuchar *portDirection, uchar pinMask);

/**
 * @brief Read Digital Pin
 * @param port Port
 * @param pinMask Pin
 * @return Value Digital Read
 */
uchar _hal_pinDigitalRead(vuchar *port, uchar pinMask);

/**
 * @brief Write Digital Pin On
 * @param port Port
 * @param pinMask Pin
 */
void _hal_pinDigitalWriteOn(vuchar *port, uchar pinMask);

/**
 * @brief Write Digital Pin Off
 * @param port Port
 * @param pinMask Pin
 */
void _hal_pinDigitalWriteOff(vuchar *port, uchar pinMask);

/**
 * @brief Write Digital Toggle Pin
 * @param port Port
 * @param pinMask Pin
 */
void _hal_pinDigitalWriteToggle(vuchar *port, uchar pinMask);

/**
 * @brief Select I/O Function Pin
 * @param port Port
 * @param pinMask Pin
 */
void _hal_pinSelectIOFunction(vuchar *port, uchar pinMask);

/**
 * @brief Select Primary Function Pin
 * @param port Port
 * @param pinMask Pin
 */
void _hal_pinSelectPrimaryFunction(vuchar *port, uchar pinMask);

/**
 * @brief Select Secondary Function Pin
 * @param port Port
 * @param pinMask Pin
 */
void _hal_pinSelectSecondaryFunction(vuchar *port, uchar pinMask);

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
uchar _hal_waitLevelPin(vuchar *port, uchar pinNo, uchar typePulse, uchar typeFlanco, uchar timeOff, uchar timeOn);

/**
 * @brief Enable Pin Interrupt
 * @param port Port
 * @param pinMask Pin
 */
void _hal_pinDigitalEnableInterrupt(vuchar *port, uchar pinMask);

/**
 * @brief Disable Pin Interrupt
 * @param port Port
 * @param pinMask Pin
 */
void _hal_pinDigitalDisableInterrupt(vuchar *port, uchar pinMask);

/**
 * @brief Enable Pin High Low Transition Interrupt
 * @param port Port
 * @param pinMask Pin
 */
void _hal_pinDigitalSelectHighLowTransitionInterrupt(vuchar *port, uchar pinMask);

/**
 * @brief Enable Pin Low High Transition Interrupt
 * @param port Port
 * @param pinMask Pin
 */
void _hal_pinDigitalSelectLowHighTransitionInterrupt(vuchar *port, uchar pinMask);

/**
 * @brief Test Pin Pending Interrupt
 * @param port Port
 * @param pinMask Pin
 * @return Value Pending Interrupt
 */
uint _hal_pinDigitalIsPendingInterrupt(vuchar *port, uchar pinMask);

/**
 * @brief Clear Pin Pending Interrupt
 * @param port Port
 * @param pinMask Pin
 */
void _hal_pinDigitalClearPendingInterrupt(vuchar *port, uchar pinMask);

#endif
