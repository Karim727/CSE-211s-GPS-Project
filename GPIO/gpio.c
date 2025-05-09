#include "tm4c123gh6pm.h"
#include "Bit_Utilities.h"
#include "gpio.h"

void GPIO_initPortE (void) {

SET(SYSCTL_RCGCGPIO_R,0x10); // PortE clock enable
while ((SYSCTL_PRGPIO_R & 0x10)==0); //Delay
GPIO_PORTE_LOCK_R = 0x4C4F434B; // Unlock PortE Commit register
SET(GPIO_PORTE_CR_R,0x3E); // Allow changes 
CLR(GPIO_PORTE_AMSEL_R,0x3E); // Disable analog function
CLR(GPIO_PORTE_PCTL_R,0xFFFFFFFF); // GPIO clear bit PCTL
CLR(GPIO_PORTE_AFSEL_R,0x3E); // No alternate function
SET(GPIO_PORTE_DIR_R,0x3E); // Determine the direction
SET(GPIO_PORTE_DEN_R,0x3E); // Enable digital pins

}
void GPIO_initPortD (void) {

SET(SYSCTL_RCGCGPIO_R,0x08); // PortD clock enable
while ((SYSCTL_PRGPIO_R & 0x08)==0); //Delay
GPIO_PORTD_LOCK_R = 0x4C4F434B; // Unlock PortD Commit register
SET(GPIO_PORTD_CR_R,0x07); // Allow changes 
CLR(GPIO_PORTD_AMSEL_R,0x07); // Disable analog function
CLR(GPIO_PORTD_PCTL_R,0xFFFFFFFF); // GPIO clear bit PCTL
CLR(GPIO_PORTD_AFSEL_R,0x07); // No alternate function
SET(GPIO_PORTD_DIR_R,0x07); // determine direction
SET(GPIO_PORTD_DEN_R,0x07); // Enable digital pins
}
void GPIO_initPortB (void) {

SET(SYSCTL_RCGCGPIO_R,0x02); // PortB clock enable
while ((SYSCTL_PRGPIO_R & 0x02)==0); //Delay
GPIO_PORTB_LOCK_R = 0x4C4F434B; // Unlock PortB Commit register
SET(GPIO_PORTB_CR_R,0x1B); // Allow changes 
CLR(GPIO_PORTB_AMSEL_R,0x1B); // Disable analog function
CLR(GPIO_PORTB_PCTL_R,0xFFFFFFFF); // GPIO clear bit PCTL
CLR(GPIO_PORTB_AFSEL_R,0x1B); // No alternate function
SET(GPIO_PORTB_DIR_R,0x1B); // determine directions
SET(GPIO_PORTB_DEN_R,0x1B); // Enable digital pins

}

void GPIO_init(void){
GPIO_initPortB();
GPIO_initPortD();
GPIO_initPortE();
}
