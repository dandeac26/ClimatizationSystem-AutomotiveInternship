#COMPILER
CC = gcc

#COMPILER FLAGS
CFLAGS = -c -Wall
OBJFLAGS = -o

INCLUDEFLAG = -I

#FILE PATHS
#MYSYSTEMCUPSA = C:\Users\bogdan.cupsa\repository_internship

MYSYSTEM = C:\Users\dan.deac\repos\AutomotiveProject_1

RTEC = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\bsw\rtos\rte.c
RTEH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\bsw\rtos\rte.h
RTEPATH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\bsw\rtos

MEMEC = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\bsw\mem\meme.c
MEMEH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\bsw\mem\meme.h
MEMEPATH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\bsw\mem

PWMC = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\bsw\io\pwm\BSW_PWM_cnf.c
PWMH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\bsw\io\pwm\BSW_PWM_cnf.h
PWMPATH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\bsw\io\pwm

IGNITIONC = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\bsw\io\ignition\ignition.c
IGNITIONH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\bsw\io\ignition\ignition.h
IGNITIONPATH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\bsw\io\ignition

ADCC = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\bsw\io\adc\BSW_ADC_cnf.c
ADCH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\bsw\io\adc\BSW_ADC_cnf.h
ADCPATH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\bsw\io\adc

#ADCC = BSW_ADC_cnf.c
#ADCH = BSW_ADC_cnf.h
#ADCPATH = C:\Users\roxana.petran\Desktop\Main\ProiectInternship2-main

COMMONC = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\common\common.c

COMMONH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\common\common.h
COMMONPATH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\common

TESTC = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\test\test.c
TESTH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\test\test.h
TESTPATH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\test

STATEC = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\state\state.c
STATEH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\state\state.h
STATEPATH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\state

WIPERSC = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\wipers\wipers.c
WIPERSH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\wipers\wipers.h
WIPERSPATH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\wipers

SPEEDC = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\wipers\speed.c
SPEEDH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\wipers\speed.h
SPEEDPATH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\wipers

LIGHTSC = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\lights_control\lights.c
LIGHTSH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\lights_control\lights.h
LIGHTSPATH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\lights_control

INTENSITYC = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\lights_control\intensity.c
INTENSITYH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\lights_control\intensity.h
INTENSITYPATH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\lights_control

MILEAGEC = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\bsw\mileage\mileage.c
MILEAGEH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\bsw\mileage\mileage.h
MILEAGEPATH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\bsw\mileage

AIRC = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\climate_control\AUTO\air_sensors.c
AIRH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\climate_control\AUTO\air_sensors.h
AIRPATH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\climate_control\AUTO

CLIMATEBTNC = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\bsw\io\buttons\climate_btn.c
CLIMATEBTNH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\bsw\io\buttons\climate_btn.h
CLIMATEBTNPATH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\bsw\io\buttons

CLIMATECTLC = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\climate_control\climate_state.c
CLIMATECTLH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\climate_control\climate_state.h
CLIMATECTLPATH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\climate_control

ACC = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\climate_control\AC\air_conditioning.c
ACH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\climate_control\AC\air_conditioning.h
ACPATH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\climate_control\AC

AUTOC = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\climate_control\AUTO\climate_auto.c
AUTOH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\climate_control\AUTO\climate_auto.h
AUTOPATH = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main\work\asw\climate_control\AUTO



MAINDIR = $(MYSYSTEM)\AutomotiveProjectSim\ProiectInternship2-main

INCLUDECOMMON = $(INCLUDEFLAG) $(COMMONPATH)
INCLUDEPWM = $(INCLUDEFLAG) $(PWMPATH)
INCLUDEADC = $(INCLUDEFLAG) $(ADCPATH)
INCLUDEMEME = $(INCLUDEFLAG) $(MEMEPATH)
INCLUDEMILEAGE = $(INCLUDEFLAG) $(MILEAGEPATH)
INCLUDERTEH = $(INCLUDEFLAG) $(RTEPATH)
INCLUDEMAINH = $(INCLUDEFLAG) $(MAINDIR)
INCLUDEIGNITION = $(INCLUDEFLAG) $(IGNITIONPATH)
INCLUDETEST = $(INCLUDEFLAG) $(TESTPATH)
INCLUDESTATE = $(INCLUDEFLAG) $(STATEPATH)
INCLUDEWIPERS = $(INCLUDEFLAG) $(WIPERSPATH)
INCLUDESPEED = $(INCLUDEFLAG) $(SPEEDPATH)
INCLUDELIGHTS = $(INCLUDEFLAG) $(LIGHTSPATH)
INCLUDEINTENSITY = $(INCLUDEFLAG) $(INTENSITYPATH)
INCLUDEAIR = $(INCLUDEFLAG) $(AIRPATH)
INCLUDECLIMATEBTN = $(INCLUDEFLAG) $(CLIMATEBTNPATH)
INCLUDECLIMATECTL = $(INCLUDEFLAG) $(CLIMATECTLPATH)
INCLUDEAC = $(INCLUDEFLAG) $(ACPATH)
INCLUDEAUTO = $(INCLUDEFLAG) $(AUTOPATH)

