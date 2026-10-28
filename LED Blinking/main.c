#include<stdint.h>

#define RCC_AHB1ENR (*(volatile uint32_t *) 0x40023830)

typedef struct{
    volatile uint32_t MODER;
    volatile uint16_t OTYPER;
    volatile uint16_t reserved0;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint16_t IDR;
    volatile uint16_t reserved1;
    volatile uint16_t ODR;
} GPIO;

#define GPIOA ((GPIO*) 0x40020000)

#define pin 6


int main(void){
    //Enabling GPIOA
    RCC_AHB1ENR |= 1;

    //////Configuring GPIO Pin (PA6)
    
    //Setting pin to output mode
    GPIOA -> MODER &=~(3<<(2*pin));
    GPIOA -> MODER |=(1<<(2*pin));

    //Push-pull output configuration
    GPIOA -> OTYPER &=~(1<<(pin));

    //Output spped
    GPIOA -> OSPEEDR &=~(3<<(2*pin));
    
    //No pull-up, no pull-down  configuration
    GPIOA -> PUPDR &=~(3<<(2*pin));
    

    while(1){
        GPIOA -> ODR |= (1<<pin); //Turn LED ON

        for(int i=0;i<300000;i++);

        GPIOA -> ODR &=~ (1<<pin); //Turn LED OFF

        for(int i=0;i<300000;i++);
    }
}