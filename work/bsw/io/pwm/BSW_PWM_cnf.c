/**-------------------------------------------------------------------------------------------------
File:      nume file
Description: descirere file
-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/
#ifndef BSW_PWM_cnf_C
#define BSW_PWM_cnf_C


/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/
#include "BSW_PWM_cnf.h"

/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/
struct BSW_PWM_struct pwmData;
bool PWM_ON_OFF = false;
uint16* pPWM_Data;
/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/



/*-------------------------------------------------------------------------------------------------
Function: g_PWM_init



Description:
    Sets PWM_ON_OFF to true



Parameters In:
    None

Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void g_PWM_init()
{
    /*activez PWM-ul*/
    PWM_ON_OFF = true;
}

/*-------------------------------------------------------------------------------------------------
Function: g_PWM_off



Description:
    Sets PWM_ON_OFF to false
    Stops all channels.


Parameters In:
    None

Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void g_PWM_off()
{
    /*dezactivez PWM-ul*/
    
    bsw_pwm_setPWMresults(pwmData.output1, 0);
    bsw_pwm_setPWMresults(pwmData.output2, 0);
    bsw_pwm_setPWMresults(pwmData.output3, 0);
    bsw_pwm_setPWMresults(pwmData.output4, 0);
    bsw_pwm_setPWMresults(pwmData.output5, 0);
    bsw_pwm_setPWMresults(pwmData.output6, 0);
    bsw_pwm_setPWMresults(pwmData.output7, 0);
    bsw_pwm_setPWMresults(pwmData.output8, 0);

    pwmData.input1 = 0;
    pwmData.input2 = 0;
    pwmData.input3 = 0;
    pwmData.input4 = 0;
    pwmData.input5 = 0;
    pwmData.input6 = 0;
    pwmData.input7 = 0;
    pwmData.input8 = 0;
    
    g_bsw_pwm_setAllPWM();

    PWM_ON_OFF = false;
}


