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
#include "rte.h"

/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/
struct taskData_ADC signal1;
struct taskData_ADC signal2; 
struct taskData_ADC signal3;
struct taskData_ADC signal4;
struct taskData_ADC signal5; 
struct taskData_ADC signal6;
struct taskData_ADC signal7;
uint8 command_flag;
clock_t time_till_call;
clock_t startTask_100ms, startTask_10ms, startTask_1ms;
time_t* getTime;
uint32* mileage;

/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
Function: TASK_100ms



Description:
    Returns value from specified channel indirectly using a pointer



Parameters In:
    None


Parameters Out:
     None



Return Value:
     None
-------------------------------------------------------------------------------------------------*/
void TASK_100ms()
{

    #if TEST_SESSION
    struct l_bsw_adc_readADCTESTER signalADC_TESTER;
    bool l_bsw_pwm_writePWM_TESTER;
    bool l_bsw_readMileage_TESTER;
    bool g_bsw_mem_setTime_TESTER;
    bool g_bsw_mem_getTime_TESTER;
    bool g_bsw_getMileage_TESTER;

    signalADC_TESTER.channel1_READ_ADC = l_bsw_adc_readADC(signal1.channelADC);
    signalADC_TESTER.channel2_READ_ADC = l_bsw_adc_readADC(signal2.channelADC);
    signalADC_TESTER.channel1_GET_ADC = g_bsw_adc_getADCresults(signal1.channelADC,&signal1.pDataADC);
    signalADC_TESTER.channel2_GET_ADC = g_bsw_adc_getADCresults(signal2.channelADC,&signal2.pDataADC);
    l_bsw_pwm_writePWM_TESTER = l_bsw_pwm_writePWM(PWM_CHANNEL1, 50);
    l_bsw_readMileage_TESTER = l_bsw_readMileage();
    g_bsw_mem_setTime(time(NULL));
    g_bsw_mem_getTime(&getTime);
    g_bsw_getMileage_TESTER = g_bsw_getMileage(&mileage);
    task_100ms_counter++;
    task_TESTER();

    #else

    l_bsw_adc_readADC(signal1.channelADC);
    l_bsw_adc_readADC(signal2.channelADC);
    g_bsw_adc_getADCresults(signal1.channelADC,&signal1.pDataADC);
    g_bsw_adc_getADCresults(signal2.channelADC,&signal2.pDataADC);
    /* 
     l_bsw_pwm_writePWM(PWM_CHANNEL1, 0); //was 50
     l_bsw_pwm_writePWM(PWM_CHANNEL2, 0);
     l_bsw_pwm_writePWM(PWM_CHANNEL3, 0);
     l_bsw_pwm_writePWM(PWM_CHANNEL4, 0);
     l_bsw_pwm_writePWM(PWM_CHANNEL5, 0);
     l_bsw_pwm_writePWM(PWM_CHANNEL6, 0); */

    l_bsw_readMileage();
    g_bsw_mem_setTime(time(NULL));
    g_bsw_mem_getTime(&getTime);
    g_bsw_getMileage(&mileage);

    #endif  /* TEST_SESSION */

}

/*-------------------------------------------------------------------------------------------------
Function: TASK_10ms



Description:
    Returns value from specified channel indirectly using a pointer



Parameters In:
     None



Parameters Out:
     None



Return Value:
     None
-------------------------------------------------------------------------------------------------*/
void TASK_10ms()
{

    #if TEST_SESSION

    signalADC_TESTER.channel3_READ_ADC = l_bsw_adc_readADC(signal3.channelADC);
    signalADC_TESTER.channel4_READ_ADC = l_bsw_adc_readADC(signal4.channelADC);
    signalADC_TESTER.channel3_GET_ADC = g_bsw_adc_getADCresults(signal3.channelADC,&signal3.pDataADC);
    signalADC_TESTER.channel4_GET_ADC = g_bsw_adc_getADCresults(signal4.channelADC,&signal4.pDataADC);
    task_10ms_counter++;
    task_TESTER();

    #else

    l_bsw_adc_readADC(signal3.channelADC);
    l_bsw_adc_readADC(signal4.channelADC);
    l_bsw_adc_readADC(signal7.channelADC);
    g_bsw_adc_getADCresults(signal3.channelADC,&signal3.pDataADC);
    g_bsw_adc_getADCresults(signal4.channelADC,&signal4.pDataADC);
    g_bsw_adc_getADCresults(signal7.channelADC,&signal7.pDataADC);
    #endif /* TEST_SESSION */

}

/*-------------------------------------------------------------------------------------------------
Function: TASK_1ms



Description: The function increments the task_1ms_counter counter




Parameters In:
    None


Parameters Out:
     None



Return Value:
     None
-------------------------------------------------------------------------------------------------*/
void TASK_1ms()
{
    #if TEST_SESSION
    task_1ms_counter++;
    /*if(task_1ms_counter == 1){*/

     task_TESTER();

    /*}*/
    #endif /* TEST_SESSION */
}

/*-------------------------------------------------------------------------------------------------
Function: RTE_call()



Description:




Parameters In:



Parameters Out:
     None



Return Value:
     None
-------------------------------------------------------------------------------------------------*/

void RTE_call(KL_tested_t *KL_is_tested)
{
    startTask_100ms = clock();
    startTask_10ms = clock();
    startTask_1ms = clock();

    uint32 x = 1;
    command_flag = 0;

    while(command_flag == 0)
    {

        if (x % 7 == 0)
        {
            command_flag = 1;
        }
        
        
        time_till_call = clock();

        if((time_till_call - startTask_1ms) >= CONDITION_FOR_TASK_1MS)
        {
            TASK_1ms(&signal1);
            startTask_1ms = clock();
            x++;
        }

        if((time_till_call - startTask_10ms) >= CONDITION_FOR_TASK_10MS)
        {
            TASK_10ms(&signal1);
            startTask_10ms = clock();
            x++;
        }

        if((time_till_call - startTask_100ms) >= CONDITION_FOR_TASK_100MS)
        {
            TASK_100ms(&signal1);
            startTask_100ms = clock();
            printf("\n");
            x++;
        }

    }

    /* assuming everything worked fine, we confirm testing successful for kl30*/
    *KL_is_tested = eIsTestedKL30;

    command_flag = 0;

}
