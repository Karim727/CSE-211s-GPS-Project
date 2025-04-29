#ifndef UART
#define UART

#define UART_FR_TXFF   0x20   //UART TX fifo
#define UART_FR_RXFE  0x10    // FIFO empty flag
#define CB 0x2A								//HexaDecimal for (*)
///*	initialization	*///
void UART0_Init(void);

///*	used functions	*///
char UART0_getChar();
void UART0_OutChar(char data);
void UART0_OutString(char *pt);
void GetCommand_UART0(char *Command,int len );


#endif