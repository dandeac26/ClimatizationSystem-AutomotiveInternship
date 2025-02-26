/**-------------------------------------------------------------------------------------------------
File:      nume file
Description: descirere file
-------------------------------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/
#ifndef BSW_ADC_cnf_H
#define BSW_ADC_cnf_H

#define adcdataPath "C:/Users/dan.deac/repos/AutomotiveProject_1/AutomotiveProjectSim/ProiectInternship2-main/data/adcData.txt"

#define ADC_CHANNEL1 1
#define ADC_CHANNEL2 2
#define ADC_CHANNEL3 3
#define ADC_CHANNEL4 4
#define ADC_CHANNEL5 5
#define ADC_CHANNEL6 6
#define ADC_CHANNEL7 7

#define NUMBER_OF_ADC_CHANNELS 7

/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#include "common.h"

/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/
void g_ADC_off();
void g_ADC_init();

bool bsw_adc_setADCresults(uint8, uint8);
bool g_bsw_adc_getADCresults(uint8, uint16*);
bool l_bsw_adc_readADC(uint8);
void g_bsw_adc_readAllADC();

/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/
extern bool ADC_ON_OFF;

struct BSW_ADC_struct {

    uint16 input1;
    uint16 input2;
    uint16 input3;
    uint16 input4;
    uint16 input5; /* Cabin Temperature */
    uint16 input6; /* Outside Temperature */
    uint16 input7; /* Air Quality */

};
extern struct BSW_ADC_struct adcData;
#endif /* BSW_ADC_cnf_H */
