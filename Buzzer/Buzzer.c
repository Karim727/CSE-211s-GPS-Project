#include "gpio.h"
#include "Bit_Utilities.h"

#include "LCD.h"
#include "delay_Function.c"


void activate_Buzzer(void){
	GPIO_PORTB_DATA_R |= 0x08;
}

void deActivate_Buzzer(void){
	GPIO_PORTB_DATA_R &= ~0x08;
}

void callBuzzer(void){
	activate_Buzzer();
	delay_ms(1000);
	deActivate_Buzzer();
}

//SysCtlDelay(SysCtlClockGet() / (3 * 1000));
