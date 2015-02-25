#include <stdint.h>
#include "tms320f2802xx.h"


#ifdef FLASH
// Used for running BackGround in flash, and ISR in RAM
extern uint16_t * RamfuncsLoadStart, * RamfuncsLoadEnd, * RamfuncsRunStart;

static void memCopy(uint16_t * srcStartAddr, uint16_t * srcEndAddr, uint16_t * dstAddr)
{
	while( srcStartAddr <= srcEndAddr )
	{
		*dstAddr++ = *srcStartAddr++;
	}
}

#endif

#ifdef FLASH
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

void test(void)
{
	while( 1 )
	{
		GPATOGGLE = GPIO_MASK(0);
		GPATOGGLE = GPIO_MASK(0);
		GPATOGGLE = GPIO_MASK(1);
		GPATOGGLE = GPIO_MASK(1);
		GPATOGGLE = GPIO_MASK(2);
		GPATOGGLE = GPIO_MASK(2);
		GPATOGGLE = GPIO_MASK(3);
		GPATOGGLE = GPIO_MASK(3);
		GPATOGGLE = GPIO_MASK(0);
		GPATOGGLE = GPIO_MASK(0);
		GPATOGGLE = GPIO_MASK(1);
		GPATOGGLE = GPIO_MASK(1);
		GPATOGGLE = GPIO_MASK(2);
		GPATOGGLE = GPIO_MASK(2);
		GPATOGGLE = GPIO_MASK(3);
		GPATOGGLE = GPIO_MASK(3);
	}
}

int main(void)
{
	EALLOW();
	WDCR = WDCR_WDDIS_DISABLE | WDCR_WDCHK_KEY;
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
				CLKCTL_TMR2CLKPRESCALE_DIV2 |	
				CLKCTL_TMR2CLKSRCSEL_INTOSC1 |
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

#ifdef FLASH
	// Copy time critical code and Flash setup code to RAM
	// The RamfuncsLoadStart, RamfuncsLoadEnd, and RamfuncsRunStart
	// symbols are created by the linker. Refer to the linker files.
	memCopy((uint16_t *)&RamfuncsLoadStart, (uint16_t *)&RamfuncsLoadEnd, (uint16_t *)&RamfuncsRunStart);
#endif
	flash_config();
	EDIS();
	test();
}