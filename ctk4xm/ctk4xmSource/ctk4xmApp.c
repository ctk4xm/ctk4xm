/**
 *  @file ctk4xmApp.c
 *  @brief Application Program
 *  @date 10/08/2013
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

/**
 * NMEA Sentence Data
 */
uchar nmeaSentenceData [15][15];

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
	uchar *ptrNmeaSentence;
	uchar *ptrNmeaData;

	uchar i, j, k, counter = 0;

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

	// Initialize LCD Module
	lcdInit();

	// Write Welcome Message
	lcdWriteMessage(1,1,"CTK4XM  Easy!!!");

	// Enable MCU Interrupts
	coreEnableInterrupts();

	while(1)
	{
		// Get NMEA GPRMC
		gpsStructNmeaGPRMC structNmeaGPRMC = gpsGetNmeaGPRMCSentence(5);

		if(structNmeaGPRMC.state == 'A')
		{
			// Export data to LCD
			lcdSetCursor(2,1);
			lcdDataDecFormat(structNmeaGPRMC.rtcHour, 2);
			lcdWrite(':');
			lcdDataDecFormat(structNmeaGPRMC.rtcMinute, 2);
			lcdWrite(':');
			lcdDataDecFormat(structNmeaGPRMC.rtcSecond, 2);
			lcdDataDecFormat(structNmeaGPRMC.rtcDay, 2);
			lcdWrite('/');
			lcdDataDecFormat(structNmeaGPRMC.rtcMonth, 2);
			lcdWrite('/');
			lcdDataDecFormat(structNmeaGPRMC.rtcYear, 2);
			
			lcdSetCursor(1,1);
			lcdDataDoubleFormat(structNmeaGPRMC.latitudeHourMinuteSecond, 4, 4);
			lcdDataDoubleFormat(structNmeaGPRMC.longitudeHourMinuteSecond, 4, 4);

			// Export data to Display 7-Seg
			display7SegWriteDecFormat(1, structNmeaGPRMC.rtcHour, 2);
			display7SegWriteDecFormat(3, structNmeaGPRMC.rtcMinute, 2);
			display7SegWriteDecFormat(5, structNmeaGPRMC.rtcSecond, 2);
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
	// Process GPS NMEA Sentence
	gpsReceiveNMEASentence(uartReadByte());
}

/**
 * @brief Interrupt Service Routine SCI1 ERROR
 */
void isrSCI1_ERR()
{
	SCI1S1 = 0;
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
