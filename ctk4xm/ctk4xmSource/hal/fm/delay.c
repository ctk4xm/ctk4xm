/**
 *  @file delay.c
 *  @brief Module that allows delays
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

#include "delay.h"
#include "hal/delay.h"

#ifdef FREESCALE

/**
 * @brief Delay in Miliseconds
 * @param delayMs Milisecond Value
 */
void _hal_delayMs(uint delayMs)
{
	 uint i, j;

	 for(i = 0; i < delayMs; i++)
		 for(j = 0; j < 724; j++);
}

#endif
