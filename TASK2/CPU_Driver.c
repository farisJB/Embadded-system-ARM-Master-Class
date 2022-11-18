#include "CPU_Driver.h"	
    
    void 	CpuDriver_StartCriticalSection(void)
    {
        CpuDriver_DisableGlobalInterrupt();
    }
	void 	CpuDriver_StopCriticalSection(void)
    {
        CpuDriver_EnableGlobalInterrupt();
    }

    void Cpuswitch_privaleged()
    {
        ENABLE_INTERRUPT("SVC #1");
    }
    void Cpuswitch_unprivaleged()
    {
        DISABLE_INTERRUPT("MOV RO, 0x0\n");
        DISABLE_INTERRUPT("MSR CONTROL, RO\n");
    }