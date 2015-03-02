
#define  EINT()   asm(" clrc INTM")
#define  DINT()   asm(" setc INTM")
#define  ERTM()   asm(" clrc DBGM")
#define  DRTM()   asm(" setc DBGM")
#define  EALLOW() asm(" EALLOW")
#define  EDIS()   asm(" EDIS")
#define  ESTOP0()  asm(" ESTOP0")
#define  IDLE90()  asm(" IDLE")

#define RA(x)	(*((volatile uint16_t*)(x)))
#define RA32(x)	(*((volatile uint32_t*)(x)))

extern cregister volatile unsigned int IFR;
extern cregister volatile unsigned int IER;

#define Device_cal() ((void(*)(void))0x3D7C80)()

// SPRUFN3D
// TMS320F2802x/TMS320F2802xx Piccolo System Control and Interrupts

#define LOSPCP		RA(0x00701B)

#define LOSPCP_LSPCLK_MASK					7
#define LOSPCP_LSPCLK_DIV1					0
#define LOSPCP_LSPCLK_DIV2					1
#define LOSPCP_LSPCLK_DIV4					2
#define LOSPCP_LSPCLK_DIV6					3			
#define LOSPCP_LSPCLK_DIV8					4
#define LOSPCP_LSPCLK_DIV10					5
#define LOSPCP_LSPCLK_DIV12					6
#define LOSPCP_LSPCLK_DIV14					7

#define CLKCTL		RA(0x007012)

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

#define XCLK	RA(0x007010)

#define XCLK_XCLKINSEL_MASK		(1<<6)
#define XCLK_XCLKINSEL_GPIO38	0
#define XCLK_XCLKINSEL_GPIO19	(1<<6)

#define XCLK_XCLKOUTDIV_MASK	(3<<0)
#define XCLK_XCLKOUTDIV_DIV4	(0<<0)
#define XCLK_XCLKOUTDIV_DIV2	(1<<0)
#define XCLK_XCLKOUTDIV_DIV1	(2<<0)
#define XCLK_XCLKOUTDIV_OFF		(3<<0)

#define PLLSTS	RA(0x007011)

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

#define PLLCR	RA(0x007021)

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
#define PLLCR_DIV_12				12

#define PCLKCR0	RA(0x00701C)							// Peripheral Clock Control Register 0

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

#define PCLKCR1	RA(0x00701D)							// Peripheral Clock Control Register 1

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


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///	CPU INTERRUPT
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define CPU_INT1          (1 << 0)
#define CPU_INT2          (1 << 1)
#define CPU_INT3          (1 << 2)
#define CPU_INT4          (1 << 3)
#define CPU_INT5          (1 << 4)
#define CPU_INT6          (1 << 5)
#define CPU_INT7          (1 << 6)
#define CPU_INT8          (1 << 7)
#define CPU_INT9          (1 << 8)
#define CPU_INT10         (1 << 9)
#define CPU_INT11         (1 << 10)
#define CPU_INT12         (1 << 11)
#define CPU_INT13         (1 << 12)
#define CPU_INT14         (1 << 13)
#define CPU_DLOGINT       (1 << 14)
#define CPU_RTOSINT       (1 << 15)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// PIE
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define PIECTRL		RA(0x000CE0)

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

#define PIEACK		RA(0x000CE1)

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

#define PIEIFR1						RA(0x000CE3)
#define PIEIFR2						RA(0x000CE5)
#define PIEIFR3						RA(0x000CE7)
#define PIEIFR4						RA(0x000CE9)
#define PIEIFR5						RA(0x000CEB)
#define PIEIFR6						RA(0x000CED)
#define PIEIFR7						RA(0x000CEF)
#define PIEIFR8						RA(0x000CF1)
#define PIEIFR9						RA(0x000CF3)
#define PIEIFR10					RA(0x000CF5)
#define PIEIFR11					RA(0x000CF7)
#define PIEIFR12					RA(0x000CF9)

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

#define PIE_IVT	((PISR*)0x0D00)

#define	PIEACK_ACK_ALL 	0x0FFF				// resets all PIE
#define PIEACK_ACK(i)	(1<<((x)-1))		// Each bit in PIEACK refers to a specific PIE group. Bit 0 refers to interrupts in PIE group 1 that are
											// MUXed into INT1 up to Bit 11, which refers to PIE group 12 which is MUXed into CPU IN T12
											// 
											// If a bit reads as a 0, it indicates that the PIE can send an interrupt from the respective group to the
											// CPU. Writes of 0 are ignored.  
											// 
											// Reading a 1 indicates if an interrupt from the respective group has been 
											// sent to the CPU and all other interrupts from the group are currently blocked.
											// 
											// Writing a 1 to the respective interrupt bit clears the bit and enables the PIE block to drive a pulse into 
											// the CPU interrupt input if an interrupt is pending for that group.



#define PIEIER(x)	RA(((x)-1)*2+0xCE2)		// INT(1-12) Group Enable Register
#define PIEIFR(x)	RA(((x)-1)*2+0xCE3)		// INT(1-12) Group Flag Register

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GPIO
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define GPA_MASK(io)				(1<<(io))
#define GPB_MASK(io)				(1<<((io)-32))


