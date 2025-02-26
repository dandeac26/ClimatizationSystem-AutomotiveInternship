/**-------------------------------------------------------------------------------------------------
File:      nume file
Description: descirere file
-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/
#ifndef AUTO_C
#define AUTO_C
/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/

#include "climate_auto.h"

/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/

heating_system_t      heatingSystem;
sensors_t             sensData;
outside_weather_e     weatherState;
difference_level_e    intensityLevel;
climatization_state_t currentState;
/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
Function: l_cc_auto_setWeatherState



Description:
    Based on the weather which is the outside temperature, it will set weatherState
    accordingly: freezing if below 0, chilly if below 15 C, warm below 25 C and hot above 25 C



Parameters In:
    weather: uint16



Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void l_cc_auto_setWeatherState(uint16 weather) 
{   /* Weather is outside_temperature_data form the sensors */
    if(weather <= TEMP_0_C || weather <= TEMP_NEGATIVE_5_C) /* TEMP_NEGATIVE_5_C is represented as 1 in the weather variable. so it will not be below TEMP_0_C which is 0. so thats why we need to check both*/
    {
        weatherState = freezing;
    }
    else if(weather <= TEMP_15_C)
    {
        weatherState = chilly;
    }
    else if(weather <= TEMP_25_C)
    {
        weatherState = warm;
    }
    else if(weather > TEMP_25_C)
    {
        weatherState = hot;
    }
}


/*-------------------------------------------------------------------------------------------------
Function: l_cc_auto_setCurrentState



Description:
    Based on the desired temperature given by tempGauge and the current cabin temperature reading
    it will adjust the current state so we know how big is the difference between those two, and
    if we need heating or cooling.



Parameters In:
    tempGauge: uint16
    tempCabin: uint16



Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void l_cc_auto_setCurrentState(uint16 tempGauge, uint16 tempCabin)
{
    /* If temperature requested is greater than cabin temperature, we need heating, else cooling */
    if(tempGauge > tempCabin) 
    {
        currentState.heating = HEATING_ON;
    }
    else
    {
        currentState.heating = HEATING_OFF;
    }
    heatingSystem.heater_core = currentState.heating; /* This does nothing, just simulates starting or turning off heating mechanism */
    /* Power is the absolute value of the difference between temp gauge (temp requested) and cabin temperature*/
    currentState.power = abs(tempGauge - tempCabin);
}


/*-------------------------------------------------------------------------------------------------
Function: l_cc_auto_openBlendDoor



Description:
    Sets the pwm data input 4 (which corresponds to blend door) to the percentage the blend door will allow hot air to get mixed
    with cool air (if there is cooling), or just heat coming in then.



Parameters In:
    blendValue: blend_door_value_e



Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void l_cc_auto_openBlendDoor(blend_door_value_e blendValue)
{
    heatingSystem.blend_door = blendValue;
    pwmData.input4 = (uint16)blendValue;
}


/*-------------------------------------------------------------------------------------------------
Function: l_cc_auto_setHeatingValues



Description:
    This will only set the values that relate to heating. This means blend door and fan speed.
    It takes two values for how much should the blend door be opened, first one in case of heating, second
    in case of cooling, and fan speed.



Parameters In:
    blendValue: blend_door_value_e
    blendValueWhileCooling: blend_door_value_e
    fanSpeed : auto_fan_speed_e

Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void l_cc_auto_setHeatingValues(blend_door_value_e blendValue, blend_door_value_e blendValueWhileCooling, auto_fan_speed_e fanSpeed)
{   
    /* Based on the heating sate (cooling / heating) we set the power of fan and the bleding door value (how much heat it allows) */
    if(true == currentState.heating)
    {
        l_cc_auto_openBlendDoor(blendValue);
    }
    else
    {
        l_cc_auto_openBlendDoor(blendValueWhileCooling);
    } 
    
    g_cc_ac_setFanSpeed(fanSpeed, SET_AUTO_ON); 
}


/*-------------------------------------------------------------------------------------------------
Function: l_cc_auto_startAuto



Description:
    startAuto handles the starting all of the components related to heating.
    This will set the blend door value for either heating or cooling, and adjust fan speed, all based
    on the difference between cabin temp and the temp gauge. this value is prepresented by the 
    currentState.power value.



Parameters In:
    None



Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void l_cc_auto_startAuto()
{
    switch(currentState.power)
    {
        case VERY_HIGH:
            l_cc_auto_setHeatingValues(BLEND_DOOR_MAX, BLEND_DOOR_MIN, FAN_SPEED_MAX);
            break;
        case HIGH:
            l_cc_auto_setHeatingValues(BLEND_DOOR_9, BLEND_DOOR_1, FAN_SPEED_MAX);
            break;
        case MEDIUM_HIGH:
            l_cc_auto_setHeatingValues(BLEND_DOOR_8, BLEND_DOOR_2, FAN_SPEED_8);
            break;
        case MEDIUM_LOW:
            l_cc_auto_setHeatingValues(BLEND_DOOR_7, BLEND_DOOR_3, FAN_SPEED_6);
            break;
        case LOW:
            l_cc_auto_setHeatingValues(BLEND_DOOR_6, BLEND_DOOR_4, FAN_SPEED_4);
            break;
        case VERY_LOW:
            l_cc_auto_setHeatingValues(BLEND_DOOR_4, BLEND_DOOR_5, FAN_SPEED_2);
            break;
        case ZERO:
            l_cc_auto_setHeatingValues(BLEND_DOOR_2, BLEND_DOOR_MIN, FAN_SPEED_MIN);
            break;
        default:
            /* Very very high */
            l_cc_auto_setHeatingValues(BLEND_DOOR_MAX, BLEND_DOOR_MIN, FAN_SPEED_MAX); 
            break;
    }
}


