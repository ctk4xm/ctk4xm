/**
 *  @file lcd.c
 *  @brief Module that controls Standard LCD Module
 *  @date 05/08/2013
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

#include "lcd.h"

/**
 * @brief Init LCD Module
 */
void lcdInit()
{
	// Configure LCD Pins
	ioDigitalOutput(LCD_RS);
	ioDigitalOutput(LCD_E);
	ioDigitalOutput(LCD_D7);
	ioDigitalOutput(LCD_D6);
	ioDigitalOutput(LCD_D5);
	ioDigitalOutput(LCD_D4);

	// Idle State
	ioDigitalWrite(LCD_RS, OFF);
	ioDigitalWrite(LCD_E, OFF);
	delayMs(15);

	// Init 4-bit LCD Mode
	ioDigitalWrite(LCD_E, ON);
	ioDigitalWrite(LCD_D7, OFF);
	ioDigitalWrite(LCD_D6, OFF);
	ioDigitalWrite(LCD_D5, ON);
	ioDigitalWrite(LCD_D4, ON);
	ioDigitalWrite(LCD_E, OFF);
	delayMs(5);
	ioDigitalWrite(LCD_E, ON);
	ioDigitalWrite(LCD_E, OFF);
	delayMs(1);
	ioDigitalWrite(LCD_E, ON);
	ioDigitalWrite(LCD_E, OFF);
	delayMs(5);
	ioDigitalWrite(LCD_E, ON);
	ioDigitalWrite(LCD_D4, OFF);
	ioDigitalWrite(LCD_E, OFF);
	delayMs(1);

	// LCD 4-bit Interface
	lcdInstru(0x28);

	// LCD Off Display
	lcdInstru(0x08);

	// LCD On Display
	lcdInstru(0x0C);

	// LCD Message Static with cursor auto-increment
	lcdInstru(0x06);

	// LCD Cursor Home
	lcdInstru(0x02);

	// LCD Cursor Clear
	lcdInstru(0x01);
}

/**
 * @brief Send Byte to Two Nibbles
 * @param byteExport Byte to send to LCD Module
 */
void lcdSendByte(uchar byteExport)
{
	uchar bitExport = 0;

	// Send 4-bit MSB
	ioDigitalWrite(LCD_E, ON);

	bitExport = byteExport & 0x80;
	if(bitExport == 0x80)
	{
		ioDigitalWrite(LCD_D7, ON);
	}
	else
	{
		ioDigitalWrite(LCD_D7, OFF);
	}

	bitExport = byteExport & 0x40;
	if(bitExport == 0x40)
	{
		ioDigitalWrite(LCD_D6, ON);
	}
	else
	{
		ioDigitalWrite(LCD_D6, OFF);
	}

	bitExport = byteExport & 0x20;
	if(bitExport == 0x20)
	{
		ioDigitalWrite(LCD_D5, ON);
	}
	else
	{
		ioDigitalWrite(LCD_D5, OFF);
	}

	bitExport = byteExport & 0x10;
	if(bitExport == 0x10)
	{
		ioDigitalWrite(LCD_D4, ON);
	}
	else
	{
		ioDigitalWrite(LCD_D4, OFF);
	}
	ioDigitalWrite(LCD_E, OFF);

	// Send 4-bit LSB
	ioDigitalWrite(LCD_E, ON);

	bitExport = byteExport & 0x08;
	if(bitExport == 0x08)
	{
		ioDigitalWrite(LCD_D7, ON);
	}
	else
	{
		ioDigitalWrite(LCD_D7, OFF);
	}

	bitExport = byteExport & 0x04;
	if(bitExport == 0x04)
	{
		ioDigitalWrite(LCD_D6, ON);
	}
	else
	{
		ioDigitalWrite(LCD_D6, OFF);
	}

	bitExport = byteExport & 0x02;
	if(bitExport == 0x02)
	{
		ioDigitalWrite(LCD_D5, ON);
	}
	else
	{
		ioDigitalWrite(LCD_D5, OFF);
	}

	bitExport = byteExport & 0x01;
	if(bitExport == 0x01)
	{
		ioDigitalWrite(LCD_D4, ON);
	}
	else
	{
		ioDigitalWrite(LCD_D4, OFF);
	}
	ioDigitalWrite(LCD_E, OFF);

	// Delay 2 ms
	delayMs(2);
}

/**
 * @brief Send Data LCD Module
 */
void lcdData(uchar data)
{
	// Data Mode
	ioDigitalWrite(LCD_RS, ON);

	// Send Byte
	lcdSendByte(data);
}

/**
 * @brief Send Instruction LCD Module
 * @param instru Instruction to send to LCD Module
 */
void lcdInstru(uchar instru)
{
	// Instruction Mode
	ioDigitalWrite(LCD_RS, OFF);

	// Send Byte
	lcdSendByte(instru);
}

