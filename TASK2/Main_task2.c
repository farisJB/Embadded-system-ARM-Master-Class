#include "std_Types.h"
#include "CPU_Driver.h"

int main()
{
	while(1)
	{
		CpuDriver_StartCriticalSection();
			CpuDriver_DisableGlobalInterrupt();
		CpuDriver_StopCriticalSection();
			CpuDriver_EnableGlobalInterrupt();

		Cpuswitch_unprivaleged();
		Cpuswitch_privaleged();
	}
 return 0;
}