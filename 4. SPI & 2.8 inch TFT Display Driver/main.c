#include "drivers/tft.h"
#include "drivers/spi.h"
#include "drivers/gpio.h"


int main(void){
    
    GPIO_init();
    SPI1_init();

    TFT_16bit_Pixel_Format_Set();


        uint16_t x1=0x14;
        uint16_t y1=0x28;

        uint16_t x2=x1+9;
        uint16_t y2=y1+9;
        uint16_t color=0xf800;

        uint16_t Pixel_RGB565_Values[]={
            color,color,color,color,color,color,color,color,color,color,
            color,color,color,color,color,color,color,color,color,color,
            color,color,color,color,color,color,color,color,color,color,
            color,color,color,color,color,color,color,color,color,color,
            color,color,color,color,color,color,color,color,color,color,
            color,color,color,color,color,color,color,color,color,color,
            color,color,color,color,color,color,color,color,color,color,
            color,color,color,color,color,color,color,color,color,color,
            color,color,color,color,color,color,color,color,color,color,
            color,color,color,color,color,color,color,color,color,color
        };

        uint8_t Pixel_data_size=100;

        TFT_Write_Pixel(x1,x2,y1,y2,Pixel_RGB565_Values,Pixel_data_size);
    
    while(1){
        
    }
}