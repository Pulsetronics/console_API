#include "console_driver.h"

console_t console = {
          .init    = Serial_Init,
          .write   = Serial_Print,
          .newLine = Serial_newLine,
          .port2   = &huart2,

};


void Serial_Print(UART_HandleTypeDef *huart, const char* format, ...) {
     console_t* serial = (console_t*) calloc(1, sizeof(console_t));
     va_list args;
     va_start(args, format);
     vsnprintf((char*)serial->string, sizeof(serial->string), format, args);
     HAL_UART_Transmit(huart, serial->string, strlen((char*) serial->string), UART_TIMEOUT);
     free(serial);
     va_end(args);
}

void Serial_newLine(UART_HandleTypeDef *port) {
     console_t* serial = (console_t*) calloc(1, sizeof(console_t));
     serial->character = (uint8_t*) "\n";
     HAL_UART_Transmit(port, serial->character, strlen((char*) serial->character), UART_TIMEOUT);
     free(serial);
}

void Serial_Init(uint32_t baudrate){
 
    MX_USART2_UART_Init(baudrate);
}