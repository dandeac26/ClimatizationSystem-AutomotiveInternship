/**-------------------------------------------------------------------------------------------------
File:      nume file
Description: descirere file
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/
#ifndef MEME_H
#define MEME_H
/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/

#include "time.h"
#include "common.h"
/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/
void g_bsw_mem_setTime(time_t);
void g_bsw_mem_getTime(time_t*);

/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/
struct g_dataRecorded
{
    uint32 mileage;  /* C file de incrementat mileage */
    bool daylight;
    bool raining;

};
extern struct g_dataRecorded memRecorded;

struct g_extendedDataRecorded
{

    time_t timeDate;
    bool engineRunning;

};
extern struct g_extendedDataRecorded extended_memRecorded;

typedef enum{
    eIsTestedKL0,
    eIsTestedKL15,
    eIsTestedKL30,
    eNotTestedKL
}KL_tested_t;

#endif /* MEM_H */

