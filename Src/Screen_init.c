#include <stdio.h>
#include <stdint.h>
#include <stm32f411xe.h>
// global variables

#define ST7789_NOP 0x00 // Empty Command
#define ST7789_SWRESET 0x01 // software reset @ 00000001 @ DCX 0
#define ST7789_RDDID 0x04 //  return display id in 4 params when DCX IS HIGH but initially DCX SHOULD BE 0 @ 00000100
#define ST7789_RDDST 0x09 // active low @ 00001001 returns 5 params ( display status)
#define ST7789_MADCTL_MY   0x80 // D7 Rervese Y Address Order
#define ST7789_MADCTL_MX   0x40 // D6 Reverse X Address Order
#define ST7789_MADCTL_MV   0x20 // D5 SWAP ROW AND COLUMN
#define ST7789_MADCTL_ML   0x10 // LCD SCAN DIRECTION
#define ST7789_MADCTL_BGR  0x08 // RGB / BGR COLOR ORDER
#define ST7789_MADCTL_MH   0x04 // HORIZONTAL REFRESH ORDER
#define ST7789_RDDPM 0x0A   // CS LOW , 00001010  RETURN 2 PARAM . READ DISPLAY POWER MODE
#define ST7789_RDDCOLMOD 0x0C //
#define ST7789_RDDIM 0x0D
#define ST7789_RDDSM 0x0E
#define ST7789_RDDSDR 0x0F
#define ST7789_SLPIN  0x10
#define ST7789_SLPOUT 0x11
#define ST7789_SPI_PORT hspi1


static void init_display(GPIO_TypeDef *sclk_pin , GPIO_TypeDef *mosi_pin , GPIO_TypeDef *miso_pin , GPIO_TypeDef *dc,GPIO_TypeDef *rst_pin , GPIO_TypeDef *cs) {

        static void WriteCommand(uint8_t cmd) {
                HAL_GPIO_WritePin(curr_pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(data_pin, GPIO_PIN_RESET);
                HAL_SPI_Transmit(ST7789_SPI_PORT, uint8_t *cmd , uint16_t 8, uint32_t Timeout);

                HAL_GPIO_WritePin(curr_pin, GPIO_PIN_SET);
        };

        HAL_GPIO_WritePin(rst_pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(rst_pin, GPIO_PIN_SET);

};