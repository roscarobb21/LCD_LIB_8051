
#include <htc.h>
#define start P30
#define stop P05
#define reset P06
#define startBtn P10
#define stopBtn P11
#define resetBtn P12
#include "LCD_LIB.h"





//1257 -> 8051 value for 1ms delay
/*
for 12MHz clock 1000 for cycles for 1ms
*/
void delay_1ms() 
{ 
 unsigned int j; 
 for(j=0;j<1000;j++);   
} 

void main(){
/* initialisation */
unsigned char msg[]="0  ms";
unsigned char digitArr[]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
static int value=0;
static int decimal = 0;

		LCD_INIT();
		LCD_ENTRY_SET();
		LCD_CLEAR();
		LCD_DISPLAY_MSG("TIMER");

		start = 0;
		stop = 0;
		reset = 0;
/* end initialisation */
/* Repetitive */
	while(1){
		if(resetBtn == 0){
				start = 0; stop = 0; reset =1;
				value = 0 ;
				decimal = 0;
				LCD_CLEAR();
				msg[0]='0'; msg[1]=' '; msg[2]=' '; msg[3]= 'm'; msg[4]= 's';
				LCD_DISPLAY_MSG("0  ms");
				continue;
		}

		if(startBtn == 0){
			if(value >= 10){
			decimal++;
			value = 0 ;	
			}
			if(decimal == 0 ){
			msg[0] = digitArr[value++];
			}
			if(decimal != 0){
			msg[0] = digitArr[decimal];
			msg[1] = digitArr[value++];
			}
	
			start = 1; stop = 0; reset =0;
			LCD_CLEAR();
			LCD_DISPLAY_MSG(msg);

			delay_1ms();
		}else {
			start = 0; stop = 1; reset =0;
		}
	}
/* end Repetitive */
}
