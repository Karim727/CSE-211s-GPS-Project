#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tm4c123gh6pm.h"
#include "UART.h"
#include "GPS.h"
#include "gpio.h"
#include "LCD.h"
#include "distance.h"
#include "Bit_Utilities.h"




int main()

		GPIO_init();
        LCD_init();
	while(1)
	{
LCD_instructions(0x80);
switch(min_index){
	case 0:
	LCD_print_location(" Mosque",7,d[0]); break;
	case 1:
	LCD_print_location(" Arch",5,d[1]); break;
	case 2:
	LCD_print_location(" Hall A",7,d[2]); break;
	case 3:
	LCD_print_location(" Hall C",7,d[3]); break;
	case 4:
	LCD_print_location(" Library",8,d[4]); break;
	case 5:
	LCD_print_location(" Credit",7,d[5]); break;
	default:
		break;

}







	}


}

