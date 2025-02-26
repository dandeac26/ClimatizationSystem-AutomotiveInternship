/**-------------------------------------------------------------------------------------------------
File:        air_sensors.c
Description: read data from sensors
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/

#ifndef AIR_C
#define AIR_C

/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/

#include "air_sensors.h"

/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/

sensors_t sensorData; /* this structure holds data for all the sensors used by climate module*/

/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------------------------------
Function: l_cc_auto_readAirQuality



Description:
    Reads the adcData.input7 for the air quality sensor and translates it to the real life meaning

Parameters In:
    input: uint16 - expects adc data from channel 7



Parameters Out:
    None



Return Value:
    read_error: bool
-------------------------------------------------------------------------------------------------*/
bool l_cc_auto_readAirQuality(uint16 input_air)
{
    bool read_error = false; 

    switch(ctoi(input_air)) /* character input_air converted to integer*/
    {
        case INPUT_GOOD: /* if air quality sensor reading is GOOD, we assign check_air_quality from sensorData to GOOD */
            sensorData.check_air_quality = GOOD;
            break;
        case INPUT_MODERATE:
            sensorData.check_air_quality = MODERATE;
            break;
        case INPUT_UNHEALTHY:
            sensorData.check_air_quality = UNHEALTHY;
            break;
        case INPUT_VERY_UNHEALTHY:
            sensorData.check_air_quality = VERY_UNHEALTHY;
            break;
        case INPUT_BAD:
            sensorData.check_air_quality = BAD;
            break;
        case INPUT_HAZARDOUS:
            sensorData.check_air_quality = HAZARDOUS;
            break;
        default:
            read_error = true; /* error occured, data can't be interpreted */
            break;
    }
    return read_error;
}


/*-------------------------------------------------------------------------------------------------
Function: l_cc_auto_readTemperatureOutside



Description:
    Reads the adcData.input6 for the outside temperature sensor and translates it to the real life meaning

Parameters In:
    input: uint16 - expects adc data from channel 6



Parameters Out:
    None



Return Value:
    read_error: bool
-------------------------------------------------------------------------------------------------*/
bool l_cc_auto_readTemperatureOutside(uint16 input_temp)
{
    bool read_error = false; /* returns false if no error occured */   

    switch(ctoi(input_temp)) /* character input_temp converted to integer*/
    {
        case INPUT_BELOW_NEGATIVE_5_DEGREES_C: /* based on reading, assign corresponding temperature */
            sensorData.temperature_outside_data = TEMP_NEGATIVE_5_C;
            break;
        case INPUT_0_DEGREES_C:
            sensorData.temperature_outside_data = TEMP_0_C;
            break;
        case INPUT_5_DEGREES_C:
            sensorData.temperature_outside_data = TEMP_5_C; 
            break;
        case INPUT_10_DEGREES_C:
            sensorData.temperature_outside_data = TEMP_10_C;
            break;
        case INPUT_15_DEGREES_C:
            sensorData.temperature_outside_data = TEMP_15_C;
            break;
        case INPUT_20_DEGREES_C:
            sensorData.temperature_outside_data = TEMP_20_C;
            break;
        case INPUT_25_DEGREES_C:
            sensorData.temperature_outside_data = TEMP_25_C;
            break;
        case INPUT_30_DEGREES_C:
            sensorData.temperature_outside_data = TEMP_30_C;
            break;
        case INPUT_35_DEGREES_C:
            sensorData.temperature_outside_data = TEMP_35_C;
            break;
        case INPUT_40_DEGREES_C:
            sensorData.temperature_outside_data = TEMP_40_C;
            break;
        default:
            read_error = true; /* error occured while reading data */
            break;
    }
    return read_error; 
}

