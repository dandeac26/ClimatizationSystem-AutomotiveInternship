/**-------------------------------------------------------------------------------------------------
File:      nume file
Description: descirere file
-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/
#ifndef rte_H
#define rte_H

#define taskInterval_100ms 100
#define taskInterval_10ms 10
#define taskInterval_1ms 1

#define CONDITION_FOR_TASK_1MS 1000
#define CONDITION_FOR_TASK_10MS 2000
#define CONDITION_FOR_TASK_100MS 3000
/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <mem.h>
#include "meme.h"
#include "common.h"
#include "BSW_PWM_cnf.h"
#include "BSW_ADC_cnf.h"

/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/
extern uint32* mileage;
extern time_t* getTime;
extern clock_t startTask_100ms, startTask_10ms, startTask_1ms;
extern clock_t time_till_call;

extern uint8 command_flag;
/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/
void RTE_call(KL_tested_t*);

struct taskData_ADC{

    uint8 channelADC;
    uint16 pDataADC;

};
extern struct taskData_ADC signal1;
extern struct taskData_ADC signal2; 
extern struct taskData_ADC signal3;
extern struct taskData_ADC signal4;
extern struct taskData_ADC signal5; 
extern struct taskData_ADC signal6;
extern struct taskData_ADC signal7;

struct taskData_PWM{

    uint8 channelPWM;
    uint16 DtyCycle;

};
#endif
