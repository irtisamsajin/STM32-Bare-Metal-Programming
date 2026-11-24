#include "gpio.h"

//Initializing PA1 as AF
void GPIO_init(){
    RCC_AHB1ENR |= RCC_AHB1ENR_GPIOA_Enable; //Enable GPIOA


    //---------Setting pin PA1 to Output (DC)-------------
    GPIOA -> MODER &=~(3<<(2*1));
    GPIOA -> MODER |=(1<<(2*1)); //For output

    //Push-pull output configuration
    GPIOA -> OTYPER &=~(1<<(1));

    //Output spped
    GPIOA -> OSPEEDR |= (3<<(2*1));
    
    //No pull-up, no pull-down  configuration
    GPIOA -> PUPDR &=~(3<<(2*1));



    //---------Setting pin PA4 to AF5 (CS)-------------
    GPIOA -> MODER &=~(3<<(2*4));
    GPIOA -> MODER |=(2<<(2*4)); //For alternate function

    //Configure as AF5
    GPIOA -> AFRL &=~( 0xF << (4*4));
    GPIOA -> AFRL |= ( 5 << (4*4));

    //Push-pull output configuration
    GPIOA -> OTYPER &=~(1<<(4));

    //Output spped
    GPIOA -> OSPEEDR |= (3<<(2*4));
    
    //No pull-up, no pull-down  configuration
    GPIOA -> PUPDR &=~(3<<(2*4));




    //---------Setting pin PA5 to AF5 (SCK)-------------
    GPIOA -> MODER &=~(3<<(2*5));
    GPIOA -> MODER |=(2<<(2*5)); //For alternate function

    //Configure as AF5
    GPIOA -> AFRL &=~( 0xF << (4*5));
    GPIOA -> AFRL |= ( 5 << (4*5));

    //Push-pull output configuration
    GPIOA -> OTYPER &=~(1<<(5));

    //Output spped
    GPIOA -> OSPEEDR |= (3<<(2*5));
    
    //No pull-up, no pull-down  configuration
    GPIOA -> PUPDR &=~(3<<(2*5));


    
    //---------Setting pin PA6 to AF5 (MISO)-------------
    GPIOA -> MODER &=~(3<<(2*6));
    GPIOA -> MODER |=(2<<(2*6)); //For alternate function

    //Configure as AF5
    GPIOA -> AFRL &=~( 0xF << (4*6));
    GPIOA -> AFRL |= ( 5 << (4*6));

    //Push-pull output configuration
    GPIOA -> OTYPER &=~(1<<(6));

    //Output spped
    GPIOA -> OSPEEDR |= (3<<(2*6));
    
    //No pull-up, no pull-down  configuration
    GPIOA -> PUPDR &=~(3<<(2*6));



    //---------Setting pin PA7 to AF5 (MOSI)-------------
    GPIOA -> MODER &=~(3<<(2*7));
    GPIOA -> MODER |=(2<<(2*7)); //For alternate function

    //Configure as AF5
    GPIOA -> AFRL &=~( 0xF << (4*7));
    GPIOA -> AFRL |= ( 5 << (4*7));

    //Push-pull output configuration
    GPIOA -> OTYPER &=~(1<<(7));

    //Output spped
    GPIOA -> OSPEEDR |= (3<<(2*7));
    
    //No pull-up, no pull-down  configuration
    GPIOA -> PUPDR &=~(3<<(2*7));
    

    
}