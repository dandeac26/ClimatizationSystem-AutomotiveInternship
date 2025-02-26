/**-------------------------------------------------------------------------------------------------
File:        air_sensors.h
Description: header file
-------------------------------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/

#ifndef AIR_H
#define AIR_H

#define STANDARD_TEMPERATURE 20

#define INPUT_GOOD 0
#define INPUT_MODERATE 1
#define INPUT_UNHEALTHY 2
#define INPUT_VERY_UNHEALTHY 3
#define INPUT_BAD 4
#define INPUT_HAZARDOUS 5

#define INPUT_BELOW_NEGATIVE_5_DEGREES_C 0
#define INPUT_0_DEGREES_C 1
#define INPUT_5_DEGREES_C 2
#define INPUT_10_DEGREES_C 3
#define INPUT_15_DEGREES_C 4
#define INPUT_20_DEGREES_C 5
#define INPUT_25_DEGREES_C 6
#define INPUT_30_DEGREES_C 7
#define INPUT_35_DEGREES_C 8
#define INPUT_40_DEGREES_C 9

#define INPUT_0_DEG_C 0
#define INPUT_8_DEG_C 1
#define INPUT_14_DEG_C 2
#define INPUT_16_DEG_C 3
#define INPUT_18_DEG_C 4
#define INPUT_20_DEG_C 5
#define INPUT_22_DEG_C 6
#define INPUT_24_DEG_C 7
#define INPUT_26_DEG_C 8
#define INPUT_28_DEG_C 9

#define TEMP_NEGATIVE_5_C 1 /* temperature below -5 degrees celsius */ 
#define TEMP_0_C 0
#define TEMP_5_C 5
#define TEMP_8_C 8
#define TEMP_10_C 10
#define TEMP_14_C 14
#define TEMP_15_C 15
#define TEMP_16_C 16
#define TEMP_18_C 18
#define TEMP_20_C 20
#define TEMP_22_C 22
#define TEMP_24_C 24
#define TEMP_25_C 25
#define TEMP_26_C 26
#define TEMP_28_C 28
#define TEMP_30_C 30
#define TEMP_35_C 35
#define TEMP_40_C 40

/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#include "common.h" 
#include "BSW_ADC_cnf.h"

/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/

bool l_cc_auto_readTemperatureCabin(uint16);
bool l_cc_auto_readTemperatureOutside(uint16);
bool l_cc_auto_readAirQuality(uint16);
void l_cc_auto_mainSensors();

/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/

typedef enum{
    GOOD = 50,
    MODERATE = 100,
    UNHEALTHY = 150,
    VERY_UNHEALTHY = 200,
    BAD = 300,
    HAZARDOUS = 500
}air_quality_index;

typedef struct{
    uint16 temperature_cabin_data;
    uint16 temperature_outside_data;
    air_quality_index check_air_quality;
}sensors_t;

void g_cc_auto_getSensorData(sensors_t*);

#endif /* AIR_H */