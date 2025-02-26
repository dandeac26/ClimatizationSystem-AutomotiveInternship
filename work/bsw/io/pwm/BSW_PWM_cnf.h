/**-------------------------------------------------------------------------------------------------
File:      nume file
Description: descirere file
-------------------------------------------------------------------------------------------------*/
#ifndef BSW_PWM_cnf_H
#define BSW_PWM_cnf_H

/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/
#define pwmdataPath "C:\\Users\\dan.deac\\repos\\AutomotiveProject_1\\AutomotiveProjectSim\\ProiectInternship2-main\\data\\pwmData.txt"

#define MAX_DtCy 100
#define MIN_DtCy 0

#define PWM_POWER_SUPPLY 5

#define PWM_CHANNEL1 1
#define PWM_CHANNEL2 2
#define PWM_CHANNEL3 3
#define PWM_CHANNEL4 4
#define PWM_CHANNEL5 5
#define PWM_CHANNEL6 6
#define PWM_CHANNEL7 7
#define PWM_CHANNEL8 8
#define NUMBER_OF_PWM_CHANNELS 8

#define VOLTAGE_CONVERSION 1024

/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/
bool bsw_pwm_setPWMresults(uint8, uint16);
extern bool g_bsw_pwm_getPWMresults(uint8, uint16*);
extern bool l_bsw_pwm_writePWM(uint8, uint64);
void g_PWM_init();
void g_PWM_off();
void g_bsw_pwm_setAllPWM();
void g_setPWM_KL30();

/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/
extern bool PWM_ON_OFF;

struct BSW_PWM_struct {

    uint16 input1; /* Wipers */
    uint16 output1;

    uint16 input2; /* Lights */
    uint16 output2;

    uint16 input3; /* Valve on/off */
    uint16 output3;

    uint16 input4; /* Heater blend_door: how much hot air vs cold */
    uint16 output4;

    uint16 input5; /* Radiator Fan */
    uint16 output5;

    uint16 input6; /* cooling on/off */
    uint16 output6;

    uint16 input7; /* front defrost valve */
    uint16 output7;

    uint16 input8; /* rear resistance */
    uint16 output8;

};
extern struct BSW_PWM_struct pwmData;

#endif /*BSW_PWM_cnf_H*/
