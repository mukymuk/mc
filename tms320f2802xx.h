
#define  EINT()   asm(" clrc INTM")
#define  DINT()   asm(" setc INTM")
#define  ERTM()   asm(" clrc DBGM")
#define  DRTM()   asm(" setc DBGM")
#define  EALLOW() asm(" EALLOW")
#define  EDIS()   asm(" EDIS")
#define  ESTOP0()  asm(" ESTOP0")
#define  IDLE90()  asm(" IDLE")

extern cregister volatile unsigned int IFR;
extern cregister volatile unsigned int IER;

#define Device_cal() ((void(*)(void))0x3D7C80)()

// SPRUFN3D
// TMS320F2802x/TMS320F2802xx Piccolo System Control and Interrupts

#define LOSPCP		(*((volatile uint16_t*)0x00701B))

#define LOSPCP_LSPCLK_MASK					7
#define LOSPCP_LSPCLK_DIV1					0
#define LOSPCP_LSPCLK_DIV2					1
#define LOSPCP_LSPCLK_DIV4					2
#define LOSPCP_LSPCLK_DIV6					3			
#define LOSPCP_LSPCLK_DIV8					4
#define LOSPCP_LSPCLK_DIV10					5
#define LOSPCP_LSPCLK_DIV12					6
#define LOSPCP_LSPCLK_DIV14					7

#define CLKCTL		(*((volatile uint16_t*)0x007012))

#define CLKCTL_NMIRESETSEL_MASK				(1<<15)
#define CLKCTL_NMIRESETSEL_MCLKHS			0
#define CLKCTL_NMIRESETSEL_WATCHDOG			(1<<15)

#define CLKCTL_XTALOSCOFF_MASK				(1<<14)
#define CLKCTL_XTALOSCOFF_ON				0
#define CLKCTL_XTALOSCOFF_OFF				(1<<14)

#define CLKCTL_XCLKINOFF_MASK				(1<<13)
#define CLKCTL_XCLKINOFF_ON					0
#define CLKCTL_XCLKINOFF_OFF				(1<<13)

#define CLKCTL_WDHALTI_MASK					(1<<12)
#define CLKCTL_WDHALTI_ON					0
#define CLKCTL_WDHALTI_OFF					(1<<12)

#define CLKCTL_INTOSC2HALTI_MASK			(1<<11)
#define CLKCTL_INTOSC2HALTI_ON				0
#define CLKCTL_INTOSC2HALTI_OFF				(1<<11)

#define CLKCTL_INTOSC2OFF_MASK				(1<<10)
#define CLKCTL_INTOSC2OFF_ON				0
#define CLKCTL_INTOSC2OFF_OFF				(1<<10)

#define CLKCTL_INTOSC1HALTI_MASK			(1<<9)
#define CLKCTL_INTOSC1HALTI_ON				0
#define CLKCTL_INTOSC1HALTI_OFF				(1<<9)

#define CLKCTL_INTOSC1OFF_MASK				(1<<8)
#define CLKCTL_INTOSC1OFF_ON				0
#define CLKCTL_INTOSC1OFF_OFF				(1<<8)

#define CLKCTL_TMR2CLKPRESCALE_MASK			(7<<5)
#define CLKCTL_TMR2CLKPRESCALE_DIV1			(0<<5)
#define CLKCTL_TMR2CLKPRESCALE_DIV2			(1<<5)
#define CLKCTL_TMR2CLKPRESCALE_DIV4			(2<<5)
#define CLKCTL_TMR2CLKPRESCALE_DIV8			(3<<5)
#define CLKCTL_TMR2CLKPRESCALE_DIV16		(4<<5)

#define CLKCTL_TMR2CLKSRCSEL_MASK			(3<<3)
#define CLKCTL_TMR2CLKSRCSEL_SYSCLKOUT		(0<<3)
#define CLKCTL_TMR2CLKSRCSEL_EXTOSC			(1<<3)
#define CLKCTL_TMR2CLKSRCSEL_INTOSC1		(2<<3)
#define CLKCTL_TMR2CLKSRCSEL_INTOSC2		(3<<3)

