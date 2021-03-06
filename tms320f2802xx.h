
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

#define XCLK_XCLKINSEL_MASK			(1<<6)
#define XCLK_XCLKINSEL_GPIO38		0
#define XCLK_XCLKINSEL_GPIO19		(1<<6)

#define XCLK_XCLKOUTDIV_MASK		(3<<0)
#define XCLK_XCLKOUTDIV_DIV4		(0<<0)
#define XCLK_XCLKOUTDIV_DIV2		(1<<0)
#define XCLK_XCLKOUTDIV_DIV1		(2<<0)
#define XCLK_XCLKOUTDIV_OFF			(3<<0)

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
														//  Enable ePWM module clocks in the PCLKCR1 register.
														//  Set TBCLKSYNC to 0.
														//  Configure prescaler values and ePWM modes.
														//  Set TBCLKSYNC to 1.

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

#define GPA_MASK(io)				((uint32_t)1<<(io))
#define GPB_MASK(io)				((uint32_t)1<<((io)-32))


#define GPACTRL						RA32(0x6F80)	// GPIO A Control Register (GPIO0-GPIO31) 

													
// TODO:  GPACTRL bitfields

#define GPAQSEL1 					RA32(0x6F82)	// GPIO A Qualifier Select 1 Register (GPIO0-GPIO15)
													// Select input qualification type for GPIO0 to GPIO15. The input qualification of each GPIO
													// input is controlled by two bits as shown in Figure 57
										
#define GPQSEL_SYSCLKOUT			0				// Synchronize to SYSCLKOUT only. Valid for both peripheral and GPIO pins.
#define GPQSEL_3					1				// Qualification using 3 samples. Valid for pins configured as GPIO or a peripheral function.
													// The time between samples is specified in the GPACTRL register.
#define GPQSEL_6					2				// Qualification using 6 samples. Valid for pins configured as GPIO or a peripheral function.
													// The time between samples is specified in the GPACTRL register.
#define GPQSEL_ASYNC				3				// Asynchronous. (no synchronization or qualification). This option applies to pins configured
													// as peripherals only. If the pin is configured as a GPIO input, then this option is the same as
													// 0,0 or synchronize to SYSCLKOUT.

#define GPAQSEL1_GPIO(gpio,mode)	((uint32_t)(mode))<<((gpio)*2)	// GPIO0-GPIO15
 													
#define GPAQSEL2 					RA32(0x6F84)	// GPIO A Qualifier Select 2 Register (GPIO16-GPIO31)
													// Select input qualification type for GPIO16 to GPIO31. The input qualification of each GPIO
													// input is controlled by two bits as shown in Figure 58.
#define GPAQSEL2_GPIO(gpio,mode)	((uint32_t)(mode))<<(((gpio)-16)*2)	// GPIO16-GPIO31
													
#define GPBQSEL1					RA32(0x006F92)	// GPIO B Qualifier Select 1 Register (GPIO32 to 38)
													// Select input qualification type for GPIO32 to GPIO38 . The input qualification of each GPIO
													// input is controlled by two bits as shown in Figure 59.


#define GPBQSEL1_GPIO(gpio,mode)	(mode)<<(((gpio)-32)*2)	// GPIO32-GPIO38


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
#define GPAMUX2_GPIO29_GPIO			0				// GPIO29 (I/O) General purpose I/O 29 (default) (I/O)
#define GPAMUX2_GPIO29_SCITXDA		(1<<26) 		// SCITXDA - SCI-A transmit. (O)
#define GPAMUX2_GPIO29_SCLA			(2<<26) 		// SCLA (I/OC)
#define GPAMUX2_GPIO29_TZ3			(3<<26) 		// TZ3 - Trip zone 3(I)

#define GPAMUX2_GPIO28_MASK			(3<<24)			
#define GPAMUX2_GPIO28_GPIO			0   			// GPIO28 (I/O) General purpose I/O 28 (default) (I/O)
#define GPAMUX2_GPIO28_SCIRXDA		(1<<24) 		// SCIRXDA - SCI-A receive (I)
#define GPAMUX2_GPIO28_SDAA			(2<<24) 		// SDAA (I/OC)
#define GPAMUX2_GPIO28_TZ2			(3<<24) 		// TZ2 - Trip zone 2(I)

#define GPAMUX2_GPIO19_MASK			(3<<6)
#define GPAMUX2_GPIO19_GPIO			0				// GPIO19 - General purpose I/O 19 (default) (I/O)
#define GPAMUX2_GPIO19_SPISTEA		(1<<6)  		// SPISTEA - SPI-A slave transmit enable (I/O)
#define GPAMUX2_GPIO19_SCIRXDA		(2<<6)  		// SCIRXDA (I)
#define GPAMUX2_GPIO19_ECAP1		(3<<6)  		// ECAP1 (I/O)

#define GPAMUX2_GPIO18_MASK			(3<<4)
#define GPAMUX2_GPIO18_GPIO			0				// GPIO18 - General purpose I/O 18 (default) (I/O)
#define GPAMUX2_GPIO18_SPICLKA		(1<<4)  		// SPICLKA - SPI-A clock (I/O)
#define GPAMUX2_GPIO18_SCITXDA		(2<<4)  		// SCITXDA (O)
#define GPAMUX2_GPIO18_XCLKOUT		(3<<4)  		// XCLKOUT (O) - External clock output

