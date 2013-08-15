/**
 *  @file gps.c
 *  @brief Module that allows work GPS
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

#include "gps.h"
#include "io.h"
#include "delay.h"
#include "uart.h"

/**
 * NMEA Sentence Buffer
 * [0] $GPGGA
 * [1] $GPGSA
 * [2] $GPRMC
 */
uchar gpsNmeaSentenceBuffer[3][15][15];

/**
 * NMEA Sentence Pointer
 */
uchar *ptrNmeaSentenceBuffer;

/**
 * Capture NMEA Sentence Flag
 */
uchar gpsCaptureNMEASentence;

/**
 * Buffer ID NMEA Sentence
 */
uchar gpsNmeaSentenceIdBuffer [6];

/**
 * ID NMEA Sentence $GPGGA
 */
const uchar gpsNmeaSentenceGPGGAId [] = "$GPGGA";

/**
 * ID NMEA Sentence $GPGGA Counter
 */
uchar gpsNmeaSentenceGPGGAIdCounter;

/**
 * ID NMEA Sentence $GPGGA
 */
const uchar gpsNmeaSentenceGPGSAId [] = "$GPGSA";

/**
 * ID NMEA Sentence $GPGGA Counter
 */
uchar gpsNmeaSentenceGPGSAIdCounter;

/**
 * ID NMEA Sentence GPRMC
 */
const uchar gpsNmeaSentenceGPRMCId [] = "$GPRMC";

/**
 * ID NMEA Sentence GPRMC Counter
 */
uchar gpsNmeaSentenceGPRMCIdCounter;

/**
 * Quantity Chars Receive
 */
uchar gpsQtyCharsReceive;

/**
 * Struct NMEA GPRMC
 */
gpsStructNmeaGPRMC structNmeaGPRMC;

uchar i, j, k, l;

/**
 * @brief GPS Init
 */
void gpsInit()
{
	// Capture NMEA Sentence OFF
	gpsCaptureNMEASentence = 0;

	// Configure GPS Pins
	ioDigitalOutput(GPS_TX);
	ioDigitalInput(GPS_RX);
	ioDigitalWrite(GPS_ON_OFF,OFF);
	ioDigitalOutput(GPS_ON_OFF);
	ioDigitalInput(GPS_WAKE);

	// UART init Clock 4MHz
	uartInit(4);

	// UART Read Interrupt
	uartReadInterrupt(ON);

	// Start GPS
	ioDigitalWrite(GPS_ON_OFF,ON);
	delayMs(200);
	ioDigitalWrite(GPS_ON_OFF,OFF);

	// Wait for GPS WakeUp
	while(ioDigitalRead(GPS_ON_OFF));
}

/**
 * @brief Receive NMEA Sentence
 * @param GPS Character NMEA Sentence Receive
 */
