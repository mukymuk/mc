// read/write command bit
#define DRV8301_READ					0x8000
#define DRV8301_WRITE					0x0000
#define DRV8301_RW_MASK					0x8000
#define DRV8301_FRAME_FAULT				0x8000
#define DRV8301_ADDRESS_MASK			0x7800
#define DRV8301_DATA_MASK				0x07FF

#define DRV8301_COMAMND(rw,reg,data)	(DRV8301_##rw|DRV8301_##reg|(data))

// registers
#define DRV8301_STATUS1					(0x0<<11)	// Status Register 1
#define DRV8301_STATUS2					(0x1<<11)	// Status Register 2 
#define DRV8301_GATE					(0x2<<11)	// Control Register 1 for Gate Driver Control 
#define DRV8301_SHUNT					(0x3<<11)	// Control Register 2 for Current Shunt Amplifiers and Misc Control

// register bitfields

#define DRV8301_STATUS1_FAULT			(1<<10)    
#define DRV8301_STATUS1_GVDD_UV			(1<<9)	   	// gate charge pump undervoltage (~8V)
#define DRV8301_STATUS1_PVDD_UV			(1<<8)	   	// power under voltage (~6V)
#define DRV8301_STATUS1_OTSD			(1<<7)	   	// Junction temperature for overtemperature shut down (150C)
#define DRV8301_STATUS1_OTW				(1<<6)	   	// Junction temperature for overtemperature warning (115C)
#define DRV8301_STATUS1_FETHA_OC		(1<<5)	   	// overcurrent
#define DRV8301_STATUS1_FETLA_OC		(1<<4)	   	// overcurrent	
#define DRV8301_STATUS1_FETHB_OC		(1<<3)	   	// overcurrent
#define DRV8301_STATUS1_FETLB_OC		(1<<2)	   	// overcurrent
#define DRV8301_STATUS1_FETHC_OC		(1<<1)	   	// overcurrent
#define DRV8301_STATUS1_FETLC_OC		(1<<0)	   	// overcurrent

#define DRV8301_STATUS2_GVDD_OV			(1<<7)	   	// gate charge pump over voltage (16V)	
#define DRV8301_STATUS2_DEVID_MASK		(0xF)      

#define DRV8301_GATE_CURRENT_MASK		(3<<0)	   	// FET gate drive current
#define DRV8301_GATE_CURRENT_1A7		(0)		   	// 1.7A
#define DRV8301_GATE_CURRENT_0A7		(1<<0)	   	// 0.7A
#define DRV8301_GATE_CURRENT_A25		(3<<0)	   	// 0.25A

#define DRV8301_GATE_RESET				(1<<2)	   	// Reset gate driver latched faults (reverts to 0) 

#define DRV8301_GATE_PWM_MODE_MASK		(1<<3)     
#define DRV8301_GATE_PWM_MODE_6IN		0		   	// 6 PWM inputs
#define DRV8301_GATE_PWM_MODE_3IN		(1<<3)	   	// 3 PWM inputs

#define DRV8301_GATE_OCP_MASK			(3<<4)	   	// Overcurrent protection mode
#define DRV8301_GATE_OCP_LIMIT			0		   	// Current limit
#define DRV8301_GATE_OCP_SHUTDOWN		(1<<4)	   	// OC latch shut down 
#define DRV8301_GATE_OCP_REPORT			(2<<4)	   	// Report only 
#define DRV8301_GATE_OCP_DISABLE		(3<<4)	   	// OC disabled 

