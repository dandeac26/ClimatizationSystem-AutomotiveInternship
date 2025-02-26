/**-------------------------------------------------------------------------------------------------
File:      nume file
Description: descirere file
-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/
#ifndef LIGHTS_C
#define LIGHTS_C
/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/

#include "lights.h"


/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/
uint16 lights_data;
lights_state check_light_state;


/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
Function: menu_lights



Description:
    This function is used to display the commands that should be given from standard input in order to change the state
    of the lights and also to receive the command 



Parameters In:
    None



Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void menu_lights()
{
    uint8 command;
    
    /* display the command that should be given */

    printf("Press D for lights off\n");
    printf("Press E for lights on\n");
    printf("Press F for auto lights\n");

    /* get the command */
    
    command = getchar();
    
        if(command == 'E' || command == 'e')
        {
               /* lights turn on */
               check_light_state = LIGHTS_ON;
               command = getchar();
        }

        else if(command == 'F' || command == 'f')
        {
               /* lights in auto mode */
               check_light_state = LIGHTS_AUTO;
               command = getchar();
        }

        else if(command == 'D' || command == 'd')
        {
               /* lights are off */
               check_light_state = LIGHTS_OFF;
               command = getchar();
        }    
}

/*-------------------------------------------------------------------------------------------------
Function: main_lights



Description:
    This function updates the PWM data structures with the lights and signal data



Parameters In:
    None



Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/

void main_lights()
{   
    /* call the lights menu to get the light state */
    menu_lights();
    
    switch(check_light_state)
    {
        case LIGHTS_OFF:
            
            /* lights are off */
            lights_data = 0;
            pwmData.input2 = lights_data;
            printf("Lights are off\n");

            break;
        
        case LIGHTS_ON:
            
            lights_data = 1;
            main_intensity();

            if (intensity_signal == 0)
            {
                /* write one to pwm channel meaning that the lights are on and with low beam */
                pwmData.input2 = lights_data;
                printf("Lights are on\n");
                printf("Low beam\n");
            }

            else if (intensity_signal == 1)
            {
                /* write one to pwm channel meaning that the lights are on and with high beam */
                pwmData.input2 = 2;
                printf("Lights are on\n");
                printf("High beam\n");
            }

            break;

        case LIGHTS_AUTO:
            
            /* read from adc channel 1 */
            lights_data = adcData.input1;
            /* read from adc channel 2 */
            intensity_data = adcData.input2;
            /* modify signal accordingly */
            if(intensity_data <= 52)
            {
                intensity_signal = 0; /* low beam */
                pwmData.input2 = 1;
                printf("Lights are on\n");
                printf("Low beam\n");
            }
            
            else
            {
                intensity_signal = 1; /* high beam */
                pwmData.input2 = 2;
                printf("Lights are on\n");
                printf("High beam\n");
            }
            
            break;    

        default:
            
            /* lights are off */
            lights_data = 0;
            pwmData.input2 = lights_data;
            printf("Lights are off\n");
            
            break;

    }
    g_bsw_pwm_setAllPWM(); 
}

#endif 