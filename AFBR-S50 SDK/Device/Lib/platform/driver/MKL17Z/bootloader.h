/*************************************************************************//**
 * @file
 * @brief    	This file is part of the AFBR-S50 API.
 * @details		This file provides functionality to globally turn IRQs on/off.
 * 
 * @copyright	Copyright c 2016-2019, Avago Technologies GmbH.
 * 				All rights reserved.
 *
 *****************************************************************************/

#ifndef BOOTLOADER_H
#define BOOTLOADER_H

/*!***************************************************************************
 * @defgroup	Bootloader Bootloader: ROM Bootloader Startup
 * @ingroup		driver
 * @brief		ROM Bootloader Module
 * @details		This module provides functionality to run the ROM bootloader.
 * @addtogroup 	Bootloader
 * @{
 *****************************************************************************/

#include "utility/status.h"

/*!***************************************************************************
 * @brief	Enters the ROM bootloader if available.
 * @details	Returns ERROR_FAIL if the bootloader is not available
 * @return	Returns the \link #status_t status\endlink (#STATUS_OK on success).
 *****************************************************************************/
status_t EnterBootloader(void);

/*! @} */
#endif /* BOOTLOADER_H */