#define DRV8301_GATE_OC_ADJUST_MASK		(0x1F<<6)	// Vds
#define DRV8301_GATE_OC_ADJUST_0V060	(0<<6)		// 0.060V
#define DRV8301_GATE_OC_ADJUST_0V068	(1<<6)		// 0.068V
#define DRV8301_GATE_OC_ADJUST_0V076	(2<<6)		// 0.076V
#define DRV8301_GATE_OC_ADJUST_0V086	(3<<6)		// 0.086V
#define DRV8301_GATE_OC_ADJUST_0V097	(4<<6)		// 0.097V
#define DRV8301_GATE_OC_ADJUST_0V109	(5<<6)		// 0.109V
#define DRV8301_GATE_OC_ADJUST_0V123	(6<<6)		// 0.124V
#define DRV8301_GATE_OC_ADJUST_0V138	(7<<6)		// 0.138V
#define DRV8301_GATE_OC_ADJUST_0V155	(8<<6)		// 0.155V
#define DRV8301_GATE_OC_ADJUST_0V175	(9<<6)		// 0.175V
#define DRV8301_GATE_OC_ADJUST_0V197	(10<<6)		// 0.197V
#define DRV8301_GATE_OC_ADJUST_0V222	(11<<6)		// 0.222V
#define DRV8301_GATE_OC_ADJUST_0V250	(12<<6)		// 0.250V
#define DRV8301_GATE_OC_ADJUST_0V282	(13<<6)		// 0.282V
#define DRV8301_GATE_OC_ADJUST_0V317	(14<<6)		// 0.317V
#define DRV8301_GATE_OC_ADJUST_0V358	(15<<6)		// 0.358V
#define DRV8301_GATE_OC_ADJUST_0V403	(16<<6)		// 0.403V
#define DRV8301_GATE_OC_ADJUST_0V454	(17<<6)		// 0.454V
#define DRV8301_GATE_OC_ADJUST_0V511	(18<<6)		// 0.511V
#define DRV8301_GATE_OC_ADJUST_0V576	(19<<6)		// 0.576V
#define DRV8301_GATE_OC_ADJUST_0V648	(20<<6)		// 0.648V
#define DRV8301_GATE_OC_ADJUST_0V730	(21<<6)		// 0.730V
#define DRV8301_GATE_OC_ADJUST_0V822	(22<<6)		// 0.822V
#define DRV8301_GATE_OC_ADJUST_0V926	(23<<6)		// 0.926V
#define DRV8301_GATE_OC_ADJUST_1V043	(24<<6)		// 1.043V
#define DRV8301_GATE_OC_ADJUST_1V175	(25<<6)		// 1.175V
#define DRV8301_GATE_OC_ADJUST_1V324	(26<<6)		// 1.324V
#define DRV8301_GATE_OC_ADJUST_1V491	(27<<6)		// 1.491V
#define DRV8301_GATE_OC_ADJUST_1V679	(28<<6)		// 1.679V
#define DRV8301_GATE_OC_ADJUST_1V892	(29<<6)		// 1.892V
#define DRV8301_GATE_OC_ADJUST_2V131	(30<<6)		// 2.131V
#define DRV8301_GATE_OC_ADJUST_2V400	(31<<6)		// 2.400V

#define DRV8301_SHUNT_OCTW_MASK			(3<<0)		// OCTW pin usage
#define DRV8301_SHUNT_OCTW_OT_OC		(0<<0)		// Report both OT and OC at nOCTW pin
#define DRV8301_SHUNT_OCTW_OT			(1<<0)		// Report OT only 
#define DRV8301_SHUNT_OCTW_OC			(2<<0)		// Report OC only 

#define DRV8301_SHUNT_GAIN_MASK			(3<<2)
#define DRV8301_SHUNT_GAIN_10			(0<<2)
#define DRV8301_SHUNT_GAIN_20			(1<<2)
#define DRV8301_SHUNT_GAIN_40			(2<<2)
#define DRV8301_SHUNT_GAIN_80			(3<<2)

#define DRV8301_SHUNT_INPUT1_MASK		(1<<4)
#define DRV8301_SHUNT_INPUT1_LOAD		0			// Shunt amplifier 1 connects to load through input pins 
#define DRV8301_SHUNT_INPUT1_SHORT		(1<<4)		// Shunt amplifier 1 shorts input pins and disconnects from load for external calibration

#define DRV8301_SHUNT_INPUT2_MASK		(1<<5)
#define DRV8301_SHUNT_INPUT2_LOAD		0			// Shunt amplifier 2 connects to load through input pins 
#define DRV8301_SHUNT_INPUT2_SHORT		(1<<5)		// Shunt amplifier 2 shorts input pins and disconnects from load for external calibration

#define DRV8301_SHUNT_OC_MASK			(1<<6)
#define DRV8301_SHUNT_OC_CYCLE			0			// Cycle by cycle 
#define DRV8301_SHUNT_OC_OFFTIME		(1<<6)		// Off-time control 


