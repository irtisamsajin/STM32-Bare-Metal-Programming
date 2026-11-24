#ifndef SPI_H
#define SPI_H

#include<stdint.h>

#ifndef RCC_APB2ENR
#define RCC_APB2ENR (*(volatile uint32_t *) (0x40023800+ 0x44))
#endif

#define RCC_APB2ENR_SPI1_SET (1<<12)

#define SPI1 0x40013000
#define SPI1_CR1 (*(volatile uint16_t*) (SPI1+0x00)) 
#define SPI1_CR2 (*(volatile uint16_t*) (SPI1+0x04)) 
#define SPI1_SR (*(volatile uint16_t*) (SPI1+0x08))
#define SPI1_DR (*(volatile uint16_t*) (SPI1+0x0C))  

#define SPI_CR1_SPE (1<<6)
#define SPI_CR2_TXEIE (1<<7)
#define SPI_CR2_RXNEIE (1<<6)
#define SPI_SR_TXE (1<<1)
#define SPI_SR_RXNE (1<<0)
#define SPI_SR_BSY (1<<7)
#define SPI_CR1_DFF (1<<11)

void SPI1_init();

#endif