#define GPACTRL						RA32(0x6F80)	// GPIO A Control Register (GPIO0-GPIO31)
													
// TODO:  GPACTRL bitfields

#define GPAQSEL1 					RA32(0x6F82)	// GPIO A Qualifier Select 1 Register (GPIO0-GPIO15)
													
// TODO:  GPAQSEL1 bitfields
 													
#define GPAQSEL2 					RA32(0x6F84)	// GPIO A Qualifier Select 2 Register (GPIO16-GPIO31)
													
// TODO:  GPAQSEL2 bitfields
													
#define GPAMUX1 					RA32(0x6F86)	// GPIO A MUX 1 Register (GPIO0-GPIO15)

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

#define GPAMUX2 					RA32(0x6F88)	// GPIO A MUX 2 Register (GPIO16-GPIO31)
													
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

#define GPADIR 						RA32(0x6F8A)	// GPIO A Direction Register (GPIO0-GPIO31)

#define GPADIR_INPUT(io)			0				// GPIO A input (GPIO0-GPIO31)
#define GPADIR_OUTPUT(io)			GPA_MASK(io)	// GPIO A output (GPIO0-GPIO31)

#define GPAPUD 						RA32(0x6F8C)	// GPIO A Pull Up Disable Register (GPIO0-GPIO31)
													
#define GPAPUD_ENABLE(io)			0				// enable port A pullup (GPIO32-GPIO38)
#define GPAPUD_DISABLE(io)			GPA_MASK(io)	// disable port A pullup (GPIO32-GPIO38)
													
#define GPBCTRL 					RA32(0x6F90)	// GPIO B Control Register (GPIO32-GPIO38)

// TODO:  GPBCTRL bitfields

#define GPBQSEL1 					RA32(0x6F92)	// GPIO B Qualifier Select 1 Register (GPIO32-GPIO38)
#define GPBMUX1 					RA32(0x6F96)	// GPIO B MUX 1 Register (GPIO32-GPIO38)
#define GPBDIR 						RA32(0x6F9A)	// GPIO B Direction Register (GPIO32-GPIO38)
													
#define GPBDIR_INPUT(io)			0				// GPIO B input (GPIO32-GPIO38)
#define GPBDIR_OUTPUT(io)			GPB_MASK(io)	// GPIO B output (GPIO32-GPIO38)

#define GPBPUD 						RA32(0x6F9C)	// GPIO B Pull Up Disable Register (GPIO32-GPIO38)
													
#define GPBPUD_ENABLE(io)			0				// enable port B pullup (GPIO32-GPIO38)
#define GPBPUD_DISABLE(io)			GPB_MASK(io)	// disable port B pullup (GPIO32-GPIO38)

#define AIOMUX1 					RA32(0x6FB6)	// Analog, I/O MUX 1 register (AIO0 - AIO15)
#define AIODIR 						RA32(0x6FBA)	// Analog, I/O Direction Register (AIO0 - AIO15) 

#define GPASET						RA32(0x006FC2)
#define GPBSET						RA32(0x006FCA)
#define GPACLEAR					RA32(0x006FC4)
#define GPBCLEAR					RA32(0x006FCC)
#define GPATOGGLE					RA32(0x006FC6)
#define GPBTOGGLE   				RA32(0x006FCE)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// WATCHDOG
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define WDCR			RA(0x007029)

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///  FLASH
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define FOPT 		RA(0x000A80)

#define FOPT_ENPIPE_MASK		1
#define FOPT_ENPIPE_DISABLE		0
#define FOPT_ENPIPE_ENABLE		1

#define FBANKWAIT 		RA(0x000A86)

#define FBANKWAIT_PAGEWAIT_MASK		(15<<8)
#define FBANKWAIT_PAGEWAIT(c)		(((c)<<8)&FBANKWAIT_PAGEWAIT_MASK)

#define FBANKWAIT_RANDWAIT_MASK		(7<<0)
#define FBANKWAIT_RANDWAIT(c)		(((c)<<0)&FBANKWAIT_RANDWAIT_MASK)

											
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///	32-BIT CPU Timers 0/1/2
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define TIMERTIM(i)		RA((i)*8+0xC00)			// CPU-Timer (0-2) Counter Register
#define TIMERTIMH(i)	RA((i)*8+0xC01)			// CPU-Timer (0-2) Counter Register High 
#define TIMERPRD(i)		RA((i)*8+0xC02)			// CPU-Timer (0-2) Period Register
												// CPU-Timer Period Registers (PRDH:PRD): The PRD register holds the low 16 bits of the 32-bit period. The
												// PRDH register holds the high 16 bits of the 32-bit period. When the TIMH:TIM decrements to zero, the
												// TIMH:TIM register is reloaded with the period value contained in the PRDH:PRD registers, at the start of
												// the next timer input clock cycle (the output of the prescaler). The PRDH:PRD contents are also loaded into
												// the TIMH:TIM when you set the timer reload bit (TRB) in the Timer Control Register (TCR).

#define SET_TIMER_PERIOD(t,p)	TIMERPRD(t) = ((uint16_t)((uint32_t)(p))); TIMERPRDH(t) = ((uint16_t)((uint32_t)(p)>>16))

