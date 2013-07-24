/**
 *  @file lcd.h
 *  @brief Module that controls Standard LCD Module
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

#ifndef LCD_H_
#define LCD_H_

#include "config.h"
#include "delay.h"
#include "io.h"

/**
 * LCD Clear Constant
 */
#define LCD_CLEAR 		0x01
/**
 * LCD Blink On Constant
 */
#define LCD_BLINK_ON 	0x0D
/**
 * LCD Blink Off Constant
 */
#define LCD_BLINK_OFF 	0x0C
/**
 * LCD Cursor On Constant
 */
#define LCD_CURSOR_ON 	0x0E
/**
 * LCD Cursor Off Constant
 */
#define LCD_CURSOR_OFF 	0x0C
/**
 * LCD Display On Constant
 */
#define LCD_DISPLAY_ON 	0x0C
/**
 * LCD Display Off Constant
 */
#define LCD_DISPLAY_OFF 0x08
/**
 * LCD Display Off Constant
 */
#define LCD_SHIFT_OFF 	0x10
/**
 * LCD Shift Left Constant
 */
#define LCD_SHIFT_LEFT	0x18
/**
 * LCD Shift Right Constant
 */
#define LCD_SHIFT_RIGHT	0x1C
/**
 * LCD Home Constant
 */
#define LCD_HOME  		0x80

/**
 * @brief Init LCD Module
 */
void lcdInit();

/**
 * @brief Send Byte to Two Nibbles
 * @param data Byte to send to LCD Module
 */
void lcdData(uchar data);

/**
 * @brief Send Instruction LCD Module
 * @param instru Instruction to send to LCD Module
 */
void lcdInstru(uchar instru);

/**
 * @brief Clear LCD Module
 */
void lcdClear();

/**
 * @brief Set Home Cursor Position LCD Module
 */
void lcdHome();

/**
 * @brief Set Cursor Position LCD Module
 * @param row LCD Row
 * @param column LCD Column
 */
void lcdSetCursor(uchar row, uchar column);

/**
 * @brief Write Character LCD Module
 * @param exportData Data to Send to LCD Module
 */
void lcdWrite(uchar character);

/**
 * @brief Write Character LCD Module
 * @param row LCD Row
 * @param column LCD Column
 * @param exportData Data to Send to LCD Module
 */
void lcdWriteSetPosition(uchar row, uchar column, uchar exportData);

/**
 * @brief Write Character LCD Module
 * @param row LCD Row
 * @param column LCD Column
 * @param message Array Message to Send to LCD Module
 */
void lcdWriteMessage(uchar row, uchar column, const uchar message []);

/**
 * @brief Set Cursor Blink On LCD Module
 */
void lcdCursorBlinkOn();

/**
 * @brief Set Cursor Blink Off LCD Module
 */
void lcdCursorBlinkOff();

/**
 * @brief Set Cursor Display On LCD Module
 */
void lcdCursorDisplayOn();

/**
 * @brief Set Cursor Display Off LCD Module
 */
void lcdCursorDisplayOff();

/**
 * @brief Set Display On LCD Module
 */
void lcdDisplayOn();

/**
 * @brief Set Display Off LCD Module
 */
void lcdDisplayOff();

/**
 * @brief Set Shift Off LCD Module
 */
void lcdShiftOff();

/**
 * @brief Set Shift Left LCD Module
 */
void lcdShiftLeft();

/**
 * @brief Set Shift Right LCD Module
 */
void lcdShiftRight();

/**
 * @brief Send Data Binary Format LCD Module
 * @param row LCD Row
 * @param column LCD Column
 * @param exportData Data to Send to LCD Module
 */
void lcdDataBinFormat(uchar row, uchar column, uchar dataExport);

/**
 * @brief Send Data Hexadecimal Format LCD Module
 * @param row LCD Row
 * @param column LCD Column
 * @param exportData Data to Send to LCD Module
 */
void lcdDataHexFormat(uchar row, uchar column, uchar dataExport);

/**
 * @brief Send Data Decimal Format LCD Module
 * @param row LCD Row
 * @param column LCD Column
 * @param exportData Data to Send to LCD Module
 * @param quantityDigits Quantity Digits
 */
void lcdDataDecFormatSetPosition(uchar row, uchar column, uint dataExport, uchar quantityDigits);

/**
 * @brief Send Data Decimal Format LCD Module
 * @param dataExport Data to Send to LCD Module
 * @param quantityDigits Quantity Digits
 */
void lcdDataDecFormat(uint dataExport, uchar quantityDigits);

/**
 * @brief Send Data Double Format LCD Module
 * @param row LCD Row
 * @param column LCD Column
 * @param dataExport Data to Send to LCD Module
 * @param quantityDigits Quantity Digits
 * @param quantityDecimals Quantity Decimals
 */
void lcdDataDoubleFormatSetPosition(uchar row, uchar column, double dataExport, uchar quantityDigits, uchar quantityDecimals);

/**
 * @brief Send Data Double Format LCD Module
 * @param dataExport Data to Send to LCD Module
 * @param quantityDigits Quantity Digits
 * @param quantityDecimals Quantity Decimals
 */
void lcdDataDoubleFormat(double dataExport, uchar quantityDigits, uchar quantityDecimals);

/**
 * @brief Send Data Date Format LCD Module
 * @param row LCD Row
 * @param column LCD Column
 * @param day Day
 * @param month Month
 * @param year Year
 */
void lcdDataDateFormat(uchar row, uchar column, uint day, uint month, uint year);

/**
 * @brief Send Data Time Format LCD Module
 * @param row LCD Row
 * @param column LCD Column
 * @param hour Hour
 * @param minute Minute
 * @param second Second
 */
void lcdDataTimeFormat(uchar row, uchar column, uint hour, uint minute, uint second);

#endif