#define CLKCTL_WDCLKSRCSEL_MASK				(1<<2)
#define CLKCTL_WDCLKSRCSEL_INTOSC1			0
#define CLKCTL_WDCLKSRCSEL_EXTOSC_INTOSC2	(1<<2)

#define CLKCTL_OSCCLKSRC2SEL_MASK			(1<<1)
#define CLKCTL_OSCCLKSRC2SEL_EXTOSC			0
#define CLKCTL_OSCCLKSRC2SEL_INTOSC2		(1<<1)

#define CLKCTL_OSCCLKSRCSEL_MASK			(1<<0)
#define CLKCTL_OSCCLKSRCSEL_INTOSC1			0
#define CLKCTL_OSCCLKSRCSEL_EXTOSC_INTOSC2	(1<<0)

#define XCLK	(*((volatile uint16_t*)0x007010))

#define XCLK_XCLKINSEL_MASK		(1<<6)
#define XCLK_XCLKINSEL_GPIO38	0
#define XCLK_XCLKINSEL_GPIO19	(1<<6)

#define XCLK_XCLKOUTDIV_MASK	(3<<0)
#define XCLK_XCLKOUTDIV_DIV4	(0<<0)
#define XCLK_XCLKOUTDIV_DIV2	(1<<0)
#define XCLK_XCLKOUTDIV_DIV1	(2<<0)
#define XCLK_XCLKOUTDIV_OFF		(3<<0)

#define PLLSTS	(*((volatile uint16_t*)0x007011))

#define PLLSTS_NORMRDYE_MASK		(1<<16)
#define PLLSTS_NORMRDYE_ENABLE		(1<<16)
#define PLLSTS_NORMRDYE_DISABLE		0

#define PLLSTS_DIVSEL_MASK			(3<<7)
#define PLLSTS_DIVSEL_DIV4			(1<<7)
#define PLLSTS_DIVSEL_DIV2			(2<<7)
#define PLLSTS_DIVSEL_DIV1			(3<<7)

#define PLLSTS_MCLKOFF_MASK			(1<<6)
#define PLLSTS_MCLKOFF_ENABLE		0
#define PLLSTS_MCLKOFF_DISABLE		(1<<6)

#define PLLSTS_OSCOFF_MASK			(1<<5)
#define PLLSTS_OSCOFF_ON			0
#define PLLSTS_OSCOFF_OFF			(1<<5)

#define PLLSTS_MCLKCLR_MASK			(1<<4)
#define PLLSTS_MCLKCLR_RESET		(1<<4)

#define PLLSTS_MCLKSTS_MASK			(1<<3)
#define PLLSTS_MCLKSTS_NORMAL		0
#define PLLSTS_MCLKSTS_MISSING		(1<<3)

#define PLLSTS_PLLOFF_MASK			(1<<2)
#define PLLSTS_PLLOFF_ON			0
#define PLLSTS_PLLOFF_OFF			(1<<2)

#define PLLSTS_PLLLOCKS_MASK		(1<<0)
#define PLLSTS_PLLLOCKS_LOCKING		0
#define PLLSTS_PLLLOCKS_STABLE		(1<<0)

#define PLLCR	(*((volatile uint16_t*)0x007021))

#define PLLCR_DIV_MASK				(0x000F)
#define PLLCR_DIV_BYPASS			0
#define PLLCR_DIV_1					1
#define PLLCR_DIV_2					2
#define PLLCR_DIV_3					3
#define PLLCR_DIV_4					4
#define PLLCR_DIV_5					5
#define PLLCR_DIV_6					6
#define PLLCR_DIV_7					7
#define PLLCR_DIV_8					8
#define PLLCR_DIV_9					9
#define PLLCR_DIV_10				10
#define PLLCR_DIV_11				11
#define PLLCR_DIV_12				(uint16_t)12

#define PCLKCR0	(*((volatile uint16_t*)0x00701C))

#define PCLKCR0_SCIAENCLK_MASK				(1<<10)		// SCI-A clock enable
														//
#define PCLKCR0_SCIAENCLK_DISABLE			0			// The SCI-A module is not clocked. (default)
														//