#define TIMERPRDH(i)	RA((i)*8+0xC03)			// CPU-Timer (0-2) Period Register High
												// CPU-Timer Period Registers (PRDH:PRD): The PRD register holds the low 16 bits of the 32-bit period. The
												// PRDH register holds the high 16 bits of the 32-bit period. When the TIMH:TIM decrements to zero, the
												// TIMH:TIM register is reloaded with the period value contained in the PRDH:PRD registers, at the start of
												// the next timer input clock cycle (the output of the prescaler). The PRDH:PRD contents are also loaded into
												// the TIMH:TIM when you set the timer reload bit (TRB) in the Timer Control Register (TCR).

#define TIMERTPR(i)		RA((i)*8+0xC06)			// CPU-Timer (0-2) Prescale Register

#define TIMER_TPR_PSC(v)	(((v)&0xFF)<<8)		// CPU-Timer Prescale Counter. These bits hold the current prescale count for the timer. For every timer clock
												// source cycle that the PSCH:PSC value is greater than 0, the PSCH:PSC decrements by one. One timer clock
												// (output of the timer prescaler) cycle after the PSCH:PSC reaches 0, the PSCH:PSC is loaded with the contents
												// of the TDDRH:TDDR, and the timer counter register (TIMH:TIM) decrements by one. The PSCH:PSC is also
												// reloaded whenever the timer reload bit (TRB) is set by software. The PSCH:PSC can be checked by reading
												// the register, but it cannot be set directly. It must get its value from the timer divide-down register
												// (TDDRH:TDDR). At reset, the PSCH:PSC is set to 0.
												// 
#define TIMER_TPR_TDDR(v)	((v)&0xFF)			// CPU-Timer Divide-Down. Every (TDDRH:TDDR + 1) timer clock source cycles, the timer counter register
												// (TIMH:TIM) decrements by one. At reset, the TDDRH:TDDR bits are cleared to 0. To increase the overall timer
												// count by an integer factor, write this factor minus one to the TDDRH:TDDR bits. When the prescaler counter
												// (PSCH:PSC) value is 0, one timer clock source cycle later, the contents of the TDDRH:TDDR reload the
												// PSCH:PSC, and the TIMH:TIM decrements by one. TDDRH:TDDR also reloads the PSCH:PSC whenever the
												// timer reload bit (TRB) is set by software.

#define TIMERTPRH(i)	RA((i)*8+0xC07)			// CPU-Timer (0-2) Control Register High

#define TIMER_TPRH_PSCH(v)	(((v)&0xFF)<<8)		// CPU-Timer Prescale Counter. These bits hold the current prescale count for the timer. For every timer clock
												// source cycle that the PSCH:PSC value is greater than 0, the PSCH:PSC decrements by one. One timer clock
												// (output of the timer prescaler) cycle after the PSCH:PSC reaches 0, the PSCH:PSC is loaded with the contents
												// of the TDDRH:TDDR, and the timer counter register (TIMH:TIM) decrements by one. The PSCH:PSC is also
												// reloaded whenever the timer reload bit (TRB) is set by software. The PSCH:PSC can be checked by reading
												// the register, but it cannot be set directly. It must get its value from the timer divide-down register
												// (TDDRH:TDDR). At reset, the PSCH:PSC is set to 0.

#define TIMER_TPRH_TDDRH(v)	((v)&0xFF)			// CPU-Timer Divide-Down. Every (TDDRH:TDDR + 1) timer clock source cycles, the timer counter register
												// (TIMH:TIM) decrements by one. At reset, the TDDRH:TDDR bits are cleared to 0. To increase the overall timer
												// count by an integer factor, write this factor minus one to the TDDRH:TDDR bits. When the prescaler counter
												// (PSCH:PSC) value is 0, one timer clock source cycle later, the contents of the TDDRH:TDDR reload the
												// PSCH:PSC, and the TIMH:TIM decrements by one. TDDRH:TDDR also reloads the PSCH:PSC whenever the
												// timer reload bit (TRB) is set by software.

#define SET_TIMER_PRESCALE(t,p)		TIMERTPR(t) = TIMER_TPR_TDDR(p); TIMERTPRH(t) = TIMER_TPRH_TDDRH((p)>>8)


#define TIMERTCR(i)		RA((i)*8+0xC04)			// CPU-Timer (0-2) Control Register
												//
#define TIMERTCR_TIF_MASK		(1<<15)			// CPU-Timer Interrupt Flag
#define TIMERTCR_TIF_NOT_ZERO	0				// The CPU-Timer has not decremented to zero.
												// Writes of 0 are ignored.
#define TIMERTCR_TIF_ZERO		(1<<15)			// This flag gets set when the CPU-timer decrements to zero.
												// Writing a 1 to this bit clears the flag.
												// 
#define TIMERTCR_TIE_MASK		(1<<14)			// CPU-Timer Interrupt Enable.
#define TIMERTCR_TIE_DISABLE	0				// The CPU-Timer interrupt is disabled.
#define TIMERTCR_TIE_ENABLE		(1<<14)			// The CPU-Timer interrupt is enabled. If the timer decrements to zero, and TIE is set, the
												// timer asserts its interrupt request.
												// 