#define GPAMUX2_GPIO17_MASK			(3<<2)
#define GPAMUX2_GPIO17_GPIO			0				// GPIO17 - General purpose I/O 17 (default) (I/O)
#define GPAMUX2_GPIO17_SPISOMIA		(1<<2)  		// SPISOMIA - SPI-A slave-out, master-in (I/O)
#define GPAMUX2_GPIO17_TZ3			(3<<2)			// TZ3 - Trip zone 3 (I)

#define GPAMUX2_GPIO16_MASK			(3<<0)			// GPIO16 - General purpose I/O 16 (default) (I/O)
#define GPAMUX2_GPIO16_SPISIMOA		(1<<0)  		// SPISIMOA - SPI-A slave-in, master-out (I/O),
#define GPAMUX2_GPIO16_TZ2			(3<<0)			// TZ2 - Trip zone 2 (I)

#define GPADIR 						RA32(0x6F8A)	// GPIO A Direction Register (GPIO0-GPIO31)

#define GPADIR_INPUT(io)			0				// GPIO A input (GPIO0-GPIO31)
#define GPADIR_OUTPUT(io)			GPA_MASK(io)	// GPIO A output (GPIO0-GPIO31)

#define GPAPUD 						RA32(0x6F8C)	// GPIO A Pull Up Disable Register (GPIO0-GPIO31)
													
#define GPAPUD_ENABLE(io)			0				// enable port A pullup (GPIO0-GPIO31)
#define GPAPUD_DISABLE(io)			GPA_MASK(io)	// disable port A pullup (GPIO0-GPIO31)
													
#define GPBCTRL 					RA32(0x6F90)	// GPIO B Control Register (GPIO32-GPIO38)

#define GPBMUX1 					RA32(0x6F96)	// GPIO B MUX 1 Register (GPIO32-GPIO38)

#define GPBMUX1_GPIO38_MASK			(3<<12)
#define GPBMUX1_GPIO38_GPIO			0

#define GPBMUX1_GPIO37_MASK			(3<<10)
#define GPBMUX1_GPIO37_GPIO			0

#define GPBMUX1_GPIO36_MASK			(3<<8)
#define GPBMUX1_GPIO36_GPIO			0		

#define GPBMUX1_GPIO35_MASK			(3<<6)
#define GPBMUX1_GPIO35_GPIO			0

#define GPBMUX1_GPIO34_MASK			(3<<4)
#define GPBMUX1_GPIO34_GPIO			0				// GPIO 34 - general purpose I/O 34 (default)
#define GPBMUX1_GPIO34_COMP2OUT		(1<<4)  		// COMP2OUT (O)

#define GPBMUX1_GPIO33_MASK			(3<<2)
#define GPBMUX1_GPIO33_GPIO			0				// GPIO 33 - general purpose I/O 33 (default)
#define GPBMUX1_GPIO33_SCLA			(1<<2)  		// SCLA - I2C clock open drain bidirectional port (I/O)
#define GPBMUX1_GPIO33_EPWMSYNCO	(2<<2)  		// EPWMSYNCO - External ePWM sync pulse output (O)
#define GPBMUX1_GPIO33_ADCSOCBO		(3<<2)  		// ADCSOCBO - ADC start-of-conversion B (O)
													  
#define GPBMUX1_GPIO32_MASK			(3<<0)
#define GPBMUX1_GPIO32_GPIO			0				// GPIO 32 - general purpose I/O 32 (default)
#define GPBMUX1_GPIO32_SDAA			(1<<0)  		// SDAA - I2C data open drain bidirectional port (I/O)
#define GPBMUX1_GPIO32_EPWMSYNCI	(2<<0)  		// EPWMSYNCI - External ePWM sync pulse input (I)
#define GPBMUX1_GPIO32_ADCSOCAO		(3<<0)  		// ADCSOCAO - ADC start-of-conversion A (O)

#define GPBDIR 						RA32(0x6F9A)	// GPIOOBBDirectiontRegist-conversioneBr(O) (GPIO32-GPIO38)
													
#define GPBDIR_INPUT(io)			0				// GPIO B input (GPIO32-GPIO38)
#define GPBDIR_OUTPUT(io)			GPB_MASK(io)	// GPIO B output (GPIO32-GPIO38)

#define GPBPUD 						RA32(0x6F9C)	// GPIO B Pull Up Disable Register (GPIO32-GPIO38)
													
#define GPBPUD_ENABLE(io)			0				// enable port B pullup (GPIO32-GPIO38)
#define GPBPUD_DISABLE(io)			GPB_MASK(io)	// disable port B pullup (GPIO32-GPIO38)

#define AIOMUX1 					RA32(0x6FB6)	// Analog, I/O MUX 1 register (AIO0 - AIO15)
													//
#define AIOMUX1_AIO14_MASK			(3<<28)
#define AIOMUX1_AIO14_ENABLE		0
#define AIOMUX1_AIO14_DISABLE		(3<<28)

