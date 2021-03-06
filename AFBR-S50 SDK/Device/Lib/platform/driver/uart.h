/*************************************************************************//**
 * @file
 * @brief    	This file is part of the AFBR-S50 API.
 * @details		This file provides UART driver functionality.
 * 
 * @copyright	Copyright c 2016-2019, Avago Technologies GmbH.
 * 				All rights reserved.
 *
 *****************************************************************************/

#ifndef UART_H
#define UART_H

/*!***************************************************************************
 * @defgroup	UART UART:Universal Asynchronous Receiver/Transmitter
 * @ingroup		driver
 * @brief		UART Hardware Layer Module
 * @details		Provides a layer for the UART driver functions.
 * 				It uses UART interface with DMA
 *
 * 				Example:
 * @code
 *  				UART_Printf("askldfjlsadf");
 * @endcode
 * @code
 * 					UART_SendBuffer(txBuff, sizeof(txBuff), 0, 0);
 * 					while (UART_IsTxBusy());
 * @endcode
 * @addtogroup 	UART
 * @{
 *****************************************************************************/

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "utility/platform_status.h"

/*! @brief Return status for the UART driver.
 *  @ingroup status */
enum StatusUART
{
	/*! Baud rate not supported by system. */
    ERROR_UART_BAUDRATE_NOT_SUPPORTED = -71,

	/*! Receiver buffer hasen't been read before receiving new data.
	 *  Data loss! */
    ERROR_UART_RX_OVERRUN = -72,

	/*! Noise detected in the received character. */
	ERROR_UART_RX_NOISE = -73,

	/*! Framing error occurs when the receiver detects a logic 0 where a stop
	 *  bit was expected. This suggests the receiver was not properly aligned
	 *  to a character frame. */
	ERROR_UART_FRAMING_ERR = -74,

	/*! Transmitting error stemming from the DMA module. */
	ERROR_UART_TX_DMA_ERR = -75,
};


/*!***************************************************************************
 * @brief	UART received byte callback function type.
 * @param	rxByte The received byte.
 * @return 	-
 *****************************************************************************/
typedef void (* uart_rx_callback_t)(uint8_t rxByte);

/*!***************************************************************************
 * @brief	UART transmit done callback function type.
 * @param	status The \link #status_t status\endlink of the transmitter;
 *       			 (#STATUS_OK on success).
 * @param	state A pointer to the state that was passed to the Tx function.
 * @return 	-
 *****************************************************************************/
typedef void (* uart_tx_callback_t)(status_t status, void * state);

/*!***************************************************************************
 * @brief	UART layer error callback function type.
 * @param	status The error \link #status_t status\endlink that yielded to
 * 					 the callback.
 * @return 	-
 *****************************************************************************/
typedef void (* uart_error_callback_t)(status_t status);

/*!***************************************************************************
 * @brief	Initialize the Universal Asynchronous Receiver/Transmitter
 * 			(UART2 or LPSCI) bus and DMA module
 * @param 	-
 * @return 	Returns the \link #status_t status\endlink (#STATUS_OK on success).
 *****************************************************************************/
status_t UART2_Init(void);

/*!***************************************************************************
 * @brief	Initialize the Universal Asynchronous Receiver/Transmitter
 * 			(UART or LPSCI) bus and DMA module
 * @param 	-
 * @return 	Returns the \link #status_t status\endlink (#STATUS_OK on success).
 *****************************************************************************/
status_t UART_Init(void);

/*!***************************************************************************
 * @brief	Writes several bytes to the UART connection.
 * @param	txBuff Data array to write to the uart2 connection
 * @param	txSize The size of the data array
 * @param	f Callback function after tx is done, set 0 if not needed;
 * @param	state Optional user state that will be passed to callback
 * 					function; set 0 if not needed.
 * @return 	Returns the \link #status_t status\endlink:
 * 			 - #STATUS_OK (0) on success.
 * 			 - #STATUS_BUSY on Tx line busy
 * 			 - #ERROR_NOT_INITIALIZED
 * 			 - #ERROR_INVALID_ARGUMENT
 *****************************************************************************/
status_t UART2_SendBuffer(uint8_t const * txBuff, size_t txSize, uart_tx_callback_t f, void * state);

/*!***************************************************************************
 * @brief	Writes several bytes to the UART connection.
 * @param	txBuff Data array to write to the uart connection
 * @param	txSize The size of the data array
 * @param	f Callback function after tx is done, set 0 if not needed;
 * @param	state Optional user state that will be passed to callback
 * 					function; set 0 if not needed.
 * @return 	Returns the \link #status_t status\endlink:
 * 			 - #STATUS_OK (0) on success.
 * 			 - #STATUS_BUSY on Tx line busy
 * 			 - #ERROR_NOT_INITIALIZED
 * 			 - #ERROR_INVALID_ARGUMENT
 *****************************************************************************/
status_t UART_SendBuffer(uint8_t const * txBuff, size_t txSize, uart_tx_callback_t f, void * state);

/*!***************************************************************************
 * @brief	Reads the transmittion status of the uart2 interface
 * @param 	-
 * @return	Booleon value:
 * 			 - true: device is busy
 * 			 - false: device is idle
 *****************************************************************************/
bool UART2_IsTxBusy(void);

/*!***************************************************************************
 * @brief	Reads the transmittion status of the uart interface
 * @param 	-
 * @return	Booleon value:
 * 			 - true: device is busy
 * 			 - false: device is idle
 *****************************************************************************/
bool UART_IsTxBusy(void);

/*!***************************************************************************
 * @brief	Installs an callback function for the byte received event.
 * @param	f The callback function pointer.
 *****************************************************************************/
void UART2_SetRxCallback(uart_rx_callback_t f);

/*!***************************************************************************
 * @brief	Installs an callback function for the byte received event.
 * @param	f The callback function pointer.
 *****************************************************************************/
void UART_SetRxCallback(uart_rx_callback_t f);

/*!***************************************************************************
 * @brief	Removes the callback function for the byte received event.
 *****************************************************************************/
void UART_RemoveRxCallback(void);

/*!***************************************************************************
 * @brief	Installs an callback function for the error occurred event.
 * @param	f The callback function pointer.
 *****************************************************************************/
void UART_SetErrorCallback(uart_error_callback_t f);

/*!***************************************************************************
 * @brief	Removes the callback function for the error occurred event.
 *****************************************************************************/
void UART_RemoveErrorCallback(void);

/*! @} */
#endif /* UART_H */
