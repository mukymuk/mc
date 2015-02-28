#include <stdint.h>
#include "tms320f2802xx.h"
#include "pie.h"

#ifdef FLASH
extern uint16_t RamfuncsLoadStart;
extern uint16_t RamfuncsLoadSize;
extern uint16_t RamfuncsRunStart;
extern uint16_t InitOnlyLoadStart;
extern uint16_t InitOnlyLoadSize;
extern uint16_t InitOnlyRunStart;

//#pragma CODE_SECTION(test,"ramfuncs")
#pragma CODE_SECTION(flash_config,"ramfuncs")
#endif
static void flash_config( void )
{
	// this has to be executed out of RAM.
	uint16_t delay = 3;
	FBANKWAIT = FBANKWAIT_PAGEWAIT(2)|FBANKWAIT_RANDWAIT(2);
	FOPT = FOPT_ENPIPE_ENABLE;
	while( delay-- );
}

int main(void)
{
	EALLOW();
	DINT();
	IER = 0;
	IFR = 0;

	Device_cal();

	CLKCTL =	CLKCTL_NMIRESETSEL_MCLKHS |
				CLKCTL_XTALOSCOFF_OFF |
				CLKCTL_XCLKINOFF_OFF |
				CLKCTL_WDHALTI_ON |
				CLKCTL_INTOSC2HALTI_ON |
				CLKCTL_INTOSC2OFF_OFF |
				CLKCTL_INTOSC1HALTI_ON |
				CLKCTL_INTOSC1OFF_ON |
				CLKCTL_TMR2CLKPRESCALE_DIV1 |	
				CLKCTL_TMR2CLKSRCSEL_SYSCLKOUT |
				CLKCTL_WDCLKSRCSEL_INTOSC1 |
				CLKCTL_OSCCLKSRC2SEL_INTOSC2 |
				CLKCTL_OSCCLKSRCSEL_INTOSC1;
	LOSPCP = 	LOSPCP_LSPCLK_DIV1;
	if( (PLLSTS & PLLSTS_MCLKSTS_MASK) == PLLSTS_MCLKSTS_MISSING )
	{
		PLLSTS |= PLLSTS_MCLKCLR_RESET;
		ESTOP0();
	}
	if( (PLLSTS & PLLSTS_DIVSEL_MASK) )
	{
		PLLSTS &= ~PLLSTS_DIVSEL_MASK;
	}
	PLLSTS = (PLLSTS & PLLSTS_MCLKOFF_MASK) | PLLSTS_MCLKOFF_DISABLE;
	PLLCR = PLLCR_DIV_12;
	while( PLLSTS & PLLSTS_PLLLOCKS_LOCKING );
	PLLSTS = (PLLSTS & (PLLSTS_MCLKOFF_MASK|PLLSTS_DIVSEL_MASK)) | PLLSTS_MCLKOFF_ENABLE|PLLSTS_DIVSEL_DIV2;
	XCLK = XCLK_XCLKINSEL_GPIO38 | XCLK_XCLKOUTDIV_DIV1;
	GPAMUX2 = GPAMUX2_GPIO18_XCLKOUT;

	GPADIR = (GPADIR & (GPIO_MASK(0)|GPIO_MASK(1)|GPIO_MASK(2)|GPIO_MASK(3))) | 
			(GPIO_OUTPUT(0)|GPIO_OUTPUT(1)|GPIO_OUTPUT(2)|GPIO_OUTPUT(3));

	GPASET = GPIO_MASK(0)|GPIO_MASK(1)|GPIO_MASK(2)|GPIO_MASK(3);

#ifdef FLASH
	memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (int16_t)&RamfuncsLoadSize);
//	memcpy(&InitOnlyRunStart, &InitOnlyLoadStart, (int16_t)&InitOnlyLoadSize);
#endif

	flash_config();
	pie_init();

	SET_TIMER_PRESCALE(2,60000);	// timer2 = 1ms tick rate
	SET_TIMER_PERIOD(2,100);	// 10Hz
	TIMERTCR(2) = TIMERTCR_TIE_ENABLE | TIMERTCR_FREE_SOFT_HARDSTOP | TIMERTCR_TRB_RELOAD | TIMERTCR_TSS_RUNNING;

	pie_init();
	IER = CPU_INT14;
	IFR = 0;
	EINT();
	ERTM();
	EDIS();

	while( 1 )
	{
	}
}


