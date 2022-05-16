#ifndef __CONSOLE_DRIVER_H
#define __CONSOLE_DRIVER_H


#define  UART_TIMEOUT         100
#define  MAX_CONSOLE_BUFFER   512


#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>


#include "main.h"
#include "structure.h"


void Serial_Print(UART_HandleTypeDef *huart, const char* format, ...);
void Serial_Init(uint32_t baudrate);
void Serial_newLine(UART_HandleTypeDef *port);


extern console_t console;

#endif
