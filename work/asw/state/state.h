/**-------------------------------------------------------------------------------------------------
File:      nume file
Description: descirere file
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/
#ifndef STATE_H
#define STATE_H

#define TEST_SESSION 0
/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include "common.h"
#include "lights.h"
#include "ignition.h"
#include "meme.h"
#include "wipers.h"
#include "speed.h"
#include "BSW_ADC_cnf.h"
#include "rte.h"
#include "climate_btn.h"
#include "climate_state.h"
#include "air_conditioning.h"
#include "climate_auto.h"

/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/
void task_TESTER();
void state_helper(key_state s);
void l_STATE_KL0_SLEEP();
void l_STATE_KL15_WAKEUP();
void l_STATE_KL30_RUN();

/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/
/*  
uint16 task_100ms_counter = 0;
uint16 task_10ms_counter = 0;
uint16 task_1ms_counter = 0;
*/


extern uint16* pData;
extern uint16* pwm_Data;
extern uint16* pPWM_Data;
extern uint16* pPWM_Data_2;

struct l_bsw_adc_readADCTESTER{

    bool channel1_READ_ADC;
    bool channel2_READ_ADC;
    bool channel1_GET_ADC;
    bool channel2_GET_ADC;

    bool channel3_READ_ADC;
    bool channel4_READ_ADC;
    bool channel3_GET_ADC;
    bool channel4_GET_ADC;

};

extern struct l_bsw_adc_readADCTESTER signalADC_TESTER;
extern bool l_bsw_pwm_writePWM_TESTER;
extern bool l_bsw_readMileage_TESTER;
extern bool g_bsw_mem_setTime_TESTER;
extern bool g_bsw_mem_getTime_TESTER;
extern bool g_bsw_getMileage_TESTER;


#endif 

