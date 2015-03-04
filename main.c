#include <stdint.h>
#include "tms320f2802xx.h"

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

void interrupt isr_stub( void )
{
	ESTOP0();
}

#pragma CODE_SECTION(flash_config,"ramfuncs")
static void flash_config( void )
{
	// this has to be executed out of RAM.
	uint16_t delay = 3;
	FBANKWAIT = FBANKWAIT_PAGEWAIT(2)|FBANKWAIT_RANDWAIT(2);
	FOPT = FOPT_ENPIPE_ENABLE;
	while( delay-- );
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

#pragma CODE_SECTION(s3_button_isr,"ramfuncs")
void interrupt s3_button_isr( void )
{
	PIEACK = PIEACK_INT1;
}

static void drv8301_init( void )
{
	GPAMUX1 =   GPAMUX1_GPIO0_EPWM1A |		// PWM_AH / D2
				GPAMUX1_GPIO1_EPWM1B |		// PWM_AL / D4
				GPAMUX1_GPIO2_EPWM2A |		// PWM_BH / D3
				GPAMUX1_GPIO3_EPWM2B |		// PWM_BL / D5
				GPAMUX1_GPIO4_EPWM3A |		// PWM_CH
				GPAMUX1_GPIO5_EPWM3B |		// PWM_CL
				GPAMUX1_GPIO6_GPIO |		// EN_GATE (output)
				GPAMUX1_GPIO7_GPIO |		// DC_CAL (output)
				GPAMUX1_GPIO12_GPIO;		// S3

	GPAMUX2 = 	
				GPAMUX2_GPIO16_SPISIMOA |	// M_OC_SDI
				GPAMUX2_GPIO17_SPISOMIA |	// GAIN_SDO
				GPAMUX2_GPIO18_SPICLKA |	// SCLK
				GPAMUX2_GPIO19_GPIO |		// M_PWM_SCS (output)
				GPAMUX2_GPIO28_GPIO |		// FAULT* (OC input)
				GPAMUX2_GPIO29_GPIO;		// OCTW* (OC input)

	GPBMUX1 =	GPBMUX1_GPIO32_GPIO |		// connected to GPIO16
				GPBMUX1_GPIO33_GPIO |		// connected to GPIO17
				GPBMUX1_GPIO34_GPIO |		// S1.1
				GPBMUX1_GPIO35_GPIO |		// internal
				GPBMUX1_GPIO36_GPIO |		// internal
				GPBMUX1_GPIO37_GPIO |		// internal
				GPBMUX1_GPIO38_GPIO;		// internal

	GPASET = 	0;
	GPBSET = 	0;

	GPADIR =	GPADIR_OUTPUT(0) |			// PWM_AH / D2
				GPADIR_OUTPUT(1) |			// PWM_AL / D4
				GPADIR_OUTPUT(2) |			// PWM_BH / D3
				GPADIR_OUTPUT(3) |			// PWM_BL / D5
				GPADIR_OUTPUT(4) |			// PWM_CH
				GPADIR_OUTPUT(5) |			// PWM_CL
				GPADIR_OUTPUT(6) |			// EN_GATE (output)
				GPADIR_OUTPUT(7) |			// DC_CAL (output)
				GPADIR_OUTPUT(8) |			// internal
				GPADIR_OUTPUT(9) |  		// internal
				GPADIR_OUTPUT(10) | 		// internal
				GPADIR_OUTPUT(11) | 		// internal
				GPADIR_INPUT(12) | 			// S3
				GPADIR_OUTPUT(13) | 		// internal
				GPADIR_OUTPUT(14) | 		// internal
				GPADIR_OUTPUT(15) | 		// internal
				GPADIR_OUTPUT(16) | 		// M_OC_SDI
				GPADIR_INPUT(17)  | 		// GAIN_SDO
				GPADIR_OUTPUT(18) | 		// SCLK
				GPADIR_OUTPUT(19) | 		// M_PWM_SCS (output)
				GPADIR_OUTPUT(20) | 		// internal
				GPADIR_OUTPUT(21) | 		// internal
				GPADIR_OUTPUT(22) | 		// internal
				GPADIR_OUTPUT(23) | 		// internal
				GPADIR_OUTPUT(24) | 		// internal
				GPADIR_OUTPUT(25) | 		// internal
				GPADIR_OUTPUT(26) | 		// internal
				GPADIR_OUTPUT(27) | 		// internal
				GPADIR_INPUT(28)  | 		// FAULT* (OC input)
				GPADIR_INPUT(29)  | 		// OCTW* (OC input)
				GPADIR_OUTPUT(30) | 		// internal
				GPADIR_OUTPUT(31);  		// internal

	GPBDIR =	GPBDIR_INPUT(32) |			// connected to GPIO16
				GPBDIR_INPUT(33) |			// connected to GPIO17
				GPBDIR_INPUT(34) |			// S1.1
				GPBDIR_OUTPUT(35) |			// internal
				GPBDIR_OUTPUT(36) |			// internal
				GPBDIR_INPUT(37)  |			// internal
				GPBDIR_INPUT(38);			// internal

	GPAPUD = 	GPAPUD_DISABLE(0) 	| 		// PWM_AH / D2
				GPAPUD_DISABLE(1) 	|   	// PWM_AL / D4
				GPAPUD_DISABLE(2) 	|   	// PWM_BH / D3
				GPAPUD_DISABLE(3) 	|   	// PWM_BL / D5
				GPAPUD_DISABLE(4) 	|   	// PWM_CH
				GPAPUD_DISABLE(5) 	|   	// PWM_CL
				GPAPUD_DISABLE(6) 	|		// EN_GATE (output)
				GPAPUD_DISABLE(7) 	|		// DC_CAL (output)
				GPAPUD_DISABLE(8)	|		// internal
				GPAPUD_DISABLE(9)	|		// internal
				GPAPUD_DISABLE(10)	|		// internal
				GPAPUD_DISABLE(11)	|		// internal
				GPAPUD_DISABLE(12)	|		// S3
				GPAPUD_DISABLE(13)	|		// internal
				GPAPUD_DISABLE(14)	|		// internal
				GPAPUD_DISABLE(15)  |		// internal
				GPAPUD_DISABLE(16)  |		// M_OC_SDI
				GPAPUD_DISABLE(17)  |		// GAIN_SDO
				GPAPUD_DISABLE(18)	|		// SCLK
				GPAPUD_DISABLE(19)  |		// M_PWM_SCS (output)
				GPAPUD_DISABLE(20)	|		// internal
				GPAPUD_DISABLE(21)	|		// internal
				GPAPUD_DISABLE(22)	|		// internal
				GPAPUD_DISABLE(23)	|		// internal
				GPAPUD_DISABLE(24)	|		// internal
				GPAPUD_DISABLE(25)	|		// internal
				GPAPUD_DISABLE(26)	|		// internal
				GPAPUD_DISABLE(27)	|		// internal
				GPAPUD_ENABLE(28)	|		// FAULT* (OC input)
				GPAPUD_ENABLE(29)	|		// OCTW* (OC input)
				GPAPUD_DISABLE(30)	|		// internal
				GPAPUD_DISABLE(31);			// internal

	GPBPUD =	GPBPUD_DISABLE(32)  |	 	// connected to GPIO16
				GPBPUD_DISABLE(33)  |		// connected to GPIO17
				GPBPUD_DISABLE(34)  |		// S1.1
				GPBPUD_DISABLE(35)  |		// internal
				GPBPUD_DISABLE(36)  |		// internal
				GPBPUD_DISABLE(37)  |		// internal
				GPBPUD_DISABLE(38);			// internal

	GPIOXINT1SEL = GPIOXINTSEL_GPIO(12);
	PIE_IVT[IV_XINT1] = s3_button_isr;
	PIEIER1 = PIEIER_INT4;
	XINT1CR = XINTCR_POLARITY_BOTH | XINTCR_INTERRUPT_ENABLE;


}

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

	PIECTRL = PIECTRL_ENPIE_ENABLE;
	PIEACK = PIEACK_ACK_ALL;

	IER = CPU_INT14|CPU_INT1;
	IFR = 0;
	EDIS();
	ERTM();
	EINT();

	while( 1 )
	{
	}
}


