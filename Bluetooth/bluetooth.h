#ifndef HC05_UART_INIT_H
#define HC05_UART_INIT_H


void UART3_Init(void); //initialize Uart3 for HC-05 bluetooth module
void UART3_SendC(unsigned char data);  //send a character via Uart5
void UART3_SendS(char *str);  //send a string via Uart3

#endif


