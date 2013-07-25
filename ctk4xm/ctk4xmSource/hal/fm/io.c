/**
 *  @file io.c
 *  @brief Module that controls the I/O pins - Freescale Microcontroller
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

#include "hal/io.h"

#ifdef FREESCALE

// 	PTAD 	0x00000000
//	PTADD	0x00000001
//	PTAPE	0x00001840
//	PTASE	0x00001841
//	PTADS	0x00001842
//	PTASC	0x00001844
//	PTAPS	0x00001845
//	PTAES	0x00001846

//	PTBD	0x00000002
//	PTBDD	0x00000003
//	PTBPE	0x00001848
//	PTBSE	0x00001849
//	PTBDS	0x0000184A
//	PTBSC	0x0000184C
//	PTBPS	0x0000184D
//	PTBES	0x0000184E

//	PTCD	0x00000004
//	PTCDD	0x00000005
//	PTCPE	0x00001850
//	PTCSE	0x00001851
//	PTCDS	0x00001852
//	PTCSC	N/A
//	PTCPS	N/A
//	PTCES	N/A

/**
 * PTxD to PTxDD Offset
 */
const uchar OFFSET_PTxD_PTxDD = 1;

/**
 * Base Direction PTxPE
 */
const uchar BASE_DIR__PTxPE = 0x00001840;

/**
 * PTxPE to PTxPS Offset
 */
const uchar OFFSET_PTxPE__PTxPS = 5;

/**
 * PTxPE to PTxES Offset
 */
const uchar OFFSET_PTxPE__PTxES = 6;

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
	portDirection = (portDirection * 4) + DIR_BASE_PTxPE;

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

			// Enabled Pull-Up
			portDirection += OFFSET_PTxPE__PTxES;
			*portDirection &= ~(pinMask);
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
	// Get Direction PTxPE
	portDirection = (portDirection * 4) + DIR_BASE_PTxPE;

	switch(state)
	{
		// Disabled
		case 0:
			// Disabled Pull-Down
			*portDirection &= ~(pinMask);
			break;
		// Enabled
		case 1:
			// Configure Pull Up
			*portDirection |= pinMask;

			// Enabled Pull-Up
			portDirection += OFFSET_PTxPE__PTxES;
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

}

/**
 * @brief Interrupt Pin Configuration
 * @param port Port
 * @param pinMask Pin
 */
void _hal_ioDigitalInterrupt(vuchar *port, uchar pinMask, uchar state)
{
	// Get Direction PTxPS
	portDirection = (portDirection * 4) + DIR_BASE_PTxPE + OFFSET_PTxPE__PTxPS;

	switch(state)
	{
		// Disabled
		case 0:
			*port &= ~(pinMask);
			break;
		// Enabled
		case 1:
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

	port += OFFSETPxINPxIFG;
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
	port += OFFSETPxINPxIFG;
	*port &= ~(pinMask);
}

#endif