void gpsReceiveNMEASentence(uchar charReceive)
{
	// Validate First Character NMEA Sentence
	if(charReceive == '$')
	{
		// Capture NMEA Sentence ON
		gpsCaptureNMEASentence = 1;

		// Initialize Counter NMEA Identify
		gpsNmeaSentenceGPGGAIdCounter = 0;
		gpsNmeaSentenceGPGSAIdCounter = 0;
		gpsNmeaSentenceGPRMCIdCounter = 0;
		
		// Increment Pointer
		l = 1;
	}
	else
	{
		// If capture is in progress
		if(gpsCaptureNMEASentence)
		{
			// Validate NMEA Sentence Type
			if(l <= 6)
			{
				// Evaluate NMEA Sentence Type
				if(l == 6)
				{
					if(charReceive == ',')
					{
						j = 1;
						k = 0;

						// Identify GPGGA NMEA Sentence
						if(gpsNmeaSentenceGPGGAIdCounter == 5)
						{
							i = 0;
						}
						// Identify GPGSA NMEA Sentence
						else if(gpsNmeaSentenceGPGSAIdCounter == 5)
						{
							i = 1;
						}
						// Identify GPRMC NMEA Sentence
						else if(gpsNmeaSentenceGPRMCIdCounter == 5)
						{
							i = 2;

							// Indicate Sentence Capture
							gpsNmeaSentenceBuffer[2][0][0] = 'C';
						}
						else
						{
							// Capture NMEA Sentence OFF
							gpsCaptureNMEASentence = 0;
						}
					}
					else
					{
						// Capture NMEA Sentence OFF
						gpsCaptureNMEASentence = 0;
					}
				}
				else
				{
					// Validate GPGGA Sentence
					if(charReceive == gpsNmeaSentenceGPGGAId[l])
					{
						gpsNmeaSentenceGPGGAIdCounter++;
					}
					// Validate GPGSA Sentence
					if(charReceive == gpsNmeaSentenceGPGSAId[l])
					{
						gpsNmeaSentenceGPGSAIdCounter++;
					}
					// Validate GPRMC Sentence
					if(charReceive == gpsNmeaSentenceGPRMCId[l])
					{
						gpsNmeaSentenceGPRMCIdCounter++;
					}
				}	
				
				// Increment Pointer
				l++;
			}
			else
			{
				// Detect Last Character NMEA Sentence
				if(charReceive == 0x0D)
				{
					// Store Receive Character
					gpsNmeaSentenceBuffer[i][j][k] = charReceive;

					// Increment counter
					l++;

					// Identify GPGGA NMEA Sentence
					if(gpsNmeaSentenceGPGGAIdCounter == 5)
					{

					}
					// Identify GPGSA NMEA Sentence
					else if(gpsNmeaSentenceGPGSAIdCounter == 5)
					{

					}
					// Identify GPRMC NMEA Sentence
					else if(gpsNmeaSentenceGPRMCIdCounter == 5)
					{
						// Indicate Sentence Finish
						gpsNmeaSentenceBuffer[2][0][0] = 'F';
						structNmeaGPRMC.isValid = 'N';
						structNmeaGPRMC.wasRead = 'N';
					}
								
					// Capture Sentence OFF
					gpsCaptureNMEASentence = 0;
				}
				else
				{				
					// Increment variable position
					if(charReceive == ',')
					{
						// Last Character Variable
						gpsNmeaSentenceBuffer[i][j][k] = '\n';

						// Reset Pointers
						j++;
						k = 0;
					}
					else
					{
						// Store Char NMEA Sentence
						gpsNmeaSentenceBuffer[i][j][k] = charReceive;

						// Point the next character
						k++;
					}

					// Increment counter
					l++;
				}
			}
		}
	}
}

/**
 * @brief Obtain and Parse NMEA GPRMC Sentence
 * @param utcTime UTC Time Zone
 * 0,1111111111,2,333333333,4,5555555555,6,7777,88888,999999,10
 * C,181611.863,A,0000.0000,N,00000.0000,W,0.00,40.38,030813,,,A*47
 */