#define PCLKCR0_SCIAENCLK_ENABLE			(1<<10)		// The SCI-A module is clocked by the low-speed clock (LSPCLK).

#define PCLKCR0_SPIAENCLK_MASK				(1<<8)		// SPI-A clock enable
														//
#define PCLKCR0_SPIAENCLK_DISABLE			0			// The SPI-A module is not clocked. (default)
														//
#define PCLKCR0_SPIAENCLK_ENABLE			(1<<8)		// The SPI-A module is clocked by the low-speed clock (LSPCLK).

#define PCLKCR0_I2CAENCLK_MASK				(1<<4)		// I2C clock enable
														//
#define PCLKCR0_I2CAENCLK_DISABLE			0			// The I2C module is not clocked. (default)
														//
#define PCLKCR0_I2CAENCLK_ENABLE			(1<<4)		// The I2C module is clocked.

#define PCLKCR0_ADCENCLK_MASK				(1<<3)		// ADC clock enable
														//
#define PCLKCR0_ADCENCLK_DISABLE			0			// The ADC is not clocked. (default)
														//
#define PCLKCR0_ADCENCLK_ENABLE				(1<<3)		// The ADC module is clocked

#define PCLKCR0_TBCLKSYNC_MASK				(1<<2)		// ePWM Module Time Base Clock (TBCLK) Sync: Allows the user to
														// globally synchronize all enabled ePWM modules to the time base 
														// clock (TBCLK):
														// 
#define PCLKCR0_TBCLKSYNC_DISABLE			0			// The TBCLK (Time Base Clock) within each enabled ePWM module is 
														// stopped. (default). If, however, the ePWM clock enable bit is set
														// in the PCLKCR1 register, then the ePWM module will still be 
														// clocked by SYSCLKOUT even if TBCLKSYNC is 0.
														//
#define PCLKCR0_TBCLKSYNC_ENABLE			(1<<2)		// All enabled ePWM module clocks are started with the first rising 
														// edge of TBCLK aligned. For perfectly synchronized TBCLKs, the 
														// prescaler bits in the TBCTL register of each ePWM module must be 
														// set identically. The proper procedure for enabling ePWM clocks is 
														// as follows:
														// • Enable ePWM module clocks in the PCLKCR1 register.
														// • Set TBCLKSYNC to 0.
														// • Configure prescaler values and ePWM modes.
														// • Set TBCLKSYNC to 1.

#define PCLKCR0_HRPWMENCLK_MASK				(1<<0)		// HRPWM clock enable
#define PCLKCR0_HRPWMENCLK_DISABLE			0			// HRPWM is not enabled.
#define PCLKCR0_HRPWMENCLK_ENABLE			(1<<0)		// HRPWM is enabled.

#define PCLKCR1	(*((volatile uint16_t*)0x00701C))

#define PCLKCR1_ECAP1ENCLK_MASK				(1<<8)		// eCAP1 clock enable	
#define PCLKCR1_ECAP1ENCLK_DISABLE			0			// The eCAP1 module is not clocked. (default)
#define PCLKCR1_ECAP1ENCLK_ENABLE			(1<<8)		// The eCAP1 module is clocked by the system clock (SYSCLKOUT).

#define PCLKCR1_EPWM4ENCLK_MASK				(1<<3)		// ePWM4 clock enable.
#define PCLKCR1_EPWM4ENCLK_DISABLE 			0   		// The ePWM4 module is not clocked. (default)
#define PCLKCR1_EPWM4ENCLK_ENABLE			(1<<3)  	// The ePWM4 module is clocked by the system clock (SYSCLKOUT).

#define PCLKCR1_EPWM3ENCLK_MASK				(1<<2)		// ePWM3 clock enable.
#define PCLKCR1_EPWM3ENCLK_DISABLE			0   		// The ePWM3 module is not clocked. (default)
#define PCLKCR1_EPWM3ENCLK_ENABLE			(1<<2)  	// The ePWM3 module is clocked by the system clock (SYSCLKOUT).

