/**
 *  @file io.c
 *  @brief Module that controls the I/O pins - Texas Instrument Microcontroller
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

#ifdef TIM

//				P1		P2
//				--		--
// 	PxIN 		0x20	0x28
//	PxOUT		0x21	0x29
//	PxDIR		0x22	0x2A
//	PxIFG		0x23	0x2B
//	PxIES		0x24	0x2C
//	PxIE		0x25	0x2D
//	PxSEL		0x26	0x2E
//	PxSEL2		0x41	0x42
//	PxREN		0x27	0x2F

/**
 * PxOUT to PxDIR Register Offset
 */
const uchar OFFSET_PxOUT_PxDIR = 1;

/**
 * PxOUT to PxSEL Register Offset
 */
const uchar OFFSET_PxOUT_PxSEL = 5;

/**
 * PxSEL to PxSEL2 Register Offset
 */
const uchar OFFSET_PxSEL_PxSEL2 = 27;

/**
 * PxINP to PxOUT Register Offset
 */
const uchar OFFSET_PxIN_PxOUT = 1;

/**
 * PxINP to PxDIR Register Offset
 */
const uchar OFFSET_PxIN_PxDIR = 2;

/**
 * PxINP to PxIFG Register Offset
 */
const uchar OFFSET_PxIN_PxIFG = 3;

/**
 * PxINP to PxIES Register Offset
 */
const uchar OFFSETPxINPxIES = 4;

/**
 * PxINP to PxIE Register Offset
 */
const uchar OFFSET_PxIN_PxIE = 5;

/**
 * PxINP to PxREN Register Offset
 */
const uchar OFFSET_PxIN_PxREN = 7;

/**
 * @brief Configure Digital Output Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void _hal_ioDigitalOutput(vuchar *portDirection, uchar pinMask)
{
	// Output Pin
	portDirection += OFFSET_PxOUT_PxDIR;
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
	portDirection += OFFSET_PxIN_PxDIR;
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
	switch(state)
	{
		// Disabled
		case 0:
			// Disabled Pull-Up
			portDirection += OFFSET_PxIN_PxREN;
			*portDirection &= ~(pinMask);
			break;
		// Enabled
		case 1:
			// Configure Pull Up
			portDirection += OFFSET_PxIN_PxOUT;
			*portDirection |= pinMask;

			// Enabled Pull-Up
			portDirection += OFFSET_PxIN_PxREN - OFFSET_PxOUT_PxDIR;
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
	switch(state)
	{
		// Disabled
		case 0:
			// Disabled Pull-Down
			portDirection += OFFSET_PxIN_PxREN;
			*portDirection &= ~(pinMask);
			break;
		// Enabled
		case 1:
			// Configure Pull-Down
			portDirection += OFFSET_PxIN_PxOUT;
			*portDirection &= ~(pinMask);

			// Enable Pull-Down
			portDirection += OFFSET_PxIN_PxREN - OFFSET_PxOUT_PxDIR;
			*portDirection |= pinMask;
			break;
	}
}

/**
 * @brief Select I/O Function Pin
 * @param port Port
 * @param pinMask Pin
 */
void _hal_ioSelectFunction(vuchar *port, uchar pinMask, uchar function)
{
	switch(function)
		{
			// Primary
			case 0:
				port += OFFSET_PxOUT_PxSEL;
				*port |= pinMask;
				port += OFFSET_PxSEL_PxSEL2;
				*port &= ~(pinMask);
				break;
			// Secondary
			case 1:
				port += OFFSET_PxOUT_PxSEL;
				*port |= pinMask;
				port += OFFSET_PxSEL_PxSEL2;
				*port |= pinMask;
				break;
			// IO
			case 2:
				port += OFFSET_PxOUT_PxSEL;
				*port &= ~(pinMask);
				port += OFFSET_PxSEL_PxSEL2;
				*port &= ~(pinMask);
				break;
		}
}

/**
 * @brief Interrupt Pin Configuration
 * @param port Port
 * @param pinMask Pin
 */
void _hal_ioDigitalInterrupt(vuchar *port, uchar pinMask, uchar state)
{
	switch(state)
	{
		// Disabled
		case 0:
			port += OFFSET_PxIN_PxIE;
			*port &= ~(pinMask);
			break;
		// Enabled
		case 1:
			port += OFFSET_PxIN_PxIE;
			*port |= pinMask;
			break;
	}
}

/**
 * @brief Interrupt Transition Pin Configuration
 * @param port Port
 * @param pinMask Pin
 */
void _hal_ioDigitalSelectInterruptTransition(vuchar *port, uchar pinMask, uchar transition)
{
	switch(transition)
	{
		// Low to High
		case 0:
			port += OFFSET_PxIN_PxIE;
			*port &= ~(pinMask);
			break;
		// High to Low
		case 1:
			port += OFFSETPxINPxIES;
			*port |= pinMask;
			break;
	}
}

/**
 * @brief Test Pin Pending Interrupt
 * @param port Port
 * @param pinMask Pin
 * @return Value Pending Interrupt
 */
uint _hal_ioDigitalIsPendingInterrupt(vuchar *port, uchar pinMask)
{
	uchar isPendingInterrupt = 0;

	port += OFFSET_PxIN_PxIFG;
	isPendingInterrupt = *port & ~(pinMask);

	return isPendingInterrupt;
}

/**
 * @brief Clear Pin Pending Interrupt
 * @param port Port
 * @param pinMask Pin
 */
void _hal_ioDigitalClearPendingInterrupt(vuchar *port, uchar pinMask)
{
	port += OFFSET_PxIN_PxIFG;
	*port &= ~(pinMask);
}

#endif