INCLUDEALLH = $(INCLUDEMAINH) $(INCLUDERTEH) $(INCLUDEMEME) $(INCLUDECOMMON) $(INCLUDEPWM) $(INCLUDEADC) $(INCLUDEMILEAGE) $(INCLUDEIGNITION) $(INCLUDETEST) $(INCLUDESTATE) $(INCLUDEWIPERS) $(INCLUDESPEED) $(INCLUDELIGHTS) $(INCLUDEINTENSITY) $(INCLUDEAIR) $(INCLUDECLIMATEBTN) $(INCLUDECLIMATECTL) $(INCLUDEAC) $(INCLUDEAUTO)

all: myapp

myapp: main.o libmylib.a
	$(CC) -lm $(OBJFLAGS) myapp main.o -L. -lmylib

main.o: main.c rte.o ignition.o test.o state.o wipers.o speed.o lights.o intensity.o meme.o air_sensors.o climate_btn.o climate_state.o air_conditioning.o climate_auto.o
	$(CC) $(INCLUDEALLH) $(CFLAGS) -lm main.c -lrte.o -lignition.o climate_btn.o climate_state.o air_conditioning.o climate_auto.o

libmylib.a: BSW_ADC_cnf.o rte.o BSW_PWM_cnf.o meme.o common.o ignition.o mileage.o air_sensors.o climate_btn.o climate_state.o air_conditioning.o climate_auto.o
	ar rcs libmylib.a BSW_ADC_cnf.o rte.o BSW_PWM_cnf.o meme.o common.o ignition.o mileage.o test.o state.o wipers.o speed.o lights.o intensity.o air_sensors.o climate_btn.o climate_state.o air_conditioning.o climate_auto.o

rte.o: $(RTEC) meme.o BSW_PWM_cnf.o BSW_ADC_cnf.o mileage.o test.o state.o wipers.o speed.o lights.o intensity.o air_sensors.o climate_btn.o climate_state.o air_conditioning.o climate_auto.o
	$(CC) $(INCLUDEMEME) $(INCLUDECOMMON) $(INCLUDEPWM) $(INCLUDEADC) $(INCLUDEMILEAGE) $(CFLAGS) $(RTEC) -lmeme.o -lBSW_PWM_cnf.o -lBSW_ADC_cnf.o -lmileage.o

BSW_PWM_cnf.o: $(PWMC)
	$(CC) $(INCLUDECOMMON) $(CFLAGS) $(PWMC)

meme.o: $(MEMEC) common.o
	$(CC) $(INCLUDECOMMON) $(CFLAGS) $(MEMEC) common.o 

common.o: $(COMMONC) 
	$(CC)  $(CFLAGS) $(COMMONC) 

ignition.o: $(IGNITIONC)
	$(CC) $(INCLUDECOMMON) $(INCLUDEADC) $(CFLAGS) $(IGNITIONC) $(INCLUDEWIPERS) $(INCLUDEPWM) $(INCLUDESPEED) $(INCLUDEAIR) $(INCLUDECLIMATEBTN) $(INCLUDECLIMATECTL) $(INCLUDEAC)

BSW_ADC_cnf.o: $(ADCC)
	$(CC) $(INCLUDECOMMON) $(INCLUDEADC) $(CFLAGS) $(ADCC)

mileage.o: $(MILEAGEC)
	$(CC) $(INCLUDECOMMON) $(INCLUDEMEME) $(CFLAGS) $(MILEAGEC)

test.o: $(TESTC)
	$(CC) $(INCLUDECOMMON) $(INCLUDEADC) $(INCLUDETEST) $(CFLAGS) $(TESTC) $(INCLUDERTEH) $(INCLUDEIGNITION) $(INCLUDEMEME) $(INCLUDEPWM) $(INCLUDEMILEAGE) $(INCLUDEWIPERS) $(INCLUDESPEED) $(INCLUDEAIR) $(INCLUDECLIMATEBTN) $(INCLUDECLIMATECTL) $(INCLUDEAC) $(INCLUDEAUTO)

