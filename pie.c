#include <stdint.h>
#include "tms320f2802xx.h"
#include "pie.h"


typedef void interrupt (*PISR)(void);


#define COUNT_OF(x)	(sizeof(x)/sizeof(*x))

#pragma CODE_SECTION(isr_cpu_timer2,"ramfuncs")
void interrupt isr_cpu_timer2( void )
{
	GPATOGGLE = GPIO_MASK(0);
}


void interrupt isr_stub( void )
{
	while( 1 )
	{
	}
}

static const PISR s_ivt[128] =
{
	isr_stub,		// unused
	isr_stub,
	isr_stub,
	isr_stub,
	isr_stub,
	isr_stub,
	isr_stub,
	isr_stub,
	isr_stub,
	isr_stub,
	isr_stub,
	isr_stub,
	isr_stub,

	isr_stub,		// External Interrupt 13 (XINT13) or CPU-Timer1
	isr_cpu_timer2,	// CPU-Timer2
	isr_stub,		// CPU Data Logging Interrupt
	isr_stub,		// CPU Real-Time OS Interrupt
	isr_stub,		// CPU Emulation Interrupt 
	isr_stub,		// External Non-Maskable Interrupt 
	isr_stub,		// Illegal Operation 
	isr_stub,		// User-Defined Trap 1
	isr_stub,		// User-Defined Trap 2
	isr_stub,		// User-Defined Trap 3
	isr_stub,		// User-Defined Trap 4
	isr_stub,		// User-Defined Trap 5
	isr_stub,		// User-Defined Trap 6
	isr_stub,		// User-Defined Trap 7
	isr_stub,		// User-Defined Trap 8
	isr_stub,		// User-Defined Trap 9
	isr_stub,		// User-Defined Trap 10
	isr_stub,		// User-Defined Trap 11
	isr_stub,		// User-Defined Trap 12 
				
	// Group 1

	isr_stub,		// ADCINT1
	isr_stub,		// ADCINT2
	isr_stub,		// reserved
	isr_stub,		// XINT1
	isr_stub,		// XINT2
	isr_stub,		// ADCINT9
	isr_stub,		// TINT0
	isr_stub,		// WAKEINT

	// Group 2

	isr_stub,		// EPWM1_TZINT
	isr_stub,		// EPWM2_TZINT
	isr_stub,		// EPWM3_TZINT
	isr_stub,		// EPWM4_TZINT
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved

	// Group 3

	isr_stub,		// EPWM1_INT
	isr_stub,		// EPWM2_INT
	isr_stub,		// EPWM3_INT
	isr_stub,		// EPWM4_INT
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved

	// Group 4

	isr_stub,		// ECAP1_INT
	isr_stub,		// reserved
	isr_stub,		// reserved		
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved

	// Group 5
	isr_stub,		// EQEP1_INT
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved

	// Group 6

	isr_stub,		// SPIRXINTA
	isr_stub,		// SPIRXINTA
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved

	// Group 7

	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved

	// Group 8

	isr_stub,		// I2CINT1A
	isr_stub,		// I2CINT2A
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved

	// Group 9

	isr_stub,		// SCIRXINTA
	isr_stub,		// SCITXINTA
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved

	// Group 10

	isr_stub,		// ADCINT1
	isr_stub,		// ADCINT2
	isr_stub,		// ADCINT3
	isr_stub,		// ADCINT4
	isr_stub,		// ADCINT5
	isr_stub,		// ADCINT6
	isr_stub,		// ADCINT7
	isr_stub,		// ADCINT8

	// Group 11

	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved

	// Group 12

	isr_stub,		// XINT3
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub,		// reserved
	isr_stub		// reserved
};

void pie_init(void)
{
	memcpy( PIE_IVT,s_ivt,sizeof(s_ivt) );
	PIECTRL = PIECTRL_ENPIE_ENABLE;
	PIEACK = PIEACK_ACK_ALL;
}


