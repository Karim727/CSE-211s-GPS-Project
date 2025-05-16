
#include "hc05_uart_init.h"

void UART3_Init(void) {

    SYSCTL_RCGCUART_R |= 0x08;
    SYSCTL_RCGCGPIO_R |= 0x04;

    while((SYSCTL_PRUART_R & SYSCTL_PRUART_R3) == 0);
    while((SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R2) == 0);

    GPIO_PORTC_AFSEL_R |= 0xC0;   // Enable alt functions on PC6, PC7
    GPIO_PORTC_PCTL_R &= ~0xFF000000;
    GPIO_PORTC_PCTL_R |=  0x11000000;
    GPIO_PORTC_DEN_R   |= 0xC0;
    GPIO_PORTC_AMSEL_R &= ~0xC0;

    UART3_CTL_R = 0x0;
    UART3_IBRD_R = 104;  // Baud rate 9600
    UART3_FBRD_R = 11;
    UART3_LCRH_R = 0x60;
    UART3_CC_R = 0x0;
    UART3_CTL_R |= 0x301;   // Enable UART3, TXE and RXE
} 

void UART3_SendC(unsigned char data) {
    while((UART3_FR_R & UART_FR_TXFF));  // Wait until TX fifo is not full before giving it another byte
    UART3_DR_R = data;
}

void UART3_SendS(char *str) {
    while(*str) {
        UART3_SendC(*(str++));
    }
}