/**
 * @brief Clear LCD Module
 */
void lcdClear()
{
	lcdInstru(LCD_CLEAR);
}

/**
 * @brief Set Home Cursor Position LCD Module
 */
void lcdHome()
{
	lcdInstru(LCD_HOME);
}

/**
 * @brief Set Cursor Position LCD Module
 * @param row LCD Row
 * @param column LCD Column
 */
void lcdSetCursor(uchar row, uchar column)
{
	uchar lcdPosition = 0;

	if(row > 0 && row <= 4 && column > 0 && column <= 20)
	{
		if(row == 1)
		{
			lcdPosition = 0x80 + (column - 1);
		}
		else if(row == 2)
		{
			lcdPosition = 0xC0 + (column - 1);
		}
		else if(row == 3)
		{
			lcdPosition = 0x94 + (column - 1);
		}
		else if(row == 4)
		{
			lcdPosition = 0xD4 + (column - 1);
		}

		// Send position to LCD Module
		lcdInstru(lcdPosition);
	}
}

/**
 * @brief Write Character LCD Module
 * @param exportData Data to Send to LCD Module
 */
void lcdWrite(uchar exportData)
{
	lcdData(exportData);
}

/**
 * @brief Write Character LCD Module
 * @param row LCD Row
 * @param column LCD Column
 * @param exportData Data to Send to LCD Module
 */
void lcdWriteSetPosition(uchar row, uchar column, uchar exportData)
{
	// LCD Position
	lcdSetCursor(row, column);

	// Write Data LCD Module
	lcdData(exportData);
}

/**
 * @brief Write Character LCD Module
 * @param row LCD Row
 * @param column LCD Column
 * @param ptrMessage Pointer Message to Send to LCD Module
 */
void lcdWriteMessage(uchar row, uchar column, char * ptrMessage)
{
	// LCD Position
	lcdSetCursor(row, column);

	while(*ptrMessage != 0)
	{
		lcdData(*ptrMessage);

		// Next Character
		ptrMessage++;
	}
}

/**
 * @brief Set Cursor Blink On LCD Module
 */
void lcdCursorBlinkOn()
{
	lcdInstru(LCD_BLINK_ON);
}

/**
 * @brief Set Cursor Blink Off LCD Module
 */
void lcdCursorBlinkOff()
{
	lcdInstru(LCD_BLINK_OFF);
}

/**
 * @brief Set Cursor Display On LCD Module
 */
void lcdCursorDisplayOn()
{
	lcdInstru(LCD_CURSOR_ON);
}

/**
 * @brief Set Cursor Display Off LCD Module
 */
void lcdCursorDisplayOff()
{
	lcdInstru(LCD_CURSOR_OFF);
}

/**
 * @brief Set Display On LCD Module
 */
void lcdDisplayOn()
{
	lcdInstru(LCD_DISPLAY_ON);
}

/**
 * @brief Set Display Off LCD Module
 */
void lcdDisplayOff()
{
	lcdInstru(LCD_DISPLAY_OFF);
}

/**
 * @brief Set Shift Off LCD Module
 */
void lcdShiftOff()
{
	lcdInstru(LCD_SHIFT_OFF);
}

/**
 * @brief Set Shift Left LCD Module
 */
void lcdShiftLeft()
{
	lcdInstru(LCD_SHIFT_LEFT);
}

/**
 * @brief Set Shift Right LCD Module
 */
void lcdShiftRight()
{
	lcdInstru(LCD_SHIFT_RIGHT);
}

/**
 * @brief Send Data Binary Format LCD Module
 * @param row LCD Row
 * @param column LCD Column
 * @param exportData Data to Send to LCD Module
 */
void lcdDataBinFormat(uchar row, uchar column, uchar exportData)
{
	uchar binaryMask = 0x80;
	uchar digit = 0;
	int i = 0;

	// LCD Position
	lcdSetCursor(row, column);

	for(i=0; i < 8; i++)
	{
		// Get Digit
		digit = (exportData / binaryMask);

		// Fix the Export Data and Binary Mask
		if(digit == 1)
		{
			exportData = exportData - binaryMask;
		}
		binaryMask = binaryMask >> 1;

		// Export Digit to LCD Module
		digit += 0x30;
		lcdData(digit);
	}

	// Print Binary Symbol
	lcdData('b');
}

/**
 * @brief Send Data Hexadecimal Format LCD Module
 * @param row LCD Row
 * @param column LCD Column
 * @param exportData Data to Send to LCD Module
 */