#define TIMERTCR_FREE_SOFT_MASK		(3<<10)		// CPU-Timer Emulation Modes: These bits are special emulation bits that determine the
												// SOFT state of the timer when a breakpoint is encountered in the high-level language
												// debugger. If the FREE bit is set to 1, then, upon a software breakpoint, the timer
												// continues to run (that is, free runs). In this case, SOFT is a don't care. But if FREE is 0,
												// then SOFT takes effect. In this case, if SOFT = 0, the timer halts the next time the
												// TIMH:TIM decrements. If the SOFT bit is 1, then the timer halts when the TIMH:TIM
												// has decremented to zero.
												//
#define TIMERTCR_FREE_SOFT_HARDSTOP	0			// Stop after the next decrement of the TIMH:TIM (hard stop)
#define TIMERTCR_FREE_SOFT_SOFTSTOP	(1<<10)		// Stop after the TIMH:TIM decrements to 0 (soft stop)
												// In the SOFT STOP mode, the timer generates an interrupt before shutting down (since
												// reaching 0 is the interrupt causing condition).
#define TIMERTCR_FREE_SOFT_FREERUN	(2<<10)		// Free run
												//
#define TIMERTCR_TRB_MASK		(1<<5)			// CPU-Timer Reload bit.
#define TIMERTCR_TRB_RELOAD		(1<<5)			// When you write a 1 to TRB, the TIMH:TIM is loaded with the value in the PRDH:PRD,
												// and the prescaler counter (PSCH:PSC) is loaded with the value in the timer dividedown
												// register (TDDRH:TDDR).
												// 
#define TIMERTCR_TSS_MASK		(1<<4)			// CPU-Timer stop status bit. TSS is a 1-bit flag that stops or starts the CPU-timer.
#define TIMERTCR_TSS_RUNNING	0				// Reads of 0 indicate the CPU-timer is running.  
												// To start or restart the CPU-timer, set TSS to 0. At reset, TSS is cleared to 0 and the
												// CPU-timer immediately starts.
#define TIMERTCR_TSS_STOPPED	(1<<4)			// Reads of 1 indicate that the CPU-timer is stopped.
												// To stop the CPU-timer, set TSS to 1

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///	PWM
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define TBCTL(i)		RA(((i)-1)*0x40+0x6800)		// Time Base Control Register
													//
#define TBCTL_FREE_SOFT_MASK		(3<<14)			// Emulation Mode Bits. These bits select the behavior of the ePWM time-base counter during
													// emulation events
#define TBCTL_FREE_SOFT_TIMEBASE	0   			// Stop after the next time-base counter increment or decrement
#define TBCTL_FREE_SOFT_CYCLE		(1<<14) 		// Stop when counter completes a whole cycle:
#define TBCTL_FREE_SOFT_FREE_RUN	(2<<14) 		// Free run

#define TBCTL_PHSDIR_MASK			(1<<13) 		// Phase Direction Bit.
													// This bit is only used when the time-base counter is configured in the up-down-count mode. The
													// PHSDIR bit indicates the direction the time-base counter (TBCTR) will count after a synchronization
													// event occurs and a new phase value is loaded from the phase (TBPHS) register. This is
													// irrespective of the direction of the counter before the synchronization event..
													// In the up-count and down-count modes this bit is ignored.
													// 
#define TBCTL_PHSDIR_COUNT_DOWN		(0)				// Count down after the synchronization event.
#define TBCTL_PHSDIR_COUNT_UP		(1<<13)			// Count up after the synchronization event.

#define TBCTL_CLKDIV_MASK			(7<<10)			// Time-base Clock Prescale Bits
													// These bits determine part of the time-base clock prescale value.
													// TBCLK = SYSCLKOUT / (HSPCLKDIV × CLKDIV)
													// 
#define TBCTL_CLKDIV_1				(0<<10)			// /1 (default on reset)
#define TBCTL_CLKDIV_2				(1<<10)
#define TBCTL_CLKDIV_4				(2<<10)
#define TBCTL_CLKDIV_8				(3<<10)
#define TBCTL_CLKDIV_16				(4<<10)
#define TBCTL_CLKDIV_32				(5<<10)
#define TBCTL_CLKDIV_64				(6<<10)
#define TBCTL_CLKDIV_128			(7<<10)
												
#define TBCTL_HSPCLKDIV_MASK		(7<<7)			// High Speed Time-base Clock Prescale Bits
													// These bits determine part of the time-base clock prescale value.
													// TBCLK = SYSCLKOUT / (HSPCLKDIV × CLKDIV)
													// This divisor emulates the HSPCLK in the TMS320x281x system as used on the Event Manager
													// (EV) peripheral.

#define TBCTL_HSPCLKDIV_1			(0<<7)	    	
#define TBCTL_HSPCLKDIV_2			(1<<7)			// /2 (default on reset)
#define TBCTL_HSPCLKDIV_4			(2<<7)      	
#define TBCTL_HSPCLKDIV_6			(3<<7)      	
#define TBCTL_HSPCLKDIV_8			(4<<7)      	
#define TBCTL_HSPCLKDIV_10			(5<<7)      	
#define TBCTL_HSPCLKDIV_12			(6<<7)      	
#define TBCTL_HSPCLKDIV_14			(7<<7)      	

