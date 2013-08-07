/**
 *  @file gps.c
 *  @brief Module that allows work GPS
 *  @date 05/08/2013
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
 * Maximum NMEA Sentences
 */
#define 	MAX_NMEA_SENTENCES		8

/**
 * NMEA Sentence Counter
 */
uchar nmeaSentenceCounter;

/**
 * NMEA Sentence Buffer
 */
uchar nmeaSentenceBuffer [MAX_NMEA_SENTENCES][80];

/**
 * NMEA Sentence Pointer
 */
uchar *ptrNmeaSentenceBuffer;

/**
 * GPS Capture Sentence Switch
 */
uchar gpsCaptureSentence;

/**
 * GPS Capture
 */
uchar gpsCapture;

/**
 * @brief GPS Init
 */
void gpsInit()
{
	// Intialize the counter sentence
	nmeaSentenceCounter = 0;

	// Capture Sentence OFF
	gpsCaptureSentence = 0;

	// GPS Capture
	gpsCapture = 1;
	
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
 * @brief Collect NMEA Sentence
 * @param GPS Char NMEA Sentence Receive
 */
void gpsCollectNMEASentence(uchar charReceive)
{
	// Capture Chars NMEA Sentences
	if(gpsCapture)
	{
		// Validate First Character NMEA Sentence
		if(charReceive == '$')
		{
			// Point NMEA Sentence Buffer
			ptrNmeaSentenceBuffer = &nmeaSentenceBuffer[nmeaSentenceCounter][0];

			// Store NMEA Character Receive
			*ptrNmeaSentenceBuffer = charReceive;

			// Increment at the next character in the Buffer
			ptrNmeaSentenceBuffer++;

			// Capture Sentence ON
			gpsCaptureSentence = 1;
		}
		else
		{
			// If capture is in progress
			if(gpsCaptureSentence)
			{
				// Detect Last Character NMEA Sentence
				if(charReceive == 0x0D)
				{
					// Store NMEA Character Receive
					*ptrNmeaSentenceBuffer = charReceive;
					
					// Point the next sentence
					nmeaSentenceCounter++;

					// Initialize sentence counter
					if(nmeaSentenceCounter > MAX_NMEA_SENTENCES)
					{
						nmeaSentenceCounter = 0;
						gpsCapture = 0;
					}

					// Capture Sentence OFF
					gpsCaptureSentence = 0;
				}
				else
				{
					// Store NMEA Character Receive
					*ptrNmeaSentenceBuffer = charReceive;

					// Increment at the next character in the Buffer
					ptrNmeaSentenceBuffer++;
				}
			}
		}		
	}
}

/**
 * @brief Obtain a pointer to NMEA Selected
 */
uchar * gpsGetNmeaSentence(const uchar nmeaSentence [])
{
	uchar i, j, nmeaSentenceRequested;
	
	// Validate for Finish Capture
	if(gpsCapture == 0)
	{
		// Find the NMEA Sentence
		for(i = 0; i < MAX_NMEA_SENTENCES; i++)
		{
			// Start Requested State
			nmeaSentenceRequested = 1;

			// Point NMEA Sentence Buffer
			ptrNmeaSentenceBuffer = &nmeaSentenceBuffer[i][0];
			
			// Compare if the Actual NMEA Sentence is required
			for(j = 0; j < 6; j++)
			{
				if(nmeaSentence[j] != *ptrNmeaSentenceBuffer)
				{
					nmeaSentenceRequested = 0;
					break;
				}

				// Increment at the next character in the Buffer
				ptrNmeaSentenceBuffer++;
			}
			
			// If NMEA is requested
			if(nmeaSentenceRequested)
			{
				// Point NMEA Sentence Buffer
				ptrNmeaSentenceBuffer = &nmeaSentenceBuffer[i][0];
				gpsCapture = 1;
				break;
			}
		}		
	}
	return ptrNmeaSentenceBuffer;
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
