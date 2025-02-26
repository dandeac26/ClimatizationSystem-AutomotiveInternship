/**-------------------------------------------------------------------------------------------------
File:      nume file
Description: descirere file
-------------------------------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/
#ifndef AUTO_H
#define AUTO_H

#define HEATING_ON 1
#define HEATING_OFF 0
#define SET_AUTO_ON 1
#define DEFROST_FAN_SPEED 8
#define AUTO_OFF 0
#define START_RECIRCULATION 1
#define STOP_RECIRCULATION 0

/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "BSW_PWM_cnf.h"
#include "air_sensors.h"
#include "air_conditioning.h"


/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/

void g_cc_auto_run(uint8, bool*, bool*);
void l_cc_auto_closeBlendDoor();
void g_cc_auto_stopAuto();

/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/


typedef enum{
    freezing=0,
    chilly=1,
    warm=2,
    hot=3
}outside_weather_e;

typedef enum{ /* difference in temperatrue between desired temp and cabin temp*/
    VERY_HIGH=12,
    HIGH=10,
    MEDIUM_HIGH=8,
    MEDIUM_LOW=6,
    LOW=4,
    VERY_LOW=2,
    ZERO=0
}difference_level_e;

typedef struct{
    bool heating;
    difference_level_e power;
}climatization_state_t;

typedef enum{ /* values from 1 through 10 are automatically assigned */
    FAN_SPEED_MIN = 1,
    FAN_SPEED_2,
    FAN_SPEED_3,
    FAN_SPEED_4,
    FAN_SPEED_5,
    FAN_SPEED_6,
    FAN_SPEED_7,
    FAN_SPEED_8,
    FAN_SPEED_9,
    FAN_SPEED_MAX = 10
}auto_fan_speed_e;

typedef enum{ 
    BLEND_DOOR_MIN = 0,
    BLEND_DOOR_1,
    BLEND_DOOR_2,
    BLEND_DOOR_3,
    BLEND_DOOR_4,
    BLEND_DOOR_5,
    BLEND_DOOR_6,
    BLEND_DOOR_7,
    BLEND_DOOR_8,
    BLEND_DOOR_9,
    BLEND_DOOR_MAX = 10
}blend_door_value_e;

typedef struct{
    bool heater_core;
    blend_door_value_e blend_door; /* adjust mixing of hot and cool air */
}heating_system_t;



#endif /* AUTO_H */