#define TBCTL_SWFSYNC_MASK			(1<<6)			// Software Forced Synchronization Pulse

#define TBCTL_SWFSYNC_FORCE			(1<<6)			// Writing a 0 has no effect and reads always return a 0.
													// Writing a 1 forces a one-time synchronization pulse to be generated.
													// This event is ORed with the EPWMxSYNCI input of the ePWM module.
													// SWFSYNC is valid (operates) only when EPWMxSYNCI is selected by SYNCOSEL = 00.


#define TBCTL_SYNCOSEL_MASK			(3<<4)			// Synchronization Output Select. These bits select the source of the EPWMxSYNCO signal.

#define TBCTL_SYNCOSEL_EPWMXSYNC	0				// EPWMxSYNC
#define TBCTL_SYNCOSEL_CTR_ZERO		(1<<4)			// CTR = zero: Time-base counter equal to zero (TBCTR = 0x0000)
#define TBCTL_SYNCOSEL_CTR_CMPB		(2<<4)  		// CTR = CMPB : Time-base counter equal to counter-compare B (TBCTR = CMPB)
#define TBCTL_SYNCOSEL_DISABLE		(3<<4)  		// Disable EPWMxSYNCO signal


#define TBCTL_PRDLD_MASK			(1<<3)			// Active Period Register Load From Shadow Register Select

#define TBCTL_PRDLD_SHADOW			(0)				// The period register (TBPRD) is loaded from its shadow register when the time-base counter,
													// TBCTR, is equal to zero.
													// A write or read to the TBPRD register accesses the shadow register.
#define TBCTL_PRDLD_IMMEDIATE		(1<<3)			// Load the TBPRD register immediately without using a shadow register.
													// A write or read to the TBPRD register directly accesses the active register.

#define TBCTL_PHSEN_MASK			(1<<2)			// Counter Register Load From Phase Register Enable


#define TBCTL_PHSEN_NOLOAD			0				// Do not load the time-base counter (TBCTR) from the time-base phase register (TBPHS)
#define TBCTL_PHSEN_LOAD			(1<<2)			// Load the time-base counter with the phase register when an EPWMxSYNCI input signal occurs or
													// when a software synchronization is forced by the SWFSYNC bit, or when a digital compare sync
													// event occurs.

#define TBCTL_CTRMODE_MASK			(3<<0)			// Counter Mode
													// The time-base counter mode is normally configured once and not changed during normal operation.
													// If you change the mode of the counter, the change will take effect at the next TBCLK edge and the
													// current counter value shall increment or decrement from the value before the mode change.
#define TBCTL_CTRMODE_UP_COUNT		0				// Up-count mode
#define TBCTL_CTRMODE_DOWN_COUNT1	1   			// Down-count mode
#define TBCTL_CTRMODE_UP_DOWN_COUNT	2				// Up-down-count mode
#define TBCTL_CTRMODE_STOP_FREEZE	3   			// Stop-freeze counter operation (default on reset)

#define TBSTS(i)		RA(((i)-1)*0x40+0x6801)		// Time Base Status Register
													//
#define TBSTS_CTRMAX_MASK			(1<<2)			// Time-Base Counter Max Latched Status Bit
													//
#define TBSTS_CTRMAX_NONE			(0<<2)			// Reading a 0 indicates the time-base counter never reached its maximum value. Writing a 0 will
													// have no effect.
#define TBSTS_CTRMAX_MAX			(1<<2)  		// Reading a 1 on this bit indicates that the time-base counter reached the max value 0xFFFF. Writing
													// a 1 to this bit will clear the latched event.
													// 
#define TBSTS_SYNCI_MASK			(1<<1)			// Input Synchronization Latched Status Bit
													//
#define TBSTS_SYNCI_NONE			0				// Writing a 0 will have no effect. Reading a 0 indicates no external synchronization event has
													// occurred.
#define TBSTS_SYNCI_SYNC			(1<<1)  		// Reading a 1 on this bit indicates that an external synchronization event has occurred
													// (EPWMxSYNCI). Writing a 1 to this bit will clear the latched event.
													// 
#define TBSTS_CTRDIR_MASK			(1<<0)			// Time-Base Counter Direction Status Bit. At reset, the counter is frozen; therefore, this bit has no
													// meaning. To make this bit meaningful, you must first set the appropriate mode via TBCTL[CTRMODE].
#define TBSTS_CTRDIR_DOWN			0   			// Time-Base Counter is currently counting down.
#define TBSTS_CTRDIR_UP				1   			// Time-Base Counter is currently counting up.

