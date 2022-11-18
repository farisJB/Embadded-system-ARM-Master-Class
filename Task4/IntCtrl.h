#include "std_Types"
#include "IntCtrl_Cfg.h"

extern Nvic_CfgType NVIC_Cf[];

typedef enum

{
	INT_0,
	INT_1,
	INT_2,
	INT_3,
}Nvic_IntType;

typedef struct
{
    interrupt_id;
    group_int;
    subgroup_int;

}Nvic_CfgType;