void lcdDataHexFormat(uchar row, uchar column, uchar exportData)
{
	uchar firstDigit = 0;
	uchar secondDigit = 0;

	// LCD Position
	lcdSetCursor(row, column);

	// Print Hex Symbol
	lcdData('0');
	lcdData('x');

	// First Digit
	firstDigit = exportData / 16;

	// Second Digit
	secondDigit = exportData - (firstDigit * 16);

	// Export First Digit
		if(firstDigit > 9)
	{
		firstDigit += 0x37;
	}
	else
	{
		firstDigit += 0x30;
	}
	lcdData(firstDigit);

	// Export Second Digit
	if(secondDigit > 9)
	{
		secondDigit += 0x37;
	}
	else
	{
		secondDigit += 0x30;
	}
	lcdData(secondDigit);
}

/**
 * @brief Send Data Decimal Format LCD Module
 * @param row LCD Row
 * @param column LCD Column
 * @param exportData Data to Send to LCD Module
 * @param quantityDigits Quantity Digits
 */
void lcdDataDecFormatSetPosition(uchar row, uchar column, uint exportData, uchar quantityDigits)
{
	// LCD Position
	lcdSetCursor(row, column);

	// Send Data Decimal Format LCD Module
	lcdDataDecFormat(exportData, quantityDigits);
}

/**
 * @brief Send Data Decimal Format LCD Module
 * @param dataExport Data to Send to LCD Module
 * @param quantityDigits Quantity Digits
 */
void lcdDataDecFormat(uint dataExport, uchar quantityDigits)
{
	uchar i = 0;
	uint divisor = 1;
	uchar digitExport = 0;

	// Get Divisor
	for(i = 1; i < quantityDigits; i++)
	{
		divisor *= 10;
	}

	// Get and Export Digits
	for(i = 1; i <= quantityDigits; i++)
	{
		// Export Digit
		digitExport = (dataExport / divisor) + 0x30;
		lcdData(digitExport);

		// Decrement export data and divisor
		dataExport %= divisor;
		divisor /= 10;
	}
}

/**
 * @brief Send Data Double Format LCD Module
 * @param row LCD Row
 * @param column LCD Column
 * @param dataExport Data to Send to LCD Module
 * @param quantityDigits Quantity Digits
 * @param quantityDecimals Quantity Decimals
 */
void lcdDataFloatFormatSetPosition(uchar row, uchar column, float dataExport, uchar quantityDigits, uchar quantityDecimals)
{
	// LCD Position
	lcdSetCursor(row, column);

	// Send Data Double Format LCD Module
	lcdDataFloatFormat(dataExport, quantityDigits, quantityDecimals);
}

/**
 * @brief Send Data Float Format LCD Module
 * @param dataExport Data to Send to LCD Module
 * @param quantityDigits Quantity Digits
 * @param quantityDecimals Quantity Decimals
 */
void lcdDataFloatFormat(float dataExport, uchar quantityDigits, uchar quantityDecimals)
{
	uchar i = 0;
	float divisorInteger = 1;
	float divisorDecimal = 1;
	uchar digitExport = 0;

	// Get Integer Digits
	for(i = 1; i < quantityDigits; i++)
	{
		divisorInteger *= 10;
	}
	
	// Get Decimal Digits
	for(i = 1; i < quantityDecimals; i++)
	{
		divisorDecimal *= 10;
	}	

	// Print Integer Digits
	for(i = 1; i < quantityDigits; i++)
	{
		digitExport = (uchar) (dataExport / divisorInteger);
		dataExport =- (digitExport * 1000);
		lcdData(digitExport);
		divisorInteger /= 10;
	}	
	
	// Fixed Decimal Digits
	dataExport *= divisorDecimal;
	
	// Print Decimal Digits
	for(i = 1; i < quantityDecimals; i++)
	{
		digitExport = (uchar) (dataExport / divisorDecimal);
		lcdData(digitExport);
		divisorDecimal /= 10;
	}
}

/**
 * @brief Send Data Date Format LCD Module
 * @param row LCD Row
 * @param column LCD Column
 * @param day Day
 * @param month Month
 * @param year Year
 */
void lcdDataDateFormat(uchar row, uchar column, uint day, uint month, uint year)
{
	// LCD Position
	lcdSetCursor(row, column);

	// Write Day
	lcdDataDecFormat(day,2);
	lcdWrite('/');

	// Write Month
	lcdDataDecFormat(month,2);
	lcdWrite('/');

	// Write Day
	lcdDataDecFormat(year,4);
}

/**
 * @brief Send Data Time Format LCD Module
 * @param row LCD Row
 * @param column LCD Column
 * @param hour Hour
 * @param minute Minute
 * @param second Second
 */
void lcdDataTimeFormat(uchar row, uchar column, uint hour, uint minute, uint second)
{
	// LCD Position
	lcdSetCursor(row, column);

	// Write Day
	lcdDataDecFormat(hour,2);
	lcdWrite(':');

	// Write Month
	lcdDataDecFormat(minute,2);
	lcdWrite(':');

	// Write Day
	lcdDataDecFormat(second,2);
}
