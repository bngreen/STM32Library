/**
  ******************************************************************************
  * @file           : usbd_cdc_if.c
  * @author         : MCD Application Team
  * @version        : V1.1.0
  * @date           : 19-March-2012
  * @brief          :
  ******************************************************************************
  * COPYRIGHT(c) 2015 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  * 1. Redistributions of source code must retain the above copyright notice,
  * this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  * this list of conditions and the following disclaimer in the documentation
  * and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of its contributors
  * may be used to endorse or promote products derived from this software
  * without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "usbd_cdc_if.h"

/** @addtogroup STM32_USB_OTG_DEVICE_LIBRARY
  * @{
  */

/** @defgroup USBD_CDC 
  * @brief usbd core module
  * @{
  */ 

/** @defgroup USBD_CDC_Private_TypesDefinitions
  * @{
  */ 
  /* USER CODE BEGIN 0 */ 
  /* USER CODE END 0 */ 
/**
  * @}
  */ 

/** @defgroup USBD_CDC_Private_Defines
  * @{
  */ 
  /* USER CODE BEGIN 1 */
/* Define size for the receive and transmit buffer over CDC */
/* It's up to user to redefine and/or remove those define */
#define APP_RX_DATA_SIZE  64
#define APP_TX_DATA_SIZE  64
  /* USER CODE END 1 */  
/**
  * @}
  */ 

/** @defgroup USBD_CDC_Private_Macros
  * @{
  */ 
  /* USER CODE BEGIN 2 */ 
  /* USER CODE END 2 */
/**
  * @}
  */ 
  
/** @defgroup USBD_CDC_Private_Variables
  * @{
  */

/* Create buffer for reception and transmission           */
/* It's up to user to redefine and/or remove those define */
/* Received Data over USB are stored in this buffer       */
uint8_t UserRxBufferHS[APP_RX_DATA_SIZE];

/* Send Data over USB CDC are stored in this buffer       */
uint8_t UserTxBufferHS[APP_TX_DATA_SIZE];

/* USB handler declaration */

/* Handle for USB High Speed IP */
USBD_HandleTypeDef  *hUsbDevice_1;
  
extern USBD_HandleTypeDef hUsbDeviceHS;  

/**
  * @}
  */ 
  
/** @defgroup USBD_CDC_Private_FunctionPrototypes
  * @{
  */

static int8_t CDC_Init_HS     (void);
static int8_t CDC_DeInit_HS   (void);
static int8_t CDC_Control_HS  (uint8_t cmd, uint8_t* pbuf, uint16_t length);
static int8_t CDC_Receive_HS  (uint8_t* pbuf, uint32_t *Len);

USBD_CDC_ItfTypeDef USBD_Interface_fops_HS = 
{
  CDC_Init_HS,
  CDC_DeInit_HS,
  CDC_Control_HS,  
  CDC_Receive_HS
};

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  CDC_Init_HS
  *         Initializes the CDC media low layer over the USB HS IP
  * @param  None
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CDC_Init_HS(void)
{
  hUsbDevice_1 = &hUsbDeviceHS;
  /* USER CODE BEGIN 8 */ 
  /* Set Application Buffers */
  USBD_CDC_SetTxBuffer(hUsbDevice_1, UserTxBufferHS, 0);
  USBD_CDC_SetRxBuffer(hUsbDevice_1, UserRxBufferHS);
  return (USBD_OK);
  /* USER CODE END 8 */ 
}

/**
  * @brief  CDC_DeInit_HS
  *         DeInitializes the CDC media low layer
  * @param  None
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CDC_DeInit_HS(void)
{
  /* USER CODE BEGIN 9 */ 
  return (USBD_OK);
  /* USER CODE END 9 */ 
}

