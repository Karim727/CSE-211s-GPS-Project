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



#define SYSCTL_RCGCUART_R       (*((volatile unsigned long *)0x400FE618))
#define SYSCTL_RCGCGPIO_R       (*((volatile unsigned long *)0x400FE608))


#define UART0_CTL_R             (*((volatile unsigned long *)0x4000C030))
#define UART0_IBRD_R            (*((volatile unsigned long *)0x4000C024))
#define UART0_FBRD_R            (*((volatile unsigned long *)0x4000C028))
#define UART0_LCRH_R            (*((volatile unsigned long *)0x4000C02C))
#define UART0_FR_R              (*((volatile unsigned long *)0x4000C018))
#define UART0_DR_R              (*((volatile unsigned long *)0x4000C000))


#define GPIO_PORTA_DEN_R        (*((volatile unsigned long *)0x4000451C))
#define GPIO_PORTA_AMSEL_R      (*((volatile unsigned long *)0x40004528))
#define GPIO_PORTA_PCTL_R       (*((volatile unsigned long *)0x4000452C))
#define GPIO_PORTA_AFSEL_R      (*((volatile unsigned long *)0x40004420))


#define UART4_DR_R              (*((volatile unsigned long *)0x40010000))
#define UART4_FR_R              (*((volatile unsigned long *)0x40010018))
#define UART4_IBRD_R            (*((volatile unsigned long *)0x40010024))
#define UART4_FBRD_R            (*((volatile unsigned long *)0x40010028))
#define UART4_LCRH_R            (*((volatile unsigned long *)0x4001002C))
#define UART4_CTL_R             (*((volatile unsigned long *)0x40010030))


#define GPIO_PORTC_AMSEL_R      (*((volatile unsigned long *)0x40006528))
#define GPIO_PORTC_PCTL_R       (*((volatile unsigned long *)0x4000652C))
#define GPIO_PORTC_DEN_R        (*((volatile unsigned long *)0x4000651C))
#define GPIO_PORTC_AFSEL_R      (*((volatile unsigned long *)0x40006420))



#endif
