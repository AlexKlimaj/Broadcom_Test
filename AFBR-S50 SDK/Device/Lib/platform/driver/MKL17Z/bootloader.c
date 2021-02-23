/*************************************************************************//**
 * @file
 * @brief    	This file is part of the AFBR-S50 API.
 * @details		This file provides functionality to globally turn IRQs on/off.
 * 
 * @copyright	Copyright c 2016-2019, Avago Technologies GmbH.
 * 				All rights reserved.
 *
 *****************************************************************************/


/*******************************************************************************
 * Include Files
 ******************************************************************************/
#include "bootloader.h"
#include <stdint.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*! The prototype of the ROM bootloader entry point. */
void (*runBootloader)(void * arg);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
status_t EnterBootloader(void)
{

#if defined(CPU_MKL17Z256VFM4)

	// Variables
	uint32_t runBootloaderAddress;

	// Read the function address from the ROM API tree.
	runBootloaderAddress = **(uint32_t **)(0x1c00001c);
	runBootloader = (void (*)(void * arg))runBootloaderAddress;

	// Start the bootloader.
	runBootloader(0);
#endif
	return ERROR_FAIL;

}
