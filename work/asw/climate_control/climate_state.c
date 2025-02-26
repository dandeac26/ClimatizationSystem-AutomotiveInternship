/**-------------------------------------------------------------------------------------------------
File:      nume file
Description: descirere file
-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/
#ifndef CLIMATE_CONTROL_C
#define CLIMATE_CONTROL_C
/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/

#include "climate_state.h"

/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/



/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------------------------------
Function: l_cc_runRecirculation



Description:
    This function sets the pwm data to either 1 (open), if recirculation is on, or 0 (off) when it is off



Parameters In:
    recirculation: bool



Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void l_cc_runRecirculation(bool recirculation)
{
    if(true == recirculation)
    {
        pwmData.input3 = START_RECIRCULATION;
        printf("Recirculation ON!\n");
    }    
    else 
    {
        pwmData.input3 = STOP_RECIRCULATION;
        printf("Recirculation OFF!\n");
    }
}


/*-------------------------------------------------------------------------------------------------
Function: g_cc_mainClimate



Description:
    This function runs a test at the beginning, and then it calls the main run function, where
    values are read and written at each step, based on the inputs from the user and modification to
    sensor readings.



Parameters In:
    None



Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void g_cc_mainClimate()
{
    printf("\nPress any key for Climate Control module...\n");
    getchar();
    g_cc_run();
}


/*-------------------------------------------------------------------------------------------------
Function: l_cc_runAC



Description:
    This function run the Ac module. here is all the logic needed for the AC module to run. The value
    of last_fan_state is meant to detect if the fan gauge was moved by the user. This is because we want
    to stop auto module when this happens. This is a feature of the climate module i studied, implemented here.



Parameters In:
    None



Parameters Out:
    last_fan_state: *uint8



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void l_cc_runAC(uint8 *last_fan_state)
{
    
    g_cc_ac_set_AC_ON_OFF(gClimateButtonsState.ac_on);

    
    if((gClimateButtonsState.fan != *last_fan_state) && false == gClimateButtonsState.ac_on)
    {
        /* this part handles the start of AC when fan gauge changes possition  */
        g_cc_ac_set_AC_ON_OFF(AC_ON);
        gClimateButtonsState.ac_on = AC_ON;
        gClimateButtonsState.auto_on = AUTO_OFF; 
        if(true == g_bsw_buttons_writeState()) /* error occured while writing */
        {
            fprintf(stderr, "[%sError%s] %sin file %s:\n  function %s`%s`:%d: Failed writing buttons' state\n",COLOR_RED,COLOR_RESET, COLOR_GRAY, __FILE__,COLOR_RESET, __func__, __LINE__);
        }
    }else if((gClimateButtonsState.fan != *last_fan_state) && true == gClimateButtonsState.ac_on && true == gClimateButtonsState.auto_on) 
    {
        /* this part handles stopping of Auto module when choosing a fan speed, and starting AC */
        g_cc_ac_set_AC_ON_OFF(AC_ON);
        gClimateButtonsState.auto_on = AUTO_OFF;
        if(true == g_bsw_buttons_writeState()) /* error occured while writing */
        {
            fprintf(stderr, "[%sError%s] %sin file %s:\n  function %s`%s`:%d: Failed writing buttons' state\n",COLOR_RED,COLOR_RESET, COLOR_GRAY, __FILE__,COLOR_RESET, __func__, __LINE__);
        }
    }
    /* if AC needs to be stopped, it will stop automatically from here */
    g_cc_ac_stopAC(gClimateButtonsState.auto_on);
    /* start the ac if everything checks out */
    if(false == gClimateButtonsState.front_on)
    {
        g_cc_ac_startAC(gClimateButtonsState.fan, gClimateButtonsState.auto_on); 
    }
     

    *last_fan_state = gClimateButtonsState.fan;
}


/*-------------------------------------------------------------------------------------------------
Function: l_cc_climateControl



Description:
    climateControl represents the auto module. This is the logic wehre it checks if the 
    module is on, if so it will run it and write the state of the buttons if auto module modified
    them. if the auto should be off, it will stop the auto module and let buttons as they were.
    Also here recirculation is set.



Parameters In:
    None



Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void l_cc_climateControl()
{   /* manage the auto module */
    if(true == gClimateButtonsState.auto_on && false == gClimateButtonsState.front_on)
    {   /*run auto module */
        g_cc_auto_run(
            gClimateButtonsState.temperatureGauge, 
            &gClimateButtonsState.recirculation_on, 
            &gClimateButtonsState.ac_on
        );
        /* update buttons file with the new buttons modified in auto module */
        if(true == g_bsw_buttons_writeState()) /* error occured while writing */
        {
            fprintf(stderr, "[%sError%s] %sin file %s:\n  function %s`%s`:%d: Failed writing buttons' state\n",COLOR_RED,COLOR_RESET, COLOR_GRAY, __FILE__,COLOR_RESET, __func__, __LINE__);
        }
    }
    else
    {   /* turn auto off */
        g_cc_auto_stopAuto();  
    }
    if(false == gClimateButtonsState.front_on)
    {
        l_cc_runRecirculation(gClimateButtonsState.recirculation_on);
    }
    else
    {
        /* turn turn recirculation, it will eventually be turned on by the front defrost function*/
    }    
}


