/**
 *  @file eeprom.h
 *  @brief Module that allows simulate EEPROM in FLASH Memory
 *  @date 19/08/2013
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

#include "eeprom.h"
#include "hal/eeprom.h"

#ifdef FREESCALE

/**
 * @brief Init EEPROM Module
 * @param frequency Bus Frequency
 */
void _hal_eepromInit(uchar busFrequency)
{
	// Initialize Flash Clock Divider
	switch(busFrequency)
	{
		case 1:
			FCDIV = 4;
			break;
		case 2:
			FCDIV = 9;
			break;
		case 4:
			FCDIV = 19;
			break;
		case 8:
			FCDIV = 39;
			break;
		case 10:
			FCDIV = 49;
			break;
		case 20:
			FCDIV = FCDIV_PRDIV8 | 12;
			break;
	}
}


/**
 * @brief Read Byte EEPROM
 * @param address Address EEPROM to read
 */
uchar _hal_eepromReadByte(uint address)
{
	return 'E';
}

/**
 * @brief Write Byte EEPROM
 * @param *addressPtr Pointer to Address EEPROM to write
 * @param writeByte Byte to Write in EEPROM
 */
uchar _hal_eepromWriteByte(uchar *addressPtr, uchar writeByte)
{
	uchar errorCode = 0;

	// Clear FACCERR Flag
	FSTAT &= ~(FSTAT_FACCERR_MASK);

	// Store data to write
	*addressPtr = writeByte;

	// Store Byte Program Command
	FCMD = 0x20;

	// Execute the command
	FSTAT |= FSTAT_FCBEF_MASK;

	// Wait 4 bus cycles
	asm
	{
		nop;
		nop;
		nop;
	}

	// Verify errors at byte write
	if(FSTAT & FSTAT_FPVIOL_MASK == 0 || FSTAT & FSTAT_FACCERR_MASK == 0)
	{
		if(!(FSTAT & FSTAT_FCCF_MASK))
		{
			errorCode = 1;
		}
	}
	else
	{
		errorCode = 1;
	}
}

#endif
