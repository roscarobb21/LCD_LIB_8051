#ifndef __LCD_LIB__
#define __LCD_LIB__

void delay(int time);

//Init the LCD
void LCD_INIT();
//Clear the screen
void LCD_CLEAR();
//Set entry parameters eg 16x2 or 16x1 LCD
void LCD_ENTRY_SET();

//Shift cursor to the right
void LCD_SHIFT();

//Write one character to LCD
void LCD_WRITE(unsigned char data);
//Write array of characters to LCD
void LCD_DISPLAY_MSG(unsigned char data[]);


//Set display ON/OFF
void LCD_DISPLAY_ON_OFF();
//Set DDRAM ADDRESS
void LCD_SET_CURSOR(int row, int col);

#endif