/*-------------------------------------------------------------------------------------------------
Function: l_cc_auto_closeBlendDoor



Description:
    Function is setting the pwm data of the blend door to 0, meaning that it is fully closed.
    Also updates the heating system value.



Parameters In:
    None



Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void l_cc_auto_closeBlendDoor()
{
    heatingSystem.blend_door = BLEND_DOOR_MIN;
    pwmData.input4 = BLEND_DOOR_MIN;
}


/*-------------------------------------------------------------------------------------------------
Function: g_cc_auto_stopAuto



Description:
    Shuts off the heating core (this value is not used, is just to simulate 
    turing off the component for heating), and closes the blend door.
    



Parameters In:
    None



Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void g_cc_auto_stopAuto()
{
    heatingSystem.heater_core = HEATING_OFF;
    l_cc_auto_closeBlendDoor();
}


/*-------------------------------------------------------------------------------------------------
Function: l_cc_auto_setRecirculation



Description:
    This function determines the appropriate state of the recirculation valve. this value
    will be returned to the pointer which is the recirculation button, which in turn in the 
    climate_state component will close or open the valve to let resh air in.



Parameters In:
    tempGauge uint8



Parameters Out:
    None



Return Value:
    result: bool
-------------------------------------------------------------------------------------------------*/
bool l_cc_auto_setRecirculation(uint8 tempGauge)
{
    bool result = false; /* If recirculation not needed, stop it */

    
    if(sensData.check_air_quality > UNHEALTHY)
    {
        result = true; /* If air is polluted, start recirculation */
    }
    else if(weatherState == hot)
    {
        if(tempGauge >= sensData.temperature_cabin_data)
        {
            result = false; /* If air is somehow still cool inside and need heating, allow hot air in */
        }
        else
        {
            result = true; /* If air is too hot outside, cool cabin air for quicker climate control, start recirculation */
        }
    }
    else if(weatherState == freezing)
    {
        if(tempGauge <= sensData.temperature_cabin_data)
        {
            result = false; /* If somehow air is hot in cabin, and need cooling, allow cool fresh air */
        }
        else 
        {
            result = true; /* reheat cabin air by enabling recirculation, heating it faster */
        }
    }

    return result;
}


/*-------------------------------------------------------------------------------------------------
Function: g_cc_auto_run



Description:
    This function represents the runnable module of this component. Here are all the 
    functionalities of the auto module in the appropriate order.
    First, sensor data is read, logic is set, and pwm values are set but not written. The pwm
    channels are written only in the climate_state where the main run function resides. 



Parameters In:
    tempGauge: uint8



Parameters Out:
    recirculationSignal: *bool
    acSignal: *bool



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void g_cc_auto_run(uint8 tempGauge, bool *recirculationSignal, bool *acSignal)
{
    /* read sensors and put the reading into sensData */
    g_cc_auto_getSensorData(&sensData);
    
    printf("Sensor readings: %d(tempC cabin) | %d(tempC outside) | %d(airQality)\n\n", sensData.temperature_cabin_data, sensData.temperature_outside_data, sensData.check_air_quality);
    
    /* Assign the states of the environment: freezing / hot / warm / chilly */
    l_cc_auto_setWeatherState(sensData.temperature_outside_data);
    
    /* Based on sensor data and temperature gauge turn recirculation on/off */
    *recirculationSignal = l_cc_auto_setRecirculation(tempGauge);

    /* Current state of the cabin vs desired temperature is calculated here */
    l_cc_auto_setCurrentState(tempGauge, sensData.temperature_cabin_data);

    /* Control the climate based on readings and desired temperature (tempGague)  */
    l_cc_auto_startAuto();

    /* If needed, turn on AC to help cool the cabin */
    if(ZERO == currentState.power || true == currentState.heating)
    {   
        *acSignal = AC_OFF; /* update button */
        g_cc_ac_set_AC_ON_OFF(AC_OFF); /* stop cooling */
        g_cc_ac_coolingOff();
    }
    else if(false == currentState.heating)
    { 
        *acSignal = AC_ON; 
        g_cc_ac_set_AC_ON_OFF(AC_ON); /* start cooling */
        g_cc_ac_coolingOn();
    }
}


#endif /* AUTO_C */