/*-------------------------------------------------------------------------------------------------
Function: l_cc_auto_readTemperatureCabin



Description:
    Reads the adcData.input5 for the cabin temperature sensor and translates it to the real life meaning

Parameters In:
    input: uint16 - expects adc data from channel 5



Parameters Out:
    None



Return Value:
    read_error: bool
-------------------------------------------------------------------------------------------------*/
bool l_cc_auto_readTemperatureCabin(uint16 input_temp)
{
    bool read_error = false;   

    switch(ctoi(input_temp))    /* character input_temp converted to integer*/
    {
        case INPUT_0_DEG_C:     /* based on reading, assign corresponding temperature */
            sensorData.temperature_cabin_data = TEMP_0_C; 
            break;
        case INPUT_8_DEG_C:
            sensorData.temperature_cabin_data = TEMP_8_C; 
            break;
        case INPUT_14_DEG_C:
            sensorData.temperature_cabin_data = TEMP_14_C; 
            break;
        case INPUT_16_DEG_C:
            sensorData.temperature_cabin_data = TEMP_16_C;
            break;
        case INPUT_18_DEG_C:
            sensorData.temperature_cabin_data = TEMP_18_C;
            break;
        case INPUT_20_DEG_C:
            sensorData.temperature_cabin_data = TEMP_20_C;
            break;
        case INPUT_22_DEG_C:
            sensorData.temperature_cabin_data = TEMP_22_C;
            break;
        case INPUT_24_DEG_C:
            sensorData.temperature_cabin_data = TEMP_24_C;
            break;
        case INPUT_26_DEG_C:
            sensorData.temperature_cabin_data = TEMP_26_C;
            break;
        case INPUT_28_DEG_C:
            sensorData.temperature_cabin_data = TEMP_28_C;
            break;
        default:
            read_error = true; /* error occured */
            break;
    }
    return read_error;
}

/*-------------------------------------------------------------------------------------------------
Function: main_sensors



Description:
    Call all functions to read adc data from sensors (temperature and air quality) and handle exceptions / errors

Parameters In:
    None



Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void l_cc_auto_mainSensors()
{
    if(l_cc_auto_readTemperatureCabin(adcData.input5)) /* calls function and based on return we know if it worked or failed */
    {   
        /* Handle error */
        sensorData.temperature_cabin_data = STANDARD_TEMPERATURE;
        fprintf(stderr, "[%sWarning%s] %sin file %s:\n  function %s`%s`:%d: Could not read cabin temperature, so it is set to 20 degrees C\n",COLOR_MAGENTA,COLOR_RESET, COLOR_GRAY, __FILE__,COLOR_RESET, __func__, __LINE__); 
    }
    else
    { 
        /* Success */
    }
    
    if(l_cc_auto_readTemperatureOutside(adcData.input6))
    { 
        /* Handle error */
        sensorData.temperature_outside_data = STANDARD_TEMPERATURE;
        fprintf(stderr, "[%sWarning%s] %sin file %s:\n  function %s`%s`:%d: Could not read outside temperature, so it is set to 20 degrees C\n",COLOR_MAGENTA,COLOR_RESET, COLOR_GRAY, __FILE__,COLOR_RESET, __func__, __LINE__); 
    }
    else
    {
        /* Success */
    }

    if(l_cc_auto_readAirQuality(adcData.input7))
    { 
        /* Handle error */
        sensorData.check_air_quality = GOOD;
        fprintf(stderr, "[%sWarning%s] %sin file %s:\n  function %s`%s`:%d: Could not read air quality, so it is set to GOOD\n",COLOR_MAGENTA,COLOR_RESET, COLOR_GRAY, __FILE__,COLOR_RESET, __func__, __LINE__); 
    }
    else
    {
        /* Success */
    }
}

/*-------------------------------------------------------------------------------------------------
Function: g_cc_auto_getSensorData



Description:
    This function gets the value of sensorData structure where are sensor readings are placed.

Parameters In:
    None



Parameters Out:
    *sdata : sensors_t 



Return Value:
    None
-------------------------------------------------------------------------------------------------*/

void g_cc_auto_getSensorData(sensors_t *sdata)
{
    l_cc_auto_mainSensors();         /* call main sensors to assign values to sensorData */

    *sdata = sensorData;    /* return sensorData through parameter */
}

#endif 