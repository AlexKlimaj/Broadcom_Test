/*************************************************************************//**
 * @file
 * @brief    	This file is part of the AFBR-S50 API.
 * @details		This file provides drivers for SLCD display
 * 
 * @copyright	Copyright c 2016-2019, Avago Technologies GmbH.
 * 				All rights reserved.
 *
 *****************************************************************************/

#ifndef SLCD_H
#define SLCD_H

/*!***************************************************************************
 * @defgroup	SLCD SLCD: Segment LCD
 * @ingroup		driver
 * @brief		SLCD Hardware Layer Module
 * @details		Driver functionality for SLCD Module.
 * @addtogroup 	SLCD
 * @{
 *****************************************************************************/

#include <stdint.h>

/*!***************************************************************************
 * @brief	Initializes the SLCD driver and setup pin muxing.
 *****************************************************************************/
void SLCD_Init(void);

/*!***************************************************************************
 * @brief	Displays a unsigned integer in decimal mode.
 * @param	value The integer to display.
 *****************************************************************************/
void SLCD_DisplayDecimalUnsigned(uint16_t value);

/*!***************************************************************************
 * @brief	Displays a signed integer in decimal mode.
 * @param	value The integer to display.
 *****************************************************************************/
void SLCD_DisplayDecimalSigned(int16_t value);

/*!***************************************************************************
 * @brief	Displays the decimal point at a given position on the SLCD.
 * @param	pos The position of the decimal point:
 * 					- 0 = off;
 * 					- 1, 2, 3 = display at position 1, 2, 3;
 * 					- 4 = display colon at pos 2.
 *****************************************************************************/
void SLCD_SetDecimalPointPosition(uint8_t pos);

/*!***************************************************************************
 * @brief	Displays "----" on the SLCD.
 *****************************************************************************/
void SLCD_DisplayBar(void);

/*!***************************************************************************
 * @brief	Clear the SLCD Display.
 *****************************************************************************/
void SLCD_ClearDisplay(void);

/*!***************************************************************************
 * @brief	Displays an error number on the SLCD.
 * @param	error An 8bit unsigned integer that represents the error number.
 *****************************************************************************/
void SLCD_DisplayError(uint8_t error);



/*! @} */
#endif /* SLCD_H */
