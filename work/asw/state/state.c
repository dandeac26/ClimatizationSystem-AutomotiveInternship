/**-------------------------------------------------------------------------------------------------
File:      nume file
Description: descirere file
-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/
#ifndef STATE_C
#define STATE_C
/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/


#include "state.h"


/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/

uint16*     pwm_Data;
uint16*     pPWM_Data_2;
KL_tested_t gKL_tested;
/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------------------------------
Function: state_helper



Description:
    This function gathers the information specific to each of the Klemme states



Parameters In:
     s: key_state

Parameters Out:
     None



Return Value:
     None
-------------------------------------------------------------------------------------------------*/
void state_helper(key_state s)
{    
     switch(s)
     {
          case STATE_KL0_SLEEP:
          
          l_STATE_KL0_SLEEP();      /*KL0 state*/

          break;
          case STATE_KL15_WAKEUP:   
          
          l_STATE_KL15_WAKEUP();   /*KL15 state*/

          break;
          case STATE_KL30_RUN:

          l_STATE_KL30_RUN();     /*KL30 state*/

          break;
          default:
          l_STATE_KL0_SLEEP();   /*KL0 state*/
          break;   

     }
}


/*-------------------------------------------------------------------------------------------------
Function: l_STATE_KL30_RUN

Description:
    This function gathers the information for the KL30 state
    IMPORTANT NOTE: KL30 state refers to the components that are critical to unction
    like Engine control unit (ECU) or lights. These are always connected to power
    Accessories like radio, windows, wipers need KL15 to run!


Parameters In:
     None

Parameters Out:
     None



Return Value:
     None
-------------------------------------------------------------------------------------------------*/
void l_STATE_KL30_RUN()
{
     g_PWM_init();                      /*Turn on the PWM*/
     g_ADC_init();                      /*Turn on the ADC*/
     
     printf("ADC is enabled\n");
     printf("PWM is enabled\n");

     g_setPWM_KL30();

     gKL_tested = eNotTestedKL;   

     RTE_call(&gKL_tested);             /*Call the scheduler*/

     if(gKL_tested == eIsTestedKL30)    /* Print correct state of the tests*/
     {
          printf("KL30_TESTED\n");
     }
     else
     {
          printf("KL30_NOT_TESTED\n");
     }

     g_bsw_adc_readAllADC();            /* Read all the sensors (from file)*/
     printf("\n");
     
     main_lights();                     /* So far only the lights module is connected to kl30, other components are kl15*/

     /*g_bsw_pwm_setAllPWM();*/           /* Write the pwm channels to the file and stdout */
}


/*-------------------------------------------------------------------------------------------------
Function: l_STATE_KL15_WAKEUP



Description:
     This function gathers the information for the KL15 state.
     IMPORTANT NOTE: KL15 refers to the components like radio, windows, wipers
     which are considered accessory. It is when you turn the key but not necesarrily all the
     way as i understand. But even like this should have all the power without the engine on
     besides the heater which needs the engine to run.

Parameters In:
     None

Parameters Out:
     None



Return Value:
     None
-------------------------------------------------------------------------------------------------*/

void l_STATE_KL15_WAKEUP()
{    /* These should be only in the KL30 state (or only the ADC init should be present), but for convenience and testing 
     *  purposes they are also present here 
     */                      
     g_ADC_init();      /*Turn on the ADC*/
     g_PWM_init();      /*Turn on the PWM*/  

     printf("ADC is enabled\n");
     printf("PWM is enabled\n");

     gKL_tested = eNotTestedKL;   

     /* perform KL15 tests */

     if(gKL_tested == eIsTestedKL15) /* Print if tests ran or not*/
     {
          printf("KL15_TESTED\n");
     }
     else
     {
          printf("KL15_NOT_TESTED\n");
     }
          
     g_bsw_adc_readAllADC();  /* Read sensor data from file */
     printf("\n");

     main_lights();           /* Call the lights module */
              
     wipers();                /* Call the wipers module */
     
     g_test_runClimateTests();

     g_cc_mainClimate();      /* Call the climate module */

     g_bsw_pwm_setAllPWM();   /* Write the PWM channels after they were set by the logic above*/
}


/*-------------------------------------------------------------------------------------------------
Function: l_STATE_KL15_SLEEP



Description:
    This function gathers the information for the KL0 state
     - turns off ADC and PWM


Parameters In:
     None

Parameters Out:
     None



Return Value:
     None
-------------------------------------------------------------------------------------------------*/

void l_STATE_KL0_SLEEP()
{
     g_PWM_init();
     gKL_tested = eNotTestedKL;   
     /* perform KL15 tests */
     if(gKL_tested == eIsTestedKL0)     /* Print if tests ran or not */
     {
          printf("KL0_TESTED\n");
     }
     else
     {
          printf("KL0_NOT_TESTED\n");
     }

     g_ADC_off();                      /*Turn off the ADC*/
     g_PWM_off();                      /*Turn off the PWM*/
     printf("ADC disabled\n");
     printf("PWM disabled\n");
}

#endif /* STATE_C */ 

