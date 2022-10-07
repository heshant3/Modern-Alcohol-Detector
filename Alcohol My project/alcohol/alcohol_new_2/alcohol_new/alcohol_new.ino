#define B_PIN A2
const int analogPin = 0;    // the pin that the potentiometer is attached to
const int ledCount = 10;    // the number of LEDs in the bar graph

int ledPins[] = {
  A1,13,12,11,10,9,8,7,6,5 // Here we have the number of LEDs to use in the BarGraph
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
 delay(10);
  int ledLevel = map(sensorReading, 110, 400, 0, ledCount);


  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
   
   if (thisLed < ledLevel) {
      digitalWrite(ledPins[thisLed], HIGH);
    }



    else {
      digitalWrite(ledPins[thisLed], LOW);  
    }
    
  

   if (sensorReading > 205) {
      digitalWrite( B_PIN, HIGH);
      }



    else {      
      digitalWrite( B_PIN, LOW);
    }
  }
}

