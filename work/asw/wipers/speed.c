/*-------------------------------------------------------------------------------------------------
File:      file name
Description: file description
-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/
#ifndef SPEED_C 
#define SPEED_C 
/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/
#include "speed.h"

/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/
uint8 wipers_status;
intensity_state checkIntensity_state;
uint16 wipers_data;
/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
Function: activate_wipers



Description:
    This function is used to display the speed of the wipers accordingly



Parameters In:
     None

Parameters Out:
     None



Return Value:
     None
-------------------------------------------------------------------------------------------------*/

void activate_wipers()
{
    /*Displaying the speed of the wipers*/
    switch(checkIntensity_state)
    {
        case SPEED_LOW:
            printf("Speed low\n");     /*The speed of the wipers is low*/
          break;
        case SPEED_HIGH:
            printf("Speed high\n");    /*The speed of the wipers is high*/
          break;
        default:
            printf("No rain\n");
          break;
    }
    
}

/*-------------------------------------------------------------------------------------------------
Function: wipers_menu



Description:
    This function reads a character from standard input and modifies the state of the wipers accordingly



Parameters In:
     None

Parameters Out:
     None



Return Value:
     None
-------------------------------------------------------------------------------------------------*/

void wipers_menu()
{
    printf("Choose one of the following states:\n");
    printf("For WIPERS_OFF state press M:\n");
    printf("For WIPERS_ON state press N:\n");
    printf("For WIPERS_AUTO state press P:\n");
    command = getchar();                               /*Get the command*/
    if(command == 'M' || command == 'm')
    {
        /*Wipers turn off*/
         checkWipers_state = WIPERS_OFF;
         wipers_status = WIPERS_OFF;
         command = getchar();
    }
    else 
    {
        if(command == 'N' || command == 'n')
        {
            /*Wipers turn on*/
            checkWipers_state = WIPERS_ON;
            wipers_status = WIPERS_ON;
            command = getchar();
        }
        else
        {
            if(command == 'P' || command == 'p')
            {
                /*Wipers in auto mode*/
                checkWipers_state = WIPERS_AUTO;
                wipers_status = WIPERS_AUTO;
                command = getchar();
            }
            else 
            {
               fprintf(stderr, "[%sWarning%s] %sin file %s:\n  function %s`%s`:%d: Command not provided\n",COLOR_MAGENTA,COLOR_RESET, COLOR_GRAY, __FILE__,COLOR_RESET, __func__, __LINE__);
            }
        }

    }
}


#endif /* SPEED_C */