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


static void drv8301_init( void )
{
	GPBMUX1 = 	GPBMUX1_GPIO38_GPIO |		// internal
				GPBMUX1_GPIO37_GPIO |		// internal
				GPBMUX1_GPIO36_GPIO |		// internal
				GPBMUX1_GPIO35_GPIO |		// internal
				GPBMUX1_GPIO34_GPIO |		// S1.1
				GPBMUX1_GPIO33_GPIO |		// connected to GPIO17
				GPBMUX1_GPIO32_GPIO;		// connected to GPIO16

	GPAMUX2 = 	GPAMUX2_GPIO29_GPIO |		// OCTW* (OC input)
				GPAMUX2_GPIO28_GPIO |		// FAULT* (OC input)
				GPAMUX2_GPIO19_GPIO |		// M_PWM_SCS (output)
				GPAMUX2_GPIO18_SPICLKA |	// SCLK
				GPAMUX2_GPIO17_SPISOMIA |	// GAIN_SDO
				GPAMUX2_GPIO16_SPISIMOA;	// M_OC_SDI
	GPAMUX1 = 	GPAMUX1_GPIO12_GPIO |
				GPAMUX1_GPIO7_GPIO |		// DC_CAL (output)
				GPAMUX1_GPIO6_GPIO |		// EN_GATE (output)
				GPAMUX1_GPIO5_EPWM3B |		// PWM_CL
				GPAMUX1_GPIO4_EPWM3A |		// PWM_CH
				GPAMUX1_GPIO3_EPWM2B |		// PWM_BL
				GPAMUX1_GPIO2_EPWM2A |		// PWM_BH
				GPAMUX1_GPIO1_EPWM1B |		// PWM_AL
				GPAMUX1_GPIO0_EPWM1A;		// PWM_AH

	GPADIR =	GPADIR_OUTPUT(0) |
				GPADIR_OUTPUT(1) |
				GPADIR_OUTPUT(2) |
				GPADIR_OUTPUT(3) |
				GPADIR_OUTPUT(4) |
				GPADIR_OUTPUT(5) |
				GPADIR_OUTPUT(6) |
				GPADIR_OUTPUT(7) |
				GPADIR_OUTPUT(8) |
				GPADIR_OUTPUT(9) |
				GPADIR_OUTPUT(10) |
				GPADIR_OUTPUT(11) |
				GPADIR_OUTPUT(12) |
				GPADIR_OUTPUT(13) |
				GPADIR_OUTPUT(14) |
				GPADIR_OUTPUT(15) |
				GPADIR_OUTPUT(16) |
				GPADIR_INPUT(17)  |
				GPADIR_OUTPUT(18) |
				GPADIR_OUTPUT(19) |
				GPADIR_OUTPUT(20) |
				GPADIR_OUTPUT(21) |
				GPADIR_OUTPUT(22) |
				GPADIR_OUTPUT(23) |
				GPADIR_OUTPUT(24) |
				GPADIR_OUTPUT(25) |
				GPADIR_OUTPUT(26) |
				GPADIR_OUTPUT(27) |
				GPADIR_INPUT(28)  |
				GPADIR_INPUT(29)  |
				GPADIR_OUTPUT(30) |
				GPADIR_OUTPUT(31);

	GPAPUD = 	GPAPUD_DISABLE(0) 	| 		// PMW's
				GPAPUD_DISABLE(1) 	|
				GPAPUD_DISABLE(2) 	|
				GPAPUD_DISABLE(3) 	|
				GPAPUD_DISABLE(4) 	|
				GPAPUD_DISABLE(5) 	|
				GPAPUD_DISABLE(6) 	|		// EN_GATE (output)
				GPAPUD_DISABLE(7) 	|		// DC_CAL (output)
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

	GPBPUD =	GPBPUD_DISABLE(38)  |		// internal
				GPBPUD_DISABLE(37)  |		// internal
				GPBPUD_DISABLE(36)  |		// internal
				GPBPUD_DISABLE(35)  |		// internal
				GPBPUD_DISABLE(34)  |		// S1.1
				GPBPUD_DISABLE(33)  |		// connected to GPIO17
				GPBPUD_DISABLE(32);			// connected to GPIO16

	GPADIR = GPADIR_OUTPUT(0)|GPADIR_OUTPUT(1)|GPADIR_OUTPUT(2)|GPADIR_OUTPUT(3);
	GPASET = GPA_MASK(0)|GPA_MASK(1)|GPA_MASK(2)|GPA_MASK(3);
}

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
	XCLK = XCLK_XCLKINSEL_GPIO38 | XCLK_XCLKOUTDIV_DIV1;
	GPAMUX2 = 	GPAMUX2_GPIO29_GPIO |
				GPAMUX2_GPIO28_GPIO |
				GPAMUX2_GPIO19_GPIO |
				GPAMUX2_GPIO18_XCLKOUT;
	GPAMUX1 = 	GPAMUX1_GPIO12_GPIO |
				GPAMUX1_GPIO7_GPIO |
				GPAMUX1_GPIO6_GPIO |
				GPAMUX1_GPIO5_GPIO |
				GPAMUX1_GPIO4_GPIO |
				GPAMUX1_GPIO3_GPIO |
				GPAMUX1_GPIO2_GPIO |
				GPAMUX1_GPIO1_GPIO |
				GPAMUX1_GPIO0_EPWM1A;
	GPAPUD = 	GPAPUD_DISABLE(0)|GPAPUD_DISABLE(1)|GPAPUD_DISABLE(2)|GPAPUD_DISABLE(3);
	GPADIR = GPADIR_OUTPUT(0)|GPADIR_OUTPUT(1)|GPADIR_OUTPUT(2)|GPADIR_OUTPUT(3);
	GPASET = GPA_MASK(0)|GPA_MASK(1)|GPA_MASK(2)|GPA_MASK(3);



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
	EINT();
	ERTM();
	EDIS();

	while( 1 )
	{
	}
}


