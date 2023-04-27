# Alarm-Clock-With-Bluetooth-Remote-Arduino-Project

# About
##### The Alarm Clock with Bluetooth Remote Arduino Project is a digital clock with a Bluetooth remote.
##### One circuit consists of the active buzzer, Liquid Crystal Display (LCD), NPN transistor, DS3231 Real Time Clock (RTC), and a receiver Bluetooth module. 
##### The other circuit has the transmitter Bluetooth module, pushbutton, and debounce circuit. 
##### The clock utilizes a 24-hour time format. The current time is generated using the RTC and a code library found online. 
##### The clock also has a built-in alarm feature to replicate normal clocks today. Recurring alarms are also accounted for in this microcontroller project. 
##### An active buzzer is used along with the transistor to generate noise. The alarm is set in the code. 
##### Both the time and the alarm are displayed on different rows on the LCD screen for simplicity and are labeled. 
##### The potentiometer is used to control the brightness of the text on the LCD. This would allow the user to control the dimness of the time displayed on the clock. 
##### The alarm feature occurs when the alarm time, which is set in the code, is triggered when it matches the current time. 
##### Once that occurs, the bool type alarmFlag will be set to prevent the buzzer from turning off once the time passes, and the base of the transistor will turn on. 
##### This will power the active buzzer, allowing the buzzer to ring. 
##### It will only stop ringing until the user presses the button on the transmitter Bluetooth remote. 
##### Once the user presses the button on the remote, a signal is sent (in the code it is ‘S’).
##### Once the receiver reads that signal, then it turns off the power to the transistor while will turn off the buzzer. 
##### It will also turn alarmFlag to false. The transistor is acting a switch for the buzzer in this situation. 
##### On the remote, interrupt service routines (ISR) are used to detect edge changes in button presses. 
##### A debounce circuit was built for the button to prevent any button bouncing from occurring. 

# Part List:
(2) 2K 5% resistor	
(4) 1k 5% resistor	
(1) 10k 5% resistor	
(1) 220 Ohms 5% resistor	
(1) Pushbutton	
(1) 10 µF capacitor	
(2) BC352-239AU Bluetooth Module	
(1) TIP31 NPN Transistor	
(1) Active Buzzer	
(1) DS3231M Real-Time Clock	
(1) 10K Potentiometer	
(1) LCD1602 Module	
(2) Arduino UNO	
(2) USB 2.0 Printer Cable Type A/B	

# Picture of Circuit Diagram

![Alarm Clock Circuit Diagram](https://user-images.githubusercontent.com/129560634/234762866-65273b2f-6491-435d-a2e7-8eebdbbbb4d7.png)


![Bluetooth Transmitter Circuit Diagram (1)](https://user-images.githubusercontent.com/129560634/234779232-78c8b781-15bf-4402-819d-f0bf2efefe97.png)