#define AIOMUX1_AIO12_MASK			(3<<24)
#define AIOMUX1_AIO12_ENABLE		0
#define AIOMUX1_AIO12_DISABLE		(3<<24)

#define AIOMUX1_AIO10_MASK			(3<<20)
#define AIOMUX1_AIO10_ENABLE		0
#define AIOMUX1_AIO10_DISABLE		(3<<20)

#define AIOMUX1_AIO6_MASK			(3<<12)
#define AIOMUX1_AIO6_ENABLE			0
#define AIOMUX1_AIO6_DISABLE		(3<<12)

#define AIOMUX1_AIO4_MASK			(3<<8)
#define AIOMUX1_AIO4_ENABLE			0
#define AIOMUX1_AIO4_DISABLE		(3<<8)

#define AIOMUX1_AIO2_MASK			(3<<4)
#define AIOMUX1_AIO2_ENABLE			0
#define AIOMUX1_AIO2_DISABLE		(3<<4)

#define AIODIR 						RA32(0x6FBA)	// Analog, I/O Direction Register (AIO0 - AIO15) 

#define AIODIR_AIO14_MASK			(1<<14)
#define AIODIR_AIO14_INPUT			0
#define AIODIR_AIO14_DISABLE		(1<<14)

#define AIODIR_AIO12_MASK			(1<<12)
#define AIODIR_AIO12_INPUT			0
#define AIODIR_AIO12_DISABLE		(1<<12)

#define AIODIR_AIO10_MASK			(1<<10)
#define AIODIR_AIO10_INPUT			0
#define AIODIR_AIO10_DISABLE		(1<<10)

#define AIODIR_AIO6_MASK			(1<<6)
#define AIODIR_AIO6_INPUT			0
#define AIODIR_AIO6_DISABLE			(1<<6)

#define AIODIR_AIO4_MASK			(1<<4)
#define AIODIR_AIO4_INPUT			0
#define AIODIR_AIO4_DISABLE			(1<<4)

#define AIODIR_AIO2_MASK			(1<<2)
#define AIODIR_AIO2_INPUT			0
#define AIODIR_AIO2_DISABLE			(1<<2)

#define GPASET						RA32(0x006FC2)
#define GPBSET						RA32(0x006FCA)
#define GPACLEAR					RA32(0x006FC4)
#define GPBCLEAR					RA32(0x006FCC)
#define GPATOGGLE					RA32(0x006FC6)
#define GPBTOGGLE   				RA32(0x006FCE)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// WATCHDOG
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define WDCR						RA(0x007029)

#define WDCR_WDFLAG_MASK			(1<<7)
#define WDCR_WDFLAG_POWER_ON		(0) 
#define WDCR_WDFLAG_WATCHDOG		(1<<7)

#define WDCR_WDDIS_MASK				(1<<6)
#define WDCR_WDDIS_DISABLE			(1<<6)
#define WDCR_WDDIS_ENABLE			0   

#define WDCR_WDCHK_MASK				(7<<3)
#define WDCR_WDCHK_KEY				(5<<3)
#define WDCR_WDCHK_RESET			0   

#define WDCR_WDPS_MASK				(7<<0)
#define WDCR_WDPS_DIV512			0   
#define WDCR_WDPS_DIV256			1   
#define WDCR_WDPS_DIV128			2   
#define WDCR_WDPS_DIV64				3   
#define WDCR_WDPS_DIV32				4   
#define WDCR_WDPS_DIV16				5   
#define WDCR_WDPS_DIV8				6   
#define WDCR_WDPS_DIV4				7   

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
													// TBCLK = SYSCLKOUT / (HSPCLKDIV Χ CLKDIV)
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
													// TBCLK = SYSCLKOUT / (HSPCLKDIV Χ CLKDIV)
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
													//  Do nothing; the event is ignored.
													//  Clear: Pull the EPWMxA and/or EPWMxB signal low
													//  Set: Pull the EPWMxA and/or EPWMxB signal high
													//  Toggle the EPWMxA and/or EPWMxB signal
													// Shadowing of this register is enabled and disabled by the CMPCTL[SHDWAMODE] bit. By default this
													// register is shadowed.
													//  If CMPCTL[SHDWAMODE] = 0, then the shadow is enabled and any write or read will automatically
													// go to the shadow register. In this case, the CMPCTL[LOADAMODE] bit field determines which event
													// will load the active register from the shadow register.
													//  Before a write, the CMPCTL[SHDWAFULL] bit can be read to determine if the shadow register is
													// currently full.
													//  If CMPCTL[SHDWAMODE] = 1, then the shadow register is disabled and any write or read will go
													// directly to the active register, that is the register actively controlling the hardware.
													//  In either mode, the active and shadow registers share the same memory map address. 


