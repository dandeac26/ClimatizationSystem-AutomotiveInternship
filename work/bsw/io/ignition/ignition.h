/**-------------------------------------------------------------------------------------------------
File:      nume file
Description: descirere file
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/
#ifndef IGNITION_H
#define IGNITION_H

#define IGNITION_ON 1
#define IGNITION_OFF 0
/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include "common.h"
#include "BSW_ADC_cnf.h"
#include "wipers.h"
#include "speed.h"
#include "air_sensors.h"

#define ignitiondataPath "C:/Users/dan.deac/repos/AutomotiveProject_1/AutomotiveProjectSim/ProiectInternship2-main/data/ignitionData.txt"
/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/

void menu(void);
void wipers_menu(void);
bool l_bsw_adc_readIgnition(void);

/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/

extern uint8 ignition_status;

typedef enum{
    STATE_KL0_SLEEP,
    STATE_KL15_WAKEUP,
    STATE_KL30_RUN
}key_state;

extern key_state checkSystem_state;

extern uint8 command;

#endif /* IGNITION_H */



