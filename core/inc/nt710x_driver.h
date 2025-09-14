#ifndef GLCD_H
#define GLCD_H

#include "stm32f4xx_hal.h"

// Define control pins
#define GLCD_RS_Pin     GPIO_PIN_0
#define GLCD_RW_Pin     GPIO_PIN_1
#define GLCD_EN_Pin     GPIO_PIN_2
#define GLCD_CS1_Pin    GPIO_PIN_4
#define GLCD_CS2_Pin    GPIO_PIN_3
#define GLCD_RST_Pin    GPIO_PIN_5
#define GLCD_CTRL_Port  GPIOB

// Data port
#define GLCD_DATA_Port  GPIOD

void GLCD_Init(void);
void GLCD_Clear(void);
void GLCD_WriteCommand(uint8_t cmd, uint8_t chip);
void GLCD_WriteData(uint8_t data, uint8_t chip);
void GLCD_GotoXY(uint8_t x, uint8_t y);
void GLCD_DisplayChar(char c,uint8_t x, uint8_t y);
void GLCD_DisplayString(const char* str,uint8_t x, uint8_t y);
void GLCD_SetPixel(uint8_t x, uint8_t y, uint8_t state);
uint8_t GLCD_GetPixel(uint8_t x, uint8_t y);
void GLCD_InvertDisplay(uint8_t invert);
void GLCD_DrawLine(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1);
void GLCD_DrawRect(uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void GLCD_FillRect(uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void GLCD_Update(void);

#endif
