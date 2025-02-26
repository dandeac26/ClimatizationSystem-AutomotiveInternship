/**-------------------------------------------------------------------------------------------------
File:      climate_btn.h
Description: header file
-------------------------------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/
#ifndef CLIMATE_BUTTONS_H
#define CLIMATE_BUTTONS_H

#define climateButtonsDataPath "C:/Users/dan.deac/repos/AutomotiveProject_1/AutomotiveProjectSim/ProiectInternship2-main/data/climateButtons.txt"
#define MAX_CHAR_LINE 100
#define STANDARD_TEMPERATURE 20

#define TEMP_0_C 0
#define TEMP_5_C 5
#define TEMP_8_C 8
#define TEMP_10_C 10
#define TEMP_14_C 14
#define TEMP_15_C 15
#define TEMP_16_C 16
#define TEMP_18_C 18
#define TEMP_20_C 20
#define TEMP_22_C 22
#define TEMP_24_C 24
#define TEMP_25_C 25
#define TEMP_26_C 26
#define TEMP_28_C 28
#define TEMP_30_C 30
#define TEMP_35_C 35
#define TEMP_40_C 40

#define GAUGE_ZERO 0
#define GAUGE_ONE 1
#define GAUGE_TWO 2
#define GAUGE_THREE 3
#define GAUGE_FOUR 4
#define GAUGE_FIVE 5
#define GAUGE_SIX 6
#define GAUGE_SEVEN 7
#define GAUGE_ERROR 1

#define MAX_LINE_WIDTH 4

#define BTN__AUTO_AC_RECIRCULATION_OFF 0
#define BTN__TEMP_GAUGE 1
#define BTN__REAR_FRONT_DEMIST 2
#define BTN__FAN_GAUGE 3

#define AUTO_INDEX 0
#define AC_INDEX 1
#define REC_INDEX 2
#define OFF_INDEX 3
#define TEMP_GAUGE_INDEX 0
#define REAR_INDEX 0
#define FRONT_INDEX 1
#define FAN_INDEX 0

#define LINES_LIMIT 10
/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/
bool  g_bsw_buttons_readClimate();
void  l_bsw_buttons_setState(uint8*, uint8);
uint8 l_bsw_buttons_setTemp(uint8);
void  g_bsw_buttons_printState();
bool  g_bsw_buttons_writeState();
uint8 l_bsw_buttons_encodeTemp(uint8);

/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/
typedef struct {
    bool  auto_on;
    bool  ac_on;
    bool  recirculation_on;
    bool  off;
    uint8 temperatureGauge;
    bool  rear_on;
    bool  front_on;
    uint8 fan;
}climate_buttons_t;

extern climate_buttons_t  gClimateButtonsState;

#endif /* CLIMATE_BUTTONS_H */
