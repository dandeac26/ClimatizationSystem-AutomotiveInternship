/**-------------------------------------------------------------------------------------------------
File:      file name
Description: file description
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/
#ifndef WIPERS_H
#define WIPERS_H
#define wipersdataPath "C:/Users/dan.deac/repos/AutomotiveProject_1/AutomotiveProjectSim/data/wipersData.txt"
/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/

#include <stdio.h>

#include "common.h"
#include "BSW_ADC_cnf.h"
#include "BSW_PWM_cnf.h"
#include "speed.h"


/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/
void wipers();
bool l_bsw_adc_readWipers();
/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/
/*
uint8 wipers_status;
uint16 wipers_data;
struct BSW_ADC_struct mystruct;
*/

typedef enum{
    WIPERS_OFF,
    WIPERS_AUTO,
    WIPERS_ON
}wipers_state;
extern wipers_state checkWipers_state;



#endif /* WIPERS_H */