state.o: $(STATEC)
	$(CC) $(INCLUDECOMMON) $(INCLUDEADC) $(INCLUDETEST) $(CFLAGS) $(STATEC) $(INCLUDERTEH) $(INCLUDEIGNITION) $(INCLUDEMEME) $(INCLUDEPWM) $(INCLUDEMILEAGE) $(INCLUDEWIPERS) $(INCLUDESPEED) $(INCLUDELIGHTS) $(INCLUDEAIR) $(INCLUDECLIMATEBTN) $(INCLUDECLIMATECTL) $(INCLUDEAC) $(INCLUDEAUTO)

wipers.o: $(WIPERSC)
	$(CC) $(INCLUDECOMMON) $(INCLUDEADC) $(INCLUDETEST) $(CFLAGS) $(WIPERSC) $(INCLUDERTEH) $(INCLUDEIGNITION) $(INCLUDEMEME) $(INCLUDEPWM) $(INCLUDEMILEAGE) $(INCLUDESPEED) $(INCLUDESTATE)

speed.o: $(SPEEDC)
	$(CC) $(INCLUDECOMMON) $(INCLUDEADC) $(INCLUDETEST) $(CFLAGS) $(SPEEDC) $(INCLUDERTEH) $(INCLUDEIGNITION) $(INCLUDEMEME) $(INCLUDEPWM) $(INCLUDEMILEAGE) $(INCLUDEWIPERS) $(INCLUDESTATE)

lights.o: $(LIGHTSC)
	$(CC) $(INCLUDECOMMON) $(INCLUDEIGNITION) $(INCLUDEADC) $(INCLUDEINTENSITY) $(INCLUDERTEH) $(INCLUDESTATE) $(INCLUDEMEME) $(INCLUDEPWM) $(INCLUDEMILEAGE) $(INCLUDESTATE) $(CFLAGS) $(LIGHTSC)

intensity.o: $(INTENSITYC)
	$(CC) $(INCLUDECOMMON) $(INCLUDEIGNITION) $(INCLUDEADC) $(INCLUDESTATE) $(INCLUDERTEH) $(INCLUDEMEME) $(INCLUDEPWM) $(INCLUDEMILEAGE) $(INCLUDESTATE) $(CFLAGS) $(INTENSITYC)

air_sensors.o: $(AIRC)
	$(CC) $(INCLUDECOMMON) $(INCLUDEIGNITION) $(INCLUDEADC) $(INCLUDESTATE) $(INCLUDERTEH) $(INCLUDEMEME) $(INCLUDEPWM) $(INCLUDEMILEAGE) $(INCLUDESTATE) $(CFLAGS) $(AIRC) $(INCLUDECLIMATEBTN) $(CLIMATEBTNC) $(INCLUDEAUTO)

climate_btn.o: $(CLIMATEBTNC)
	$(CC) $(INCLUDECOMMON) $(INCLUDEADC) $(CFLAGS) $(CLIMATEBTNC) $(INCLUDEAIR) $(INCLUDESTATE) $(AIRC) $(CLIMATECTLC) $(PWMC) $(INCLUDEPWM) $(INCLUDECLIMATECTL) $(INCLUDEAC) $(INCLUDEAUTO)

climate_state.o: $(CLIMATECTLC)
	$(CC) $(INCLUDECOMMON) $(INCLUDEIGNITION) $(INCLUDEADC) $(INCLUDERTEH) $(INCLUDESTATE) $(INCLUDEMEME) $(INCLUDEPWM) $(CFLAGS) $(CLIMATECTLC) $(CLIMATEBTNC) $(INCLUDECLIMATEBTN) $(PWMC) $(INCLUDEPWM) $(INCLUDECLIMATECTL) $(INCLUDEAC) $(INCLUDEAUTO)

air_conditioning.o: $(ACC)
	$(CC) $(INCLUDECOMMON) $(INCLUDEIGNITION) $(INCLUDEADC) $(INCLUDERTEH) $(INCLUDESTATE) $(INCLUDEMEME) $(INCLUDEPWM) $(CFLAGS) $(ACC) $(CLIMATECTLC) $(CLIMATEBTNC) $(PWMC) $(INCLUDEPWM) $(INCLUDECLIMATECTL) $(INCLUDECLIMATEBTN) $(INCLUDEAC) $(INCLUDEAUTO)

climate_auto.o: $(AUTOC)
	$(CC) $(INCLUDECOMMON) $(INCLUDEIGNITION) $(INCLUDEADC) $(INCLUDERTEH) $(INCLUDESTATE) $(INCLUDEMEME) $(INCLUDEPWM) $(CFLAGS) $(ACC) $(AUTOC) $(CLIMATECTLC) $(CLIMATEBTNC) $(PWMC) $(INCLUDEPWM) $(INCLUDECLIMATECTL) $(INCLUDECLIMATEBTN) $(INCLUDEAC) $(INCLUDEAUTO)

cleanall:
	del *.o *.exe *.a