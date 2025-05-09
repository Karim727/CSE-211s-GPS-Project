#ifndef UART
#define UART

//#define UART_FR_TXFF   0x20   //UART TX fifo
//#define UART_FR_RXFE  0x10    // FIFO empty flag
///*	initialization	*///
void UART0_Init(void);
void UART4_Init(void);
///*	used functions	*///
//char UART0_getChar();
void UART0_Rx(char data); 
char UART4_Tx(void);
//void GetCommand_UART0(char *Command,int len );


#endif
