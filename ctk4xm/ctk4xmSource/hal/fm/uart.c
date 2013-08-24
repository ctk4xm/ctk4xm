/**
 *  @file uart.c
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

#include "hal/uart.h"

#ifdef FREESCALE

// UART Module Pins Definition
#define SCI1_TX			&PTED,BIT0
#define SCI1_RX			&PTED,BIT1
#define SCI2_TX			&PTCD,BIT0
#define SCI2_RX			&PTCD,BIT1

#define	SC1_BR			BUS_CLK / (16 * SCI1_BPS)
#define	SC1_BDH			(SC1_BR & 0xFF00) >> 8
#define	SC1_BDL			SC1_BR & 0x00FF

#define	SC2_BR			BUS_CLK / (16 * SCI2_BPS)
#define	SC2_BDH			(SC2_BR & 0xFF00) >> 8
#define	SC2_BDL			SC2_BR & 0x00FF

/**
 * @brief Init UART Module
 * @param uartId UART Id
 * UART1 --> PTE0 (RX), PTE1 (TX)
 * UART2 --> PTC0 (RX), PTC1 (TX)
 */
void _hal_uartInit(uchar uartId)
{
	// Configure SCI Pins
	switch(uartId)
	{
		case 1:
			ioDigitalOutput(SCI1_TX);
			ioDigitalInput(SCI1_RX);
			SCI1BDH = SC1_BDH;
			SCI1BDL = SC1_BDL;
			break;
		case 2:
			ioDigitalOutput(SCI2_TX);
			ioDigitalInput(SCI2_RX);
			SCI2BDH = SC2_BDH;
			SCI2BDL = SC2_BDL;
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
