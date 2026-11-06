#include "timer.h"

void TIM_CH_init(){
    RCC_APB1ENR |= (1<<3); //Enable TIM5

    TIM5_PSC = 50;
    TIM5_ARR = 199;
    TIM5_CCR2 = 0; 

    //Set as PWM Mode
    TIM5_CCMR1 &= ~ (7 << 12);
    TIM5_CCMR1 |= (6<<12);

    //Output enable
    TIM5_CCER |= (1<<4);

    //Counter enable
    TIM5_CR1 |=1;
}