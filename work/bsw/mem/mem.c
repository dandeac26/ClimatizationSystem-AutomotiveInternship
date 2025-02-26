/**-------------------------------------------------------------------------------------------------
File:      nume file
Description: descirere file
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/
#include "mem.h"

/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/
struct g_dataRecorded
{
    uint32 mileage;  /*C file de incrementat mileage*/
    bool daylight;
    bool raining;

}memRecorded;
/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------
Function: g_bsw_mem_setTime



Description:
    This function sets the inputs from struct "g_extendedDataRecorded"



Parameters In:
     data: uint8, value to be set in BSW_ADC_struct

Parameters Out:
     None



Return Value:
     None
-------------------------------------------------------------------------------------------------*/
void g_bsw_mem_setTime(time_t timeRead)
{

    extended_memRecorded.timeDate = timeRead;

}

/*-------------------------------------------------------------------------------------------------
Function: g_bsw_mem_getTime



Description:
    This function sets the inputs from struct "BSW_ADC_struct"
    ctime(&getTime) for right date format show



Parameters In:
     time_t* timeRead, value to be set in g_extendedDataRecorded

Parameters Out:
     None



Return Value:
     None
-------------------------------------------------------------------------------------------------*/

void g_bsw_mem_getTime(time_t* timeRead)
{

    *timeRead = extended_memRecorded.timeDate;

}


