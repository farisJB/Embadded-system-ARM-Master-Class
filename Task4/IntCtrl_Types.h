#include "std_Types.h"

#define NVIC_ENABLE_BASE_ADDRESS 			((volatile uint32*)0xE000E0004)
#define NVIC_PIROIRTY_BASE_ADDRESS			((volatile uint32*)0xE000E0008)
#define SRAM_BASE				0x20000000
#define BASE_SRAM_ALIAS 		0x22000000
#define PERI_BASE 				0x40000000
#define BASE_PRI_ALIAS 			0x42000000
