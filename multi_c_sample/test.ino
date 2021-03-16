/* 
  Blink 
  Turns on an LED on for one second, then off for one second, repeatedly. 
  
  This example code is in the public domain.
*/

#include "packet.h" // including a custom written c/c++ library
#include "Mouse.h" // including a standard Arduino library
 
// Pin 13 has an LED connected on most Arduino boards. 
// give it a name: 
int led = 13;

// the setup routine runs once when you press reset: 
void setup() { 
  // initialize the digital pin as an output. 
  pinMode(led, OUTPUT);
  EtherType e = EtherType(); // instantiate an object from custom c/c++ library
} 

// the loop routine runs over and over again forever: 
void loop() { 
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level) 
  delay(1000);               // wait for a second 
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW 
  delay(1000);               // wait for a second 
} 