#define CMPB(i)			RA(((i)-1)*0x40+0x680A)		// The value in the active CMPB register is continuously compared to the time-base counter (TBCTR). When
													// the/values are equal, the counter-compare module generates a "time-base counter equal to counter
													// compare B" event. This event is sent to the action-qualifier where it is qualified and converted it into one
													// or more actions. These actions can be applied to either the EPWMxA or the EPWMxB output depending
													// on the configuration of the AQCTLA and AQCTLB registers. The actions that can be defined in the
													// AQCTLA and AQCTLB registers include:
													//  Do nothing. event is ignored.
													//  Clear: Pull the EPWMxA and/or EPWMxB signal low
													//  Set: Pull the EPWMxA and/or EPWMxB signal high
													//  Toggle the EPWMxA and/or EPWMxB signal
													// Shadowing of this register is enabled and disabled by the CMPCTL[SHDWBMODE] bit. By default this
													// register is shadowed.
													//  If CMPCTL[SHDWBMODE] = 0, then the shadow is enabled and any write or read will automatically
													// go to the shadow register. In this case, the CMPCTL[LOADBMODE] bit field determines which event
													// will load the active register from the shadow register:
													//  Before a write, the CMPCTL[SHDWBFULL] bit can be read to determine if the shadow register is
													// currently full.
													//  If CMPCTL[SHDWBMODE] = 1, then the shadow register is disabled and any write or read will go
													// directly to the active register, that is the register actively controlling the hardware.
													//  In either mode, the active and shadow registers share the same memory map address.

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	GPIO INTERRUPT
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define XINT1CR			RA(0x007070)				// XINT1 configuration register
#define XINT2CR			RA(0x007071)				// XINT2 configuration register
#define XINT3CR			RA(0x007072)				// XINT3 configuration register

#define XINTCR_POLARITY_MASK		(3<<2)			// This read/write bit determines whether interrupts are generated on the rising edge or the
													// falling edge of a signal on the pin.
#define XINTCR_POLARITY_FALLING		(0)				// Interrupt generated on a falling edge (high-to-low transition)
#define XINTCR_POLARITY_RISING		(1<<2)			// Interrupt generated on a rising edge (low-to-high transition)
#define XINTCR_POLARITY_BOTH		(3<<2)			// Interrupt generated on both a falling edge and a rising edge (high-to-low and low-to-high transition)

#define XINTCR_INTERRUPT_MASK		1				// This read/write bit enables or disables external interrupt XINTn.
#define XINTCR_INTERRUPT_ENABLE		1
#define XINTCR_INTERRUPT_DISABLE	0

#define XINT1CTR		RA(0x007078)				// XINT1 configuration register
#define XINT2CTR		RA(0x007079)				// XINT2 configuration register
#define XINT3CTR		RA(0x00707A)				// XINT3 configuration register

#define GPIOXINT1SEL	RA(0x6FE0)					// XINT1 Source Select Register (GPIO0-GPIO31)
#define GPIOXINT2SEL	RA(0x6FE1)					// XINT2 Source Select Register (GPIO0-GPIO31)
#define GPIOXINT3SEL	RA(0x6FE2)					// XINT3 Source Select Register (GPIO0-GPIO31)

#define GPIOXINTSEL_GPIO(i)		(i)					// Select the port A GPIO signal (GPIO0 - GPIO31) that will be used as the XINT1, XINT2, or
													// XINT3 interrupt source. In addition, you can configure the interrupt in the XINT1CR, XINT2CR,
													// or XINT3CR registers described in Section 6.6.
													// To use XINT2 as ADC start of conversion, enable it in the desired ADCSOCxCTL register.
													//  The ADCSOC signal is always rising edge sensitive.

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

typedef void interrupt(*PISR)(void)
;



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///  SPI
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define SPICCR						RA(0x007040)	// SPI-A Configuration Control Register

#define SPICCR_RESET_MASK			(1<<7)			// SPI software reset. When changing configuration, you should clear this bit before the changes and
													// set this bit before resuming operation.
#define SPICCR_RESET_ENABLE			0				// Initializes the SPI operating flags to the reset condition. Specifically, the RECEIVER OVERRUN
													// Flag bit (SPISTS.7), the SPI INT FLAG bit (SPISTS.6), and the TXBUF FULL Flag bit (SPISTS.5)
													// are cleared. The SPI configuration remains unchanged. If the module is operating as a master, the
													// SPICLK signal output returns to its inactive level.
#define SPICCR_RESET_DISABLE		(1<<7)			// SPI is ready to transmit or receive the next character. When the SPI SW RESET bit is a 0, a
													// character written to the transmitter will not be shifted out when this bit is set. A new character must
													// 
#define SPICCR_CLOCK_POLARITY_MASK 	(1<<6)			// Shift Clock Polarity. This bit controls the polarity of the SPICLK signal. CLOCK POLARITY and
													// CLOCK PHASE (SPICTL.3) control four clocking schemes on the SPICLK pin. See Section 1.5.3.
													// 
#define SPICCR_CLOCK_POLARITY_RISING 0				// Data is output on rising edge and input on falling edge. When no SPI data is sent, SPICLK is at low
													// level. The data input and output edges depend on the value of the CLOCK PHASE bit (SPICTL.3)
													// as follows:
													//  CLOCK PHASE = 0: Data is output on the rising edge of the SPICLK signal; input data is latched
													// on the falling edge of the SPICLK signal.
													//  CLOCK PHASE = 1: Data is output one half-cycle before the first rising edge of the SPICLK
													// signal and on subsequent falling edges of the SPICLK signal; input data is latched on the rising
													// edge of the SPICLK signal.
													// 
