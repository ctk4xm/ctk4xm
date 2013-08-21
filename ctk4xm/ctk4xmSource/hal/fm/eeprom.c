/**
 *  @file eeprom.h
 *  @brief Module that allows simulate EEPROM in FLASH Memory
 *  @date 21/08/2013
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
	// Clear FACCERR Flag
	if(FSTAT & FSTAT_FACCERR_MASK)
	{
		FSTAT |= FSTAT_FACCERR_MASK;
	}
		
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
uchar _hal_eepromReadByte(uchar *addressPtr)
{
	return *addressPtr;
}

/**
 * @brief Write Byte EEPROM
 * @param *addressPtr Pointer to Address EEPROM to write
 * @param writeByte Byte to Write in EEPROM
 */
uchar _hal_eepromWriteByte(uchar *addressPtr, uchar writeByte)
{
	// Store Byte Program Command
	return _hal_eepromExecuteCommand(0x20, addressPtr, writeByte);
}

/**
 * @brief Erase Page EEPROM
 * @param address Address EEPROM to erase
 */
uchar _hal_eepromErasePage(uchar *addressPtr)
{
	// Store Erase Page Command
	return _hal_eepromExecuteCommand(0x40, addressPtr, 0xFF);
}

/**
 * @brief Execute EEPROM Command
 * @param eepromCommand Command EEPROM to execute
 */
uchar _hal_eepromExecuteCommand(uchar eepromCommand, uchar *addressPtr, uchar writeByte)
{
	uchar errorCode = 0;

	// Clear FACCERR Flag
	if(FSTAT & FSTAT_FACCERR_MASK)
	{
		FSTAT |= FSTAT_FACCERR_MASK;
	}

	// Store data to write
	*addressPtr = writeByte;

	// Store EEPROM Command
	FCMD = eepromCommand;

	// Execute the command
	FSTAT |= FSTAT_FCBEF_MASK;

	// Wait 4 bus cycles
	asm
	{
		nop;
		nop;
		nop;
		nop;
	}

	// Verify errors at byte write
	if((FSTAT & FSTAT_FPVIOL_MASK) || (FSTAT & FSTAT_FACCERR_MASK))
	{
		errorCode = 1;
	}
	else
	{
		while(!(FSTAT & FSTAT_FCBEF_MASK));
	}
	return errorCode;
}

#endif
