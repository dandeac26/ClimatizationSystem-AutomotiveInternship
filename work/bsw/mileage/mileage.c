/**-------------------------------------------------------------------------------------------------
File:      nume file
Description: descirere file
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/
#ifndef MILEAGE_C
#define MILEAGE_C

/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/
#include "mileage.h"


/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/
struct g_dataRecorded memRecorded;

/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
Function: l_bsw_setMileage



Description:
    Update memRecorded with data and 
    if data is irrelevant ( <=0 ) then returns l_error as true


Parameters In:
     data: uint32

Parameters Out:
     None



Return Value:
     l_error: bool 
-------------------------------------------------------------------------------------------------*/
bool l_bsw_setMileage(uint32 data) 
{
    bool l_error = false;

    if(data > 0)
    {
        memRecorded.mileage = data;
    }
    else
    {
        l_error = true;
    }

    return l_error;
}



/*-------------------------------------------------------------------------------------------------
Function: g_bsw_getMileage



Description:
    Returns value from specified channel indirectly using a pointer



Parameters In:
     data: uint32*



Parameters Out:
     None



Return Value:
     l_error
-------------------------------------------------------------------------------------------------*/
bool g_bsw_getMileage(uint32* data) 
{
    bool l_error = false;

    if(memRecorded.mileage > 0)
    {
        *data = memRecorded.mileage;
    }
    else
    {
        l_error = true;
    }

    return l_error;
}

/*-------------------------------------------------------------------------------------------------
Function: l_bsw_readMileage



Description:
    This function reads data from the file about milage 



Parameters In:
     none



Parameters Out:
     none



Return Value:
     l_error
-------------------------------------------------------------------------------------------------*/
bool l_bsw_readMileage() 
{
    FILE* fp;
    uint32 l_data;
    bool l_error = false;

    /*File opening Check*/
    if((fp = fopen(mileagedataPath, "r")) == NULL)
    {
      l_error = true;
      fprintf(stderr, "[%sError%s] %sin file %s:\n  function %s`%s`:%d: Failed opening milage file\n",COLOR_RED,COLOR_RESET, COLOR_GRAY, __FILE__,COLOR_RESET, __func__, __LINE__);        
      return l_error;
    }

    /*File reading*/
    fscanf(fp, "%i", &l_data);
    fclose(fp);
    l_bsw_setMileage(l_data);

    return l_error;

}

/*-------------------------------------------------------------------------------------------------
Function: l_bsw_readMileage



Description:
    This function increments the mileage is the previously recorder mileage is differnet than 0
    and the engine is running 



Parameters In:
     none



Parameters Out:
     none



Return Value:
     none
-------------------------------------------------------------------------------------------------*/
bool l_bsw_incrementMileage()
{

    bool l_error = false;
    if(memRecorded.mileage != 0 && extended_memRecorded.engineRunning)
    {
        memRecorded.mileage++;

    }
    else
    {
        l_error = true;

    }

    return l_error;

}
#endif /* MILEAGE_C */
