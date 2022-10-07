/*

@ Code for interfacing Alcohol Gas Sensor MQ-3 with Arduino
@ Code by Daniel Spillere Andrade and Daniel Amato Zabotti
@ daniel@danielandrade.net / danielzabotti@gmail.com
@     www.DanielAndrade.net

*/

#define B_PIN A1
const int analogPin = 0;    // the pin that the potentiometer is attached to
const int ledCount = 10;    // the number of LEDs in the bar graph

int ledPins[] = {
  5,13,12,11,10,9,8,7,6,4 // Here we have the number of LEDs to use in the BarGraph
  };   


void setup() {

  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT);
    pinMode( B_PIN, OUTPUT);
  }
}

void loop() {
  //This is the code to light up LED's
  int sensorReading = analogRead(analogPin);

  int ledLevel = map(sensorReading, 100, 600, 0, ledCount);


  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
   
   if (thisLed < ledLevel) {
      digitalWrite(ledPins[thisLed], HIGH);
    }



    else {
      digitalWrite(ledPins[thisLed], LOW);
      digitalWrite( B_PIN, LOW);
    }
  }
  {
  if ( 250< sensorReading) {
      digitalWrite( B_PIN, HIGH);
      delay(100);
      digitalWrite( B_PIN, LOW);
      delay(100);
    }

    else {
      //digitalWrite(ledPins[thisLed], LOW);
      digitalWrite( B_PIN, LOW);
    }}
}