#define TBPHSHR(i)		RA(((i)-1)*0x40+0x6802)		// Time Base Phase HRPWM Register
#define TBPHS(i)		RA(((i)-1)*0x40+0x6803)		// Time Base Phase Register
#define TBCTR(i)		RA(((i)-1)*0x40+0x6804)		// Time Base Counter Register
#define TBPRD(i)		RA(((i)-1)*0x40+0x6805)		// Time Base Period Register Set
#define TBPRDHR(i)		RA(((i)-1)*0x40+0x6806)		// Time Base Period High Resolution Register
#define CMPCTL(i)		RA(((i)-1)*0x40+0x6807)		// Counter Compare Control Register
#define CMPAHR(i)		RA(((i)-1)*0x40+0x6808)		// Time Base Compare A HRPWM Register
#define CMPA(i)			RA(((i)-1)*0x40+0x6809)		// The value in the active CMPA register is continuously compared to the time-base counter (TBCTR). When
													// the values are equal, the counter-compare module generates a "time-base counter equal to counter
													// compare A" event. This event is sent to the action-qualifier where it is qualified and converted it into one
													// or more actions. These actions can be applied to either the EPWMxA or the EPWMxB output depending
													// on the configuration of the AQCTLA and AQCTLB registers. The actions that can be defined in the
													// AQCTLA and AQCTLB registers include:
													// • Do nothing; the event is ignored.
													// • Clear: Pull the EPWMxA and/or EPWMxB signal low
													// • Set: Pull the EPWMxA and/or EPWMxB signal high
													// • Toggle the EPWMxA and/or EPWMxB signal
													// Shadowing of this register is enabled and disabled by the CMPCTL[SHDWAMODE] bit. By default this
													// register is shadowed.
													// • If CMPCTL[SHDWAMODE] = 0, then the shadow is enabled and any write or read will automatically
													// go to the shadow register. In this case, the CMPCTL[LOADAMODE] bit field determines which event
													// will load the active register from the shadow register.
													// • Before a write, the CMPCTL[SHDWAFULL] bit can be read to determine if the shadow register is
													// currently full.
													// • If CMPCTL[SHDWAMODE] = 1, then the shadow register is disabled and any write or read will go
													// directly to the active register, that is the register actively controlling the hardware.
													// • In either mode, the active and shadow registers share the same memory map address. 


#define CMPB(i)			RA(((i)-1)*0x40+0x680A)		// The value in the active CMPB register is continuously compared to the time-base counter (TBCTR). When
													// the/values are equal, the counter-compare module generates a "time-base counter equal to counter
													// compare B" event. This event is sent to the action-qualifier where it is qualified and converted it into one
													// or more actions. These actions can be applied to either the EPWMxA or the EPWMxB output depending
													// on the configuration of the AQCTLA and AQCTLB registers. The actions that can be defined in the
													// AQCTLA and AQCTLB registers include:
													// • Do nothing. event is ignored.
													// • Clear: Pull the EPWMxA and/or EPWMxB signal low
													// • Set: Pull the EPWMxA and/or EPWMxB signal high
													// • Toggle the EPWMxA and/or EPWMxB signal
													// Shadowing of this register is enabled and disabled by the CMPCTL[SHDWBMODE] bit. By default this
													// register is shadowed.
													// • If CMPCTL[SHDWBMODE] = 0, then the shadow is enabled and any write or read will automatically
													// go to the shadow register. In this case, the CMPCTL[LOADBMODE] bit field determines which event
													// will load the active register from the shadow register:
													// • Before a write, the CMPCTL[SHDWBFULL] bit can be read to determine if the shadow register is
													// currently full.
													// • If CMPCTL[SHDWBMODE] = 1, then the shadow register is disabled and any write or read will go
													// directly to the active register, that is the register actively controlling the hardware.
													// • In either mode, the active and shadow registers share the same memory map address.

#define AQCTLA(i)		RA(((i)-1)*0x40+0x680B)		// Action Qualifier Control Register For Output A
													
#define AQCTL_CBD_MASK			(3<<10)				// Action when the time-base counter equals the active CMPB register and the counter is decrementing
#define AQCTL_CBD_DISABLE		(0<<10)				// Do nothing (action disabled)
#define AQCTL_CBD_CLEAR			(1<<10) 			// Clear: force EPWMxA output low.
#define AQCTL_CBD_SET			(2<<10) 			// Set: force EPWMxA output high.
#define AQCTL_CBD_TOGGLE		(3<<10) 			// Toggle EPWMxA output: low output signal will be forced high, and a high signal will be forced low.

#define AQCTL_CBU_MASK			(3<<8)				// Action when the counter equals the active CMPB register and the counter is incrementing.
#define AQCTL_CBU_DISABLE		(0<<8)				// Do nothing (action disabled)
#define AQCTL_CBU_CLEAR			(1<<8)  			// Clear: force EPWMxA output low.
#define AQCTL_CBU_SET			(2<<8)  			// Set: force EPWMxA output high.
#define AQCTL_CBU_TOGGLE		(3<<8)  			// Toggle EPWMxA output: low output signal will be forced high, and a high signal will be forced low.

#define AQCTL_CAD_MASK			(3<<6)				// Action when the counter equals the active CMPA register and the counter is decrementing.
#define AQCTL_CAD_DISABLE		(0<<6)				// Do nothing (action disabled)
#define AQCTL_CAD_CLEAR			(1<<6)  			// Clear: force EPWMxA output low.
#define AQCTL_CAD_SET			(2<<6)  			// Set: force EPWMxA output high.
#define AQCTL_CAD_TOGGLE		(3<<6)  			// Toggle EPWMxA output: low output signal will be forced high, and a high signal will be forced low.

