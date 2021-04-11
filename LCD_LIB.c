#include<htc.h>
#include <stdio.h>
#include <string.h>
#include "LCD_LIB.h"


#define EN P00
#define RS P01
#define RW P02
#define D0 P20
#define D1 P21
#define D2 P22
#define D3 P23
#define D4 P24
#define D5 P25
#define D6 P26
#define D7 P27

void delay(int time){
	int i=0;
	for(i=0; i<time; i++){
	}
}


void LCD_CLEAR(){
EN=1;
	RS=0;
	RW=0;
		D7=0;D6=0;D5=0;D4=0;D3=0;D2=0;D1=0;D0=1;
	delay(5);
EN=0;
}

void LCD_INIT(){
//0011 1000
	EN=1;
	RS=0;RW=0;D7=0;D6=0;D5=1;D4=1;D3=1;D2=0;D1=0;D0=0;
	delay(5);
	EN=0;
}

void LCD_SHIFT(){
EN=1;
	RS=0;
	RW=0;
		D7=0;D6=0;D5=0;D4=1;D3=0;D2=1;D1=0;D0=0;
	delay(5);
EN=0;
}

void LCD_ENTRY_SET(){
EN=1;
	RS=0;
	RW=0;
		D7=0;D6=0;D5=0;D4=0;D3=0;D2=1;D1=1;D0=0;
	delay(5);
EN=0;
}

void LCD_DISPLAY_MSG(unsigned char data[]){
	int i;
	for(i = 0 ; i<strlen(data); i++){
		LCD_WRITE(data[i]);
		delay(10);
	}
}

void LCD_WRITE(unsigned char data){
EN=1;
	RS=1;
	RW=0;
		D7=(data >> 7) & 1;
		D6=(data >> 6) & 1;
		D5=(data >> 5) & 1;
		D4=(data >> 4) & 1;
		D3=(data >> 3) & 1;
		D2=(data >> 2) & 1;
		D1=(data >> 1) & 1;
		D0=(data >> 0) & 1;
	delay(5);
EN=0;
}



void LCD_DISPLAY_ON_OFF(){
EN=1;
	RS=0;
	RW=0;
		D7=0;D6=0;D5=0;D4=0;D3=1;D2=1;D1=0;D0=1;
	delay(5);
EN=0;
}

void LCD_SET_CURSOR(int row, int col){

int col1[16]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
int col2[16]={40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 74, 75, 76, 77, 78, 79 };

int data;

if(row == 1){
	data = col1[col];
}

if(row == 2){
	data = col2[col];
}

EN=1;
	RS=0;
	RW=0;
		D7=1;
		D6=(data >> 6) & 1;
		D5=(data >> 5) & 1;
		D4=(data >> 4) & 1;
		D3=(data >> 3) & 1;
		D2=(data >> 2) & 1;
		D1=(data >> 1) & 1;
		D0=(data >> 0) & 1;
	delay(5);
EN=0;
}

