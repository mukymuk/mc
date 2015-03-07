#include "global.h"
#include "tms320f2802xx.h"
#include "drv8301_reg.h"
#include "drv8301.h"

#ifndef CFG
#define CFG Debug
#endif

#ifdef FLASH
extern uint16_t RamfuncsLoadStart;
extern uint16_t RamfuncsLoadSize;
extern uint16_t RamfuncsRunStart;
#endif
extern uint16_t InitOnlyLoadStart;
extern uint16_t InitOnlyLoadSize;
extern uint16_t InitOnlyRunStart;

#pragma CODE_SECTION(flash_config,"ramfuncs")
static void flash_config( void )
{
	// this has to be executed out of RAM.
	uint16_t delay = 3;
	FBANKWAIT = FBANKWAIT_PAGEWAIT(2)|FBANKWAIT_RANDWAIT(2);
	FOPT = FOPT_ENPIPE_ENABLE;
	while( delay-- );
}

void interrupt isr_stub( void )
{
	ESTOP0();
}


/*
#pragma CODE_SECTION(isr_cpu_timer2,"ramfuncs")
void interrupt isr_cpu_timer2( void )
{
	static int16_t	cmp;
	static int16_t step = 100;

	GPATOGGLE = GPA_MASK(3);
	cmp += step;
	if(  cmp > 2000 )
	{
		cmp = 2000;
		step = -step;
		cmp += step;
	}
	else if(  cmp < 0 )
	{
		cmp = 0;
		step = -step;
		cmp += step;
	}
	CMPA(1) = cmp;
}
*/

int main(void)
{
	EALLOW();
	DINT();
	IER = 0;
	IFR = 0;

	WDCR = WDCR_WDCHK_KEY | WDCR_WDDIS_DISABLE;

#if CFG==Debug
	Device_cal();
#endif

	CLKCTL =	CLKCTL_NMIRESETSEL_MCLKHS |
				CLKCTL_XTALOSCOFF_OFF |
				CLKCTL_XCLKINOFF_OFF |
				CLKCTL_WDHALTI_ON |
				CLKCTL_INTOSC2HALTI_ON |
				CLKCTL_INTOSC2OFF_OFF |
				CLKCTL_INTOSC1HALTI_ON |
				CLKCTL_INTOSC1OFF_ON |
				CLKCTL_TMR2CLKPRESCALE_DIV1 |			// CPU Timer 2 souce clock =
				CLKCTL_TMR2CLKSRCSEL_SYSCLKOUT |		// 60MHz
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
	XCLK = XCLK_XCLKINSEL_GPIO19 | XCLK_XCLKOUTDIV_DIV1;

#ifdef FLASH
	memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (int16_t)&RamfuncsLoadSize);
//	memcpy(&InitOnlyRunStart, &InitOnlyLoadStart, (int16_t)&InitOnlyLoadSize);
#endif

	flash_config();

	uint16_t i;
	for (i=0;i<128;i++)
	{
		PIE_IVT[i] = isr_stub;
	}
	// PIE_IVT[IV_TIMER2] = isr_cpu_timer2;

	drv8301_init();


//	SET_TIMER_PRESCALE(2,60000);	// timer2 = 1ms tick rate
//	SET_TIMER_PERIOD(2,100);	// 10Hz
//	TIMERTCR(2) = TIMERTCR_TIE_ENABLE | TIMERTCR_FREE_SOFT_HARDSTOP | TIMERTCR_TRB_RELOAD | TIMERTCR_TSS_RUNNING;

/*
		// Enable PWM clock
	PCLKCR1 = 	PCLKCR1_ECAP1ENCLK_DISABLE |
				PCLKCR1_EPWM4ENCLK_DISABLE |
				PCLKCR1_EPWM3ENCLK_DISABLE |
				PCLKCR1_EPWM2ENCLK_DISABLE |
				PCLKCR1_EPWM1ENCLK_ENABLE;

	TBCTL(1) =	TBCTL_FREE_SOFT_FREE_RUN |
				TBCTL_PHSDIR_COUNT_DOWN |
				TBCTL_CLKDIV_1 |
				TBCTL_HSPCLKDIV_2 |
				TBCTL_SYNCOSEL_CTR_ZERO |
				TBCTL_PRDLD_IMMEDIATE |
				TBCTL_PHSEN_NOLOAD |
				TBCTL_CTRMODE_UP_COUNT;

	AQCTLA(1) = AQCTL_CBD_DISABLE |
				AQCTL_CBU_DISABLE |
				AQCTL_CAD_DISABLE |
				AQCTL_CAU_SET |
				AQCTL_PRD_TOGGLE |
				AQCTL_ZRO_DISABLE;

	TBPRD(1) = 6000;
	CMPA(1) = 0;
	TBCTR(1) = 0;

	PCLKCR0 = 	PCLKCR0_SCIAENCLK_DISABLE |
				PCLKCR0_SPIAENCLK_DISABLE |
				PCLKCR0_I2CAENCLK_DISABLE |
				PCLKCR0_ADCENCLK_DISABLE |
				PCLKCR0_TBCLKSYNC_ENABLE |
				PCLKCR0_HRPWMENCLK_DISABLE;
*/
	PIECTRL = PIECTRL_ENPIE_ENABLE;
	PIEACK = PIEACK_ACK_ALL;

	IER = CPU_INT14|CPU_INT1;
	IFR = 0;
	EDIS();
	ERTM();
	EINT();
	volatile uint16_t z;
	while( 1 )
	{
		GPACLEAR = GPA_MASK(19);
		SPITXBUF = DRV8301_COMAMND(READ,STATUS2,0);
		while( SPIFFRX & SPIFFRX_RXFIFO_STATUS_MASK )
		{
			z = SPIRXBUF;
		}
		GPASET = GPA_MASK(19);

	}
}


