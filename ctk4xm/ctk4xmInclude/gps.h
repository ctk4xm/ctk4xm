/**
 *  @file gps.h
 *  @brief Module that allows work GPS
 *  @date 13/07/2013
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

#ifndef DELAY_H_
#define DELAY_H_

#include "config.h"

/**
 * @brief Calculate the distance geodesic between two points according to algorithm Thaddeus Vincenty
 * @param latitude1 Latitude First Point
 * @param latitude1 Longitude First Point
 * @param latitude1 Latitude Second Point
 * @param latitude1 Longitude Second Point
 */
uint gpsVincentyDistance(uint latitude1, uint longitude1, uint latitude2, uint longitude2);

#endif
