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

/**
 * @brief Configure Digital Output Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void pinDigitalOutput(vuchar *portDirection, uchar pinMask);

/**
 * @brief Configure Digital Input Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void pinDigitalInput(vuchar *portDirection, uchar pinMask);

/**
 * @brief Enabled Pull-Up Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void pinDigitalEnabledPullUp(vuchar *portDirection, uchar pinMask);

/**
 * @brief Enabled Pull-Down Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void pinDigitalEnabledPullDown(vuchar *portDirection, uchar pinMask);

/**
 * @brief Disabled Digital Pull-Up Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void pinDigitalDisabledPullUp(vuchar *portDirection, uchar pinMask);

/**
 * @brief Disabled Digital Pull-Down Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void pinDigitalDisabledPullDown(vuchar *portDirection, uchar pinMask);

/**
 * @brief Read Digital Pin
 * @param port Port
 * @param pinMask Pin
 * @return Value Digital Read
 */
uchar pinDigitalRead(vuchar *port, uchar pinMask);

/**
 * @brief Write Digital Pin On
 * @param port Port
 * @param pinMask Pin
 */
void pinDigitalWriteOn(vuchar *port, uchar pinMask);

/**
 * @brief Write Digital Pin Off
 * @param port Port
 * @param pinMask Pin
 */
void pinDigitalWriteOff(vuchar *port, uchar pinMask);

/**
 * @brief Write Digital Toggle Pin
 * @param port Port
 * @param pinMask Pin
 */
void pinDigitalWriteToggle(vuchar *port, uchar pinMask);

/**
 * @brief Select I/O Function Pin
 * @param port Port
 * @param pinMask Pin
 */
void pinSelectIOFunction(vuchar *port, uchar pinMask);

/**
 * @brief Select Primary Function Pin
 * @param port Port
 * @param pinMask Pin
 */
void pinSelectPrimaryFunction(vuchar *port, uchar pinMask);

/**
 * @brief Select Secondary Function Pin
 * @param port Port
 * @param pinMask Pin
 */
void pinSelectSecondaryFunction(vuchar *port, uchar pinMask);

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
uchar waitLevelPin(vuchar *port, uchar pinNo, uchar typePulse, uchar typeFlanco, uchar timeOff, uchar timeOn);

/**
 * @brief Enable Pin Interrupt
 * @param port Port
 * @param pinMask Pin
 */
void pinDigitalEnableInterrupt(vuchar *port, uchar pinMask);

/**
 * @brief Disable Pin Interrupt
 * @param port Port
 * @param pinMask Pin
 */
void pinDigitalDisableInterrupt(vuchar *port, uchar pinMask);

/**
 * @brief Enable Pin High Low Transition Interrupt
 * @param port Port
 * @param pinMask Pin
 */
void pinDigitalSelectHighLowTransitionInterrupt(vuchar *port, uchar pinMask);

/**
 * @brief Enable Pin Low High Transition Interrupt
 * @param port Port
 * @param pinMask Pin
 */
void pinDigitalSelectLowHighTransitionInterrupt(vuchar *port, uchar pinMask);

/**
 * @brief Test Pin Pending Interrupt
 * @param port Port
 * @param pinMask Pin
 * @return Value Pending Interrupt
 */
uint pinDigitalIsPendingInterrupt(vuchar *port, uchar pinMask);

/**
 * @brief Clear Pin Pending Interrupt
 * @param port Port
 * @param pinMask Pin
 */
void pinDigitalClearPendingInterrupt(vuchar *port, uchar pinMask);

#endif