#define SPICCR_CLOCK_POLARITY_FALING	(1<<6)		//  Data is output on falling edge and input on rising edge. When no SPI data is sent, SPICLK is at
													//  high level. The data input and output edges depend on the value of the CLOCK PHASE bit
													// (SPICTL.3) as follows:
													//  CLOCK PHASE = 0: Data is output on the falling edge of the SPICLK signal; input data is
													// latched on the rising edge of the SPICLK signal.
													//  CLOCK PHASE = 1: Data is output one half-cycle before the first falling edge of the SPICLK
													// signal and on subsequent rising edges of the SPICLK signal; input data is latched on the falling
													// edge of the SPICLK signal.
#define SPICCR_SPILBK_MASK				(1<<4)		// SPI loopback. Loop back mode allows module validation during device testing. This mode is valid
													// only in master mode of the SPI.


#define SPICCR_SPILBK_DISABLE			0			// SPI loop back mode disabled  default value after reset


#define SPICCR_SPILBK_ENABLE			(1<<4)		// SPI loop back mode enabled, SIMO/SOMI lines are connected internally. Used for module self
													// tests.

#define SPICCR_CHARLEN_MASK				(4<<0)		// Character Length Control Bits 3-0. These four bits determine the number of bits to be shifted in or
													// out as a single character during one shift sequence. Table 8 lists the character length selected by
													// the bit values.
													// `
#define SPICCR_CHARLEN(i)				((i)-1)		// number of bits (1-16) to be shifted in or out as a single character during one shift sequence.

#define SPICTL						RA(0x007041)	// SPI-A Operation Control Register

#define SPICTL_OVERRUN_MASK			(1<<4)			// overrun Interrupt Enable. Setting this bit causes an interrupt to be generated when the RECEIVER
													// OVERRUN Flag bit (SPISTS.7) is set by hardware. Interrupts generated by the RECEIVER
													// OVERRUN Flag bit and the SPI INT FLAG bit (SPISTS.6) share the same interrupt vector.

#define SPICTL_OVERRUN_ENABLE		(1<<4)			// Enable RECEIVER OVERRUN Flag bit (SPISTS.7) interrupts

#define SPICTL_OVERRUN_DISABLE		0				// Disable RECEIVER OVERRUN Flag bit (SPISTS.7) interrupts


#define SPICTL_CLOCK_PHASE_MASK	(1<<3)				// SPI Clock Phase Select. This bit controls the phase of the SPICLK signal.
													// CLOCK PHASE and CLOCK POLARITY (SPICCR.6) make four different clocking schemes
													// possible (see Figure 4). When operating with CLOCK PHASE high, the SPI (master or slave)
													// makes the first bit of data available after SPIDAT is written and before the first edge of the SPICLK
													// signal, regardless of which SPI mode is being used.
#define SPICTL_CLOCK_PHASE_NORMAL	0				// Normal SPI clocking scheme, depending on the CLOCK POLARITY bit (SPICCR.6)
#define SPICTL_CLOCK_PHASE_DELAY	(1<<3)			// SPICLK signal delayed by one half-cycle; polarity determined by the CLOCK POLARITY bit

#define SPICTL_MODE_MASK			(1<<2)			// SPI Network Mode Control. This bit determines whether the SPI is a network master or slave.
													// During reset initialization, the SPI is automatically configured as a network slave.
#define SPICTL_MODE_MASTER			(1<<2)			// SPI configured as a master.
#define SPICTL_MODE_SLAVE			0				// SPI configured as a slave.

#define SPICTL_TALK_MASK			(1<<1)			// Master/Slave Transmit Enable. The TALK bit can disable data transmission (master or slave) by
													// placing the serial data output in the high-impedance state. If this bit is disabled during a
													// transmission, the transmit shift register continues to operate until the previous character is shifted
													// out. When the TALK bit is disabled, the SPI is still able to receive characters and update the status
													// flags. TALK is cleared (disabled) by a system reset.
#define SPICTL_TALK_DISABLE		0					// Disables transmission:
													//  Slave mode operation: If not previously configured as a general-purpose I/O pin, the SPISOMI
													//   pin will be put in the high-impedance state.
													//  Master mode operation: If not previously configured as a general-purpose I/O pin, the SPISIMO
													//   pin will be put in the high-impedance state.
#define SPICTL_TALK_ENABLE			(1<<1)			// Enables transmission For the 4-pin option, ensure to enable the receivers SPISTE input pin.

#define SPICTL_INT_MASK				(1<<0)			// SPI Interrupt Enable. This bit controls the SPIs ability to generate a transmit/receive interrupt. The
													// SPI INT FLAG bit (SPISTS.6) is unaffected by this bit.

#define SPICTL_INT_ENABLE			(1<<0)			// Enables interrupt
#define SPICTL_INT_DISABLE			0				// Disables interrupt

#define SPIST						RA(0x007042)	// SPI-A Status Register

