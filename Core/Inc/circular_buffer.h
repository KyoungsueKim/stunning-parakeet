//
// Created by Administrator on 2024-06-23.
//

#ifndef STM32H735G_DK_CIRCULAR_BUFFER_H
#define STM32H735G_DK_CIRCULAR_BUFFER_H

#include <stdint.h>

#define CIRCULAR_BUFFER_SIZE 1024

typedef struct {
    uint8_t buffer[CIRCULAR_BUFFER_SIZE];
    volatile uint16_t head;
    volatile uint16_t tail;
} CircularBuffer;

void CircularBuffer_Init(CircularBuffer *cb);
int CircularBuffer_isEmpty(CircularBuffer *cb);
void CircularBuffer_Put(CircularBuffer *cb, uint8_t data);
int CircularBuffer_Get(CircularBuffer *cb, uint8_t *data);

#endif //STM32H735G_DK_CIRCULAR_BUFFER_H
