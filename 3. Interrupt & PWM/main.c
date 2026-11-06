
#include "drivers/timer.h"
#include "drivers/gpio.h"
#include "drivers/interrupt.h"

uint32_t dutyCycle;

void EXTI1_IRQHandler(){
    if(EXTI_PR & (1<<1)){
        EXTI_PR|= (1<<1);
        dutyCycle+=10;
        if(dutyCycle>=TIM5_ARR)dutyCycle=TIM5_ARR;
        TIM5_CCR2=dutyCycle;
    }
}

void EXTI9_5_IRQHandler(){
    if(EXTI_PR & (1<<5)){
        EXTI_PR|= (1<<5);
        if(dutyCycle>=10)dutyCycle-=10;
        else dutyCycle=0;
        TIM5_CCR2=dutyCycle;
    }
}

int main(void){
    
    GPIO_init();
    TIM_CH_init();
    EXTI1_init();
    EXTI5_init();
    dutyCycle=0;
    while(1){
    }
}