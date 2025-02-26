/**-------------------------------------------------------------------------------------------------
File:      climate_btn.c
Description: read data from the buttons file and assign variable gClimateButtonsState
-------------------------------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/
#ifndef CLIMATE_BUTTONS_C
#define CLIMATE_BUTTONS_C

/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/
#include "climate_btn.h"

/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/

climate_buttons_t  gClimateButtonsState;

/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
Function: g_bsw_buttons_printState



Description:
    Prints to command line the values of the gClimateButtonsState structure
    


Parameters In:
     none



Parameters Out:
     none



Return Value:
     none
-------------------------------------------------------------------------------------------------*/
void g_bsw_buttons_printState()
{
     /* print results to screen */
     printf("\n");
     printf("[AUTO | AC | Recirculation | ON/OFF]: %d,%d,", gClimateButtonsState.auto_on, gClimateButtonsState.ac_on);
     printf("%d,%d\n", gClimateButtonsState.recirculation_on, gClimateButtonsState.off);
     printf("[Temperature Gauge]: %d\n", gClimateButtonsState.temperatureGauge);
     printf("     [REAR | FRONT]: %d, %d\n", gClimateButtonsState.rear_on, gClimateButtonsState.front_on);
     printf("        [Fan Gauge]: %d", gClimateButtonsState.fan);
     printf("\n");
}


/*-------------------------------------------------------------------------------------------------
Function: g_bsw_buttons_writeState



Description:
    writes to climateButtons.txt file the values of the gClimateButtonsState variable
    


Parameters In:
     none



Parameters Out:
     none



Return Value:
     none
-------------------------------------------------------------------------------------------------*/
bool g_bsw_buttons_writeState()
{ 
     /* print results to screen */
     bool write_error = false;

     FILE* fp;
     if((fp = fopen(climateButtonsDataPath, "w")) == NULL)       /* File opening Check */
     {
          /* Error occured, couldn't open file  */
          write_error = true;
          fprintf(stderr, "[%sError%s] %sin file %s:\n  function %s`%s`:%d: Failed opening file from climateButtonsDataPath\n",COLOR_RED,COLOR_RESET, COLOR_GRAY, __FILE__,COLOR_RESET, __func__, __LINE__);
     }
     else
     {    /* Print to the climateButtons.txt file the contents of the gClimateButtonsState */
          fprintf(fp, "# [AUTO | AC | Recirculation | ON/OFF]: bool\n%d%d", gClimateButtonsState.auto_on, gClimateButtonsState.ac_on);
          fprintf(fp, "%d%d\n", gClimateButtonsState.recirculation_on, gClimateButtonsState.off);
          fprintf(fp, "# [Temperature Gauge]: number -> [0->7]\n%d\n", l_bsw_buttons_encodeTemp(gClimateButtonsState.temperatureGauge));
          fprintf(fp, "# [REAR | FRONT]: bool\n%d%d\n", gClimateButtonsState.rear_on, gClimateButtonsState.front_on);
          fprintf(fp, "# [Fan Gauge]: number -> [0,10]\n%d", gClimateButtonsState.fan);
          
          fclose(fp);
     }
     
     return write_error;
}


/*-------------------------------------------------------------------------------------------------
Function: l_bsw_buttons_setTemp



Description:
     Based on the temperature gauge input, it will give a real world value as temperature
     for example if input is 1, it will give the meaning of temperature = 16 degrees Celsius
    


Parameters In:
     input: uint8



Parameters Out:
     none



Return Value:
     result : uint8
-------------------------------------------------------------------------------------------------*/
uint8 l_bsw_buttons_setTemp(uint8 input)
{    /* based on the temperature gauge, set the result to the corresponding temperature for the gauge value*/
     uint8 result;
     switch(input)
     {
          case GAUGE_ZERO:
               result = TEMP_14_C; 
               break;
          case GAUGE_ONE:
               result = TEMP_16_C;
               break;
          case GAUGE_TWO:
               result = TEMP_18_C;
               break;
          case GAUGE_THREE:
               result = TEMP_20_C;
               break;
          case GAUGE_FOUR:
               result = TEMP_22_C;
               break;
          case GAUGE_FIVE:
               result = TEMP_24_C;
               break;
          case GAUGE_SIX:
               result = TEMP_26_C;
               break;
          case GAUGE_SEVEN:
               result = TEMP_28_C;
               break;
          default:
               result = GAUGE_ERROR;
               break;
     }
     return result;
}

/*-------------------------------------------------------------------------------------------------
Function: l_bsw_buttons_encodeTemp



Description:
     when writing the value again to file, it is important that its the same encoding as it was read
     The temperature was set to actual value and when writing, we want to encode this actual value to the 
     way we want it to be in the file, so when we read again from climateButtons.txt the data will be 
     interpreted correctly


Parameters In:
     input: uint8



Parameters Out:
     none



Return Value:
     result : uint8
-------------------------------------------------------------------------------------------------*/
uint8 l_bsw_buttons_encodeTemp(uint8 input)
{    /* input is the temperature value and the result will be corresponding gauge value */
     uint8 result;
     switch(input)
     {
          case TEMP_14_C:
               result = GAUGE_ZERO; 
               break;
          case TEMP_16_C:
               result = GAUGE_ONE;
               break;
          case TEMP_18_C:
               result = GAUGE_TWO;
               break;
          case TEMP_20_C:
               result = GAUGE_THREE;
               break;
          case TEMP_22_C:
               result = GAUGE_FOUR;
               break;
          case TEMP_24_C:
               result = GAUGE_FIVE;
               break;
          case TEMP_26_C:
               result = GAUGE_SIX;
               break;
          case TEMP_28_C:
               result = GAUGE_SEVEN;
               break;
          default:
               result = GAUGE_ERROR;
               break;
     }
     return result;
}


