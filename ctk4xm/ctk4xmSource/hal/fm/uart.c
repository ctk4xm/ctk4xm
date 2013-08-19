/**
 *  @file uart.c
 *  @brief Module that allows Asynchronous Communications
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

#include "hal/uart.h"

#ifdef FREESCALE

/**
 * @brief Init UART Module
 * @param frequencyMHz MCU Frequency in MHz
 */
void _hal_uartInit(uchar frequencyMHz)
{
	// Configure SCI Pins
	ioDigitalOutput(SCI1_TX);
	ioDigitalInput(SCI1_RX);

	// Configure 9600 bps
	switch(frequencyMHz)
	{
		case 1:
			SCI1BDH = 0x00;
			SCI1BDL = 0x07;
			break;

		case 4:
			SCI1BDH = 0x01;
			SCI1BDL = 0x04;		// 4800 bps
			break;

		case 8:
			SCI1BDH = 0x00;
			SCI1BDL = 0x3A;
			break;

		case 12:
			SCI1BDH = 0x00;
			SCI1BDL = 0x57;
			break;

		case 16:
			SCI1BDH = 0x00;
			SCI1BDL = 0x74;
			break;

		default:
			SCI1BDH = 0x00;
			SCI1BDL = 0x3A;
			break;
	}

	// Enabled RX and TX
	SCI1C2 = SCI1C2_TE_MASK | SCI1C2_RE_MASK;
}

/**
 * @brief Read Byte UART
 */
uchar _hal_uartReadByte()
{
	// Wait for Reception Complete
	while(!(SCI1S1 & SCI1S1_RDRF_MASK));

	return SCI1D;
}

/**
 * @brief Write Byte UART
 * @param writeByte Byte to Write
 */
void _hal_uartWriteByte(uchar writeByte)
{
	// Write Byte to Send
	SCI1D = writeByte;

	// Wait for Transmit Complete
	while(!(SCI1S1 & SCI1S1_TC_MASK));
}

/**
 * @brief Read Interrupt Enable/Disable
 */
void _hal_uartReadInterrupt(uchar state)
{
	if(state)
	{
		SCI1C2 |= SCI1C2_RIE_MASK;
	}
	else
	{
		SCI1C2 &= ~(SCI1C2_RIE_MASK);
	}
}

/**
 * @brief Write Interrupt Enable/Disable
 */
void _hal_uartWriteInterrupt(uchar state)
{
	if(state)
	{
		SCI1C2 |= SCI1C2_TCIE_MASK;
	}
	else
	{
		SCI1C2 &= ~(SCI1C2_TCIE_MASK);
	}
}

#endif
