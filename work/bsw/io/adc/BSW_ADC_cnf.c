/**-------------------------------------------------------------------------------------------------
File:      nume file
Description: descirere file
-------------------------------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/
#ifndef BSW_ADC_cnf_C
#define BSW_ADC_cnf_C

/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/

#include "BSW_ADC_cnf.h"

/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/
bool ADC_ON_OFF = false;
struct BSW_ADC_struct adcData;
uint16* pData;
/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------------------------------
Function: g_ADC_init



Description:
    Sets ADC_ON_OFF to true



Parameters In:
    None

Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void g_ADC_init()
{
    /*  activez ADC-ul */
    ADC_ON_OFF = true;
}
/*-------------------------------------------------------------------------------------------------
Function: g_ADC_off



Description:
    Sets ADC_ON_OFF to false



Parameters In:
    None

Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void g_ADC_off()
{
    /*  dezactivez ADC-ul */
    ADC_ON_OFF = false;
}
/*-------------------------------------------------------------------------------------------------
Function: bsw_adc_setADCresults



Description:
    This function sets the inputs from struct "BSW_ADC_struct"



Parameters In:
     channel: uint8, value: ADC_CHANNEL1-...-ADC_CHANNEL4 ()
     data: uint8, value to be set in BSW_ADC_struct

Parameters Out:
     None



Return Value:
     l_error: bool
-------------------------------------------------------------------------------------------------*/
bool bsw_adc_setADCresults(uint8 channel, uint8 data) 
{

     bool l_error = false;

    if(ADC_ON_OFF)
    {
        

        /*SWITCH HANDLING CALLING THE INPUT SETTING METHODS*/
        switch (channel)
        {
              case ADC_CHANNEL1:
                  /*SETTING CHANNEL 1 VALUE*/
                   adcData.input1 = (uint16)data;
                   break;
              case ADC_CHANNEL2:
                  /*SETTING CHANNEL 2 VALUE*/
                   adcData.input2 = (uint16)data;
                   break;
              case ADC_CHANNEL3:
                  /*SETTING CHANNEL 3 VALUE*/
                   adcData.input3 = (uint16)data;
                   break;
              case ADC_CHANNEL4:
                  /*SETTING CHANNEL 4 VALUE*/
                   adcData.input4 = (uint16)data;
                   break;
              case ADC_CHANNEL5:
                  /*SETTING CHANNEL 5 VALUE*/
                   adcData.input5 = (uint16)data;
                   break;
              case ADC_CHANNEL6:
                  /*SETTING CHANNEL 6 VALUE*/
                   adcData.input6 = (uint16)data;
                   break;
              case ADC_CHANNEL7:
                  /*SETTING CHANNEL 7 VALUE*/
                   adcData.input7 = (uint16)data;
                   break;
              default:
                  l_error = true;
                   break;
        }

        return l_error;
    }
    return l_error;

}



/*-------------------------------------------------------------------------------------------------
Function: g_bsw_adc_getADCresults



Description:
    Returns value from specified channel indirectly using a pointer



Parameters In:
     channel: uint8
     



Parameters Out:
     data: uint16*



Return Value:
     None
-------------------------------------------------------------------------------------------------*/
bool g_bsw_adc_getADCresults(uint8 channel, uint16* data) 
{

     bool l_error = false;

    if(ADC_ON_OFF)
    {
         
        /*SWITCH HANDLING RETURNING THE DATA*/
         switch(channel)
         {
              case ADC_CHANNEL1:
                  /*RETURNING CHANNEL 1 VALUE*/
                   *data = adcData.input1;
                   break;
              case ADC_CHANNEL2:
                  /*RETURNING CHANNEL 2 VALUE*/
                   *data = adcData.input2;
                   break;
              case ADC_CHANNEL3:
                  /*RETURNING CHANNEL 3 VALUE*/
                   *data = adcData.input3;
                   break;
              case ADC_CHANNEL4:
                  /*RETURNING CHANNEL 4 VALUE*/
                   *data = adcData.input4;
                   break;
               case ADC_CHANNEL5:
                  /*RETURNING CHANNEL 5 VALUE*/
                   *data = adcData.input5;
                   break;
              case ADC_CHANNEL6:
                  /*RETURNING CHANNEL 6 VALUE*/
                   *data = adcData.input6;
                   break;
              case ADC_CHANNEL7:
                  /*RETURNING CHANNEL 7 VALUE*/
                   *data = adcData.input7;
                   break;
              default:
                   l_error = true;
                   break;
         }

        return l_error;
    }

    return l_error;
}




