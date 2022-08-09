/*
 * lcd.c
 *
 *  Created on: Apr 23, 2022
 *      Author: bassam
 */

#include "lcd.h"

void LCD_clear_screen(){
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}

void LCD_lcd_kick(){
	LCD_CTRL |= (1 << EN_SWITCH);
	_delay_ms(50);
	LCD_CTRL &= ~(1 << EN_SWITCH);
}

void LCD_GOTO_XY(unsigned char line, unsigned char position){
	if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW+position);
		}
	}
	if (line == 2)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW+position);
		}
	}
}

void LCD_INIT(){
/*	_delay_ms(20);
	DataDir_LCD_CTRL |= (1<<EN_SWITCH | 1<<RS_SWITCH | 1<<RW_SWITCH);
	LCD_CTRL &= ~ (1<<EN_SWITCH | 1<<RS_SWITCH | 1<<RW_SWITCH);
	LCD_WRITE_COMMAND(0x03);
	_delay_ms(5);
	LCD_WRITE_COMMAND(0x03);
	_delay_us(100);
	LCD_WRITE_COMMAND(0x03);
	LCD_WRITE_COMMAND(0x02);
	LCD_WRITE_COMMAND(0x02);
	LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);
	LCD_WRITE_COMMAND(0x00);
	LCD_WRITE_COMMAND(0x08);
	LCD_WRITE_COMMAND(0x00);
	LCD_WRITE_COMMAND(0x01);
	LCD_WRITE_COMMAND(0x00);
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
*/
	_delay_ms(20);
	DataDir_LCD_CTRL |= (1<<EN_SWITCH | 1<<RS_SWITCH | 1<<RW_SWITCH);
	LCD_CTRL &= ~ (1<<EN_SWITCH | 1<<RS_SWITCH | 1<<RW_SWITCH);
	//DataDir_LCD_PORT = 0xFF;
	_delay_ms(15);
	LCD_clear_screen();
	_delay_us(100);
	#ifdef EIGHT_BIT_MODE
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	#endif
	#ifdef FOUR_BIT_MODE
		//LCD_WRITE_COMMAND(0x02);		/* send for 4 bit initialization of LCD  */
		//LCD_WRITE_COMMAND(0x28);              /* 2 line, 5*7 matrix in 4-bit mode */
		//LCD_WRITE_COMMAND(0x0c);              /* Display on cursor off*/
		//LCD_WRITE_COMMAND(0x06);              /* Increment cursor (shift cursor to right)*/
		//LCD_WRITE_COMMAND(0x01);
	//LCD_WRITE_COMMAND(0x33);
	LCD_WRITE_COMMAND(0x02);
	LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);
	#endif
	//LCD_WRITE_COMMAND(0x0E);
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);	

}

void LCD_check_lcd_isbusy(){
	DataDir_LCD_PORT &= ~(0xFF<<DATA_shift);
	LCD_CTRL |= (1 << RW_SWITCH);
	LCD_CTRL &= ~(1 << RS_SWITCH);
	LCD_lcd_kick();
	DataDir_LCD_PORT |= (0xFF<<DATA_shift);
	LCD_CTRL &= ~(1 << RW_SWITCH);
	
}


void LCD_WRITE_COMMAND(unsigned char command){
	#ifdef EIGHT_BIT_MODE
		LCD_check_lcd_isbusy();
		LCD_PORT = command;
		LCD_CTRL &= ~((1 << RS_SWITCH) | (1<<RW_SWITCH)); 
		_delay_ms(1);
		LCD_lcd_kick();
	#endif
	#ifdef FOUR_BIT_MODE
		LCD_check_lcd_isbusy();
		LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0);
		LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
		LCD_lcd_kick ();
		LCD_PORT = (LCD_PORT & 0x0F) | (command << 4);
		LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
		LCD_lcd_kick();
	#endif
}

void LCD_WRITE_CHAR(unsigned char character){
	#ifdef EIGHT_BIT_MODE
		LCD_check_lcd_isbusy();
		LCD_PORT = character;
		LCD_CTRL &= ~(1 << RW_SWITCH);
		LCD_CTRL |= (1 << RS_SWITCH);
		_delay_ms(1);
		LCD_lcd_kick();
	#endif
	#ifdef FOUR_BIT_MODE
		//LCD_check_lcd_isbusy();
		LCD_PORT = (LCD_PORT & 0x0F) | (character & 0xF0);
		LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
		LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
		LCD_lcd_kick();
		LCD_PORT = (LCD_PORT & 0x0F) | (character << 4);
		LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
		LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
		LCD_lcd_kick ();
	#endif
}

void LCD_WRITE_STRING(char* string){
	int count = 0;
	while (*string > 0){
		count++;
		LCD_WRITE_CHAR(*string++);
		if (count == 16)
		{
			LCD_GOTO_XY(2,0);
		}
		else if (count == 32)
		{
			LCD_clear_screen();
			LCD_GOTO_XY(1,0);
			count = 0;
		}
	}
}


void LCD_custom_character(){

	LCD_WRITE_COMMAND(64);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(14);
	LCD_WRITE_CHAR(17);
	LCD_WRITE_CHAR(2);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_CHAR(0);
	_delay_ms(10);


	LCD_WRITE_COMMAND(72);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(10);
	LCD_WRITE_CHAR(21);
	LCD_WRITE_CHAR(17);
	LCD_WRITE_CHAR(18);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(0);
	LCD_GOTO_XY(1,3);
	LCD_WRITE_CHAR(1);
	_delay_ms(10);

	LCD_WRITE_COMMAND(80);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(20);
	LCD_WRITE_CHAR(11);
	LCD_WRITE_CHAR(27);
	LCD_WRITE_CHAR(28);
	LCD_WRITE_CHAR(40);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(0);
	LCD_GOTO_XY(1,5);
	LCD_WRITE_CHAR(2);
	_delay_ms(10);



}
