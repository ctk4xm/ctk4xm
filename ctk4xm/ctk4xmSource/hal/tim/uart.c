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

#ifdef TIM

/**
 * @brief Init UART Module
 * @param frequencyMHz MCU Frequency in MHz
 */
void _hal_uartInit(uchar frequencyMHz)
{

}

/**
 * @brief Read Byte UART
 */
uchar _hal_uartReadByte()
{
	uchar readByte = 0;

	return readByte;
}

/**
 * @brief Write Byte UART
 * @param writeByte Byte to Write
 */
void _hal_uartWriteByte(uchar writeByte)
{

}

#endif
