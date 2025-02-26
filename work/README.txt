
The main file where everything is called is the state.c from `work/asw/state`. based on the chosen car state
the modules will become available.

Each module implemented is present in `work/asw` -> Climate | Wipers | Lights

The input / output is handled in `work/bsw/io` -> ADC from sensor input 
					       -> PWM output ( fans, lights, wipers)

The `Data` folder holds the input files where we get buttons data and sensor data (simulating pins for adc)
and files with the output from channels from the pwm module(BSW_PWM_cnf.c) -> pwmDATA.txt (here are the values written)

