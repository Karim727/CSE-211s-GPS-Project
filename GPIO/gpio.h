void GPIO_initPortE (void);
void GPIO_initPortD (void);
void GPIO_initPortB (void);
void GPIO_init(void);


#define SYSCTL_RCGCUART_R       (*((volatile unsigned long *)0x400FE618))
#define SYSCTL_PRGPIO_R         (*((volatile unsigned long *)0x400FEA08))





#define GPIO_PORTB_LOCK_R       (*((volatile unsigned long *)0x40005520))
#define GPIO_PORTB_CR_R         (*((volatile unsigned long *)0x40005524))
#define GPIO_PORTB_AMSEL_R      (*((volatile unsigned long *)0x40005528))
#define GPIO_PORTB_PCTL_R       (*((volatile unsigned long *)0x4000552C))
#define GPIO_PORTB_DEN_R        (*((volatile unsigned long *)0x4000551C))
#define GPIO_PORTB_DIR_R        (*((volatile unsigned long *)0x40005400))
#define GPIO_PORTB_AFSEL_R      (*((volatile unsigned long *)0x40005420))




#define GPIO_PORTD_DEN_R        (*((volatile unsigned long *)0x4000751C))
#define GPIO_PORTD_LOCK_R       (*((volatile unsigned long *)0x40007520))
#define GPIO_PORTD_CR_R         (*((volatile unsigned long *)0x40007524))
#define GPIO_PORTD_AMSEL_R      (*((volatile unsigned long *)0x40007528))
#define GPIO_PORTD_PCTL_R       (*((volatile unsigned long *)0x4000752C))
#define GPIO_PORTD_AFSEL_R      (*((volatile unsigned long *)0x40007420))
#define GPIO_PORTD_DIR_R        (*((volatile unsigned long *)0x40007400))




#define GPIO_PORTE_DEN_R        (*((volatile unsigned long *)0x4002451C))
#define GPIO_PORTE_LOCK_R       (*((volatile unsigned long *)0x40024520))
#define GPIO_PORTE_CR_R         (*((volatile unsigned long *)0x40024524))
#define GPIO_PORTE_AMSEL_R      (*((volatile unsigned long *)0x40024528))
#define GPIO_PORTE_PCTL_R       (*((volatile unsigned long *)0x4002452C))
#define GPIO_PORTE_AFSEL_R      (*((volatile unsigned long *)0x40024420))
#define GPIO_PORTE_DIR_R        (*((volatile unsigned long *)0x40024400))