#define PCLKCR1_EPWM2ENCLK_MASK				(1<<1)		// ePWM2 clock enable.
#define PCLKCR1_EPWM2ENCLK_DISABLE			0   		// The ePWM2 module is not clocked. (default)
#define PCLKCR1_EPWM2ENCLK_ENABLE 			(1<<1)  	// The ePWM2 module is clocked by the system clock (SYSCLKOUT).

#define PCLKCR1_EPWM1ENCLK_MASK				(1<<0)		// ePWM1 clock enable.
#define PCLKCR1_EPWM1ENCLK_DISABLE			0   		// The ePWM1 module is not clocked. (default)
#define PCLKCR1_EPWM1ENCLK_ENABLE			(1<<0)  	// The ePWM1 module is clocked by the system clock (SYSCLKOUT).

#define PIECTRL		(*((volatile uint16_t*)0x000CE0))

#define PIECTRL_PIEVECT_MASK				0xFFFE		// These bits indicate the address within the PIE vector table from which the vector was fetched. The
														// least significant bit of the address is ignored and only bits 1 to 15 of the address is shown. You can
														// read the vector value to determine which interrupt generated the vector fetch.
														// For Example: If PIECTRL = 0x0D27 then the vector from address 0x0D26 (illegal operation) was
														// fetched.
														// 
#define PIECTRL_ENPIE_MASK					1			// Enable vector fetching from PIE vector table.
														// Note: The reset vector is never fetched from the PIE, even when it is enabled. This vector is always
														// fetched from boot ROM.
														// 
#define PIECTRL_ENPIE_DISABLE				0			// If this bit is set to 0, the PIE block is disabled and vectors are fetched from the CPU vector table in
														// boot ROM. All PIE block registers (PIEACK, PIEIFR, PIEIER) can be accessed even when the PIE
														// block is disabled.
														// 
#define PIECTRL_ENPIE_ENABLE				1			// When ENPIE is set to 1, all vectors, except for reset, are fetched from the PIE vector table. The reset
														// vector is always fetched from the boot ROM.

#define PIEACK		(*((volatile uint16_t*)0x000CE1))

// Each bit in PIEACK refers to a specific PIE group. Bit 0 refers to interrupts in PIE group 1 that are
// MUXed into INT1 up to Bit 11, which refers to PIE group 12 which is MUXed into CPU IN T12
// If a bit reads as a 0, it indicates that the PIE can send an interrupt from the respective group to the CPU.
// Writes of 0 are ignored.
// Reading a 1 indicates if an interrupt from the respective group has been sent to the CPU and all
// other interrupts from the group are currently blocked.
// Writing a 1 to the respective interrupt bit clears the bit and enables the PIE block to drive a pulse into
// the CPU interrupt input if an interrupt is pending for that group.

#define PIEACK_MASK					0x0FFF
#define PIEACK_INT1					(1<<0)
#define PIEACK_INT2					(1<<1)
#define PIEACK_INT3					(1<<2)
#define PIEACK_INT4					(1<<3)
#define PIEACK_INT5					(1<<4)
#define PIEACK_INT6					(1<<5)
#define PIEACK_INT7					(1<<6)
#define PIEACK_INT8					(1<<7)
#define PIEACK_INT9					(1<<8)
#define PIEACK_INT10				(1<<9)
#define PIEACK_INT11				(1<<10)
#define PIEACK_INT12				(1<<11)

#define PIEIFR1		(*((volatile uint16_t*)0x000CE3))
#define PIEIFR2		(*((volatile uint16_t*)0x000CE5))
#define PIEIFR3		(*((volatile uint16_t*)0x000CE7))
#define PIEIFR4		(*((volatile uint16_t*)0x000CE9))
#define PIEIFR5		(*((volatile uint16_t*)0x000CEB))
#define PIEIFR6		(*((volatile uint16_t*)0x000CED))
#define PIEIFR7		(*((volatile uint16_t*)0x000CEF))
#define PIEIFR8		(*((volatile uint16_t*)0x000CF1))
#define PIEIFR9		(*((volatile uint16_t*)0x000CF3))
#define PIEIFR10	(*((volatile uint16_t*)0x000CF5))
#define PIEIFR11	(*((volatile uint16_t*)0x000CF7))
#define PIEIFR12	(*((volatile uint16_t*)0x000CF9))

