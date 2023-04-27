//This code works as follows: 
//It represents an alarm clock with receive bluetooth capabilities. 
//It displays the time and alarm clock on the LCD screen. 
//It uses a 24 hour time format.  The alarm is set in the code. 
//When the alarm matches the current time, a tone function will
//be given the base of the transistor turns on which will power 
//the buzzer. To stop the buzzer from running, the code will look 
//for a certain signal from the transmitter. Once it receives that signal
//it will turn off the buzzer.  


#include <LiquidCrystal.h> //imported the LCD library
#include <Wire.h> //imported the WIRE library
#include <SoftwareSerial.h> //imported the SOFTWARESERIAL library
#include <TimeLib.h> //imported the TIMELIB library: https://github.com/PaulStoffregen/Time
#include <DS3231.h> //imported the DS3231 library: https://github.com/jarzebski/Arduino-DS3231

//LCD setup
//Used this website to learn more about LCD screens and the idea on how to code the LCD:
//https://docs.arduino.cc/learn/electronics/lcd-displays
const int rs = 11, en = 10, d4 = 9, d5 = 8, d6 = 7, d7 = 6; //set the values of the arduino pins to the LCD pins
LiquidCrystal LCD(rs, en, d4, d5, d6, d7); //created an instance of the LCD

//RTC setup
int hrs = -1; //set int hours to be equal to -1
int mins = -1; //set int mins to be equal to -1
DS3231 ct; //created an instance of the DS3231 time object
RTCDateTime t; //variable to store time 

//alarm setup
int alarmHours = 16, alarmMins = 21; //time that you want for the alarm
bool alarmFlag = false; //created bool false for alarmFlag
int buzzerPin = 3; //buzzerPin equals 3, pin used to indirectly power the buzzer
bool doneFlag = true; //flag called doneFlag in order to allow for reoccuring alarm

//bluetooth for Receiver
//consulted with Wesley Cooke on how to use bluetooth
SoftwareSerial myReceiver(4,5); //rx, tx of the arduino for Bluetooth

void setup() 
{  
  LCD.begin(16,2); //set the 16 columns and 2 rows in the LCD 
  ct.begin(); 
  ct.setDateTime(__DATE__,__TIME__); //set the current date and time into the time object
  Serial.begin(9600); //begin comms  
  myReceiver.begin(9600); //starts softwareserial for bluetooth pins  
  pinMode(buzzerPin, OUTPUT); //set buzzerPin to be output  
}

void loop() 
{
    t = ct.getDateTime(); //get the current date and time
    hrs = t.hour; //get the hour value from the current time
    mins = t.minute; //get the minute value from the current time
    
    LCD.setCursor(0,0); //set location of the text on the LCD    
    printTime(); //gets the current time

    LCD.setCursor(0,1); //set location of the text on the LCD
    printAlarm(); //gets the alarm

    //if condition to allow the same alarm to occur every
    //day it is for continuous alarms (same alarm from Monday to Sunday)
    //without this statement, the alarm will keep ringing until the times don't equal
    if(mins == alarmMins + 1)
    {
      doneFlag = true;
    }
    
    //if condition for ringing the alarm, checks if the alarmFlag is on (to counter if the time passes because we still need the alarm)
    //also checks if the current time is equal to the set time
    //doneFlag is there for repeated alarms since we would have no way to stop the alarm without changing the alarmHours or alarmMins
    //with doneFlag there is a way to
    if(alarmFlag || (doneFlag && (alarmHours == hrs && alarmMins == mins)))
    {
      alarmFlag = true; //sets the alarmFlag to true
      alarm(); //calls the alarm function
    }   

    delay(5); //delay of 5 ms to prevent LCD flickering issue
    LCD.clear(); //clears the LCD
}


void alarm()
{
  if(alarmFlag) //if alarmFlag is true, it should be since this is alarm code
  {
    beep(); //beep function for buzzer
    //uses the bluetooth to communicate    
    if(myReceiver.available() > 0) 
    {      
      char startingBit = myReceiver.read(); //reads the 'syncing' bit
      if(startingBit == 'S') //checks if the bit is 'S', when the button on the transceiver chip is pressed
      {
        alarmFlag = false; //sets the alarmFlag to false
        doneFlag = false;  //sets doneFlag to false      
      }
    }
  }
}

//method for speaker to make noise by powering the transistor
void beep()
{
  tone(buzzerPin, 500, 1000); //tone function on buzzerPin with freq of 500 hz and 1000 ms duration
}

//method to print current Time
void printTime()
{
  //print statements for when min past 10 
    if(mins >= 10)
    {
      LCD.print("Time "); //print statement
      LCD.print(hrs); //print time statement on the LCD 
      LCD.print(":"); //print statement
      LCD.print(mins); //print statement
    }
    //condition for when min is less than 10, for aesthetic purposes
    else
    {
      LCD.print("Time "); //print statement
      LCD.print(hrs); //print time statement on the LCD 
      LCD.print(":"); //print statement
      LCD.print(0); //print statement
      LCD.print(mins); //print statement
      
    }
}

//method to print Alarm
void printAlarm()
{
  if(alarmMins < 10)
  {
    LCD.print("Alarm ");
    LCD.print(alarmHours);
    LCD.print(":");
    LCD.print(0);
    LCD.print(alarmMins);
  }
  else
  {
    LCD.print("Alarm ");
    LCD.print(alarmHours);
    LCD.print(":");
    LCD.print(alarmMins);
  }
}
