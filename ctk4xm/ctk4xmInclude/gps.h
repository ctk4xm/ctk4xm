/**
 *  @file gps.h
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

#ifndef GPS_H_
#define GPS_H_

#include "config.h"
#include "math.h"


/**
 * Struct GPRMC NMEA Sentence
 * $GPRMC,181611.863,A,0000.0000,N,00000.0000,W,0.00,40.38,030813,,,A*47
 */
typedef struct
{
	uchar rtcHour;
	uchar rtcMinute;
	uchar rtcSecond;
	uchar state;
	uchar latitudeHour;
	float latitudeMinuteSecond;
	uchar latitudeNS;
	uchar longitudeHour;
	float longitudeMinuteSecond;
	uchar longitudeEW;
	float speedOverGround;
	float course;
	uchar rtcDay;
	uchar rtcMonth;
	uchar rtcYear;
} gpsStructNmeaGPRMC;


/**
 * @brief GPS Init
 */
void gpsInit();

/**
 * @brief Receive NMEA Sentence
 * @param GPS Character NMEA Sentence Receive
 */
void gpsReceiveNMEASentence(uchar charReceive);

/**
 * @brief Obtain Struct NMEA GPRMC
 */
gpsStructNmeaGPRMC gpsGetNmeaGPRMCSentence();

/**
 * @brief Calculate the distance geodesic between two points according to algorithm Thaddeus Vincenty
 * @param latitude1 Latitude First Point
 * @param latitude1 Longitude First Point
 * @param latitude1 Latitude Second Point
 * @param latitude1 Longitude Second Point
 */
float gpsVincentyDistance(uint latitude1, uint longitude1, uint latitude2, uint longitude2);

#endif