#define PIEIER_INT8					(1<<7)
#define PIEIER_INT7					(1<<6)
#define PIEIER_INT6					(1<<5)
#define PIEIER_INT5					(1<<4)
#define PIEIER_INT4					(1<<3)
#define PIEIER_INT3					(1<<2)
#define PIEIER_INT2					(1<<1)
#define PIEIER_INT1					(1<<0)

#define PIEIER1		(*((volatile uint16_t*)0x000CE2))
#define PIEIER2		(*((volatile uint16_t*)0x000CE4))
#define PIEIER3		(*((volatile uint16_t*)0x000CE6))
#define PIEIER4		(*((volatile uint16_t*)0x000CE8))
#define PIEIER5		(*((volatile uint16_t*)0x000CEA))
#define PIEIER6		(*((volatile uint16_t*)0x000CEC))
#define PIEIER7		(*((volatile uint16_t*)0x000CEE))
#define PIEIER8		(*((volatile uint16_t*)0x000CF0))
#define PIEIER9		(*((volatile uint16_t*)0x000CF2))
#define PIEIER10	(*((volatile uint16_t*)0x000CF4))
#define PIEIER11	(*((volatile uint16_t*)0x000CF6))
#define PIEIER12	(*((volatile uint16_t*)0x000CF8))

#define PIEIFR_INT8					(1<<7)
#define PIEIFR_INT7					(1<<6)
#define PIEIFR_INT6					(1<<5)
#define PIEIFR_INT5					(1<<4)
#define PIEIFR_INT4					(1<<3)
#define PIEIFR_INT3					(1<<2)
#define PIEIFR_INT2					(1<<1)
#define PIEIFR_INT1					(1<<0)

#define GPAMUX1	(*((volatile uint16_t*)0x006F86))

#define GPAMUX1_GPIO12_MASK			(3<<24)
#define GPAMUX1_GPIO12_GPIO			0
#define GPAMUX1_GPIO12_TZ1			(1<<24)
#define GPAMUX1_GPIO12_SCITXDA		(2<<24)

#define GPAMUX1_GPIO7_MASK			(3<<14)
#define GPAMUX1_GPIO7_GPIO			0
#define GPAMUX1_GPIO7_EPWM4B		(1<<14)
#define GPAMUX1_GPIO7_SCIRXDA		(2<<14)

#define GPAMUX1_GPIO6_MASK			(3<<12)
#define GPAMUX1_GPIO6_GPIO			0
#define GPAMUX1_GPIO6_EPWM4A		(1<<12)
#define GPAMUX1_GPIO6_EPWMSYNCI		(2<<12)
#define GPAMUX1_GPIO6_EPWMSYNCO		(3<<12)

#define GPAMUX1_GPIO5_MASK			(3<<10)
#define GPAMUX1_GPIO5_GPIO			0
#define GPAMUX1_GPIO5_EPWM3B		(1<<10)
#define GPAMUX1_GPIO5_ECAP1			(3<<10)

#define GPAMUX1_GPIO4_MASK			(3<<8)
#define GPAMUX1_GPIO4_GPIO			0
#define GPAMUX1_GPIO4_EPWM3A		(1<<8)

#define GPAMUX1_GPIO3_MASK			(3<<6)
#define GPAMUX1_GPIO3_GPIO			0
#define GPAMUX1_GPIO3_EPWM2B		(1<<6)
#define GPAMUX1_GPIO3_COMP2OUT		(3<<6)

#define GPAMUX1_GPIO2_MASK			(3<<4)
#define GPAMUX1_GPIO2_GPIO			0
#define GPAMUX1_GPIO2_EPWM2A		(1<<4)

#define GPAMUX1_GPIO1_MASK			(3<<2)
#define GPAMUX1_GPIO1_GPIO			0
#define GPAMUX1_GPIO1_EPWM1B		(1<<2)
#define GPAMUX1_GPIO1_COMP1OUT		(3<<2)

#define GPAMUX1_GPIO0_MASK			3
#define GPAMUX1_GPIO0_GPIO			0
#define GPAMUX1_GPIO0_EPWM1A		1

