#ifndef APP_MAIN_H
#define APP_MAIN_H

static void CPU_DISABLE_INTERRUPT(void)
{
    ("MOV RO, 0xE000E004");
    ("MSR PRIMASK, RO");
}
static void CPU_ENABLE_INTERRUPT(void)
{
    ("MOV R0, 0x0");
    ("MSR PRIMASK, R0");
}

void CpuDriver_StartCriticalSection(void);
void CpuDriver_StopCriticalSection(void);
void CpuDriver_DisableGlobalInterrupt(void);
void CpuDriver_EnableGlobalInterrupt(void);
void Cpuswitch_privaleged(void);
void Cpuswitch_unprivaleged(void);

#endif