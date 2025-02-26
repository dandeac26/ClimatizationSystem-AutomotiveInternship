/**-------------------------------------------------------------------------------------------------
File:      nume file
Description: descirere file
-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/
#ifndef TEST_C
#define TEST_C
/*-------------------------------------------------------------------------------------------------
Includes
-------------------------------------------------------------------------------------------------*/

#include "test.h"


/*-------------------------------------------------------------------------------------------------
Variables
-------------------------------------------------------------------------------------------------*/
/* uint8 ignition_status;*/
uint8 totalTestsCount;
uint8 globalTestCount;
/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/

/*void state_helper(key_state s)
{

   uint16* pData = 0;

   switch(s)
   {
      case STATE_KL0_SLEEP:
         
         printf("ADC dissabled\n");
         printf("KL0_TESTED\n");
         g_ADC_off();

         break;
      case STATE_KL15_WAKEUP:
         
         g_ADC_init();
         printf("ADC is enabled\n");
         printf("KL15_TESTED\n");
                
         l_bsw_adc_readADC(ADC_CHANNEL1);
         g_bsw_adc_getADCresults(ADC_CHANNEL1,&pData);
         printf("Value from Channel: %d is %d\n",ADC_CHANNEL1,pData);

         break;
      case STATE_KL30_RUN:

         g_PWM_init();
         g_ADC_init();
         printf("ADC is enabled\n");
         printf("PWM is enabled\n");
         printf("KL30_TESTED\n");
                
         RTE_call();

         break;
      default:
         break;   

   }
}*/

/*-------------------------------------------------------------------------------------------------
Function: task_TESTER



Description:
This function is used to test if the system is working by printing all the values



Parameters In:
none



Parameters Out:
none



Return Value:
none
-------------------------------------------------------------------------------------------------*/


/*void task_TESTER()
{
    /* I write 1 in ignitionData.txt 
    ignition_status = 0; /* We make sure that our flag is 0 at the beginning
    bool b = l_bsw_adc_readIgnition(); /* we call this function to read the ignition value 
    
    if(ignition_status) /* check if the test value correspond to the ignition status 
    {
       printf("The test passed");
    }

    else
    {
       printf("The test failed");
    }

}
*/



void l_test_PASSED(test_case_e testNum, char* functionName)
{
   printf("---> %s: %sTEST %d.%d.%d PASSED!%s\n", functionName,COLOR_GREEN, globalTestCount, totalTestsCount, testNum, COLOR_RESET);
}

void l_test_FAILED(test_case_e testNum, char* functionName)
{
   printf("---> %s: %sTEST %d.%d.%d FAILED!%s\n", functionName, COLOR_RED, globalTestCount, totalTestsCount, testNum, COLOR_RESET);
}




void l_test_runReadTemperatureCabin(sensor_reading_t instance, test_case_e test)
{
   char* functionName = "l_cc_auto_readTemperatureCabin";
   if(true == l_cc_auto_readTemperatureCabin(test_itoc(instance.reading)))
   {
      /* error occured in readTemperatureCabin */
      if(instance.expectedResult == 0)
      {
         l_test_PASSED(test, functionName);
      }
      else
      {
         l_test_FAILED(test, functionName);
      }
   }
   else
   {
      /* success */
      sensors_t resultSensorData;
      
      bsw_adc_setADCresults(ADC_CHANNEL5, test_itoc(instance.reading));
      g_cc_auto_getSensorData(&resultSensorData);
      
      if(resultSensorData.temperature_cabin_data == instance.expectedResult)
      {
         l_test_PASSED(test, functionName);
      }
      else
      {
         l_test_FAILED(test, functionName);
      }
   }
}

void l_test_readTemperatureCabin()
{
   sensor_reading_t sensorInstance[MAX_TESTS];
   sensorInstance[1].reading = 3;
   sensorInstance[1].expectedResult = TEMP_16_C;
   sensorInstance[2].reading = 9;
   sensorInstance[2].expectedResult = TEMP_28_C;
   sensorInstance[3].reading = 0;
   sensorInstance[3].expectedResult = TEMP_0_C;
   sensorInstance[4].reading = 50;
   sensorInstance[4].expectedResult = 0;
   sensorInstance[5].reading = 1;
   sensorInstance[5].expectedResult = TEMP_8_C;

   for(int test = 1; test<=5; test++){
      l_test_runReadTemperatureCabin(sensorInstance[test], test);
   }
}

void l_test_runMainSensors(test_sensors_t instance, test_case_e test)
{
   char* functionName = "l_cc_auto_mainSensors";
   bsw_adc_setADCresults(ADC_CHANNEL5, test_itoc(instance.cabinTemp.reading));
   bsw_adc_setADCresults(ADC_CHANNEL6, test_itoc(instance.outsideTemp.reading));
   bsw_adc_setADCresults(ADC_CHANNEL7, test_itoc(instance.airQuality.reading));

   sensors_t sensData;

   g_cc_auto_getSensorData(&sensData); /* this calls mainSensors and returns the data structure generated */

   if(sensData.temperature_cabin_data == instance.cabinTemp.expectedResult &&
      sensData.temperature_outside_data == instance.outsideTemp.expectedResult &&
      sensData.check_air_quality == instance.airQuality.expectedResult)
   {
      l_test_PASSED(test, functionName);
   }
   else
   {
      l_test_FAILED(test, functionName);
   }
}