/*-------------------------------------------------------------------------------------------------
Function: g_setPWM_KL30



Description:
    kill all channels which are not open in kl30 (all but channel 2 so far)



Parameters In:
    None

Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void g_setPWM_KL30()
{
    bsw_pwm_setPWMresults(pwmData.output1, 0);
    bsw_pwm_setPWMresults(pwmData.output3, 0);
    bsw_pwm_setPWMresults(pwmData.output4, 0);
    bsw_pwm_setPWMresults(pwmData.output5, 0);
    bsw_pwm_setPWMresults(pwmData.output6, 0);
    bsw_pwm_setPWMresults(pwmData.output7, 0);
    bsw_pwm_setPWMresults(pwmData.output8, 0);

    pwmData.input1 = 0;
    pwmData.input3 = 0;
    pwmData.input4 = 0;
    pwmData.input5 = 0;
    pwmData.input6 = 0;
    pwmData.input7 = 0;
    pwmData.input8 = 0;

    g_bsw_pwm_setAllPWM();
}


/*-------------------------------------------------------------------------------------------------
Function: bsw_pwm_setPWMresults



Description:
This function sets the inputs to struct "BSW_PWM_struct"



Parameters In:
channel: uint8, value: PWM_CHANNEL1-...-PWM_CHANNEL2
data: uint16, value to be set in BSW_PWM_struct

Parameters Out:
None



Return Value:
l_error: bool, true in case of failure
-------------------------------------------------------------------------------------------------*/
bool bsw_pwm_setPWMresults(uint8 channel, uint16 data)
{
    bool l_error = false;
    if(PWM_ON_OFF)
    {
        /* SWITCH HANDLING SETTING THE VALUES */
        switch (channel)
        {
            case PWM_CHANNEL1:
                /*SETTING CHANNEL 1 VALUE*/
                pwmData.output1 = data;
                break;
            case PWM_CHANNEL2:
                /*SETTING CHANNEL 2 VALUE*/
                pwmData.output2 = data;
                break;
            case PWM_CHANNEL3:
                /*SETTING CHANNEL 3 VALUE*/
                pwmData.output3 = data;
                break;
            case PWM_CHANNEL4:
                /*SETTING CHANNEL 4 VALUE*/
                pwmData.output4 = data;
                break;
            case PWM_CHANNEL5:
                /*SETTING CHANNEL 5 VALUE*/
                pwmData.output5 = data;
                break;
            case PWM_CHANNEL6:
                /*SETTING CHANNEL 6 VALUE*/
                pwmData.output6 = data;
                break;
            case PWM_CHANNEL7:
                /*SETTING CHANNEL 7 VALUE*/
                pwmData.output7 = data;
                break;
            case PWM_CHANNEL8:
                /*SETTING CHANNEL 8 VALUE*/
                pwmData.output8 = data;
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
Function: g_bsw_pwm_getPWMresults



Description:
    Returns value from specified channel indirectly using a pointer



Parameters In:
    channel: uint8
    



Parameters Out:
    data: uint16*



Return Value:
    l_error: bool
-------------------------------------------------------------------------------------------------*/
extern bool g_bsw_pwm_getPWMresults(uint8 channel, uint16* data)
{
    bool l_error = false;
    if(PWM_ON_OFF)
    {

        /*SWITCH HANDLING RETURNING THE DATA*/
        switch(channel)
        {
            case PWM_CHANNEL1:
                /*RETURNING CHANNEL 1 VALUE*/
                *data = pwmData.output1;
                break;
            case PWM_CHANNEL2:
                /*RETURNING CHANNEL 2 VALUE*/
                *data = pwmData.output2;
                break;
            case PWM_CHANNEL3:
                /*RETURNING CHANNEL 3 VALUE*/
                *data = pwmData.output3;
                break;
            case PWM_CHANNEL4:
                /*RETURNING CHANNEL 4 VALUE*/
                *data = pwmData.output4;
                break;
            case PWM_CHANNEL5:
                /*RETURNING CHANNEL 5 VALUE*/
                *data = pwmData.output5;
                break;
            case PWM_CHANNEL6:
                /*RETURNING CHANNEL 6 VALUE*/
                *data = pwmData.output6;
                break;
            case PWM_CHANNEL7:
                /*RETURNING CHANNEL 7 VALUE*/
                *data = pwmData.output7;
                break;
            case PWM_CHANNEL8:
                /*RETURNING CHANNEL 8 VALUE*/
                *data = pwmData.output8;
                break;
            default:
                /*SETTING ERROR FLAG*/
                l_error = true;
                break;
        }

        return l_error;
    }
    return l_error;

}

/*-------------------------------------------------------------------------------------------------
Function: l_bsw_pwm_writePWM



Description:
    This function writes value to the 2 pwm channels



Parameters In:
    pwm channels: uint8
    DtCy: uint64



Parameters Out:
    None



Return Value:
    l_error: bool
-------------------------------------------------------------------------------------------------*/
extern bool l_bsw_pwm_writePWM(uint8 channel, uint64 DtCy)
{
    bool l_error = false;
    if(PWM_ON_OFF)
    {
        FILE* fp;
        uint64 l_bitwisePWM = 0;
        uint64 l_avgVoltage = 0;

        /*PARAMETER ERROR HANDLING*/
        if(channel < PWM_CHANNEL1 || channel > NUMBER_OF_PWM_CHANNELS)
        {
            l_error = true;
            return l_error;
        }
        else if(DtCy < MIN_DtCy || DtCy > MAX_DtCy)
        {
            l_error = true;
            return l_error;
        }
        else
        {
            l_error = false;
        }

        l_avgVoltage = (DtCy/100) * PWM_POWER_SUPPLY;
        l_bitwisePWM = l_avgVoltage* VOLTAGE_CONVERSION /PWM_POWER_SUPPLY;

        /*File Opening and Error Handling*/
        if((fp = fopen(pwmdataPath, "w")) == NULL)
        {
            l_error = true;
            fprintf(stderr, "[%sError%s] %sin file %s:\n  function %s`%s`:%d: Failed opening PWM file\n",COLOR_RED,COLOR_RESET, COLOR_GRAY, __FILE__,COLOR_RESET, __func__, __LINE__);        
            return l_error;
        }

        /*File writing*/
        

        /*SWITCH HANDLING CALLING THE INPUT SETTING METHODS*/
        switch (channel)
        {
            case PWM_CHANNEL1:
                /*CALLING METHOD TO SET PWM CHANNEL 1 VALUES*/
                bsw_pwm_setPWMresults(channel,l_bitwisePWM * pwmData.input1);
                break;
            case PWM_CHANNEL2:
                /*CALLING METHOD TO SET PWM CHANNEL 2 VALUES*/
                bsw_pwm_setPWMresults(channel,l_bitwisePWM * pwmData.input2);
                break;
            case PWM_CHANNEL3:
                /*CALLING METHOD TO SET PWM CHANNEL 3 VALUES*/
                bsw_pwm_setPWMresults(channel,l_bitwisePWM * pwmData.input3);
                break;
            case PWM_CHANNEL4:
                /*CALLING METHOD TO SET PWM CHANNEL 4 VALUES*/
                bsw_pwm_setPWMresults(channel,l_bitwisePWM * pwmData.input4);
                break;
            case PWM_CHANNEL5:
                /*CALLING METHOD TO SET PWM CHANNEL 5 VALUES*/
                bsw_pwm_setPWMresults(channel,l_bitwisePWM * pwmData.input5);
                break;
            case PWM_CHANNEL6:
                /*CALLING METHOD TO SET PWM CHANNEL 6 VALUES*/
                bsw_pwm_setPWMresults(channel,l_bitwisePWM * pwmData.input6);
                break;
            case PWM_CHANNEL7:
                /*CALLING METHOD TO SET PWM CHANNEL 7 VALUES*/
                bsw_pwm_setPWMresults(channel,l_bitwisePWM * pwmData.input7);
                break;
            case PWM_CHANNEL8:
                /*CALLING METHOD TO SET PWM CHANNEL 8 VALUES*/
                bsw_pwm_setPWMresults(channel,l_bitwisePWM * pwmData.input8);
                break;
            default:
                l_error = true;
                break;
        }

        fprintf(fp,"Wipers:       %d\n", pwmData.output1);
        fprintf(fp,"Lights:       %d\n", pwmData.output2);
        fprintf(fp,"Rec. Valve:   %d\n", pwmData.output3);
        fprintf(fp,"Blend Heat:   %d\n", pwmData.output4);
        fprintf(fp,"AC Fan:       %d\n", pwmData.output5);
        fprintf(fp,"Cooler+drier: %d\n", pwmData.output6);
        fprintf(fp,"Front Valve:  %d\n", pwmData.output7);
        fprintf(fp,"Rear Resist.: %d\n", pwmData.output8);

        fclose(fp);

        return l_error;
    }

    return l_error;

}



/*-------------------------------------------------------------------------------------------------
Function: g_bsw_pwm_setAllPWM



Description:
    This function sets all the PWM channels to their calculated value. based on the channel
    it will select automatically the required duty cycle.
    Additionally prints to screen the values written.


Parameters In:
    None


Parameters Out:
    None



Return Value:
    None
-------------------------------------------------------------------------------------------------*/
void g_bsw_pwm_setAllPWM()
{   printf("\n");
    for(uint8 channel_index = 1; channel_index <= NUMBER_OF_PWM_CHANNELS; channel_index++)
    {
        uint8* name;
        uint64 duty_cycle;
        switch(channel_index)
        {
            case PWM_CHANNEL1: 
                duty_cycle = 30;
                name = "Wipers";
                break;
            case PWM_CHANNEL2:
                duty_cycle = 30;
                name = "Lights";
                break;
            case PWM_CHANNEL3:
                duty_cycle = 100;
                name = "Rec. Valve";
                break;
            case PWM_CHANNEL4:
                duty_cycle = 10;
                name = "Blend Heat";
                break;
            case PWM_CHANNEL5:
                duty_cycle = 10;
                name = "AC Fan";
                break;
            case PWM_CHANNEL6:
                duty_cycle = 100;
                name = "Cooler+drier";
                break;
            case PWM_CHANNEL7:
                duty_cycle = 100;
                name = "Front Valve";
                break;
            case PWM_CHANNEL8:
                duty_cycle = 100;
                name = "Rear Resist";
                break;
            default:
                duty_cycle = 100;
                name = "default";
                break;
        }

        l_bsw_pwm_writePWM(channel_index, duty_cycle);           
        g_bsw_pwm_getPWMresults(channel_index, &pPWM_Data);

        printf("Value set to pwm Channel %d: is %d        (%s)\n", channel_index, pPWM_Data, name);
    }
    printf("\n");
}

#endif /* BSW_PWM_cnf_C */


