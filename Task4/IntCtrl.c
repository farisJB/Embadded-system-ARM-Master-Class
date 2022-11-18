#include "IntCtrl.h"
#include "IntCtrl_Cfg.h"

void NVIC_INT(void)
{
    Nvic_intType int_ID;
    uint8 int_Group, int_SubGroup, group_subgroup, i;
    uint32 regInterrup_Enabled, bitInterrup_Enabled, bitInterrup_Priority, regInterrup_Priority;
    volatile uint32 *Interrup_Enabled_reg, *Interrupt_prioirty_reg;

    for(i=0;i<NVIC_CONF_ENABLE;i++);
    {
        int_ID =         NVIC_Cfg[i].interrupt_id;
        int_Group =      NVIC_Cfg[i].group_int;
        int_SubGroup =   NVIC_Cfg[i].subgroup_int;

        regInterrup_Enabled = (int_ID / word_length)*word_length_byte;
        bitInterrup_Enabled = (int_ID % word_length);

        Interrup_Enabled_reg = (uint32 *)(NVIC_ENABLE_BASE_ADDRESS + regInterrup_Enabled);
        *Interrup_Enabled_reg |= (1 << bitInterrup_Enabled);

        #if (NVIC_CONF_ENABLE == NVIC_GROUPING_SYSTEM_XXX)
                group_subgroup = int_Group;
        #elif (NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_YXX)
                group_subgroup = ((int_Group << 1)&0x6) | (int_SubGroup&0x1);
        #elif (NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_YYX)
                group_subgroup = ((int_Group << 2)&0x4) | (int_SubGroup&0x3);
        #elif (NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_YYY)
                group_subgroup = int_SubGroup
        #else invalid grouping system
        #endif
    }

    regInterrup_Priority = (int_ID / 4);
    bitInterrup_Priority = ((int_ID % 4) *8)+5;

    regInterrup_Priority = (uint32*) (NVIC_PRIORITY_ENABLE_BASE_ADDRESS + regInterrup_Priority);
    *regInterrup_Priority |= (group_subgroup << bitInterrup_Priority);
}