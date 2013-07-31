/**
 *  @file io.c
 *  @brief Module that controls the I/O pins - Freescale Microcontroller
 *  @date 29/07/2013
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

#include "hal/io.h"

#ifdef FREESCALE

//				PTA			PTB			PTC
//				---			---			---
// 	PTxD 		0x0000		0x0004		0x0008
//	PTxPE		0x0001		0x0005		0x0009
//	PTxSE		0x0002		0x0006		0x000A
//	PTxDD		0x0003		0x0007		0x000B

/**
 * PTxD to PTxDD Offset
 */
const uchar OFFSET_PTxD_PTxPE = 1;

/**
 * PTxD to PTxDD Offset
 */
const uchar OFFSET_PTxD_PTxSE = 2;

/**
 * PTxD to PTxDD Offset
 */
const uchar OFFSET_PTxD_PTxDD = 3;

/**
 * @brief Configure Digital Output Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void _hal_ioDigitalOutput(vuchar *portDirection, uchar pinMask)
{
	// Output Pin
	portDirection += OFFSET_PTxD_PTxDD;
	*portDirection |= pinMask;
}

/**
 * @brief Configure Digital Input Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void _hal_ioDigitalInput(vuchar *portDirection, uchar pinMask)
{
	// Input Pin
	portDirection += OFFSET_PTxD_PTxDD;
	*portDirection &= ~(pinMask);
}

/**
 * @brief Read Digital Pin
 * @param port Port
 * @param pinMask Pin
 * @return Value Digital Read
 */
uchar _hal_ioDigitalRead(vuchar *port, uchar pinMask)
{
	uchar pinValue = 0;

	// Read Pin Value
	if((*port & pinMask) != 0)
	{
		pinValue = 1;
	}
	return pinValue;
}

/**
 * @brief Write Digital Pin
 * @param port Port
 * @param pinMask Pin
 * @param level Level Pin
 */
void _hal_ioDigitalWrite(vuchar *port, uchar pinMask, uchar level)
{
	switch(level)
	{
		// OFF Pin
		case 0:
			*port &= ~(pinMask);
			break;
		// ON Pin
		case 1:
			*port |= pinMask;
			break;
		// Toggle Pin
		case 2:
			*port ^= pinMask;
			break;
	}
}

/**
 * @brief Pull-Up Pin Configuration
 * @param portDirection Port
 * @param pinMask Pin
 * @param state Enabled or Disabled
 */
void _hal_ioDigitalPullUp(vuchar *portDirection, uchar pinMask, uchar state)
{
	// Get Direction PTxPE
	portDirection += OFFSET_PTxD_PTxPE;

	switch(state)
	{
		// Disabled
		case 0:
			// Disabled Pull-Up
			*portDirection &= ~(pinMask);
			break;
		// Enabled
		case 1:
			// Configure Pull Up
			*portDirection |= pinMask;
			break;
	}
}

/**
 * @brief Pull-Down Pin Configuration
 * @param portDirection Port
 * @param pinMask Pin
 */
void _hal_ioDigitalPullDown(vuchar *portDirection, uchar pinMask, uchar state)
{

}

/**
 * @brief Select I/O Function Pin
 * @param port Port
 * @param pinMask Pin
 */
void _hal_ioSelectFunction(vuchar *port, uchar pinMask, uchar function)
{

}

/**
 * @brief Interrupt Pin Configuration
 * @param port Port
 * @param pinMask Pin
 */
void _hal_ioDigitalInterrupt(vuchar *port, uchar pinMask, uchar state)
{

}

/**
 * @brief Interrupt Transition Pin Configuration
 * @param port Port
 * @param pinMask Pin
 */
void _hal_ioDigitalSelectInterruptTransition(vuchar *port, uchar pinMask, uchar transition)
{

}

/**
 * @brief Test Pin Pending Interrupt
 * @param port Port
 * @param pinMask Pin
 * @return Value Pending Interrupt
 */
uint _hal_ioDigitalIsPendingInterrupt(vuchar *port, uchar pinMask)
{
	return 0;
}

/**
 * @brief Clear Pin Pending Interrupt
 * @param port Port
 * @param pinMask Pin
 */
void _hal_ioDigitalClearPendingInterrupt(vuchar *port, uchar pinMask)
{

}

#endif
