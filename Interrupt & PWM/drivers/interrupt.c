#include "interrupt.h"
#include "gpio.h"

void EXTI1_init(){

    //Configure GPIOC_1 as input
    RCC_AHB1ENR |= (1<<2); //Enable GPIOC
    
    //Setting pin to input mode
    GPIOC -> MODER &=~(3<<(2*1));
    
    //pull-down  configuration
    GPIOC -> PUPDR &=~(3<<(2*1));
    GPIOC -> PUPDR |= (2<<(2*1));

    //Configure SYSCFG to map EXTI to pin
    RCC_APB2ENR |= (1<<14);
    SYSCFG_EXTICR1 |= (2<<(4*1));

    //Configure EXTI1
    EXTI_IMR |= (1<<1);
    EXTI_FTSR |= (1<<1);

    //enable NVIC interrupt and set priority
    NVIC_IPR1 &=~(255<<(8*3));
    NVIC_IPR1 |= (16<<(8*3));
    NVIC_ISER |= (1<<7);

}
void EXTI5_init(){

    //Configure GPIOC_5 as input
    RCC_AHB1ENR |= (1<<2); //Enable GPIOC
    
    //Setting pin to input mode
    GPIOC -> MODER &=~(3<<(2*5));
    
    //pull-down  configuration
    GPIOC -> PUPDR &=~(3<<(2*5));
    GPIOC -> PUPDR |= (2<<(2*5));

    //Configure SYSCFG to map EXTI to pin
    RCC_APB2ENR |= (1<<14);
    SYSCFG_EXTICR2 |= (2<<(4*1));

    //Configure EXTI5
    EXTI_IMR |= (1<<5);
    EXTI_FTSR |= (1<<5);

    //enable NVIC interrupt and set priority
    NVIC_IPR5 &=~(255<<(8*3));
    NVIC_IPR5 |= (32<<(8*3));
    NVIC_ISER |= (1<<23);
}