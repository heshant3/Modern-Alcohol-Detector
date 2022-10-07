#include "Microchip_Thermal.h"
#include "SoftwareSerial.h"

#define TX_PIN 6
#define RX_PIN 5
SoftwareSerial mySerial(RX_PIN, TX_PIN);
Microchip_Thermal printer(&mySerial);

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int buttonPin = 1;
int Buzzer =  13;
int buttonState = 0;
int value = 0;
int sensorValue;

void setup() {

  mySerial.begin(9600);
  printer.begin();
  lcd.init();
  lcd.backlight();
  lcd.begin(16, 2);
  lcd.print("<<Design by ");
  lcd.setCursor (0, 1);
  lcd.print("     Tharindu>>");
  delay(100);
  lcd.clear();

  pinMode(buttonPin, INPUT);

  pinMode(Buzzer, OUTPUT);

}

void loop() {

  Serial.begin(9600);
  sensorValue = analogRead(A0);

  value = sensorValue / 10;
  delay(100);
  buttonState = digitalRead(buttonPin);

  lcd.setCursor (0, 0);
  lcd.print("Percentage =");

  Serial.println(sensorValue);

  if (value <= 9 ) {
    lcd.setCursor (13, 0);
    lcd.print("00");
    lcd.setCursor (15, 0);
    lcd.print("%");
    lcd.setCursor (3, 1);
    lcd.print("No Liquor           ");
    digitalWrite(Buzzer , LOW);

  }

  else if (value >= 10 & value < 20) {
    lcd.setCursor (13, 0);
    lcd.print(value);
    lcd.setCursor (15, 0);
    lcd.print("%");
    lcd.setCursor (1, 1);
    lcd.print("Value = Low      ");
    digitalWrite(Buzzer , LOW);

  }

  else if (value >= 20 & value < 50) {
    lcd.setCursor (13, 0);
    lcd.print(value);
    lcd.setCursor (15, 0);
    lcd.print("%");
    lcd.setCursor (1, 1);
    lcd.print("Value = Middle   ");
    digitalWrite(Buzzer , HIGH);

  }

  else if (value >= 50 & value < 1400) {
    lcd.setCursor (13, 0);
    lcd.print(value);
    lcd.setCursor (15, 0);
    lcd.print("%");
    lcd.setCursor (1, 1);
    lcd.print("Value = High     ");
    digitalWrite(Buzzer , HIGH);

  }

  else {
    digitalWrite(Buzzer , LOW);
  }

  if (buttonState == 0) {
    Serial.println("1");
    printer.justify('C');
    printer.setSize('M');
    printer.println("Alcohol Testing Unit");
    printer.println("");

    if  (value <= 9 ) {
      printer.setSize('S');
      printer.print("Alcohol percentage=00 ");
      printer.println("%");
      printer.println("No Liquor");

    }



    if  (value >= 10 & value < 20) {
      
      printer.setSize('S');
      printer.print("Alcohol percentage = ");
      printer.print(value);
      printer.println("%");
      printer.println("Alcohol Value = High");

    }

    else if  (value >= 20 & value < 50) {
      printer.setSize('S');

      printer.print("Alcohol percentage= ");
      printer.print(value);
      printer.println("%");
      printer.println("Alcohol Value = Middle");

    }


    else if  (value >= 50 & value < 1400) {
      printer.setSize('S');

      printer.print("Alcohol percentage= ");
      printer.print(value);
      printer.println("%");
      printer.println("Alcohol Value = HIGH");
    }
    
    printer.println("");
    printer.setSize('S');
    printer.justify('C');
    printer.println("....Made In Sri Lanka....");
    printer.setSize('S');
    printer.justify('C');
    printer.println(">>..Design By Tharindu..<<");
    printer.setSize('S');
    printer.justify('C');
    printer.println(">>  T.P 0773530119  <<");
    
    printer.feed(4);
    printer.sleep();
    delay(4000);
    printer.wake();
    printer.setDefault();
  }




}
