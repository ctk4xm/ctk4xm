/**
 *  @file ctk4xmApp.c
 *  @brief Application Program
 *  @date 06/08/2013
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

/**
 * Application Include
 */
#include "ctk4xmApp.h"

/**
 * Configurations Include
 */
#include "config.h"

/**
 * Core Include
 */
#include "core.h"

/**
 * IO Include
 */
#include "io.h"

/**
 * Delay Include
 */
#include "delay.h"

/**
 * LCD Include
 */
#include "lcd.h"

/**
 * Display 7-Seg
 */
#include "display7Seg.h"

/**
 * UART Include
 */
#include "uart.h"

/**
 * GPS Include
 */
#include "gps.h"

/**
 * TIMER Include
 */
#include "timer.h"

#ifdef TIM
	#define LED		&P1OUT,BIT0
#else
	#define LED		&PTCD,BIT0
#endif

/*
 * @brief Application Program Loop
 */
void application()
{
	// NMEA Buffer
	uchar *nmeaSentenceData;

	uchar i, counter = 0;

	// Stop Watchdog Timer
	coreStopWatchdogTimer();

	// Select Internal Clock 8MHz
	//coreSelectInternalClock(8);

	// Select External Clock
	coreSelectExternalClock();

	// Configure LED Pin
	ioDigitalOutput(LED);

	// GPS Init
	gpsInit();

	// Init LCD Module
	display7SegInit();

	// Write 1234 in buffer
	//display7SegWriteMessage(1,display7SegMessage);

	// Initialize LCD Module
	lcdInit();

	// Write Welcome Message
	lcdWriteMessage(1,1,"CTK4XM  Easy!!!");

	// Write Welcome Message
	lcdWriteMessage(2,1,"Counter: ");

	// Enable MCU Interrupts
	coreEnableInterrupts();

	while(1)
	{
		// Led ON
		ioDigitalWrite(LED, ON);

		// Delay 100ms
		delayMs(100);

		// Led OFF
		ioDigitalWrite(LED, OFF);

		// Delay 100ms
		delayMs(100);

		// Write counter value
		lcdSetCursor(2,10);
		lcdDataDecFormat(counter,3);

		// Increment Counter
		counter++;

		// Get Valid RMC Character
		nmeaSentenceData = gpsGetNmeaSentenceData(1);

		if(*nmeaSentenceData == 'A')
		{
			// Write Welcome Message
			lcdWriteMessage(1,1,"Valido");
			lcdSetCursor(2,1);

			// get NMEA Variable
			nmeaSentenceData = gpsGetNmeaSentenceData(0);
			i = 1;

			// Obtain data variable
			while(*nmeaSentenceData != '\n')
			{
				lcdData(*nmeaSentenceData);
				display7SegWriteBuffer(i, (*nmeaSentenceData - 0x30));
				nmeaSentenceData++;
				i++;
			}
		}
		else
		{
			// Write Welcome Message
			lcdWriteMessage(1,1,"Invalido");
		}


	}
}

#ifdef TIM

/**
 * @brief Interrupt Service Routine Port 1
 */
void isrPort1()
{

}

/**
 * @brief Interrupt Service Routine Port 2
 */
void isrPort2()
{

}

/**
 * @brief Interrupt Service Routine ADC 10-bit
 */
void isrAdc10()
{

}

/**
 * @brief Interrupt Service Routine SCI TX
 */
void isrSci0Tx()
{

}

/**
 * @brief Interrupt Service Routine SCI RX
 */
void isrSci0Rx()
{

}

/**
 * @brief Interrupt Service Routine Timer 0 Channel 1
 */
void isrTimer0Ch1()
{

}

/**
 * @brief Interrupt Service Routine Timer 0 Channel 0
 */
void isrTimer0Ch0()
{

}

/**
 * @brief Interrupt Service Routine WatchDog Timer
 */
void isrWDT()
{

}

/**
 * @brief Interrupt Service Routine Comparator A
 */
void isrComparatorA()
{

}

/**
 * @brief Interrupt Service Routine Timer 1 Channel 1
 */
void isrTimer1Ch1()
{

}

/**
 * @brief Interrupt Service Routine Timer 1 Channel 0
 */
void isrTimer1Ch0()
{

}

/**
 * @brief Interrupt Service Routine NMI
 */
void isrNMI()
{

}

#endif


#ifdef FREESCALE

/**
 * @brief Interrupt Service Routine SCI2 TX
 */
void isrSCI2_TX()
{

}

/**
 * @brief Interrupt Service Routine SCI2 RX
 */
void isrSCI2_RX()
{

}

/**
 * @brief Interrupt Service Routine SCI2 ERROR
 */
void isrSCI2_ERR()
{

}

/**
 * @brief Interrupt Service Routine SCI1 TX
 */
void isrSCI1_TX()
{

}

/**
 * @brief Interrupt Service Routine SCI1 RX
 */
void isrSCI1_RX()
{
	// Obtain Data SCI
	uchar dataSCI = uartReadByte();

	// Process GPS NMEA Sentence
	gpsReceiveNMEASentence("$GPRMC", dataSCI);

	// Send Data Receive
	uartWriteByte(dataSCI);
}

/**
 * @brief Interrupt Service Routine SCI1 ERROR
 */
void isrSCI1_ERR()
{

}

/**
 * @brief Interrupt Service Routine TPM1 OverFlow
 */
void isrTPM1_OVER()
{
	// Display 7-Seg Update
	display7SegUpdate();

	// Clear Interrupt Flag
	timerClearInterruptFlag();
}

#endif
