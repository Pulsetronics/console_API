#ifndef __STRUCTURE_H 
#define __STRUCTURE_H


#include "main.h"
#include "usart.h"




typedef struct {
        uint8_t  string[MAX_CONSOLE_BUFFER];
        uint8_t* character;
        uint32_t baudrate;
        UART_HandleTypeDef *port1, *port2, *port3, *port4;
        void (*init)  (uint32_t baudrate);
        void (*write) (UART_HandleTypeDef *huart, const char* format, ...);
        void (*newLine) (UART_HandleTypeDef *port);
}console_t;




#endif