#define AQCTL_CAU_MASK			(3<<4)				// Action when the counter equals the active CMPA register and the counter is incrementing.
#define AQCTL_CAU_DISABLE		(0<<4)				// Do nothing (action disabled)
#define AQCTL_CAU_CLEAR			(1<<4)  			// Clear: force EPWMxA output low.
#define AQCTL_CAU_SET			(2<<4)  			// Set: force EPWMxA output high.
#define AQCTL_CAU_TOGGLE		(3<<4)  			// Toggle EPWMxA output: low output signal will be forced high, and a high signal will be forced low.

#define AQCTL_PRD_MASK          (3<<2)				// Action when the counter equals the period.
													// Note: By definition, in count up-down mode when the counter equals period the direction is defined
													// as 0 or counting down.
#define AQCTL_PRD_DISABLE       (0<<2)				// Do nothing (action disabled)
#define AQCTL_PRD_CLEAR         (1<<2)  			// Clear: force EPWMxA output low.
#define AQCTL_PRD_SET           (2<<2)  			// Set: force EPWMxA output high.
#define AQCTL_PRD_TOGGLE        (3<<2)  			// Toggle EPWMxA output: low output signal will be forced high, and a high signal will be forced low.

#define AQCTL_PRO_MASK			(3<<0)				// Action when counter equals zero.
													// Note: By definition, in count up-down mode when the counter equals 0 the direction is defined as 1
													// or counting up.
#define AQCTL_ZRO_DISABLE       (0<<0)				// Do nothing (action disabled)
#define AQCTL_ZRO_CLEAR         (1<<0)  			// Clear: force EPWMxA output low.
#define AQCTL_ZRO_SET           (2<<0)  			// Set: force EPWMxA output high.
#define AQCTL_ZRO_TOGGLE        (3<<0)  			// Toggle EPWMxA output: low output signal will be forced high, and a high signal will be forced low.


#define AQCTLB(i)		RA(((i)-1)*0x40+0x680C)		// Action Qualifier Control Register For Output B
#define AQSFRC(i)		RA(((i)-1)*0x40+0x680D)		// Action Qualifier Software Force Register
#define AQCSFRC(i)		RA(((i)-1)*0x40+0x680E)		// Action Qualifier Continuous S/W Force Register Set
#define DBCTL(i)		RA(((i)-1)*0x40+0x680F)		// Dead-Band Generator Control Register
#define DBRED(i)		RA(((i)-1)*0x40+0x6810)		// Dead-Band Generator Rising Edge Delay Count Register
#define DBFED(i)		RA(((i)-1)*0x40+0x6811)		// Dead-Band Generator Falling Edge Delay Count Register
#define TZSEL(i)		RA(((i)-1)*0x40+0x6812)		// Trip Zone Select Register
#define TZDCSEL(i)		RA(((i)-1)*0x40+0x6813)		// Trip Zone Digital Compare Register
#define TZCTL(i)		RA(((i)-1)*0x40+0x6814)		// Trip Zone Control Register
#define TZEINT(i)		RA(((i)-1)*0x40+0x6815)		// Trip Zone Enable Interrupt Register
#define TZFLG(i)		RA(((i)-1)*0x40+0x6816)		// Trip Zone Flag Register
#define TZCLR(i)		RA(((i)-1)*0x40+0x6817)		// Trip Zone Clear Register
#define TZFRC(i)		RA(((i)-1)*0x40+0x6818)		// Trip Zone Force Register
#define ETSEL(i)		RA(((i)-1)*0x40+0x6819)		// Event Trigger Selection Register
#define ETPS(i)			RA(((i)-1)*0x40+0x681A)		// Event Trigger Prescale Register
#define ETFLG(i)		RA(((i)-1)*0x40+0x681B)		// Event Trigger Flag Register
#define ETCLR(i)		RA(((i)-1)*0x40+0x681C)		// Event Trigger Clear Register
#define ETFRC(i)		RA(((i)-1)*0x40+0x681D)		// Event Trigger Force Register
#define PCCTL(i)		RA(((i)-1)*0x40+0x681E)		// PWM Chopper Control Register
#define HRCNFG(i)		RA(((i)-1)*0x40+0x6820)		// HRPWM Configuration Register
#define HRPWR(i)		RA(((i)-1)*0x40+0x6821)		// HRPWM Power Register
#define HRMSTEP(i)		RA(((i)-1)*0x40+0x6826)		// HRPWM MEP Step Register
#define HRPCTL(i)		RA(((i)-1)*0x40+0x6828)		// High resolution Period Control Register
													// Note: This bit and the TBCTL[PHSEN] bit must be set to 1 when high resolution period control is
													// enabled for up-down count mode even if TBPHSHR = 0x0000.
													// 
#define HRPCTL_TBPHSHRLOADE_MASK	(1<<2)			// TBPHSHR Load Enable
													// This bit allows you to synchronize ePWM modules with a high-resolution phase on a SYNCIN,
													// TBCTL[SWFSYNC], or digital compare event. This allows for multiple ePWM modules operating
													// at the same frequency to be phase aligned with high-resolution.
													// 
