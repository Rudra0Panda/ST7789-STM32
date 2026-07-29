#include <stdio.h>
#include <stdint.h>
#include <main.h>
#include  <main.c>
#include <stm32f411xe.h>
#include <config.h>
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


static void WriteCommand(uint8_t cmd) {
    HAL_GPIO_WritePin(cs, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(data_pin, GPIO_PIN_RESET);
    HAL_SPI_Transmit(hspi1, uint8_t &cmd, sizeof(cmd),HAL_MAX_DELAY);
    HAL_GPIO_WritePin(cs, GPIO_PIN_SET);
};

static void displaySleep() {
    WriteCommand(0x10);
}

static void displaySleepOut() {
    WriteCommand(0x11);
}

static void displayInvertOToggle() {
    int State = 1;
    if (State==1){
        WriteCommand((0x20));
        State = 0;
    }else {
        WriteCommand((0x21));
        State = 1;
    }

}

static OffDisplay() {
    WriteCommand(0x28);
}

static OnDisplay() {
    WriteCommand(0x29);
}


static void displayToggle() {
    int State = 1;
    if (State==1){
        WriteCommand((0x28));
        State = 0;
    }else {
        WriteCommand((0x29));
        State = 1;
    }

}


static void init_display() {
    HAL_GPIO_WritePin(rst_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(rst_pin, GPIO_PIN_SET);
    WriteCommand(0x01);

};