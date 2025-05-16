#ifndef HC05_UART_INIT_H
#define HC05_UART_INIT_H


void UART3_Init(void); //initialize Uart3 for HC-05 bluetooth module
void UART3_SendC(unsigned char data);  //send a character via Uart5
void UART3_SendS(char *str);  //send a string via Uart3


// System Control Registers (SYSCTL)
#define SYSCTL_RCGCUART_R    (*((volatile uint32_t *)0x400FE618)) // UART Run Mode Clock Gating Control
#define SYSCTL_RCGCGPIO_R    (*((volatile uint32_t *)0x400FE608)) // GPIO Run Mode Clock Gating Control
#define SYSCTL_PRUART_R       (*((volatile uint32_t *)0x400FEA18)) // UART Peripheral Ready
#define SYSCTL_PRGPIO_R       (*((volatile uint32_t *)0x400FEA08)) // GPIO Peripheral Ready

// UART3 Registers
#define UART3_DR_R           (*((volatile uint32_t *)0x4000D000)) // Data Register
#define UART3_FR_R           (*((volatile uint32_t *)0x4000D018)) // Flag Register
#define UART3_IBRD_R         (*((volatile uint32_t *)0x4000D024)) // Integer Baud-Rate Divisor
#define UART3_FBRD_R         (*((volatile uint32_t *)0x4000D028)) // Fractional Baud-Rate Divisor
#define UART3_LCRH_R         (*((volatile uint32_t *)0x4000D02C)) // Line Control
#define UART3_CTL_R          (*((volatile uint32_t *)0x4000D030)) // Control
#define UART3_CC_R           (*((volatile uint32_t *)0x4000DFC8)) // Clock Configuration

// GPIO Port C Registers
#define GPIO_PORTC_AFSEL_R   (*((volatile uint32_t *)0x40006420)) // Alternate Function Select
#define GPIO_PORTC_PCTL_R    (*((volatile uint32_t *)0x4000652C)) // Port Control
#define GPIO_PORTC_DEN_R     (*((volatile uint32_t *)0x4000651C)) // Digital Enable
#define GPIO_PORTC_AMSEL_R   (*((volatile uint32_t *)0x40006528)) // Analog Mode Select

#endif


