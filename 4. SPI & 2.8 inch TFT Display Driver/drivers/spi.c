#include "spi.h"

void SPI1_init(){

    //Enable SPI clock
    RCC_APB2ENR |= RCC_APB2ENR_SPI1_SET;

    //Baud Rate - fclk/ = 16/2 MHz
    SPI1_CR1 &=~(7<<3);
    //SPI1_CR1 |= (2<<3);

    //CPOL = 0 
    SPI1_CR1 &=~(1<<1);

    //CPHASE = 0
    SPI1_CR1 &=~(1);

    //MSB First 
    SPI1_CR1 &=~ (1<<7);

    //SSM (software slave management) = 0
    SPI1_CR1 &=~(1<<9);

    //SSOE (Slave Select Output Enable) = 1
    SPI1_CR2 |= (1<<2);

    //MSTR = 1 (Master configuration)
    SPI1_CR1 |= (1<<2);

    //8 bit data frame
    SPI1_CR1 &=~ (1<<11);

}