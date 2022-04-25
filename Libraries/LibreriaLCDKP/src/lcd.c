#include "stm32f1xx_hal.h"
#include "stm32f1xx.h"
#include "lcd.h"
#include "stdio.h"
/*
 * char strtemp[15];
 * sprintf(strtemp, "TEMP=%d", temparature);
 *
 * */
/*
#define PUTCHAR_PROTOTYPE int fputc(int ch,FILE *f)
PUTCHAR_PROTOTYPE
{
		lcd_putc(ch);

		return ch;
}
*/
void lcd_init(void)
{
	 GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();

	GPIO_InitStruct.Pin 	= LCDRS_PIN;
  GPIO_InitStruct.Mode 	= GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull 	= GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(LCDRS_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	= LCDE_PIN;
  GPIO_InitStruct.Mode 	= GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull 	= GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(LCDE_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	= LCD4_PIN;
  GPIO_InitStruct.Mode 	= GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull 	= GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(LCD4_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	= LCD5_PIN;
  GPIO_InitStruct.Mode 	= GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull 	= GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(LCD5_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	= LCD6_PIN;
  GPIO_InitStruct.Mode 	= GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull 	= GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(LCD6_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	= LCD7_PIN;
  GPIO_InitStruct.Mode 	= GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull 	= GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(LCD7_PORT, &GPIO_InitStruct);

	HAL_Delay(15);
	LCD7_OFF; LCD6_OFF; LCD5_OFF; LCD4_OFF;
	LCDE_OFF;
	//LCDRW_OFF;
	LCDRS_OFF;
	//---------one------
	LCD7_OFF; LCD6_OFF; LCD5_ON; LCD4_ON;
	LCDE_ON;
	//LCDRW_OFF;
	LCDRS_OFF;
	HAL_Delay(10);
	LCDE_OFF;
	HAL_Delay(10);
	//-----------two-----------
	LCD7_OFF; LCD6_OFF; LCD5_ON; LCD4_ON;
	LCDE_ON;
	//LCDRW_OFF;
	LCDRS_OFF;
	HAL_Delay(10);
	LCDE_OFF;
	HAL_Delay(10);
	//-------three-------------
	LCD7_OFF; LCD6_OFF; LCD5_ON; LCD4_OFF;
	LCDE_ON;
	//LCDRW_OFF;
	LCDRS_OFF;
	HAL_Delay(10);
	LCDE_OFF;
	HAL_Delay(10);
	//--------4 bit--dual line--5x8 dots---------------
	lcd_command(SETLCD_4BITS_2LINE);
	//-----increment address, invisible cursor shift------
	lcd_command(DISPLAY_ON_D_OFF_CB);
	//-----Clear display
	lcd_clear();
}

void lcd_putc(unsigned char ch){		//Sends Char to LCD

	LCDRS_ON;

  if ( ch & 0x10 ) {
		LCD4_ON;
	} else {
		LCD4_OFF;
	}
	if ( ch & 0x20 ) {
		LCD5_ON;
	} else {
    LCD5_OFF;
	}
	if ( ch & 0x40 ) {
		LCD6_ON;
	} else {
		LCD6_OFF;
	}
	if ( ch & 0x80 ) {
		LCD7_ON;
	} else {
		LCD7_OFF;
	}

	LCDE_ON;
	HAL_Delay(1);//__delay_us(300);
	LCDE_OFF;
  HAL_Delay(1);//__delay_us(300);

	if ( ch & 0x01 ) {
		LCD4_ON;
	} else {
		LCD4_OFF;
	}
	if ( ch & 0x02 ) {
		LCD5_ON;
	} else {
    LCD5_OFF;
	}
	if ( ch & 0x04 ) {
		LCD6_ON;
	} else {
    LCD6_OFF;
	}
	if ( ch & 0x08 ) {
		LCD7_ON;
	} else {
    LCD7_OFF;
	}

	LCDE_ON;
	HAL_Delay(1);//__delay_us(300);
  LCDE_OFF;
  HAL_Delay(1);//__delay_us(300);
}
void lcd_command(unsigned char cmd){	//Sends Command to LCD

	LCDRS_OFF;

	if ( cmd & 0x10 ) {
		LCD4_ON;
	} else {
		LCD4_OFF;
	}
	if ( cmd & 0x20 ) {
		LCD5_ON;
	} else {
		LCD5_OFF;
	}
	if ( cmd & 0x40 ) {
		LCD6_ON;
	} else {
		LCD6_OFF;
	}
	if ( cmd & 0x80 ) {
		LCD7_ON;
	} else {
		LCD7_OFF;
	}

	LCDE_ON;
  HAL_Delay(1);//__delay_us(300);
	LCDE_OFF;
  HAL_Delay(1);//__delay_us(300);

	if ( cmd & 0x01 ) {
		LCD4_ON;
	} else {
		LCD4_OFF;
	}
	if ( cmd & 0x02 ) {
		LCD5_ON;
	} else {
		LCD5_OFF;
	}
	if ( cmd & 0x04 ) {
		LCD6_ON;
	} else {
		LCD6_OFF;
	}
	if ( cmd & 0x08 ) {
		LCD7_ON;
	} else {
		LCD7_OFF;
	}

	LCDE_ON;
	HAL_Delay(1);//__delay_us(300);
	LCDE_OFF;
	HAL_Delay(1);//__delay_us(300);

}

void lcd_puts(unsigned char* data, unsigned char nBytes){	//Outputs string to LCD
	register unsigned char i=0;

	for(i=0; i<nBytes; i++){	// print data
		lcd_putc(data[i]);
	}
}

void lcd_gotoxy(unsigned char x, unsigned char y){		//Cursor to X Y position
	register unsigned char DDRAMAddr;

	switch(y){		// remap lines into proper order
	case 1: DDRAMAddr = LCD_LINE0_DDRAMADDR+x-1; break;
	case 2: DDRAMAddr = LCD_LINE1_DDRAMADDR+x-1; break;
	case 3: DDRAMAddr = LCD_LINE2_DDRAMADDR+x-1; break;
	case 4: DDRAMAddr = LCD_LINE3_DDRAMADDR+x-1; break;
	default: DDRAMAddr =LCD_LINE0_DDRAMADDR+x-1;break;
	}
	lcd_command(1<<LCD_DDRAM|DDRAMAddr);	// set data address
}
/*  Funcion para escribir en la CGRAM
 *	DATASHEET HD44780U (LCD-II) (Dot Matrix Liquid Crystal Display Controller/Driver)
 *	page 19.
 * */
void lcd_definechar(unsigned char *car,unsigned char CGRAM_dir){
	unsigned char i=0,a=0;
	a=(CGRAM_dir<<3)|1<<LCD_CGRAM;		//	posiciona en la CGRAM address
	for(i=0;i<8;i++){
        lcd_command(a++);			//	incrementa la direccion para la data
		lcd_putc(car[i]);			//	escribe caracter
	}
}

void lcd_clear(void){
    lcd_command(CLEAR_DISPLAY);
}


