/**
 *  @file uart.h
 *  @brief Module that allows Asynchronous Communications
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

#ifndef UART_H_
#define UART_H_

#include "config.h"
#include "io.h"

#define	SCI1		1
#define	SCI2		2

/**
 * @brief Init UART Module
 * @param uartId UART Id
 */
void uartInit(uchar uartId);

/**
 * @brief Read Byte UART
 */
uchar uartReadByte();

/**
 * @brief Write Byte UART
 * @param writeByte Byte to Write
 */
void uartWriteByte(uchar writeByte);

/**
 * @brief Read Interrupt Enable/Disable
 */
void uartReadInterrupt(uchar state);

/**
 * @brief Write Interrupt Enable/Disable
 */
void uartWriteInterrupt(uchar state);

#endif
