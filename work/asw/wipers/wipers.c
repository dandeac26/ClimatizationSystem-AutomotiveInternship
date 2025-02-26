/*-------------------------------------------------------------------------------------------------
File:      file name
Description: file description
-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/
#ifndef WIPERS_C 
#define WIPERS_C 
/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/
#include "wipers.h"

/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/
uint16 intensity_level;
wipers_state checkWipers_state;
/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
Function: wipers



Description:
    This function is used to turn on, auto and off the wipers



Parameters In:
     None

Parameters Out:
     None



Return Value:
     None
-------------------------------------------------------------------------------------------------*/

void wipers()
{
     intensity_level = adcData.input3;  /*Reads the value written on ADC channel 3*/

     wipers_menu(); /*Call the function to display the interface*/

     switch(checkWipers_state)
     {
          case WIPERS_OFF:   
               pwmData.input1 = 0;                    /*Wipers are off*/
               printf("Wipers are off\n");
               break;
          case WIPERS_ON:   
               pwmData.input1 = 1;                             /*Write the value on PWM channel 1*/
               checkIntensity_state = SPEED_LOW;              /*The state of speed is low*/
               activate_wipers(checkIntensity_state);                    /*Wipers are on*/
               printf("Wipers are on\n");
               break;
          case WIPERS_AUTO:
               if((intensity_level >= 49) && (intensity_level <= 52))        /*Checking the intensity of the rain*/
               {
                    pwmData.input1 = 1;                             /*Write the value on PWM channel 1*/
                    checkIntensity_state = SPEED_LOW;              /*The state of speed is low*/
                    activate_wipers(checkIntensity_state);          /*Call the function to display the speed state accordingly*/
               }
               else if((intensity_level >= 53) && (intensity_level <= 57))   /*Checking the intensity of the rain*/
               {
                    pwmData.input1 = 2;                             /*Write the value on PWM channel 1*/
                    checkIntensity_state = SPEED_HIGH;              /*The state of speed is high*/
                    activate_wipers(checkIntensity_state);          /*Call the function to display the speed state accordingly*/
               }
               printf("Wipers are in auto mode\n");
               break;
          default:
               checkWipers_state = WIPERS_OFF;                     /*Sets the state of the wipers to off*/
               break;
     } 
     g_bsw_pwm_setAllPWM();
}


#endif /* WIPERS_C */ 