/*-------------------------------------------------------------------------------------------------
Function: l_cc_turnClimateControlOFF



Description:
    This function handles all the function calls which turn every buttons off.
    All the buttons are set to off.
    Ac, Auto, front and rear defrost are set to off.
    The state of the buttons is written to the climateButtons.txt file.



Parameters In:
    None



Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void l_cc_turnClimateControlOFF()
{
    /* turn off all buttons and call the appropriate termination functions */
    gClimateButtonsState.auto_on = false;
    gClimateButtonsState.ac_on = false;
    gClimateButtonsState.recirculation_on = false;
    gClimateButtonsState.rear_on = false;
    gClimateButtonsState.front_on = false;

    /* this turns of recirculation*/
    l_cc_runRecirculation(gClimateButtonsState.recirculation_on);

    /* turn off ac */
    g_cc_ac_set_AC_ON_OFF(false); /* turn it off */
    g_cc_ac_stopAC(gClimateButtonsState.auto_on);

    /* turn off auto */
    g_cc_auto_stopAuto();

    /* those are called while buttons have value 0, so they will turn defrost off*/
    l_cc_frontDemist();
    l_cc_rearDemist();

    /* write the updated states of the buttons to file */
    g_bsw_buttons_writeState();
}


/*-------------------------------------------------------------------------------------------------
Function: l_cc_rearDemist



Description:
    Based on the button rear_on, it will turn on the resistence in the glass meant to 
    heat the rear windshield, represented by setting pwmData input8 to on or off (1 or 0)



Parameters In:
    None



Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void l_cc_rearDemist()
{   
    if(true == gClimateButtonsState.rear_on)
    {
        pwmData.input8 = START_REAR_DEFROST_RESISTANCE; 
    }
    else
    {
        pwmData.input8 = STOP_REAR_DEFROST_RESISTANCE; 
    }
        
}


/*-------------------------------------------------------------------------------------------------
Function: l_cc_frontDemist



Description:
    This function handles front demist feature. It will open a valve which redirects the air
    and close it if the option is turned off. When on, it will run the auto module to allow heated
    air to blow on the windshield, and simulatenously will start the AC, both at full strength, to dry
    the air, so the mist will go away. It will also turn recirculation on so it is easier to dehumidify
    the air.
    This needs to be called after the auto module and ac in the main climate loop, because otherwise the 
    values will not persist.


Parameters In:
    None



Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void l_cc_frontDemist()
{
    if(true == gClimateButtonsState.front_on)
    {
        /* if button pressed, open redirection valve, heater and ac together*/
        pwmData.input7 = REDIRECT_AIR_VALVE_OPEN;
        g_cc_auto_run(
            MAX_GAUGE_TEMP, 
            &gClimateButtonsState.recirculation_on, 
            &gClimateButtonsState.ac_on
        );
        gClimateButtonsState.recirculation_on = true;
        gClimateButtonsState.ac_on = true;

        /* start recirculation to let the air dry */
        l_cc_runRecirculation(gClimateButtonsState.recirculation_on);

        /* write state of buttons */
        if(true == g_bsw_buttons_writeState()) /* error occured while writing */
        {
            fprintf(stderr, "[%sError%s] %sin file %s:\n  function %s`%s`:%d: Failed writing buttons' state\n",COLOR_RED,COLOR_RESET, COLOR_GRAY, __FILE__,COLOR_RESET, __func__, __LINE__);
        } 

        /* start AC */
        g_cc_ac_set_AC_ON_OFF(AC_ON);
        g_cc_ac_startAC(DEFROST_FAN_SPEED, AUTO_OFF);
    }
    else
    {   /* if button is not pressed, this funciton call will close the valve */
        pwmData.input7 = REDIRECT_AIR_VALVE_CLOSE;
    }
    
}


/*-------------------------------------------------------------------------------------------------
Function: g_bsw_buttons_readClimate



Description:
    This is the main climate state loop. it will first read buttons only to set last_fan_state accordingly.
    then will start the loop which ends when user chooses to. at each iteration, it will read the sensors and 
    buttons, and based on the data will perform the logic for the climate control module.



Parameters In:
    None



Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void g_cc_run()
{
    g_bsw_buttons_readClimate(); /* read climate to initiate the last fan state with a relevant value */
    uint8 last_fan_state = gClimateButtonsState.fan;

    while(true)
    {
        g_bsw_buttons_readClimate(); /* Read buttons file */
        g_bsw_adc_readAllADC(); /* Read sensors file */

        /* logic */
        if(false == gClimateButtonsState.off)
        {
            l_cc_runAC(&last_fan_state);
            l_cc_climateControl();
            l_cc_frontDemist();
            l_cc_rearDemist();
        }
        else
        {
            /* turn climate control modules off */
            l_cc_turnClimateControlOFF();
        }

        /* print buttons state */
        g_bsw_buttons_printState();

        /* set all the pwm channels to the values given to pwm inputs */
        g_bsw_pwm_setAllPWM();

        /* continue or stop */
        printf("\nContinue? (y/n)");
        uint8 command = getchar();

        if('n' == command || 'N' == command)
        {
            getchar();
            break;
        }
        system("cls");
    }
    printf("\n### Climate module stopped! ###\n\n");
}

#endif /* CLIMATE_CONTROL_C */