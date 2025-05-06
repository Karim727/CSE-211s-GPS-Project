#include <stdint.h>
#include "tm4c123gh6pm.h"


#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define CYCLES_PER_LOOP 3UL

static void delay_ms(uint32_t ms){
	uint64_t total_cycles = (uint64_t)F_CPU*ms/1000UL;
	uint32_t loops = (uint32_t)(total_cycles/CYCLES_PER_LOOP);
	while(loops--){
		__asm volatile("nop");
	}
}