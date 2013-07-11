/**
 *  @file display7Seg.h
 *  @brief Module that allows controls 7-Seg Displays
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

#ifndef DISPLAY7SEG_H_
#define DISPLAY7SEG_H_

#include "core.h"
#include "io.h"

/*
 * Display 7-Seg Module
 */
#define DISPLAY7SEG_A 		&P1OUT,BIT0
#define DISPLAY7SEG_B 		&P1OUT,BIT1
#define DISPLAY7SEG_C 		&P1OUT,BIT2
#define DISPLAY7SEG_D 		&P1OUT,BIT3
#define DISPLAY7SEG_E 		&P1OUT,BIT4
#define DISPLAY7SEG_F 		&P1OUT,BIT5
#define DISPLAY7SEG_G 		&P1OUT,BIT6

#define DISPLAY7SEG_SRCLK 	&P2OUT,BIT0
#define DISPLAY7SEG_SRDAT 	&P2OUT,BIT1

/**
 * Max Displays Constant
 */
#define MAX_DISPLAYS 				4

/**
 * Max Buffer Chars
 */
#define MAX_BUFFER_DISPLAY_CHARS	24

/**
 * Max Buffer Offset
 */
#define MAX_BUFFER_DISPLAY_OFFSET	MAX_BUFFER_DISPLAY_CHARS - MAX_DISPLAYS

/**
 * @brief Init Display 7-Seg
 */
void display7SegInit();

/**
 * @brief Display 7-Seg Buffer Clear
 */
void display7SegBufferClear();

/**
 * @brief Display 7-Seg Write Buffer
 * @param bufferPosition Buffer Position
 * @param data Data to Write
 */
void display7SegWriteBuffer(uchar bufferPosition, uchar data);

/**
 * @brief Display 7-Seg Update
 */
void display7SegUpdate();

/**
 * @brief Select Display 7-Seg
 * @param display Select Display
 */
void display7SegSelectDisplay(uchar display);

/**
 * @brief Set Segments
 * @param dataSegments Data by Row
 */
void display7SegSetSegments(uchar dataSegments);

/**
 * @brief Led Matrix Scroll On
 * @param setTimeScroll Set Time Scroll
 */
void display7SegScrollOn(uchar setTimeScroll);

/**
 * @brief Led Matrix Scroll Off
 */
void display7SegScrollOff();

/**
 * @brief Write Message into Display 7-Seg Buffer
 * @param display Display to Start Write
 * @param message Array Message to Send to Led Matrix
 */
void display7SegWriteMessage(uchar display, const uchar message []);

#endif
