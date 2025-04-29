#include "../../SERVICES/tm4c123gh6pm.h"
#include <stdint.h>
#include <string.h>
#include "UART.h"
#include "../../SERVICES/BIT.h"

#define CB 0x2A								//HexaDecimal for (*)

void UART0_Init(void){
	SET_BIT(SYSCTL_RCGCUART_R,6); //Activate UART6 
	SET_BIT(SYSCTL_RCGCGPIO_R,3); //Activate PortD
	
	while(GET_BIT(SYSCTL_PRGPIO_R,3)==0 );	
	
	UART6_CTL_R &= ~UART_CTL_UARTEN;	//Disable UART6
	UART6_IBRD_R = 0x68; //IBRD=int(160000000/(16*9600)) = 104;
	UART6_FBRD_R = 0xB;	//FBRD = int(0.166*64 +0.5) = 11
	UART6_LCRH_R = 0x0070;	// 8-bit word length, enable FIFO 001110000
	UART6_CTL_R = 0x0201; //enable RXE , and UART 001100000001
	
	GPIO_PORTD_AFSEL_R |= 0x30; //enable alt function PD4, PD5
	GPIO_PORTD_PCTL_R = ( GPIO_PORTD_PCTL_R & ~0x00FF0000 ) + 0x00110000; //configure UART for PD5,PD4
	GPIO_PORTD_DEN_R |= 0x30;	//enable digital I/O on PD4, PD5
	GPIO_PORTD_AMSEL_R &= ~0x30;	//disable analog function on PD4, PD5
}

#define UART_FR_TXFF   0x20   //UART TX fifo
#define UART_FR_RXFE  0x10    // FIFO empty flag

char UART6_getChar() {
		while((UART6_FR_R & UART_FR_RXFE) !=0);
	return (char) UART6_DR_R;
}


void UART6_OutChar(char data){
		while((UART6_FR_R & UART_FR_TXFF)!=0);
	UART6_DR_R=data;
}

void UART6_OutString(char *pt){
	while(*pt){
		UART6_OutChar(*pt);
		pt++;
	}
}

void GetCommand_UART6(char *Command,int len ){ 
		
		char character_UART6;
		int p;		
		for(p=0 ; p< len-1; p++){
			character_UART6 = UART6_getChar();
			if(character_UART6!=CB)
			{
				Command[p]=character_UART6;
			}
			else if(character_UART6==CB)
				break;		
		}
		Command[p] = '\0';
}