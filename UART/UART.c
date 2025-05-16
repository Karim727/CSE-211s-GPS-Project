#include <stdint.h>
#include <string.h>


#include "UART.h"
#include "Bit_Utilities.h"



void UART0_Init(void){
	SET_BIT(SYSCTL_RCGCUART_R,0); //Activate UART0
	SET_BIT(SYSCTL_RCGCGPIO_R,0);  //Activate PortA
	
	while(GET_BIT(SYSCTL_PRGPIO_R,0)==0);
	
	UART0_CTL_R &= ~(0x0001);	//Disable UART0
	UART0_IBRD_R = 0x68; //IBRD=int(160000000/(16*9600)) = 104;
	UART0_FBRD_R = 0xB;	//FBRD = int(0.166*64 +0.5) = 11
	UART0_LCRH_R = 0x0070;	// 8-bit word length, enable FIFO 001110000
	UART0_CTL_R = 0x0301; //enable RXE , and UART 001100000001
	
	GPIO_PORTA_AFSEL_R |= 0x03; //enable alt function PA0, PA1
	GPIO_PORTA_PCTL_R = ( GPIO_PORTA_PCTL_R & 0xFFFFFF00 ) + 0x00000011; //configure UART for PA0,PA1
	GPIO_PORTA_DEN_R |= 0x03;	//enable digital I/O on PA0, PA1
	GPIO_PORTA_AMSEL_R &= ~0x03;	//disable analog function on PA0, PA1

}

void UART4_Init(void){
    SET_BIT(SYSCTL_RCGCUART_R,4); //Activate UART4
    SET_BIT(SYSCTL_RCGCGPIO_R,2); //Activate PortC

    while(GET_BIT(SYSCTL_PRGPIO_R,2)==0 );

    UART4_CTL_R &= ~(1 << 0);    //Disable UART4
    UART4_IBRD_R = 0x68; //
    UART4_FBRD_R = 0xB;    
    UART4_LCRH_R = 0x0070;    // 8-bit word length, enable FIFO
    UART4_CTL_R = (1 << 9) | (1 << 8) | (1 << 0); //enable RXE, TXE and UART

    GPIO_PORTC_AFSEL_R |= 0x30; //enable alt function PC4, PC5
    GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R & ~0x00FF0000) + 0x00110000; //configure UART for PC5(Tx),PC4(Rx)
    GPIO_PORTC_DEN_R |= 0x30;    //enable digital I/O on PC4, PC5
    GPIO_PORTC_AMSEL_R &= ~0x30;    //disable analog function on PC4, PC5
}





// UART0 RX_data // Needed for Showing the Output on PC's terminal
void UART0_Rx(char data) {
    while((UART0_FR_R & 0x0020) != 0); // Wait if full
    UART0_DR_R = data;
}


// UART4 TX_data
char UART4_Tx(void) {
    while((UART4_FR_R & 0x10) != 0);  // Wait if empty
    return (char)(UART4_DR_R & 0xFF);
}