/**
  * @brief  CDC_Control_HS
  *         Manage the CDC class requests
  * @param  cmd: Command code            
  * @param  pbuf: Buffer containing command data (request parameters)
  * @param  length: Number of data to be sent (in bytes)
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CDC_Control_HS  (uint8_t cmd, uint8_t* pbuf, uint16_t length)
{ 
  /* USER CODE BEGIN 10 */
  switch (cmd)
  {
  case CDC_SEND_ENCAPSULATED_COMMAND:
 
    break;

  case CDC_GET_ENCAPSULATED_RESPONSE:
 
    break;

  case CDC_SET_COMM_FEATURE:
 
    break;

  case CDC_GET_COMM_FEATURE:

    break;

  case CDC_CLEAR_COMM_FEATURE:

    break;

  /*******************************************************************************/
  /* Line Coding Structure                                                       */
  /*-----------------------------------------------------------------------------*/
  /* Offset | Field       | Size | Value  | Description                          */
  /* 0      | dwDTERate   |   4  | Number |Data terminal rate, in bits per second*/
  /* 4      | bCharFormat |   1  | Number | Stop bits                            */
  /*                                        0 - 1 Stop bit                       */
  /*                                        1 - 1.5 Stop bits                    */
  /*                                        2 - 2 Stop bits                      */
  /* 5      | bParityType |  1   | Number | Parity                               */
  /*                                        0 - None                             */
  /*                                        1 - Odd                              */ 
  /*                                        2 - Even                             */
  /*                                        3 - Mark                             */
  /*                                        4 - Space                            */
  /* 6      | bDataBits  |   1   | Number Data bits (5, 6, 7, 8 or 16).          */
  /*******************************************************************************/
  case CDC_SET_LINE_CODING:   
	
    break;

  case CDC_GET_LINE_CODING:     

    break;

  case CDC_SET_CONTROL_LINE_STATE:

    break;

  case CDC_SEND_BREAK:
 
    break;    
    
  default:
    break;
  }

  return (USBD_OK);
  /* USER CODE END 10 */
}


#include <stdbool.h>
#include "vcp.h"

typedef struct{
	uint8_t* buffer;
	uint32_t writePos;
	uint32_t readPos;
	size_t len;
} CircularBuffer_t;

uint32_t circularBufferAvailable(CircularBuffer_t* buffer){
	if(buffer->readPos > buffer->writePos)
		return (buffer->len - buffer->readPos) + buffer->writePos;
	else
		return buffer->writePos - buffer->readPos;
}

bool circularBufferWrite(CircularBuffer_t* buffer, uint8_t* data, size_t len){
	int i;
	if(buffer->len -1 - circularBufferAvailable(buffer) < len)
		return false;
	for(i=0;i<len;i++){
		buffer->buffer[(buffer->writePos+i)%buffer->len] = data[i];
	}
	buffer->writePos = (buffer->writePos+len) % buffer->len;
	return true;
}

bool circularBufferRead(CircularBuffer_t* buffer, uint8_t* data, size_t len){
	int i;
	if(circularBufferAvailable(buffer) < len)
		return false;
	for(i=0;i<len;i++)
		data[i] = buffer->buffer[(buffer->readPos+i)%buffer->len];
	buffer->readPos = (buffer->readPos+len) % buffer->len;
	return true;
}


uint8_t receiveBufferStorage[VCPRECEIVEBUFFSIZE];
CircularBuffer_t receiveCircularBuffer = { .buffer = receiveBufferStorage, .readPos = 0, .writePos = 0, .len = VCPRECEIVEBUFFSIZE};


/**
  * @brief  CDC_Receive_HS
  *         Data received over USB OUT endpoint are sent over CDC interface 
  *         through this function.
  *           
  *         @note
  *         This function will block any OUT packet reception on USB endpoint 
  *         untill exiting this function. If you exit this function before transfer
  *         is complete on CDC interface (ie. using DMA controller) it will result 
  *         in receiving more data while previous ones are still not sent.
  *                 
  * @param  Buf: Buffer of data to be received
  * @param  Len: Number of data received (in bytes)
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CDC_Receive_HS (uint8_t* Buf, uint32_t *Len)
{
  /* USER CODE BEGIN 11 */ 

	circularBufferWrite(&receiveCircularBuffer, Buf, *Len);
	USBD_CDC_ReceivePacket(hUsbDevice_1);

  return (USBD_OK);
  /* USER CODE END 11 */ 
}
/**
  * @brief  CDC_Transmit_HS
  *         Data send over USB IN endpoint are sent over CDC interface 
  *         through this function.           
  *         @note
  *         
  *                 
  * @param  Buf: Buffer of data to be send
  * @param  Len: Number of data to be send (in bytes)
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL or USBD_BUSY
  */
uint8_t CDC_Transmit_HS(uint8_t* Buf, uint16_t Len)
{
  uint8_t result = USBD_OK;
  /* USER CODE BEGIN 12 */ 
  USBD_CDC_SetTxBuffer(hUsbDevice_1, Buf, Len);   
  result = USBD_CDC_TransmitPacket(hUsbDevice_1);
  /* USER CODE END 12 */ 
  return result;
}