/*-------------------------------------------------------------------------------------------------
Function: l_bsw_buttons_setState



Description:
    This function takes the line which is read from readClimate function
    and transforms from character to uint8 and sets the values of the reading to
    the gClimateButtonsState data structure
    


Parameters In:
     line : uint8*
     line_index : uint8



Parameters Out:
     none



Return Value:
     none
-------------------------------------------------------------------------------------------------*/
void l_bsw_buttons_setState(uint8 *line, uint8 line_index)
{
     /* initialize the reading array with the values on the line */
     uint8 reading[MAX_LINE_WIDTH];
     for(uint8 i = 0; i < MAX_LINE_WIDTH; i++) reading[i] = ctoi(line[i]); 

     switch(line_index)
     {    /* based on position of file pointer, fill gClimateButtonsState' fileds */
          case BTN__AUTO_AC_RECIRCULATION_OFF:
               gClimateButtonsState.auto_on = reading[AUTO_INDEX];
               gClimateButtonsState.ac_on = reading[AC_INDEX];
               gClimateButtonsState.recirculation_on = reading[REC_INDEX];
               gClimateButtonsState.off = reading[OFF_INDEX];
               break;
          case BTN__TEMP_GAUGE:
               if(l_bsw_buttons_setTemp(reading[TEMP_GAUGE_INDEX]) != GAUGE_ERROR)
               {
                    gClimateButtonsState.temperatureGauge = l_bsw_buttons_setTemp(reading[TEMP_GAUGE_INDEX]);
               }
               else
               {
                    /*Handle Error*/
                    gClimateButtonsState.temperatureGauge = STANDARD_TEMPERATURE;
                    fprintf(stderr, "[%sWarning%s] %sin file %s:\n  function %s`%s`:%d: Could not read gauge, so it is set to 20 degrees C\n     Possible cause: value of gauge in the climateButtons file is not in range [0->7]\n   Care! if you see a 3, its the standard. so if you ran the program again, you will see a 3, instead of the value you wrote initially, which could have not been in the range!\n",COLOR_MAGENTA,COLOR_RESET, COLOR_GRAY, __FILE__,COLOR_RESET, __func__, __LINE__); 
               }
               
               break;
          case BTN__REAR_FRONT_DEMIST:
               gClimateButtonsState.rear_on = reading[REAR_INDEX];
               gClimateButtonsState.front_on = reading[FRONT_INDEX];
               break;
          case BTN__FAN_GAUGE:
               if(reading[FAN_INDEX] > 9)
               {
                    gClimateButtonsState.fan = 9;
               }
               else
               {
                    gClimateButtonsState.fan = reading[FAN_INDEX];
               }
               
               break;
          default:
               break;
     }
}

/*-------------------------------------------------------------------------------------------------
Function: g_bsw_buttons_readClimate



Description:
     This function reads from the file the state of the buttons (on/off) and 
     values of the temperature gauges and fan gauge. It will set the gClimateButtonsState
     variable to those values and print them to the screen 
    


Parameters In:
     none



Parameters Out:
     none



Return Value:
     read_error : bool
-------------------------------------------------------------------------------------------------*/
bool g_bsw_buttons_readClimate()
{    /* Reading buttons */
     bool read_error = false;

     FILE* fp;                                                           
     if((fp = fopen(climateButtonsDataPath, "r")) == NULL)       /* File opening Check */
     {
          read_error = true;
          fprintf(stderr, "[%sError%s] %sin file %s:\n  function %s`%s`:%d: Failed openning buttons file\n",COLOR_RED,COLOR_RESET, COLOR_GRAY, __FILE__,COLOR_RESET, __func__, __LINE__);
          /* return read_error; but in automotive can't do this*/
     }
     else
     {
          uint8 line[MAX_CHAR_LINE];                                       /* line will be the line read from the file */
          uint8 line_index = 0;                                            /* line_index is the current line we are at, if over 10 we stop reading */
          while(fgets(line, MAX_CHAR_LINE, fp) && (line_index < LINES_LIMIT)) /* go through each line, maximum 10 lines*/
          {      /* read line from the file */

               if(line[0]=='#') continue;                                  /* skip description lines of input (they start with '#') */

               l_bsw_buttons_setState(line, line_index);                   /* based on line values and the line index, we set values to the data structure which holds buttons information*/

               line_index++;                                               /* increase line index before reading the next line*/
          }
          fclose(fp);
     }
     

     return read_error;
}


#endif /* CLIMATE_BUTTONS_C */



