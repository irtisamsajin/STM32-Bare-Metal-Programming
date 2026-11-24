#ifndef GPIO_H
#define GPIO_H

#include<stdint.h>

#ifndef RCC_AHB1ENR
#define RCC_AHB1ENR (*(volatile uint32_t *) 0x40023830)
#endif

#define RCC_AHB1ENR_GPIOA_Enable 1

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

#define GPIO_ODR_PIN_1_SET (1<<1)

void GPIO_init();

#endif