/*-------------------------------------------------------------------------------------------------
Function: l_bsw_adc_readADC



Description:
    This function sets the ADC values by reading from the corresponding file
    


Parameters In:
     channels: uint8



Parameters Out:
     none



Return Value:
     l_error: bool, true if channel doesn't match any existing channel or error occured while reading in file
-------------------------------------------------------------------------------------------------*/
bool l_bsw_adc_readADC(uint8 channel)
{
     bool l_error = false;

     if(ADC_ON_OFF)
     {
          FILE* fp;
          uint8 l_i = 0;
          uint8 l_data[100];
          
          /*File opening Check*/
          if((fp = fopen(adcdataPath, "r")) == NULL)
          {
               l_error = true;
               fprintf(stderr, "[%sError%s] %sin file %s:\n  function %s`%s`:%d: Failed opening ADC file\n",COLOR_RED,COLOR_RESET, COLOR_GRAY, __FILE__,COLOR_RESET, __func__, __LINE__); 
               return l_error;
          }

          /*File reading--Reading all 7 inputs from file*/
          for (l_i = 0; l_i < NUMBER_OF_ADC_CHANNELS; l_i++)
          {
               fscanf(fp, "%c", &l_data[l_i]);
          }
          fclose(fp);

          /*SWITCH HANDLING RETURNING THE DATA*/
          switch (channel)
          {
               case ADC_CHANNEL1:
                    /*CALLING METHOD TO SET ADC CHANNEL 1 VALUES*/
                    bsw_adc_setADCresults(channel,l_data[channel-1]);
                    break;
               case ADC_CHANNEL2:
                    /*CALLING METHOD TO SET ADC CHANNEL 2 VALUES*/
                    bsw_adc_setADCresults(channel,l_data[channel-1]);
                    break;
               case ADC_CHANNEL3:
                    /*CALLING METHOD TO SET ADC CHANNEL 3 VALUES*/
                    bsw_adc_setADCresults(channel,l_data[channel-1]);
                    break;
               case ADC_CHANNEL4:
                    /*CALLING METHOD TO SET ADC CHANNEL 4 VALUES*/
                    bsw_adc_setADCresults(channel,l_data[channel-1]);
                    break;
               case ADC_CHANNEL5:
                    /*CALLING METHOD TO SET ADC CHANNEL 5 VALUES*/
                    bsw_adc_setADCresults(channel,l_data[channel-1]);
                    break;
               case ADC_CHANNEL6:
                    /*CALLING METHOD TO SET ADC CHANNEL 6 VALUES*/
                    bsw_adc_setADCresults(channel,l_data[channel-1]);
                    break;
               case ADC_CHANNEL7:
                    /*CALLING METHOD TO SET ADC CHANNEL 7 VALUES*/
                    bsw_adc_setADCresults(channel,l_data[channel-1]);
                    break;
               default:
                    l_error = true;
                    break;
          }

          return l_error; /* this is not needed */
     }

     return l_error;
}


/*-------------------------------------------------------------------------------------------------
Function: g_bsw_adc_readAllADC



Description:
    This function reads from all channels dedicated to the sensors and updates the 
    relevant data structures to the appropriate values.
    Additionally prints to screen the value on all channels.



Parameters In:
    None

Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void g_bsw_adc_readAllADC()
{
     printf("\n");
     printf("ADC reading: ");
     for(uint8 channel_index = 1; channel_index <= NUMBER_OF_ADC_CHANNELS; channel_index++)
     {
          l_bsw_adc_readADC(channel_index);                
          g_bsw_adc_getADCresults(channel_index,&pData); 
          printf("%c | ", pData);
     }
     printf("\nADC channel: 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n");
     printf("\n");
}

#endif /* BSW_ADC_cnf_H */



