#include "timer.h"

void TIM_CH_init(){
    RCC_APB1ENR |= (1<<3); //Enable TIM5

    TIM5_PSC = 65535;
    TIM5_ARR = 976;
    TIM5_CCR2 = 400; 
    TIM5_CNT =  200;

    //Set as Toggle Mode
    TIM5_CCMR1 &= ~ (7 << 12);
    TIM5_CCMR1 |= (3<<12);

    //Output enable
    TIM5_CCER |= (1<<4);

    //Counter enable
    TIM5_CR1 |=1;
}