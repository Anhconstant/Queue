#include "stdint.h"
/*
    Decription: 
        - Buffer :  Address of Data buffer 
        - BufferSize : size of Buffer
        - currentIndex :  pointer of position of data
        - Rxbuffer  : Address of buffer uart Rx
        - RxbufferSize : size of uart buffer (usually : 1)
    *Note : use in UART_RxCpltCallback
        void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
        currentIndex=UART_Add_buffer(RxData, RxSize, currentIndex, &temp, 1);
        HAL_UART_Receive_IT(&huart1, &temp, 1);
        }
*/
uint8_t UART_Add_buffer(uint8_t* Buffer,uint8_t BufferSize,uint8_t currentIndex,uint8_t* Rxbuffer,uint8_t RxbufferSize){
	uint8_t index = currentIndex;
	memcpy( Buffer + currentIndex, Rxbuffer, RxbufferSize);
	index += RxbufferSize ;
	if( index >= BufferSize ) index = index - BufferSize;
	return index;
}
