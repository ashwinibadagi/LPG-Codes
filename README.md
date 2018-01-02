The necessary component for designing of system are Arduino UNO, LPG gas sensor module, buzzer, LCD, power supply, exhaust fan, servo motor, connecting wires. The following are the different steps included in building a IoT based LPG leakage detection and control system:

•	Connect pin 2, 4, 5, 11, 12, 13 of arduino to D7, D5, D4, E, RS, D6 of LCD and VEE of LCD is connected to one end of register.

•	Sensor pin D0 connected to pin 7 of arduino

•	Pin Tx and Rx of GSM module is connected to pin 9 and 10 of arduino.

•	Relay IN4 is connected to pin 6 of arduino.

•	And one end of register connected to pin 8 of arduino and another end to base of transistor.

•	Transistor emitter end is connected to buzzer and collector to Vcc

•	Connect sensor, servo motor and relay Vcc pins to arduino Vcc and also connect anode of LCD, VDD to Vcc of arduino

•	Ground pin of arduino is connected to servo motor, sensor, relay and GSM Vcc pins.

•	Connect speaker , RW and K of LCD to ground of arduino.

connect LED one pin to register and another pin to 1pin of arduino

•	Exhaust fan red wire is connected to relay common pin C. The NC pin of relay is connected to arduino power supply pin and another power supply pin of arduino is connected to GSM module and to fan black wire.

•	And connect 12v adapter to arduino DC input. 

•	And Raspberry Pi-3 is connected to arduino to push data to cloud.

	
  The entire system will controlled by using arduino such as reading output of LPG sensor. It also sending the message to display, triggering buzzer, sending signal to exhaust fan and servo motor.
  This system is mainly used to detect the leakage of LPG by using MQ-6 gas sensor. When the leakage is occurred at that time resistance decreases and conductivity increases.
  Then arduino simultaneously work on peripheral such as main supply, servo motor, buzzer, LCD, Exhaust fan. When high pulse of gas sensor sends to arduino then that time exhaust fan get turn on, servo motor rotates to OFF knob, buzzer start beeping for alerting people and send alert message to user and also glow LED. 
  When in case no gas is leaked then sensor gives low output to the arduino and arduino send data to LCD to display the massage “No Gas Leakage”. Raspberry Pi-3 is used to upload data to ThingSpeak cloud  at which emergency condition occurred. The Arduino Integrated Development Environment is used to upload embedded c program and to control the working of all the devices.

