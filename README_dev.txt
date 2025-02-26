!!DO NOT DELETE THE PHOTO BELOW OR EVERYTHING WILL IMPLODE!!

REQUIREMETNS! (versions are in case issues appear in compilation, but newer versions should be fine).

1.Chocolately:   choco 2.1.0
(all the following tools are installed through chocolately)
2.Compiler used: gcc (x86_64-posix-seh-rev2, Built by MinGW-W64 project) 12.2.0
3.Make tool:     GNU Make 4.4.1
		(Built for Windows32)


!COMPILATION:
	There is the makefile. you need to complile using make. There is a line containing a path to different
	files, and that path is customized to my previous configuration / laptop. The new developer working on this
	project needs to update the line in the makefile which specifies the full path e.g: C:/users/dan.deac/ to their own
	user, so modify it with your own user/ laptop path!!

The important file where everything is called is the state.c from `work/asw/state`. based on the chosen car state
the modules will become available. (there is also a main file which calls the state.c functions, but that does not
	require changing to edit things or add module - at least for my own module).
	!!! When adding a new module, make sure to add it in the corresponding function representing the Klemme state (KL15 e.g) from state.c file.

Each module implemented is present in `work/asw` -> Climate | Wipers | Lights

The input / output is handled in `work/bsw/io` -> ADC from sensor input 
					       -> PWM output ( fans, lights, wipers)
						^^ These represent pins on the uC which are connected to CAN

The `Data` folder holds the input files where we get buttons data and sensor data (simulating pins for adc)
and files with the output - channels from the pwm module(BSW_PWM_cnf.c) -> pwmDATA.txt (here are the values written)