gpsStructNmeaGPRMC * gpsParseNmeaGPRMCSentence(uchar utcTimeZone)
{
	volatile uchar tens, units;
	volatile signed char hourTimeZone;
	volatile float longitude, latitude;

	if(gpsCaptureNMEASentence == 0 & structNmeaGPRMC.wasRead == 'N')
	{
		// If Sentence is Valid, parse all values
		if(gpsNmeaSentenceBuffer[2][0][0] == 'F' & gpsNmeaSentenceBuffer[2][2][0] == 'A')
		{
			// Obtain RTC Hour
			tens = gpsNmeaSentenceBuffer[2][1][0] - 0x30;
			units = gpsNmeaSentenceBuffer[2][1][1] - 0x30;
			hourTimeZone = (tens * 10) + units - utcTimeZone;

			// Obtain RTC Minute
			tens = gpsNmeaSentenceBuffer[2][1][2] - 0x30;
			units = gpsNmeaSentenceBuffer[2][1][3] - 0x30;
			structNmeaGPRMC.rtcMinute = (tens * 10) + units;

			// Obtain RTC Second
			tens = gpsNmeaSentenceBuffer[2][1][4] - 0x30;
			units = gpsNmeaSentenceBuffer[2][1][5] - 0x30;
			structNmeaGPRMC.rtcSecond = (tens * 10) + units;

			// Obtain RTC Day
			tens = gpsNmeaSentenceBuffer[2][9][0] - 0x30;
			units = gpsNmeaSentenceBuffer[2][9][1] - 0x30;
			structNmeaGPRMC.rtcDay = (tens * 10) + units;

			// Obtain RTC Month
			tens = gpsNmeaSentenceBuffer[2][9][2] - 0x30;
			units = gpsNmeaSentenceBuffer[2][9][3] - 0x30;
			structNmeaGPRMC.rtcMonth = (tens * 10) + units;

			// Obtain RTC Year
			tens = gpsNmeaSentenceBuffer[2][9][4] - 0x30;
			units = gpsNmeaSentenceBuffer[2][9][5] - 0x30;
			structNmeaGPRMC.rtcYear = (tens * 10) + units;

			// Verify if the hour is negative, and correct situation
			if(hourTimeZone < 0)
			{
				structNmeaGPRMC.rtcHour = 24 + hourTimeZone;
				structNmeaGPRMC.rtcDay--;
			}
			else
			{
				structNmeaGPRMC.rtcHour = hourTimeZone;
			}

			// Obtain Latitude Hour Minute Second
			latitude = gpsObtainFloatValue(2, 3);
			structNmeaGPRMC.latitudeHour = (uchar) (latitude/100);
			structNmeaGPRMC.latitudeMinuteSecond = latitude - (structNmeaGPRMC.latitudeHour * 100);

			// Obtain Longitude Hour Minute Second
			longitude = gpsObtainFloatValue(2, 5);
			structNmeaGPRMC.longitudeHour = (uchar) (longitude/100);
			structNmeaGPRMC.longitudeMinuteSecond = longitude - (structNmeaGPRMC.longitudeHour * 100);

			// Obtain Speed Over Ground
			structNmeaGPRMC.speedOverGround = gpsObtainFloatValue(2, 7);

			// Obtain Course
			structNmeaGPRMC.course = gpsObtainFloatValue(2, 8);

			// Valid Sentence without read
			structNmeaGPRMC.isValid = 'Y';
			structNmeaGPRMC.wasRead = 'N';
		}
		else
		{
			structNmeaGPRMC.isValid = 'N';
			structNmeaGPRMC.wasRead = 'N';
		}
	}
	return &structNmeaGPRMC;
}

/**
 * @brief Obtain Float Value Variable
 * @param nmeaSentence NMEA Sentence
 * @param varPosition Position to convert
 */
float gpsObtainFloatValue(uchar nmeaSentence, uchar varPosition)
{
	uchar i;
	uint integerPart;
	uint decimalPart;
	uint decimalDivisor;
	uchar qtyDecimal;
	float value;

	// Initialize Variables
	i = 0;
	integerPart = 0;
	decimalPart = 0;
	qtyDecimal = 0;

	// Obtain integer part
	while(gpsNmeaSentenceBuffer[nmeaSentence][varPosition][i] != '.')
	{
		integerPart *= 10;
		integerPart += (gpsNmeaSentenceBuffer[nmeaSentence][varPosition][i] - 0x30);
		i++;
	}
	i++;

	// Obtain decimal part
	while(gpsNmeaSentenceBuffer[nmeaSentence][varPosition][i] != '\n')
	{
		decimalPart *= 10;
		decimalPart += (gpsNmeaSentenceBuffer[nmeaSentence][varPosition][i] - 0x30);
		i++;
		qtyDecimal++;
	}

	// Initialize decimal divisor
	decimalDivisor = 1;

	// Calculate decimal divisor
	for(i = 0; i < qtyDecimal; i++)
	{
		decimalDivisor *= 10;
	}

	// Concatenate integer and decimal part
	value = integerPart + ((float) decimalPart/(float) decimalDivisor);

	return value;
}


