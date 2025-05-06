#ifndef Bit_Utilites
#define Bit_Utilites

#include <stdint.h>


#ifdef __cplusplus
extern "C"{
#endif

	
static void delay_ms(uint32_t ms);


#define GET_BIT(reg1,bit)		((reg1>>bit)&1)
#define GET_REG(reg)			(reg&0xff)

#define SET(reg,val)			reg|=val
#define SET_BIT(reg,val)		reg|=(1<<val)

#define CLR(reg,val)			reg &=~val
#define CLR_BIT(reg,val)		reg &=~(1<<val)

#define CHECK_REG(reg1,reg2)		((reg1&reg2))

#ifdef __cplusplus
}
#endif

#endif
