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
int Buzzer =  12;
int buttonState = 0;

int sensorValue;

void setup() {

  mySerial.begin(9600);
  printer.begin();

  lcd.begin(16, 2);
  lcd.print("<<Design by ");
  lcd.setCursor (0, 1);
  lcd.print("     Tharindu>>");
  delay(8000);
  lcd.clear();

  pinMode(buttonPin, INPUT);

  pinMode(Buzzer, OUTPUT);
  lcd.setCursor (0, 1);
  lcd.print("No liquor |");
}

void loop() {
  
  sensorValue = analogRead(A0);
  buttonState = digitalRead(buttonPin);

  lcd.setCursor (0, 0);
  lcd.print("pct=");
  lcd.setCursor (4, 0);
  lcd.print(sensorValue / 10 * 2, DEC); // prints the value read
  delay(100);
  lcd.setCursor (6, 0);
  lcd.print("%   |T=");  // prints the value read



  if (sensorValue < 110) {
    lcd.setCursor (0, 0);
    lcd.print("Pre=00");
    lcd.setCursor (0, 2);
    lcd.print("no liquor");

  }
  if (sensorValue > 110) {
    digitalWrite( blu1, HIGH);
    lcd.setCursor (0, 2);
    lcd.print("Value=low ");
  }

  else {
    digitalWrite( blu1, LOW);
  }


  if  (sensorValue > 150) {
    digitalWrite( blu2, HIGH);
    lcd.setCursor (0, 2);
    lcd.print("Value=mid ");
    printer.justify('C');
    printer.setSize('M');
    printer.println("Alcohol Testing Unit");

    printer.setSize('S');
    printer.println("Alcohol Value=Mid");
    printer.print("Alcohol percentage= ");
    printer.println(sensorValue / 10 * 2);

    printer.setSize('S');
    printer.justify('C');
    printer.println("....Made In Sri Lanka....");
    printer.setSize('S');
    printer.justify('C');
    printer.println(">>..Design By Tharindu..<<");
  }

  else {
    digitalWrite( blu2, LOW);
  }

  if  (sensorValue > 230) {
    digitalWrite( red1, HIGH);
    lcd.setCursor (0, 2);
    lcd.print("Value=high");
    printer.justify('C');
    printer.setSize('M');
    printer.println("Alcohol Testing Unit");

    printer.setSize('S');
    printer.println("Alcohol Value=High");
    printer.print("Alcohol percentage= ");
    printer.println(sensorValue / 10 * 2);

    printer.setSize('S');
    printer.justify('C');
    printer.println("....Made In Sri Lanka....");
    printer.setSize('S');
    printer.justify('C');
    printer.println(">>..Design By Tharindu..<<");
  }

  else {
    digitalWrite( red1, LOW);
  }

  if  (sensorValue > 260) {
    digitalWrite( red2, HIGH);
    lcd.setCursor (0, 2);
    lcd.print("Value=high");
    printer.justify('C');
    printer.setSize('M');
    printer.println("Alcohol Testing Unit");

    printer.setSize('S');
    printer.println("Alcohol Value=High");
    printer.print("Alcohol percentage= ");
    printer.println(sensorValue / 10 * 2);

    printer.setSize('S');
    printer.justify('C');
    printer.println("....Made In Sri Lanka....");
    printer.setSize('S');
    printer.justify('C');
    printer.println(">>..Design By Tharindu..<<");
  }

  else {
    digitalWrite( red2, LOW);
  }



}
