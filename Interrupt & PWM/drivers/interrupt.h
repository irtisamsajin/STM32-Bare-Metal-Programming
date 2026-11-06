#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <stdint.h>

#define NVIC_ISER (*(volatile uint32_t*) 0xE000E100)
#define NVIC_ICER (*(volatile uint32_t*) 0XE000E180)
#define NVIC_ISPR (*(volatile uint32_t*) 0XE000E200)
#define NVIC_ICPR (*(volatile uint32_t*) 0XE000E280)
#define NVIC_IABR (*(volatile uint32_t*) 0xE000E300)

#define NVIC_IPR 0xE000E400
#define NVIC_IPR1 (*(volatile uint32_t*) (NVIC_IPR+0x04))
#define NVIC_IPR5 (*(volatile uint32_t*) (NVIC_IPR+(0x04)*5))

#define EXTI 0x40013C00
#define EXTI_IMR (*(volatile uint32_t*) (EXTI+0x0))
#define EXTI_EMR (*(volatile uint32_t*) (EXTI+0x04))
#define EXTI_RTSR (*(volatile uint32_t*) (EXTI+0x08))
#define EXTI_FTSR (*(volatile uint32_t*) (EXTI+0x0C))
#define EXTI_SWIER (*(volatile uint32_t*) (EXTI+0x10))
#define EXTI_PR (*(volatile uint32_t*) (EXTI+0x14))

#define RCC_APB2ENR (*(volatile uint32_t*) 0x40023844)
#define SYSCFG 0x40013800
#define SYSCFG_EXTICR1 (*(volatile uint32_t*) (SYSCFG+0x8))
#define SYSCFG_EXTICR2 (*(volatile uint32_t*) (SYSCFG+0xC))

void EXTI1_init();
void EXTI5_init();

#endif