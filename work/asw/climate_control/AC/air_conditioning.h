/**-------------------------------------------------------------------------------------------------
File:      nume file
Description: descirere file
-------------------------------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/
#ifndef AC_H
#define AC_H

#define AC_ON 1
#define AC_OFF 0

#define ENABLE_COMPONENT 1
#define DISABLE_COMPONENT 0
#define FAN_OFF 0
/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "BSW_PWM_cnf.h"

/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/


void g_cc_ac_init_AC_ON_OFF();
void g_cc_ac_set_AC_ON_OFF(bool);
void g_cc_ac_get_AC_ON_OFF(bool*);
void g_cc_ac_coolingOn();
void g_cc_ac_coolingOff();
void g_cc_ac_startAC(uint8, bool);
void g_cc_ac_stopAC(bool);
bool g_cc_ac_coolingIsEnabled();
void g_cc_ac_setFanSpeed(uint8, bool);

/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/

typedef struct{
    uint8 compressor;
    uint8 condenser;
    uint8 expansion_valve;
    uint8 evaporator;
    bool enabled;
}cooling_system_t;


#endif /* AC_H */