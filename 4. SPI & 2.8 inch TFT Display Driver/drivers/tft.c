#include "tft.h"
#include "spi.h"
#include "gpio.h"


const int delay=-1;

void TFT_16bit_Pixel_Format_Set(){
    SPI1_CR1 |= SPI_CR1_SPE; //Enable SPI1 

    while((SPI1_SR & SPI_SR_TXE)==0); //wait until TX buffer is empty
    GPIOA -> ODR &=~ GPIO_ODR_PIN_1_SET; //Set as Command Mode
    for(int i=0;i<delay;i++);
    SPI1_DR = 0x1;     

    for(int i=0;i<1000;i++);

    while((SPI1_SR & SPI_SR_TXE)==0); //wait until TX buffer is empty
    GPIOA -> ODR &=~ GPIO_ODR_PIN_1_SET; //Set as Command Mode
    for(int i=0;i<delay;i++);
    SPI1_DR = 0x3A; 
    
    while((SPI1_SR & SPI_SR_TXE)==0);
    GPIOA -> ODR |= GPIO_ODR_PIN_1_SET; //Set as Data Mode
    for(int i=0;i<delay;i++);
    SPI1_DR = 0b01010101;

    while((SPI1_SR & SPI_SR_TXE)==0); //wait until TX buffer is empty
    GPIOA -> ODR &=~ GPIO_ODR_PIN_1_SET; //Set as Command Mode  
    for(int i=0;i<delay;i++);
    SPI1_DR = 0x0; //NOP  

    while( ((SPI1_SR & SPI_SR_TXE) == 0) || ((SPI1_SR & SPI_SR_BSY)!=0) );

    SPI1_CR1 &=~ SPI_CR1_SPE;

}

void TFT_Write_Pixel(uint16_t Start_Row, uint16_t End_Row, uint16_t Start_Column, uint16_t End_Column, uint16_t Pixel_RGB565_Values[], uint8_t Pixel_data_size){
    
    SPI1_CR1 |= SPI_CR1_DFF;
    
    SPI1_CR1 |= SPI_CR1_SPE; //Enable SPI1 

    // Set the coulumn of the frame
    while((SPI1_SR & SPI_SR_TXE)==0); //wait until TX buffer is empty
    GPIOA -> ODR &=~ GPIO_ODR_PIN_1_SET; //Set as Command Mode
    for(int i=0;i<delay;i++);
    SPI1_DR = 0x2A; //Column set Address 

    /* while((SPI1_SR & SPI_SR_TXE)==0);
    GPIOA -> ODR |= GPIO_ODR_PIN_1_SET; //Set as Data Mode
    for(int i=0;i<delay;i++);
    SPI1_DR = 0x0; */

    while((SPI1_SR & SPI_SR_TXE)==0);
    GPIOA -> ODR |= GPIO_ODR_PIN_1_SET; //Set as Data Mode
    for(int i=0;i<delay;i++);
    SPI1_DR = Start_Column;

    /* while((SPI1_SR & SPI_SR_TXE)==0);
    GPIOA -> ODR |= GPIO_ODR_PIN_1_SET; //Set as Data Mode
    for(int i=0;i<delay;i++);
    SPI1_DR = 0x0; */

    while((SPI1_SR & SPI_SR_TXE)==0);
    GPIOA -> ODR |= GPIO_ODR_PIN_1_SET; //Set as Data Mode
    for(int i=0;i<delay;i++);
    SPI1_DR = End_Column;


    //Set the Row of the frame
    while((SPI1_SR & SPI_SR_TXE)==0); //wait until TX buffer is empty
    GPIOA -> ODR &=~ GPIO_ODR_PIN_1_SET; //Set as Command Mode
    for(int i=0;i<delay;i++);
    SPI1_DR = 0x2B; //Page set Address 

    /* while((SPI1_SR & SPI_SR_TXE)==0);
    GPIOA -> ODR |= GPIO_ODR_PIN_1_SET; //Set as Data Mode
    for(int i=0;i<delay;i++);
    SPI1_DR = 0x0; */

    while((SPI1_SR & SPI_SR_TXE)==0);
    GPIOA -> ODR |= GPIO_ODR_PIN_1_SET; //Set as Data Mode
    for(int i=0;i<delay;i++);
    SPI1_DR = Start_Row;

    /* while((SPI1_SR & SPI_SR_TXE)==0);
    GPIOA -> ODR |= GPIO_ODR_PIN_1_SET; //Set as Data Mode
    for(int i=0;i<delay;i++);
    SPI1_DR = 0x0; */

    while((SPI1_SR & SPI_SR_TXE)==0);
    GPIOA -> ODR |= GPIO_ODR_PIN_1_SET; //Set as Data Mode
    for(int i=0;i<delay;i++);
    SPI1_DR = End_Row;


    //Send data
    while((SPI1_SR & SPI_SR_TXE)==0); //wait until TX buffer is empty
    GPIOA -> ODR &=~ GPIO_ODR_PIN_1_SET; //Set as Command Mode
    for(int i=0;i<delay;i++);
    SPI1_DR = 0x2C; //Memory Write Command

    for(uint8_t data=0;data<Pixel_data_size;data++){
        /* uint8_t MSB=Pixel_RGB565_Values[data]>>8;
        uint8_t LSB=(uint8_t) (Pixel_RGB565_Values[data] & (0xFF));

        while((SPI1_SR & SPI_SR_TXE)==0);
        GPIOA -> ODR |= GPIO_ODR_PIN_1_SET; //Set as Data Mode
        for(int i=0;i<delay;i++);
        SPI1_DR = MSB;

        while((SPI1_SR & SPI_SR_TXE)==0);
        GPIOA -> ODR |= GPIO_ODR_PIN_1_SET; //Set as Data Mode
        for(int i=0;i<delay;i++);
        SPI1_DR = LSB; */

        while((SPI1_SR & SPI_SR_TXE)==0);
        GPIOA -> ODR |= GPIO_ODR_PIN_1_SET; //Set as Data Mode
        for(int i=0;i<delay;i++);
        SPI1_DR = Pixel_RGB565_Values[data];
    }

    while((SPI1_SR & SPI_SR_TXE)==0); //wait until TX buffer is empty
    GPIOA -> ODR &=~ GPIO_ODR_PIN_1_SET; //Set as Command Mode 
    for(int i=0;i<delay;i++); 
    SPI1_DR = 0x0; //NOP  

    while( ((SPI1_SR & SPI_SR_TXE) == 0) || ((SPI1_SR & SPI_SR_BSY)!=0) );

    SPI1_CR1 &=~ SPI_CR1_SPE;

    SPI1_CR1 &=~ SPI_CR1_DFF;
}

