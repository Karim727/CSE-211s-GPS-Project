#ifndef UART
#define UART


///*	initialization	*///
void UART0_Init(void);

///*	used functions	*///
char UART0_getChar();
void UART0_OutChar(char data);
void UART0_OutString(char *pt);
void GetCommand_UART0(char *Command,int len );


#endif