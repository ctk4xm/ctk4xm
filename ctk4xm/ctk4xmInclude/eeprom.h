/**
 *  @file eeprom.h
 *  @brief Module that allows simulate EEPROM in FLASH Memory
 *  @date 21/08/2013
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

#ifndef EEPROM_H_
#define EEPROM_H_

#include "config.h"

/**
 * @brief Init EEPROM Module
 */
void eepromInit(uchar busFrequency);

/**
 * @brief Read Byte EEPROM
 * @param address Address EEPROM to read
 */
uchar eepromReadByte(uchar *addressPtr);

/**
 * @brief Write Byte EEPROM
 * @param *addressPtr Pointer to Address EEPROM to write
 * @param writeByte Byte to Write in EEPROM
 */
uchar eepromWriteByte(uchar *addressPtr, uchar writeByte);

/**
 * @brief Erase Page EEPROM
 * @param address Address EEPROM to erase
 */
uchar eepromErasePage(uchar *addressPtr);

#endif