#define SPIST_OVERRUN_MASK			(1<<7)			// SPI Receiver Overrun Flag. This bit is a read/clear-only flag. The SPI hardware sets this bit when a
													// receive or transmit operation completes before the previous character has been read from the
													// buffer. The bit indicates that the last received character has been overwritten and therefore lost
													// (when the SPIRXBUF was overwritten by the SPI module before the previous character was read
													// by the user application). The SPI requests one interrupt sequence each time this bit is set if the
													// OVERRUN INT ENA bit (SPICTL.4) is set high. The bit is cleared in one of three ways:
													//  Writing a 1 to this bit
													//  Writing a 0 to SPI SW RESET (SPICCR.7)
													//  Resetting the system
													// If the OVERRUN INT ENA bit (SPICTL.4) is set, the SPI requests only one interrupt upon the first
													// occurrence of setting the RECEIVER OVERRUN Flag bit. Subsequent overruns will not request
													// additional interrupts if this flag bit is already set. This means that in order to allow new overrun
													// interrupt requests the user must clear this flag bit by writing a 1 to SPISTS.7 each time an overrun
													// condition occurs. In other words, if the RECEIVER OVERRUN Flag bit is left set (not cleared) by
													// the interrupt service routine, another overrun interrupt will not be immediately re-entered when the
													// interrupt service routine is exited.
#define SPIST_OVERRUN_CLEAR			(1<<7)			// Clears this bit. The RECEIVER OVERRUN Flag bit should be cleared during the interrupt service
													// routine because the RECEIVER OVERRUN Flag bit and SPI INT FLAG bit (SPISTS.6) share the
													// same interrupt vector. This will alleviate any possible doubt as to the source of the interrupt when
													// the next byte is received.
#define SPIST_INT_FLAG				(1<<6)			// SPI Interrupt Flag. SPI INT FLAG is a read-only flag. The SPI hardware sets this bit to indicate that
													// it has completed sending or receiving the last bit and is ready to be serviced. The received
													// character is placed in the receiver buffer at the same time this bit is set. This flag causes an
													// interrupt to be requested if the SPI INT ENA bit (SPICTL.0) is set.
													// Writing a 0 has no effect
													// This bit is cleared in one of three ways:
													//  Reading SPIRXBUF
													//  Writing a 0 to SPI SW RESET (SPICCR.7)
													//  Resetting the system
#define SPIST_TX_FULL_FLAG			(1<<5)			// SPI Transmit Buffer Full Flag. This read-only bit gets set to 1 when a character is written to the SPI
													// Transmit buffer SPITXBUF. It is cleared when the character is automatically loaded into SPIDAT
													// when the shifting out of a previous character is complete.
#define SPIBRR						RA(0x007044)	// SPI-A Baud Rate Register
													// SPI Bit Rate (Baud) Control. These bits determine the bit transfer rate if the SPI is the network
													// master. There are 125 data-transfer rates (each a function of the CPU clock, LSPCLK) that can be
													// selected. One data bit is shifted per SPICLK cycle. (SPICLK is the baud rate clock output on the
													// SPICLK pin.)
													// If the SPI is a network slave, the module receives a clock on the SPICLK pin from the network
													// master; therefore, these bits have no effect on the SPICLK signal. The frequency of the input clock
													// from the master should not exceed the slave SPIs SPICLK signal divided by 4.
													// In master mode, the SPI clock is generated by the SPI and is output on the SPICLK pin. The SPI
													// baud rates are determined by the following formula:
													// For SPIBRR = 3 to 127:
													//   SPI Baud Rate = LSPCLK / (SPIBRR+1)
													// For SPIBRR = 0, 1, or 2:
													//   SPI Baud Rate = LSPCLK / 4
													// where: LSPCLK = Function of CPU clock frequency X low-speed peripheral clock of the device
													// SPIBRR = Contents of the SPIBRR in the master SPI device
#define SPIRXEMU					RA(0x0070460)	// Emulation Buffer Received Data. SPIRXEMU functions almost identically to SPIRXBUF, except that
													// reading SPIRXEMU does not clear the SPI INT FLAG bit (SPISTS.6). Once the SPIDAT has
													// received the complete character, the character is transferred to SPIRXEMU and SPIRXBUF, where
													// it can be read. At the same time, SPI INT FLAG is set.
													// This mirror register was created to support emulation. Reading SPIRXBUF clears the SPI INT
													// FLAG bit (SPISTS.6). In the normal operation of the emulator, the control registers are read to
													// continually update the contents of these registers on the display screen. SPIRXEMU was created
													// so that the emulator can read this register and properly update the contents on the display screen.
													// Reading SPIRXEMU does not clear the SPI INT FLAG bit, but reading SPIRXBUF clears this flag.
													// In other words, SPIRXEMU enables the emulator to emulate the true operation of the SPI more
													// accurately.
													// It is recommended that you view SPIRXEMU in the normal emulator run mode.
#define SPIRXBUF					RA(0x007047)	// Received Data. Once SPIDAT has received the complete character, the character is transferred to
													// SPIRXBUF, where it can be read. At the same time, the SPI INT FLAG bit (SPISTS.6) is set. Since
													// data is shifted into the SPIs most significant bit first, it is stored right-justified in this register.

