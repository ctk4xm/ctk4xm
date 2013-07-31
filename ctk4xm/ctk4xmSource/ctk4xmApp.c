/**
 *  @file ctk4xmApp.c
 *  @brief Application Program
 *  @date 24/07/2013
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

#ifdef TIM
	#define LED		&P1OUT,BIT0
#else
	#define LED		&PTCD,BIT0
#endif

/**
 * Welcome Message
 */
const uchar welcome [] = "CTK4XM  Easy!!!";
const uchar label [] = "Counter: ";

/*
 * @brief Application Program Loop
 */
void application()
{
	uchar counter = 0;

	// Stop Watchdog Timer
	coreStopWatchdogTimer();

	// Select Internal Clock 1MHz
	coreSelectInternalClock(1);

	// Configure LED Pin
	ioDigitalOutput(LED);

	// Initialize LCD Module
	lcdInit();

	// Write Welcome Message
	lcdWriteMessage(1,1,welcome);

	// Write Welcome Message
	lcdWriteMessage(2,1,label);

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
	}
}

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
