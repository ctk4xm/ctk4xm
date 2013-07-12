/**
 *  @file io-tim.c
 *  @brief Module that controls the I/O pins - Texas Instrument Microcontroller
 *  @date 10/07/2013
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

#include "../ctk4xmInclude/io-fm.h"

#ifdef FREESCALE

/**
 * PxOUT to PxDIR Register Offset
 */
const uchar OFFSETPxOUTPxDIR = 1;

/**
 * PxOUT to PxSEL Register Offset
 */
const uchar OFFSETPxOUTPxSEL = 5;

/**
 * PxSEL to PxSEL2 Register Offset
 */
const uchar OFFSETPxSELPxSEL2 = 27;

/**
 * PxINP to PxOUT Register Offset
 */
const uchar OFFSETPxINPxOUT = 1;

/**
 * PxINP to PxDIR Register Offset
 */
const uchar OFFSETPxINPxDIR = 2;

/**
 * PxINP to PxIFG Register Offset
 */
const uchar OFFSETPxINPxIFG = 3;

/**
 * PxINP to PxIES Register Offset
 */
const uchar OFFSETPxINPxIES = 4;

/**
 * PxINP to PxIE Register Offset
 */
const uchar OFFSETPxINPxIE = 5;

/**
 * PxINP to PxREN Register Offset
 */
const uchar OFFSETPxINPxREN = 7;

/**
 * @brief Configure Digital Output Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void _hal_pinDigitalOutput(vuchar *portDirection, uchar pinMask)
{
	// Output Pin
	portDirection += OFFSETPxOUTPxDIR;
	*portDirection |= pinMask;
}

/**
 * @brief Configure Digital Input Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void _hal_pinDigitalInput(vuchar *portDirection, uchar pinMask)
{
	// Input Pin
	portDirection += OFFSETPxINPxDIR;
	*portDirection &= ~(pinMask);
}

/**
 * @brief Enabled Pull-Up Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void _hal_pinDigitalEnabledPullUp(vuchar *portDirection, uchar pinMask)
{
	// Configure Pull Up
	portDirection += OFFSETPxINPxOUT;
	*portDirection |= pinMask;

	// Enabled Pull-Up
	portDirection += OFFSETPxINPxREN - OFFSETPxOUTPxDIR;
	*portDirection |= pinMask;
}

/**
 * @brief Enabled Pull-Down Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void _hal_pinDigitalEnabledPullDown(vuchar *portDirection, uchar pinMask)
{
	// Configure Pull-Down
	portDirection += OFFSETPxINPxOUT;
	*portDirection &= ~(pinMask);

	// Enable Pull-Down
	portDirection += OFFSETPxINPxREN - OFFSETPxOUTPxDIR;
	*portDirection |= pinMask;
}

/**
 * @brief Disabled Digital Pull-Up Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void _hal_pinDigitalDisabledPullUp(vuchar *portDirection, uchar pinMask)
{
	// Disabled Pull-Up
	portDirection += OFFSETPxINPxREN;
	*portDirection &= ~(pinMask);
}

/**
 * @brief Disabled Digital Pull-Down Pin
 * @param portDirection Port
 * @param pinMask Pin
 */
void _hal_pinDigitalDisabledPullDown(vuchar *portDirection, uchar pinMask)
{
	// Disabled Pull-Down
	portDirection += OFFSETPxINPxREN;
	*portDirection &= ~(pinMask);
}

/**
 * @brief Read Digital Pin
 * @param port Port
 * @param pinMask Pin
 * @return Value Digital Read
 */
uchar _hal_pinDigitalRead(vuchar *port, uchar pinMask)
{
	uchar pinValue = 0;

	// Read Pin Value
	if((*port & pinMask) != 0)
	{
		pinValue = 1;
	}
	return pinValue;
}

/**
 * @brief Write Digital Pin On
 * @param port Port
 * @param pinMask Pin
 */
void _hal_pinDigitalWriteOn(vuchar *port, uchar pinMask)
{
	// ON Pin
	*port |= pinMask;
}

/**
 * @brief Write Digital Pin Off
 * @param port Port
 * @param pinMask Pin
 */
void _hal_pinDigitalWriteOff(vuchar *port, uchar pinMask)
{
	// OFF Pin
	*port &= ~(pinMask);
}

/**
 * @brief Write Digital Toggle Pin
 * @param port Port
 * @param pinMask Pin
 */
void _hal_pinDigitalWriteToggle(vuchar *port, uchar pinMask)
{
	// Toggle Pin
	*port ^= pinMask;
}

/**
 * @brief Select I/O Function Pin
 * @param port Port
 * @param pinMask Pin
 */
void _hal_pinSelectIOFunction(vuchar *port, uchar pinMask)
{
	port += OFFSETPxOUTPxSEL;
	*port &= ~(pinMask);
	port += OFFSETPxSELPxSEL2;
	*port &= ~(pinMask);
}