#define	SPITXBUF					RA(0x007048)	// Transmit Data Buffer. This is where the next character to be transmitted is stored. When the
													// transmission of the current character has completed, if the TX BUF FULL Flag bit is set, the
													// contents of this register is automatically transferred to SPIDAT, and the TX BUF FULL Flag is
													// cleared.  Writes to SPITXBUF must be left-justified.
#define SPIDAT						RA(0x007049)	// Serial data. Writing to the SPIDAT performs two functions:
													//  It provides data to be output on the serial output pin if the TALK bit (SPICTL.1) is set.
													//  When the SPI is operating as a master, a data transfer is initiated. When initiating a transfer, see
													// the CLOCK POLARITY bit (SPICCR.6) described in Section 2.1.1 and the CLOCK PHASE bit
													// (SPICTL.3) described in Section 2.1.2, for the requirements.
													// In master mode, writing dummy data to SPIDAT initiates a receiver sequence. Since the data is not
													// hardware-justified for characters shorter than sixteen bits, transmit data must be written in
													// left-justified form, and received data read in right-justified form.
#define SPIFFTX						RA(0x00704A)	// SPI-A FIFO Transmit Register
#define SPIFFTX_SPIRST_MASK			(1<<15)			// SPI reset
#define SPIFFTX_SPIRST_RESET		0				// Write 0 to reset the SPI transmit and receive channels. The SPI FIFO register configuration bits will
													// be left as is.
#define SPIFFTX_SPIRST_RESUME		(1<<15) 		// SPI FIFO can resume transmit or receive. No effect to the SPI registers bits.

#define SPIFFTX_SPIFFENA_MASK		(1<<14)			// SPI FIFO enhancements
#define SPIFFTX_SPIFFENA_DISABLE	0				// SPI FIFO enhancements are disabled
#define SPIFFTX_SPIFFENA_ENABLE		(1<<14)			// SPI FIFO enhancements are enabled

#define SPIFFTX_TXFIFO_RESET_MASK	(1<<13)
#define SPIFFTX_TXFIFO_RESET		0				// Write 0 to reset the FIFO pointer to zero, and hold in reset.
#define SPIFFTX_TXFIFO_RESUME		(1<<13)			// Re-enable Transmit FIFO operation

#define SPIFFTX_TXFIFO_STATUS_MASK	(0x1F<<8)		// Transmit FIFO status
#define SPIFFTX_TXFIFO_STATUS_0		(0<<8)  		// Transmit FIFO is empty.
#define SPIFFTX_TXFIFO_STATUS_1		(1<<8)  		// Transmit FIFO has 1 word.
#define SPIFFTX_TXFIFO_STATUS_2		(2<<8)  		// Transmit FIFO has 2 words.
#define SPIFFTX_TXFIFO_STATUS_3		(3<<8)  		// Transmit FIFO has 3 words.
#define	SPIFFTX_TXFIFO_STATUS_4		(4<<8)			// Transmit FIFO has 4 words, which is the maximum.

#define	SPIFFTX_TXFFINT_FLAG		(1<<7)			// TXFIFO interrupt has occurred, This is a read-only bit.
#define	SPIFFTX_TXFFINT_CLEAR		(1<<6)			// Write 1 to clear TXFFINT flag in bit 7.

#define	SPIFFTX_TXFFIENA_MASK		(1<<5)			// TX FIFO interrupt enable
#define	SPIFFTX_TXFFIENA_ENABLE		(1<<5)  		// TX FIFO interrupt based on TXFFIVL match (less than or equal to) will be disabled .
#define	SPIFFTX_TXFFIENA_DISABLE	0   			// TX FIFO interrupt based on TXFFIVL match (less than or equal to) will be enabled.

#define SPIFFTX_TXFFIL_MASK			(0x1F)			// TXFFIL4-0 transmit FIFO interrupt level bits. Transmit FIFO will generate interrupt when the FIFO
													// status bits (TXFFST4?0) and FIFO level bits (TXFFIL4?0 ) match (less than or equal to).
#define SPIFFTX_TXFFIL(i)			(i)				// (0-4)

#define SPIFFRX						RA(0x00704B)	// SPI-A FIFO Receive Register

#define SPIFFRX_RXFFOVF_FLAG		(1<<15)			// Receive FIFO has overflowed, read-only bit. More than 16 words have been received in to the
													// FIFO, and the first received word is lost.
#define SPIFFRX_RXFFOVF_CLEAR		(1<<14)			// Write 1 to clear RXFFOVF flag in bit 15

#define SPIFFRX_RXFIFO_RESET_MASK	(1<<13)
#define SPIFFRX_RXFIFO_RESET		0				// Write 0 to reset the FIFO pointer to zero, and hold in reset.
#define SPIFFRX_RXFIFO_RESUME		(1<<13)			// Re-enable receive FIFO operation

