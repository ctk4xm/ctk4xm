/**
 *  @file adafruitPrinter.h
 *  @brief Module that allows print in the Adafruit Printer
 *  @date 24/08/2013
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

#ifndef ADAFRUIT_PRINTER_H_
#define ADAFRUIT_PRINTERS_H_

/**
 * Adafruit Printer Module
 */
#include "adafruitPrinter.h"

uchar column;

/**
 * Maximum Printing Dots
 */
uchar maxPrintingDots;

/**
 * Heating time
 */
uchar heatingTime;

/**
 * Heating Interval
 */
uchar heatingInterval;

/**
 * Break Time
 */
uchar breakTime;

/**
 * Print Density
 */
uchar printerDensity;

/**
 * @brief Adafruit Printer Init
 * @param uartId UART Id
 */
void adafruitPrinterInit(uchar uartId)
{
	// Init default value parameters
	maxPrintingDots = 20;
	heatingTime = 200;
	heatingInterval = 250;
	breakTime = 4;
	printerDensity = 14;

	// Initialize Counter Columns
	column = 0;

	// Configure UART2
	uartInit(2);

	// Delay 500 ms to Start
	delayMs(500);

	// Setting Control Parameter Command --> Esc 7 n1 n2 n3
	adafruitPrinterWrite(0x1B);										// ESC
	adafruitPrinterWrite(0x37);										// 7
	adafruitPrinterWrite(maxPrintingDots);							// n1 = 0-255 Max printing dots. Unit(8dots) Default: 7(64 dots)
	adafruitPrinterWrite(heatingTime);								// n2 = 3-255 Heating time.      Unit(10us)  Default: 80(800us)
	adafruitPrinterWrite(heatingInterval);							// n3 = 0-255 Heating interval.  Unit(10us)  Default: 2(20us)

	// Set printing density --> DC2 # n
	adafruitPrinterWrite(0x12);										// DC2
	adafruitPrinterWrite(0x23);										// #
	adafruitPrinterWrite((printBreakTime << 5) | printerDensity);	// D7..D5 Break time is (D7-D5)*250us | Density is 50% + 5% * (D4-D0) printing density
}

/**
 * @brief Print a Character
 * @param charPrint Character to print
 */
void adafruitPrinterWrite(uchar charPrint)
{
	// Skip Enter Char
	if(charPrint != 0x13)
	{
		// Validate if character line feed or final line
		if(charPrint == '\n' || column == MAX_COL)
		{
			// Send Line Feed Character
			uartWriteByte('\n');
			delayMs(1);

			// Initialize column counter
			column = 0;
		}
		else
		{
			// Send Character to Printer
			uartWriteByte(charPrint);
			delayMs(1);

			// Increment Column Counter
			column++;
		}
	}
}

#endif
