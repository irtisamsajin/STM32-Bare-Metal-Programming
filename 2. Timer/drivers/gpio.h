#ifndef GPIO_H
#define GPIO_H

#include<stdint.h>

#define RCC_AHB1ENR (*(volatile uint32_t *) 0x40023830)

#define GPIOA ((GPIO*) 0x40020000)

typedef struct{
    volatile uint32_t MODER;
    volatile uint16_t OTYPER;
             uint16_t reserved0;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint16_t IDR;
             uint16_t reserved1;
    volatile uint16_t ODR;
             uint16_t reserved2;
    volatile uint32_t BSRR;
    volatile uint16_t LCKR;
             uint16_t reserved3;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH;
} GPIO;


void GPIO_init();

#endif