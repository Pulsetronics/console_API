#ifndef __HAL_DRIVER_H
#define __HAL_DRIVER_H

#include "main.h"

typedef struct {
        void (*delay) (uint32_t Delay);
}hal_t;

extern hal_t os;

#endif