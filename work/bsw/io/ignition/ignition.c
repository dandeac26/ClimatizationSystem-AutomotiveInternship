/**-------------------------------------------------------------------------------------------------
File:      nume file
Description: descirere file
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/
#ifndef IGNITION_C
#define IGNITION_C
/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/
#include "ignition.h"
/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/
uint8 ignition_status;
key_state checkSystem_state;
uint8 command;

/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
Function: menu

Description:
    This function reads a character from standard input and modifies the KL state accordingly.

Parameters In:
     None

Parameters Out:
     None

Return Value:
     None
-------------------------------------------------------------------------------------------------*/

void menu()
{
        
        printf("Choose one of the following states\n");
        printf("For KL0 state press A\n");
        printf("For KL15 state press B\n");
        printf("For KL30 state press C\n");
        command = getchar();
    
        if(command == 'B' || command == 'b')
        {
               checkSystem_state = STATE_KL15_WAKEUP;
               command = getchar();
        }

        else if(command == 'C' || command == 'c')
        {
               checkSystem_state = STATE_KL30_RUN;
               command = getchar();
        }

        else if(command == 'A' || command == 'a')
        {
               checkSystem_state = STATE_KL0_SLEEP;
               command = getchar();
        }

}

/*-------------------------------------------------------------------------------------------------
Function: l_bsw_adc_readIgnition



Description:
    This function reads the ignition value from the file



Parameters In:
     None

Parameters Out:
     None



Return Value:
     l_error: bool, true on failure of file read
-------------------------------------------------------------------------------------------------*/

bool l_bsw_adc_readIgnition()
{

     bool l_error = false;  /* variable for checking if the reading from the file is possible */
     uint32 file_read; /* variable to write into it from the file */
     FILE* fp; /* our file descriptor */

     if((fp = fopen(ignitiondataPath, "r")) == NULL)
     {
          fprintf(stderr, "[%sError%s] %sin file %s:\n  function %s`%s`:%d: Failed opening Ignition file\n",COLOR_RED,COLOR_RESET, COLOR_GRAY, __FILE__,COLOR_RESET, __func__, __LINE__);        
          l_error = true;
     }
     
     fscanf(fp, "%d", &file_read); /* read value from the file into the variable */           \
     fclose(fp); /* close the file */
     
     if(file_read == 1)
     {
          
          /*ignition_status = IGNITION_ON;*/ /* ignition is on == 1 in the file */
          ignition_status = STATE_KL30_RUN;
     }
     
     else if(file_read == 0)
     {
          /*ignition_status = IGNITION_OFF;*/ /* ignition is off == 0 in the file */
          ignition_status = STATE_KL0_SLEEP;
     }
     
     else
     {
          perror("Value not specified in the correct manner in the file"); /* if we find something different than 1 or 0 in the file */
     }

     return l_error;

}
#endif



