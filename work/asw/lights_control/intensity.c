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

#include "intensity.h"

/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/
uint16 intensity_signal;
uint16 intensity_data;
beam_state check_beam_state;
/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
Function: menu_intensity



Description:
    This function is used to get the command from the user



Parameters In:
    None

Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/

void menu_intensity()
{
    uint8 command;
    
    printf("Press G for low beam\n");
    printf("Press H for high beam\n");
    printf("Press I for auto beam\n");

    /* get the command from standard input */
    command = getchar();
    
    if(command == 'H' || command == 'h')
    {
            /* high beams */
            check_beam_state = HB_ON;
            command = getchar();
    }

    else if(command == 'I' || command == 'i')
    {
            /* auto mode */
            check_beam_state = HB_AUTO;
            command = getchar();
    }

    else if(command == 'G' || command == 'g')
    {
            /* low beams */
            check_beam_state = HB_OFF;
            command = getchar();
    }    

}

/*-------------------------------------------------------------------------------------------------
Function: main_intensity



Description:
    This function is used to modify intensity signal flag according to what is read from the ADC channels and the user input



Parameters In:
    None



Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/

void main_intensity()
{   
    menu_intensity();
    
    switch(check_beam_state)
    {
        case HB_OFF:
            
            /* low beam */
            intensity_signal = 0;
            
            break;
        
        case HB_ON:
            
            /* high beam */
            intensity_signal = 1;

            break;

        case HB_AUTO:
            
            /* read from adc */
            intensity_data = adcData.input2;
            /* if intensity is lower than 4 then the intensity signal flag is 0 */
            if(intensity_data <= 52)
            {
                intensity_signal = 0; /* low beam */
            }
            
            else
            {
                intensity_signal = 1; /* high beam */
            }

            break;    

        default:
            
            intensity_signal = 0;

            break;

    }   

}

#endif 