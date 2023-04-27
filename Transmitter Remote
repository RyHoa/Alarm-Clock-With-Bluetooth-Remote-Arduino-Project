//This code is for the Bluetooth remote. This code allows the remote to act as a transmitter to a receiver. They do this through bluetooth. 
//The code waits for a rising edge of a button press, once that occurs, an ISR is triggered and the method detect is called.
//The detect method will send a 'S' char to the receiver. 
//Code for receiver is explained in the other file


#include <SoftwareSerial.h> //imported the library
SoftwareSerial mySerial(4,5);  // RX of the arduino and TX of the arduino. These go to the RX and TX of the bluetooth. 
int interruptPin = 2; //set the interrupt pin


void setup() 
{
  pinMode(interruptPin, INPUT); //set interruptPin to input
  mySerial.begin(9600);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(interruptPin), detect, RISING); //interrupt command to check interruptPin to call method detect on the rising edge of the button
}

void loop() 
{  

}
void detect()
{
  mySerial.print('S'); //starting bit for the reciever to read
}