void l_test_mainSensors()
{
   test_sensors_t instance[MAX_TESTS];
   
   instance[1].cabinTemp.reading = 0;
   instance[1].cabinTemp.expectedResult = TEMP_0_C;
   instance[1].outsideTemp.reading = 0;
   instance[1].outsideTemp.expectedResult = TEMP_NEGATIVE_5_C;
   instance[1].airQuality.reading = 0;
   instance[1].airQuality.expectedResult = GOOD;

   instance[2].cabinTemp.reading = 4;
   instance[2].cabinTemp.expectedResult = TEMP_18_C;
   instance[2].outsideTemp.reading = 4;
   instance[2].outsideTemp.expectedResult = TEMP_15_C;
   instance[2].airQuality.reading = 4;
   instance[2].airQuality.expectedResult = BAD;

   instance[3].cabinTemp.reading = 9;
   instance[3].cabinTemp.expectedResult = TEMP_28_C;
   instance[3].outsideTemp.reading = 9;
   instance[3].outsideTemp.expectedResult = TEMP_40_C;
   instance[3].airQuality.reading = 5;
   instance[3].airQuality.expectedResult = HAZARDOUS;

   instance[4].cabinTemp.reading = 'c';
   instance[4].cabinTemp.expectedResult = TEMP_20_C;
   instance[4].outsideTemp.reading = 'b';
   instance[4].outsideTemp.expectedResult = TEMP_20_C;
   instance[4].airQuality.reading = 7;
   instance[4].airQuality.expectedResult = GOOD;

   instance[5].cabinTemp.reading = 7;
   instance[5].cabinTemp.expectedResult = TEMP_24_C;
   instance[5].outsideTemp.reading = 'b';
   instance[5].outsideTemp.expectedResult = TEMP_20_C;
   instance[5].airQuality.reading = 2;
   instance[5].airQuality.expectedResult = UNHEALTHY;

   for(int test = 1; test<=5; test++){
      l_test_runMainSensors(instance[test], test);
   }
}


void l_test_runStartAC(test_ac_t instance, test_case_e test){
   char* functionName = "g_cc_ac_startAC";
   g_cc_ac_set_AC_ON_OFF(instance.AC_ON_OFF);
   bool fanSpeedOk = false;
   if(5 == test)
   {
      g_cc_ac_coolingOff();
      g_cc_ac_startAC(instance.fanSpeed, instance.AUTO_ON_OFF);
      if(pwmData.input5 != instance.fanSpeed)
      {
         fanSpeedOk = true;
      }
   }
   else
   {
      g_cc_ac_startAC(instance.fanSpeed, instance.AUTO_ON_OFF);
   }
   
   if(instance.fanSpeed > 9 && pwmData.input5 == 9)
   {
      fanSpeedOk = true;
   }
      
   if(pwmData.input6 == instance.pwmCooler && (pwmData.input5 == instance.fanSpeed || true == fanSpeedOk))
   {
      l_test_PASSED(test, functionName);
   }
   else
   {
      l_test_FAILED(test, functionName);
   }

   
}

void l_test_startAC(){
   test_ac_t instance[MAX_TESTS];
   instance[1].fanSpeed = 3;
   instance[1].AUTO_ON_OFF = false;
   instance[1].pwmCooler = 1;
   instance[1].AC_ON_OFF = true;

   instance[2].fanSpeed = 0;
   instance[2].AUTO_ON_OFF = false;
   instance[2].pwmCooler = 1;
   instance[2].AC_ON_OFF = true;

   instance[3].fanSpeed = 9;
   instance[3].AUTO_ON_OFF = false;
   instance[3].pwmCooler = 1;
   instance[3].AC_ON_OFF = true;

   instance[4].fanSpeed = 'a';
   instance[4].AUTO_ON_OFF = false;
   instance[4].pwmCooler = 1;
   instance[4].AC_ON_OFF = true;

   instance[5].fanSpeed = 2;
   instance[5].AUTO_ON_OFF = true;
   instance[5].pwmCooler = 0;
   instance[5].AC_ON_OFF = false;

   for(int test = 1; test<=5; test++){
      l_test_runStartAC(instance[test], test);
   }
}

void g_test_runClimateTests()
{
   uint8 command;
   totalTestsCount = 1;
   globalTestCount = CLIMATE_TESTS_IDENTIFIER; 
   printf("Run Climate Control tests? (y/n)");
   command = getchar();
   
   if(command == 'n' || command == 'N')
   {
      getchar();
      /* don't perform tests */
   }
   else
   {
      printf("\n[Testing] Cabin Temperature Sensor:\n");
      l_test_readTemperatureCabin();
      totalTestsCount++;

      printf("[Testing] Main function from air sensors:\n");
      l_test_mainSensors();
      totalTestsCount++;

      printf("[Testing] Start AC function:\n");
      l_test_startAC();
      totalTestsCount++;

      printf("Press any key to continue...\n");
      getchar();
   } 
}

#endif /* TEST_C */
