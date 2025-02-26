/**-------------------------------------------------------------------------------------------------
File:      nume file
Description: descirere file
-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/
#ifndef AC_C
#define AC_C
/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/

#include "air_conditioning.h"

/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/
cooling_system_t coolingSystem;
bool AC_ON_OFF; /* this variable will determine the state of the AC */

/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
Function: g_cc_ac_init_AC_ON_OFF



Description:
    This function sets the state of the AC module to false.



Parameters In:
    None



Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void g_cc_ac_init_AC_ON_OFF()
{
    AC_ON_OFF = false;
}

/*-------------------------------------------------------------------------------------------------
Function: g_cc_ac_set_AC_ON_OFF



Description:
    Set the value of AC_ON_OFF to a certain value recieved from parameter state_ac



Parameters In:
    state_ac : bool 



Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void g_cc_ac_set_AC_ON_OFF(bool state_ac)
{
    AC_ON_OFF = state_ac;
}

/*-------------------------------------------------------------------------------------------------
Function: g_cc_ac_get_AC_ON_OFF



Description:
    Get the value of AC_ON_OFF, representing the state of the AC module



Parameters In:
    None



Parameters Out:
    state_ac :bool*



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void g_cc_ac_get_AC_ON_OFF(bool *state_ac)
{
    *state_ac = AC_ON_OFF;
}

/*-------------------------------------------------------------------------------------------------
Function: g_cc_ac_coolingOn



Description:
    This function turns on the cooling mechanism



Parameters In:
    None



Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void g_cc_ac_coolingOn()
{
    if(true == AC_ON_OFF) /* if AC should be on, turn it on */
    {
        pwmData.input6 = AC_ON;
        coolingSystem.compressor = ENABLE_COMPONENT;
        coolingSystem.condenser = ENABLE_COMPONENT;
        coolingSystem.evaporator = ENABLE_COMPONENT;
        coolingSystem.expansion_valve = ENABLE_COMPONENT;
        coolingSystem.enabled = true;
    }
    else 
    {
        /*
        * shouldn't turn everything on if AC_ON_OFF isn't true
        */
        fprintf(stderr, "[%sWarning%s] %sin file %s:\n  function %s`%s`:%d: Cooling mechanism was not turned on, AC is off!\n",COLOR_MAGENTA,COLOR_RESET, COLOR_GRAY, __FILE__,COLOR_RESET, __func__, __LINE__); 
    }
}

/*-------------------------------------------------------------------------------------------------
Function: g_cc_ac_coolingOff



Description:
    Function turns off the cooling mechanism



Parameters In:
    None



Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void g_cc_ac_coolingOff()
{
    if(false == AC_ON_OFF) /* if ac should be turned off, turn it off */
    {
        pwmData.input6 = AC_OFF;
        coolingSystem.compressor = DISABLE_COMPONENT;
        coolingSystem.condenser = DISABLE_COMPONENT;
        coolingSystem.evaporator = DISABLE_COMPONENT;
        coolingSystem.expansion_valve = DISABLE_COMPONENT;
        coolingSystem.enabled = false;
    }
    else 
    {
        /* do nothing if AC should be on */
        fprintf(stderr, "[%sWarning%s] %sin file %s:\n  function %s`%s`:%d: Cooling machinasim was tried to be shut off, while AC state is on!\n",COLOR_MAGENTA,COLOR_RESET, COLOR_GRAY, __FILE__,COLOR_RESET, __func__, __LINE__); 
    }
}

/*-------------------------------------------------------------------------------------------------
Function: g_cc_ac_coolingIsEnabled



Description:
    Checks if the cooling mechanism is on



Parameters In:
    None



Parameters Out:
    None



Return Value:
    coolingSystem.enabled : bool
-------------------------------------------------------------------------------------------------*/
bool g_cc_ac_coolingIsEnabled()
{
    return coolingSystem.enabled;
}

/*-------------------------------------------------------------------------------------------------
Function: g_cc_ac_setFanSpeed



Description:
    This function sets the fan speed. It can also be used by the AUTO module. this is
    checked through the boolean parameter AUTO_ON_OFF.
    Writes to PWMinput5 (the fan), the value recieved in fan_speed



Parameters In:
    fan_speed : uint8
    AUTO_ON_OFF : bool 


Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void g_cc_ac_setFanSpeed(uint8 fan_speed, bool AUTO_ON_OFF)
{
    /* if AC is off, then we should turn the fan off, but if AUTO is on, we don't override it*/
    if(false == AC_ON_OFF && false == AUTO_ON_OFF)
    {  
        fan_speed = FAN_OFF;
    }
    
    pwmData.input5 = fan_speed; /* set the desired value on the pwm channel 5, which is for the fan*/
    
    if(fan_speed == FAN_OFF)
    {
        printf("Fan OFF! speed: %d%%  \n", fan_speed);
    }
    else
    {
        printf("Fan ON! speed: %d0%%  \n", fan_speed);
    }
    
}

/*-------------------------------------------------------------------------------------------------
Function: g_cc_ac_stopAC



Description:
    Stops the AC module. If auto module is still on, it will not stop the fan. AUTO module
    should be able to control the fan even when cooling mechanism is stopped.
    IF AUTO is off as well, it will override the fan value to 0, so it will stop the fan.


Parameters In:
    AUTO_ON_OFF : bool 



Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void g_cc_ac_stopAC(bool AUTO_ON_OFF)
{
    if(false == AC_ON_OFF)
    {
        g_cc_ac_coolingOff();
    }
     /* turn cooling off, but don't override fanspeed if AUTO module is still on. Only when AUTO is also off*/
    if(false == AC_ON_OFF && false == AUTO_ON_OFF)
    {
        g_cc_ac_setFanSpeed(0, AUTO_ON_OFF); /* stop fan */
    }
        
}

/*-------------------------------------------------------------------------------------------------
Function: g_cc_ac_startAC



Description:
    This function turns the AC on, and overrides the fan speed with the value given by the fan 
    gauge, through the fan_speed parameter. If the AUTO module is on, the fan will remain the 
    same, because the fan can be used also when heating.



Parameters In:
    fan_speed:   uint8 
    AUTO_ON_OFF: bool 


Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void g_cc_ac_startAC(uint8 fan_speed, bool AUTO_ON_OFF)
{   
    if(fan_speed > 9) fan_speed = 9;
    
    if(true == AC_ON_OFF)
    {
        g_cc_ac_coolingOn();
    }
     /* turn cooling off*/
    if(true == AC_ON_OFF && false == AUTO_ON_OFF) /* only override fan when AUTO is also off */
    {
        g_cc_ac_setFanSpeed(fan_speed, AUTO_ON_OFF);
    }  
}


#endif /* AC_C */