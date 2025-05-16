#include <stdio.h>
//#include "tm4c123gh6pm.h"
#include "Bit_Utilities.h"
#include <string.h>
#include "Buzzer.h"
#include "LCD.h"

void LCD_delay(long delay){
while(delay--);

}
void data_lines (unsigned char data) {
if(GET_BIT(data,0)==0x01)
SET(GPIO_PORTE_DATA_R,0x08) ;
else
CLR(GPIO_PORTE_DATA_R,0x08) ;

if(GET_BIT(data,1)==0x01)
SET(GPIO_PORTE_DATA_R,0x04)  ;
else
CLR(GPIO_PORTE_DATA_R,0x04) ;

if(GET_BIT(data,2)==0x01)
SET(GPIO_PORTE_DATA_R,0x02)  ;
else
CLR(GPIO_PORTE_DATA_R,0x02) ;

if(GET_BIT(data,3)==0x01)
SET(GPIO_PORTB_DATA_R,0x10)  ;
else
CLR(GPIO_PORTB_DATA_R,0x10) ;

if(GET_BIT(data,4)==0x01)
SET(GPIO_PORTE_DATA_R,0x20)  ;
else
CLR(GPIO_PORTE_DATA_R,0x20) ;

if(GET_BIT(data,5)==0x01)
SET(GPIO_PORTE_DATA_R,0x10)  ;
else
CLR(GPIO_PORTE_DATA_R,0x10) ;

if(GET_BIT(data,6)==0x01)
SET(GPIO_PORTB_DATA_R,0x02)  ;
else
CLR(GPIO_PORTB_DATA_R,0x02) ;

if(GET_BIT(data,7)==0x01)
SET(GPIO_PORTB_DATA_R,0x01)  ;
else
CLR(GPIO_PORTB_DATA_R,0x01) ;
}
void LCD_data (unsigned char data){
data_lines(data); // transfer data to lcd pins

CLR(GPIO_PORTD_DATA_R,0X02); //turn off R/W bin
SET(GPIO_PORTD_DATA_R,0X01); //turn on RS bin
SET(GPIO_PORTD_DATA_R,0X04); //turn on enable pin
LCD_delay(10000) ;  //delay
CLR(GPIO_PORTD_DATA_R,0X04); //turn off enable pin
	
}
void LCD_instructions (unsigned char data){
data_lines(data); //transfer data to lcd pins

CLR(GPIO_PORTD_DATA_R,0X02); //turn off R/W bin
CLR(GPIO_PORTD_DATA_R,0X01); //turn off RS bin
SET(GPIO_PORTD_DATA_R,0X04); //turn on enable pin
LCD_delay(10000) ;  //delay
CLR(GPIO_PORTD_DATA_R,0X04); //turn off enable pin

}
void LCD_init (void)
{
LCD_delay(10000) ;
LCD_instructions(0x38);// 16 column 2 row 
LCD_instructions(0x06);//cursor++
LCD_instructions(0x0c);//cursor off and display on
LCD_instructions(0x01); //clear screen
LCD_instructions(0x80); //cursor to initial position
}
void LCD_word (char *word,char length){
char n=0;
for(n=0;n<length;n++){
LCD_data(word[n]);
}
}

// changeeeeeeeeeeeeeeeee: long to float
void LCD_print_location (char* uu,char size,float mini_distance) {
char print_distance[7];
int distance_length=snprintf(print_distance,7,"%0.4f",mini_distance);
if ((mini_distance)>= 10) {LCD_word("nearest:",8); callBuzzer(); }
else {LCD_word("arrived:",8);}
LCD_word(uu,size);
LCD_instructions(0xc0);
LCD_word(print_distance,6);
LCD_word(" m",2);
}
