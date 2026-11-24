#ifndef TFT_H
#define TFT_H

#include<stdint.h>


void TFT_16bit_Pixel_Format_Set();
void TFT_Write_Pixel(uint16_t Start_Row, uint16_t End_Row, uint16_t Start_Column, uint16_t End_Column, uint16_t Pixel_RGB565_Values[], uint8_t Pixel_data_size);

#endif