void VCPWrite(uint8_t* Buf, uint32_t Len){
	int tw;
	while(Len > 0){
		tw = MIN(Len, 64);
		if(CDC_Transmit_HS(Buf, tw) == USBD_OK){
			Buf += tw;
			Len -= tw;
		}
	}
}

bool VCPRead(uint8_t* buf, uint32_t len){
	if(len == 0)
		return true;
	return circularBufferRead(&receiveCircularBuffer, buf, len);
}



uint32_t VCPAvailable(){
	return circularBufferAvailable(&receiveCircularBuffer);
}

float readFloat(){
	bool isNegative = false;
	bool isFraction = false;
	bool foundDigit = false;
	int64_t value = 0;
	uint8_t c;
	float fraction = 1.0;
	float v;
	int i, timeout = 10000;
	for(i=0;i<timeout;i++){
		if(VCPRead(&c, 1)){
			if(c >= '0' && c <= '9'){
				value = value * 10 + (c - '0');
				if(isFraction)
					fraction *= 0.1;
				foundDigit = true;
			}
			else if(c == '-'){
				if(foundDigit)
					break;
				foundDigit = true;
				isNegative = true;
			}
			else if(c == '.' && foundDigit){
				isFraction = true;
			}
			else if(foundDigit)
				break;
			i = 0;
		}
	}
	if(isNegative)
		value = -value;
	v =  ((float)value) * fraction;
	return v;
}

int64_t readInteger(){
	int64_t value = 0;
	bool foundDigit = false;
	bool isNegative = false;
	uint8_t c;
	int i, timeout = 10000;
	for(i=0;i<timeout;i++){
		if(VCPRead(&c, 1)){
			if(c >= '0' && c <= '9'){
				value = value * 10 + c - '0';
				foundDigit = true;
			}
			else if(c == '-'){
				if(foundDigit)
					break;
				foundDigit = true;
				isNegative = true;
			}
			else if(foundDigit)
				break;
			i = 0;
		}
	}
	if(isNegative)
		value = -value;
	return value;
}

char readChar(){
	while(VCPAvailable() < 1);
	char c;
	VCPRead((uint8_t*)&c, 1);
	return c;
}


static char* myitoa(char* str, int number){
	int i, n;
	if(number == 0){
		*(str++) = '0';
		return str;
	}

	bool found = false;
	if(number < 0){
		*(str++) = '-';
		number = -number;
	}
	for(i=1000000000;i>=1;i/=10){
		n = number / i;
		if(found || n != 0)
		{
			found = true;
			*(str++) = (n) + '0';
		}
		number -= n*i;
	}
	return str;
}

#include <math.h>

void printInteger(int value){
	char str[11];
	char* s = myitoa(str, value);
	VCPWrite((uint8_t*)str, s - str);
}

void printFloat(double number, uint8_t digits)
{
	char string[100];
	char* s = string;
	int i;

  if (isnan(number)) {
	  VCPWrite((uint8_t*)"nan", 3);
	  return;
  }
  if (isinf(number)) {
	  VCPWrite((uint8_t*)"inf", 3);
	  return;
  }
  if (number > 2147483647.0) {
	  VCPWrite((uint8_t*)"ovf", 3);  // constant determined empirically
	  return;
  }
  if (number <-2147483647.0) {
	  VCPWrite((uint8_t*)"ovf", 3);  // constant determined empirically
	  return;
  }

  // Handle negative numbers
  if (number < 0.0)
  {
	  *(s++) = '-';
	  number = -number;
  }

  // Round correctly so that print(1.999, 2) prints as "2.00"
  double rounding = 0.5;
  for (i=0; i<digits; ++i)
    rounding /= 10.0;

  number += rounding;

  // Extract the integer part of the number and print it
  unsigned long int_part = (unsigned long)number;
  double remainder = number - (double)int_part;
  s = myitoa(s, int_part);

  // Print the decimal point, but only if there are digits beyond
  if (digits > 0) {
	  *(s++) = '.';
  }

  // Extract digits from the remainder one at a time
  for(i=0;i<digits;i++)
	  remainder *= 10;

  s = myitoa(s, (int) remainder);
  VCPWrite((uint8_t*)string, s - string);
}

void printString(char* string){
	VCPWrite((uint8_t*)string, strlen(string));
}

void printNewLine(){
	printString("\n");
}


/**
  * @}
  */ 

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