#define	HRPCTL_TBPHSHRLOADE_DISABLE	0				// Disables synchronization of high-resolution phase on a SYNCIN, TBCTL[SWFSYNC] or digital
													// compare event.
													// 
#define	HRPCTL_TBPHSHRLOADE_ENABLE	(1<<2)			// Synchronize the high-resolution phase on a SYNCIN, TBCTL[SWFSYNC] or digital comparator
													// synchronization event. The phase is synchronized using the contents of the high-resolution phase
													// TBPHSHR register.
													// The TBCTL[PHSEN] bit which enables the loading of the TBCTR register with TBPHS register
													// value on a SYNCIN, or TBCTL[SWFSYNC] event works independently. However, users need to
													// enable this bit also if they want to control phase in conjunction with the high-resolution period
													// feature.

#define HRPCTL_HRPE_MASK			1				// High Resolution Period Enable Bit
													// When high-resolution period is enabled, TBCTL[CTRMODE] = 0,1 (down-count mode) is not
													// supported.
													// 
#define HRPCTL_HRPE_DISABLE			0   			// High resolution period feature disabled. In this mode the ePWM behaves as a Type 0 ePWM.
													//
#define HRPCTL_HRPE_ENABLE			1   			// High resolution period enabled. In this mode the HRPWM module can control high-resolution of
													// both the duty and frequency.

#define TBPRDHRM(i)		RA(((i)-1)*0x40+0x682A)		// Time Base Period HRPWM Register Mirror
#define TBPRDM(i)		RA(((i)-1)*0x40+0x682B)		// Time Base Period Register Mirror
#define CMPAHRM(i)		RA(((i)-1)*0x40+0x682C)		// Compare A HRPWM Register Mirror
#define CMPAM(i)		RA(((i)-1)*0x40+0x682D)		// Compare A Register Mirror
#define DCTRIPSEL(i)	RA(((i)-1)*0x40+0x6830)		// Digital Compare Trip Select Register
#define DCACTL(i)		RA(((i)-1)*0x40+0x6831)		// Digital Compare A Control Register
#define DCBCTL(i)		RA(((i)-1)*0x40+0x6832)		// Digital Compare B Control Register
#define DCFCTL(i)		RA(((i)-1)*0x40+0x6833)		// Digital Compare Filter Control Register
#define DCAPCT(i)		RA(((i)-1)*0x40+0x6834)		// Digital Compare Capture Control Register
#define DCFOFFSET(i)	RA(((i)-1)*0x40+0x6835)		// Digital Compare Filter Offset Register
#define DCFOFFSETCNT(i)	RA(((i)-1)*0x40+0x6836)		// Digital Compare Filter Offset Counter Register
#define DCFWINDOW(i)	RA(((i)-1)*0x40+0x6837)		// Digital Compare Filter Window Register
#define DCFWINDOWCNT(i)	RA(((i)-1)*0x40+0x6838)		// Digital Compare Filter Window Counter Register
#define DCCAP(i)		RA(((i)-1)*0x40+0x6839)		// Digital Compare Counter Capture Register


typedef void interrupt (*PISR)(void);

#define IV_TIMER1		13
#define IV_TIMER2		14
#define IV_DATALOG		15
#define IV_RTOSINT		16
#define IV_EMUINT		17
#define IV_NMI  		18
#define IV_ILLEGAL  	19
#define IV_USER1		20
#define IV_USER2		21
#define IV_USER3		22
#define IV_USER4		23
#define IV_USER5		24
#define IV_USER6		25
#define IV_USER7		26
#define IV_USER8		27
#define IV_USER9		28
#define IV_USER10   	29
#define IV_USER11   	30
#define IV_USER12   	31
#define IV_ADCINT1A  	32	// not sure how this is different from IV_ADCINT1
#define IV_ADCINT2A		33	// not sure how this is different from IV_ADCINT2
#define IV_XINT1		35
#define IV_XINT2		36
#define IV_ADCINT9		37
#define IV_TINT0		38
#define IV_WAKEINT		39
#define IV_EPWM1_TZINT	40
#define IV_EPWM2_TZINT	41
#define IV_EPWM3_TZINT	42
#define IV_EPWM4_TZINT	43
#define IV_EPWM1_INT	48
#define IV_EPWM2_INT	49
#define IV_EPWM3_INT	50
#define IV_EPWM4_INT	51
#define IV_ECAP1_INT	56
#define IV_EQEP1_INT	64
#define IV_SPIRXINTA	72
#define IV_SPITXINTA	73
#define IV_I2CINT1A		88
#define IV_I2CINT2A		89
#define IV_SCIRXINTA	96
#define IV_SCITXINTA	97
#define IV_ADCINT1		104
#define IV_ADCINT2		105
#define IV_ADCINT3		106
#define IV_ADCINT4		107
#define IV_ADCINT5		108
#define IV_ADCINT6		109
#define IV_ADCINT7		110
#define IV_ADCINT8		111
#define IV_XINT3		120

