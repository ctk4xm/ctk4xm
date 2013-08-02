/**
 *  @file uart.c
 *  @brief Module that allows Asynchronous Communications
 *  @date 02/08/2013
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

#include "uart.h"
#include "hal/uart.h"

/**
 * @brief Init UART Module
 * @param frequencyMHz MCU Frequency in MHz
 */
void uartInit(uchar frequencyMHz)
{
	_hal_uartInit(frequencyMHz);
}

/**
 * @brief Read Byte UART
 */
uchar uartReadByte()
{
	return _hal_uartReadByte();
}

/**
 * @brief Write Byte UART
 * @param writeByte Byte to Write
 */
void uartWriteByte(uchar writeByte)
{
	_hal_uartWriteByte(writeByte);
}