#define SPIFFRX_RXFIFO_STATUS_MASK	(0x1F<<8)		// Receive FIFO status
#define SPIFFRX_RXFIFO_STATUS_0		(0<<8)  		// Receive FIFO is empty.
#define SPIFFRX_RXFIFO_STATUS_1		(1<<8)  		// Receive FIFO has 1 word.
#define SPIFFRX_RXFIFO_STATUS_2		(2<<8)  		// Receive FIFO has 2 words.
#define SPIFFRX_RXFIFO_STATUS_3		(3<<8)  		// Receive FIFO has 3 words.
#define	SPIFFRX_RXFIFO_STATUS_4		(4<<8)			// Receive FIFO has 4 words, which is the maximum.

#define	SPIFFRX_RXFFINT_FLAG		(1<<7)			// RXFIFO interrupt has occurred, This is a read-only bit.
#define	SPIFFRX_RXFFINT_CLEAR		(1<<6)			// Write 1 to clear RXFFINT flag in bit 7.

#define	SPIFFRX_RXFFIENA_MASK		(1<<5)			// RX FIFO interrupt enable
#define	SPIFFRX_RXFFIENA_ENABLE		(1<<5)  		// RX FIFO interrupt based on RXFFIVL match (less than or equal to) will be disabled .
#define	SPIFFRX_RXFFIENA_DISABLE	0   			// RX FIFO interrupt based on RXFFIVL match (less than or equal to) will be enabled.

#define SPIFFRX_RXFFIL_MASK			(0x1F)			// RXFFIL4-0 receive FIFO interrupt level bits. Receive FIFO will generate interrupt when the FIFO
													// status bits (RXFFST4-0) and FIFO level bits (RXFFIL4-0 ) match (less than or equal to).
#define SPIFFRX_RXFFIL(i)			(i)				// (0-4)

#define SPIFFCT						RA(0x00704C)	// FIFO transmit delay bits
													// These bits define the delay between every transfer from FIFO transmit buffer to transmit shift
													// register. The delay is defined in number SPI serial clock cycles. The 8-bit register could define a
													// minimum delay of 0 serial clock cycles and a maximum of 255 serial clock cycles.
													// In FIFO mode, the buffer (TXBUF) between the shift register and the FIFO should be filled only
													// after the shift register has completed shifting of the last bit. This is required to pass on the delay
													// between transfers to the data stream. In the FIFO mode TXBUF should not be treated as one
													// additional level of buffer.
#define SPIPRI						RA(0x00704F) 	// SPI-A Priority Control Register

#define SPIPRI_SUSPEND_MASK			(3<<4)			// These bits determine what occurs when an emulation suspend occurs (for example, when the
													// debugger hits a breakpoint). The peripheral can continue whatever it is doing (free-run mode) or, if in
													// stop mode, it can either stop immediately or stop when the current operation (the current
													// receive/transmit sequence) is complete.

#define SPIPRI_SUSPEND_STOP			0				// Transmission stops after midway in the bit stream while TSUSPEND is asserted. Once TSUSPEND
													// is deasserted without a system reset, the remainder of the bits pending in the DATBUF are shifted.
													// Example: If SPIDAT has shifted 3 out of 8 bits, the communication freezes right there. However, if
													// TSUSPEND is later deasserted without resetting the SPI, SPI starts transmitting from where it had
													// stopped (fourth bit in this case) and will transmit 8 bits from that point. The SCI module operates
													// differently.

#define SPIPRI_SUSPEND_FINISH		(2<<4)			// If the emulation suspend occurs before the start of a transmission, (i.e., before the first SPICLK
													// pulse) then the transmission will not occur. If the emulation suspend occurs after the start of a
													// transmission, then the data will be shifted out to completion. When the start of transmission occurs is
													// dependent on the baud rate used.
													// Standard SPI mode: Stop after transmitting the words in the shift register and buffer. That is, after
													// TXBUF and SPIDAT are empty.
													// In FIFO mode: Stop after transmitting the words in the shift register and buffer. That is, after TX FIFO
													// and SPIDAT are empty.

#define SPIPRI_SUSPEND_FREERUN		(1<<4)			// Free run, continue SPI operation regardless of suspend or when the suspend occurred.

#define SPIPRI_STEINV_MASK			(1<<1)			// SPISTE inversion bit (Not available on TMS320x2802x devices).
													// On devices with 2 SPI modules, inverting the SPISTE signal on one of the modules allows the device
													// to receive left and right- channel digital audio data.
#define SPIPRI_STEINV_ACTIVELOW		0				// SPISTE is active low (normal)
#define SPIPRI_STEINV_ACTIVEHIGH	(1<<1)			// SPISTE is active high (inverted)

#define SPIPRI_TRIWIRE_MASK			(1<<0)			// SPI 3-wire mode enable
#define SPIPRI_TRIWIRE_ENABLE		(1<<0)			// 3-wire SPI mode enabled. The unused pin becomes a GPIO pin. In master mode, the SPISIMO pin
													// becomes the SPIMOMI (master receive and transmit) pin and SPISOMI is free for non-SPI use. In
													// slave mode, the SIISOMI pin becomes the SPISISO (slave receive and transmit) pin and SPISIMO is
													// free for non-SPI use.
#define SPIPRI_TRIWIRE_DISABLE		0				// Normal 4-wire SPI mode

