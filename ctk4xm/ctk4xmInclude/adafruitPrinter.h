/**
 *  @file adafruitPrinter.c
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

#define BAUD_RATE		9600

#define MAX_COL			32

/**
 * Config CTKXM FrameWork
 */
#include "config.h"

/**
 * Delay Module
 */
#include "delay.h"

/**
 * UART Module
 */
#include "uart.h"

#define printDensity   		14 // 120% (? can go higher, text is darker but fuzzy)
#define printBreakTime  	4 // 500 uS


/**
 * @brief Adafruit Printer Init
 * @param uartId UART Id
 */
void adafruitPrinterInit(uchar uartId);

/**
 * @brief Print a Chraracter
 * @param charPrint Character to print
 */
void adafruitPrinterWrite(uchar charPrint);
