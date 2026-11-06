#include "gpio.h"

//Initializing PA1 as AF
void GPIO_init(){
    RCC_AHB1ENR |= 1; //Enable GPIOA
    
    //Setting pin to output mode
    GPIOA -> MODER &=~(3<<(2*1));
    GPIOA -> MODER |=(2<<(2*1)); //For alternate function

    //Configure AF of pin 1 as AF2 for TIM5_CH2
    GPIOA -> AFRL &=~( 0xF << (4*1));
    GPIOA -> AFRL |= ( 2 << (4*1));

    //Push-pull output configuration
    GPIOA -> OTYPER &=~(1<<(1));

    //Output spped
    GPIOA -> OSPEEDR &=~(3<<(2*1));
    
    //No pull-up, no pull-down  configuration
    GPIOA -> PUPDR &=~(3<<(2*1));
}