/**
 * @brief Calculate the distance geodesic between two points according to algorithm Thaddeus Vincenty
 *        Adapted Original Version Javascript (C) Chris Veness 2002 - 2012
 *        http://www.movable-type.co.uk/scripts/latlong-vincenty.html
 * @param latitude1 Latitude First Point
 * @param longitude1 Longitude First Point
 * @param latitude2 Latitude Second Point
 * @param longitude2 Longitude Second Point
 */
float gpsVincentyDistance(uint latitude1, uint longitude1, uint latitude2, uint longitude2)
{
	float a = 6378137, b = 6356752.314245,  f = 1/298.257223563;  		// WGS-84 ellipsoid params
	float l = 0;
	float U1 = 0;
	float U2 = 0;
	//float L = (longitude2-longitude1).toRad();
	//float U1 = atan((1-f) * tan(lat1.toRad()));
	//float U2 = Math.atan((1-f) * Math.tan(lat2.toRad()));
	float cosSigma, sigma, sinAlpha, cosSqAlpha, cos2SigmaM, sinLambda, sinSigma, cosLambda, c, lambdaP;
	float uSq, A, B, deltaSigma, s;

	float sinU1 = sin(U1);
	float cosU1 = cos(U1);
	float sinU2 = sin(U2);
	float cosU2 = cos(U2);
	float lambda = l;
	float iterLimit = 100;

	do
	{
	    sinLambda = sin(lambda);
	    cosLambda = cos(lambda);
	    sinSigma = sqrt( (cosU2*sinLambda) * (cosU2*sinLambda) + (cosU1*sinU2 - sinU1*cosU2*cosLambda) * (cosU1*sinU2 - sinU1*cosU2*cosLambda));

	    if (sinSigma == 0)
	    {
	    	return 0;			// Co-incident points
	    }

	    cosSigma = sinU1*sinU2 + cosU1*cosU2*cosLambda;
	    sigma = atan2(sinSigma, cosSigma);
	    sinAlpha = cosU1 * cosU2 * sinLambda / sinSigma;
	    cosSqAlpha = 1 - sinAlpha*sinAlpha;
	    cos2SigmaM = cosSigma - 2*sinU1*sinU2/cosSqAlpha;

	    if (isnan(cos2SigmaM) == 0)
	    {
	    	cos2SigmaM = 0;		// Equatorial line: cosSqAlpha=0 (§6)
	    }
	    c = f/16*cosSqAlpha*(4 + f*(4 - 3*cosSqAlpha));
	    lambdaP = lambda;
	    lambda = l + (1-c) * f * sinAlpha * (sigma + c*sinSigma*(cos2SigmaM + c * cosSigma * (-1 + 2 * cos2SigmaM * cos2SigmaM)));
	}
	while (abs(lambda-lambdaP) > 1e-12 && --iterLimit>0);

	if (iterLimit == 0)
	{
		// return NAN;  			// Formula failed to converge
	}

	uSq = cosSqAlpha * (a*a - b*b) / (b*b);
	A = 1 + uSq/16384*(4096 + uSq*(-768 + uSq*(320 - 175*uSq)));
	B = uSq/1024 * (256 + uSq*(-128 + uSq*(74 - 47*uSq)));
	deltaSigma = B*sinSigma*(cos2SigmaM + B/4*(cosSigma*(-1 + 2*cos2SigmaM*cos2SigmaM) -B/6*cos2SigmaM*(-3 + 4*sinSigma*sinSigma)*(-3 + 4*cos2SigmaM*cos2SigmaM)));
	s = b*A*(sigma - deltaSigma);

	//s = s.toFixed(3); 		// round to 1mm precision
	return s;
}