/**
 * @brief Select Primary Function Pin
 * @param port Port
 * @param pinMask Pin
 */
void _hal_pinSelectPrimaryFunction(vuchar *port, uchar pinMask)
{
	port += OFFSETPxOUTPxSEL;
	*port |= pinMask;
	port += OFFSETPxSELPxSEL2;
	*port &= ~(pinMask);
}

/**
 * @brief Select Secondary Function Pin
 * @param port Port
 * @param pinMask Pin
 */
void _hal_pinSelectSecondaryFunction(vuchar *port, uchar pinMask)
{
	port += OFFSETPxOUTPxSEL;
	*port |= pinMask;
	port += OFFSETPxSELPxSEL2;
	*port |= pinMask;
}

/**
 * @brief Wait Level Pin int pinPulsador
 * @param port Port
 * @param pinNo Pin
 * @param typePulse Pulse Type
 * @param typeFlanco Type Flanco
 * @param timeOff Time Off
 * @param timeOn Time On
 * @return Value Digital Read
 */
uchar _hal_waitLevelPin(vuchar *port, uchar pinNo, uchar typePulse, uchar typeFlanco, uchar timeOff, uchar timeOn)
{
	uchar statusLevel = 0;
	uchar pinReference = 0;
	uchar timeOffCounter = 0;
	uchar timeOnCounter = 0;

	// Set pin Reference
	if(typePulse == 0)
	{
		pinReference = 0;
	}
	else
	{
		pinReference = 1;
	}
	
	// Wait first flanco
	while(1)
	{
		if(_hal_pinDigitalRead(port,pinNo) != pinReference)
		{
			// Espera por el tiempo antirebote
			delayMs(10);

			if(_hal_pinDigitalRead(port,pinNo) != pinReference)
			{
				statusLevel = 1;
				break;
			}
	    }
		else
		{
			// Si el contador no se ha presionado cuenta el tiempo Off
			if(timeOffCounter < timeOff)
			{
				timeOffCounter++;
				delayMs(1);
			}
			else
			{
				break;
			}  
		}
	}
	
	// Pregunta si se vencio el tiempo Off
	if(timeOffCounter < timeOff)
	{
		if(typeFlanco == 1)
		{
			// Espera por la aparición del primer flanco
			while(1)
			{
				if(_hal_pinDigitalRead(port,pinNo) == pinReference)
				{
					// Espera por el tiempo antirebote
					delayMs(10);

					if(_hal_pinDigitalRead(port,pinNo) == pinReference)
					{
						statusLevel = 1;
						break;
					}
				}
				else
				{
					// Si el contador no se ha presionado cuenta el tiempo Off
					if(timeOnCounter < timeOn)
					{
						timeOnCounter++;
						delayMs(1);
					}
					else
					{
						statusLevel = 0;
						break;
					}						
				}  
			}
		}
	}
	else
	{
		statusLevel = 0;
	}
	return statusLevel;
}

/**
 * @brief Enable Pin Interrupt
 * @param port Port
 * @param pinMask Pin
 */
void _hal_pinDigitalEnableInterrupt(vuchar *port, uchar pinMask)
{
	port += OFFSETPxINPxIE;
	*port |= pinMask;
}

/**
 * @brief Disable Pin Interrupt
 * @param port Port
 * @param pinMask Pin
 */
void _hal_pinDigitalDisableInterrupt(vuchar *port, uchar pinMask)
{
	port += OFFSETPxINPxIE;
	*port &= ~(pinMask);
}

/**
 * @brief Enable Pin High Low Transition Interrupt
 * @param port Port
 * @param pinMask Pin
 */
void _hal_pinDigitalSelectHighLowTransitionInterrupt(vuchar *port, uchar pinMask)
{
	port += OFFSETPxINPxIES;
	*port |= pinMask;
}

/**
 * @brief Enable Pin Low High Transition Interrupt
 * @param port Port
 * @param pinMask Pin
 */
void _hal_pinDigitalSelectLowHighTransitionInterrupt(vuchar *port, uchar pinMask)
{
	port += OFFSETPxINPxIE;
	*port &= ~(pinMask);
}

/**
 * @brief Test Pin Pending Interrupt
 * @param port Port
 * @param pinMask Pin
 * @return Value Pending Interrupt
 */
uint _hal_pinDigitalIsPendingInterrupt(vuchar *port, uchar pinMask)
{
	uchar isPendingInterrupt = 0;

	port += OFFSETPxINPxIFG;
	isPendingInterrupt = *port & ~(pinMask);

	return isPendingInterrupt;
}

/**
 * @brief Clear Pin Pending Interrupt
 * @param port Port
 * @param pinMask Pin
 */
void _hal_pinDigitalClearPendingInterrupt(vuchar *port, uchar pinMask)
{
	port += OFFSETPxINPxIFG;
	*port &= ~(pinMask);
}

#endif
