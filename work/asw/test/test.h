/**-------------------------------------------------------------------------------------------------
File:      nume file
Description: descirere file
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/
#ifndef TEST_H
#define TEST_H

#define TEST_SESSION 0
#define SUCCESS 1
#define FAILURE 0
#define test_itoc(X) ((X) + '0')
#define MAX_TESTS 6
#define CLIMATE_TESTS_IDENTIFIER 9
/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/

#include "common.h"
#include "ignition.h"
#include "meme.h"
#include "rte.h"
#include <stdio.h>
#include "BSW_ADC_cnf.h"
#include "BSW_PWM_cnf.h"
#include "air_sensors.h"
#include "air_conditioning.h"

/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/
void task_TESTER();
void state_helper(key_state s);
void l_test_readTemperatureCabin(test_case_e);
void g_test_runClimateTests();
/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/
/*
uint16 task_100ms_counter = 0;
uint16 task_10ms_counter = 0;
uint16 task_1ms_counter = 0;
*/ 

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

typedef enum{
    TEST_1 = 1,
    TEST_2,
    TEST_3,
    TEST_4,
    TEST_5 = 5
}test_case_e;

typedef struct{
    uint16 reading;
    uint16 expectedResult;
}sensor_reading_t;

typedef struct{
    sensor_reading_t cabinTemp;
    sensor_reading_t outsideTemp;
    sensor_reading_t airQuality;
}test_sensors_t;

typedef struct{
    uint8 fanSpeed;
    bool AUTO_ON_OFF;
    bool AC_ON_OFF;
    uint8 pwmCooler;
}test_ac_t;

extern struct l_bsw_adc_readADCTESTER signalADC_TESTER;
extern bool l_bsw_pwm_writePWM_TESTER;
extern bool l_bsw_readMileage_TESTER;
extern bool g_bsw_mem_setTime_TESTER;
extern bool g_bsw_mem_getTime_TESTER;
extern bool g_bsw_getMileage_TESTER;

#endif /*  TEST_H  */ 

