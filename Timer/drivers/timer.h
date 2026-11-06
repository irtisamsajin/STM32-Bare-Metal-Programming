#ifndef TIMER_H
#define TIMER_H

#include<stdint.h>

#define RCC_APB1ENR (*(volatile uint32_t *) 0x40023840)

#define TIM5 0x40000C00
#define TIM5_CNT (*(volatile uint32_t *) (TIM5+0x24))
#define TIM5_PSC (*(volatile uint16_t *) (TIM5+0x28))
#define TIM5_ARR (*(volatile uint32_t *) (TIM5+0x2C))
#define TIM5_CCR2 (*(volatile uint32_t *) (TIM5+0x38))
#define TIM5_CR1 (*(volatile uint16_t *) (TIM5+0x0))
#define TIM5_CCMR1 (*(volatile uint16_t *) (TIM5+0x18))
#define TIM5_CCER (*(volatile uint16_t *) (TIM5+0x20))
#define TIM5_EGR (*(volatile uint16_t *) (TIM5+0x14))

void TIM_CH_init();

#endif