#define GPAMUX2	(*((volatile uint16_t*)0x006F88))

#define GPAMUX2_GPIO29_MASK			(3<<26)
#define GPAMUX2_GPIO29_GPIO			0
#define GPAMUX2_GPIO29_SCITXDA		(1<<26)
#define GPAMUX2_GPIO29_SCLA			(2<<26)
#define GPAMUX2_GPIO29_TZ3			(3<<26)

#define GPAMUX2_GPIO28_MASK			(3<<24)
#define GPAMUX2_GPIO28_GPIO			0
#define GPAMUX2_GPIO28_SCIRXDA		(1<<24)
#define GPAMUX2_GPIO28_SDAA			(2<<24)
#define GPAMUX2_GPIO28_TZ2			(3<<24)

#define GPAMUX2_GPIO19_MASK			(3<<6)
#define GPAMUX2_GPIO19_GPIO			0
#define GPAMUX2_GPIO19_SPISTEA		(1<<6)
#define GPAMUX2_GPIO19_SCIRXDA		(2<<6)
#define GPAMUX2_GPIO19_ECAP1		(3<<6)

#define GPAMUX2_GPIO18_MASK			(3<4)
#define GPAMUX2_GPIO18_GPIO			0
#define GPAMUX2_GPIO18_SPICLKA		(1<<4)
#define GPAMUX2_GPIO18_SCITXDA		(2<<4)
#define GPAMUX2_GPIO18_XCLKOUT		(3<<4)


#define GPADIR 		(*((volatile uint32_t*)0x006F8A))
#define GPBDIR 		(*((volatile uint32_t*)0x006F9A))
#define GPASET		(*((volatile uint32_t*)0x006FC2))
#define GPBSET		(*((volatile uint32_t*)0x006FCA))
#define GPACLEAR	(*((volatile uint32_t*)0x006FC4))
#define GPBCLEAR	(*((volatile uint32_t*)0x006FCC))
#define GPATOGGLE	(*((volatile uint32_t*)0x006FC6))
#define GPBTOGGLE   (*((volatile uint32_t*)0x006FCE))

#define GPIO_MASK(io)		(1<<(io))
#define GPIO_INPUT(io)		0
#define GPIO_OUTPUT(io)		(1<<(io))

#define WDCR	(*((volatile uint16_t*)0x007029))

#define WDCR_WDFLAG_MASK		(1<<7)
#define WDCR_WDFLAG_POWER_ON	(0)
#define WDCR_WDFLAG_WATCHDOG	(1<<7)

#define WDCR_WDDIS_MASK			(1<<6)
#define WDCR_WDDIS_DISABLE		(1<<6)
#define WDCR_WDDIS_ENABLE		0

#define WDCR_WDCHK_MASK			(7<<3)
#define WDCR_WDCHK_KEY			(5<<3)
#define WDCR_WDCHK_RESET		0

#define WDCR_WDPS_MASK			(7<<0)
#define WDCR_WDPS_DIV512		0
#define WDCR_WDPS_DIV256		1
#define WDCR_WDPS_DIV128		2
#define WDCR_WDPS_DIV64			3
#define WDCR_WDPS_DIV32			4
#define WDCR_WDPS_DIV16			5
#define WDCR_WDPS_DIV8			6
#define WDCR_WDPS_DIV4			7

#define FOPT (*((volatile uint16_t*)0x000A80))

#define FOPT_ENPIPE_MASK		1
#define FOPT_ENPIPE_DISABLE		0
#define FOPT_ENPIPE_ENABLE		1

#define FBANKWAIT (*((volatile uint16_t*)0x000A86))

#define FBANKWAIT_PAGEWAIT_MASK		(15<<8)
#define FBANKWAIT_PAGEWAIT(c)		(((c)<<8)&FBANKWAIT_PAGEWAIT_MASK)

#define FBANKWAIT_RANDWAIT_MASK		(7<<0)
#define FBANKWAIT_RANDWAIT(c)		(((c)<<0)&FBANKWAIT_RANDWAIT_MASK)
