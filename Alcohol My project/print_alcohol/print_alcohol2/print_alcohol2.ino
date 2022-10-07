#include "Microchip_Thermal.h"
#include "SoftwareSerial.h"
#include <LiquidCrystal.h>
#include <dht.h>
#define dht_dpin A0
#define TX_PIN 13 // Arduino transmit  YELLOW WIRE  labeled RX on printer
#define RX_PIN 12  // Arduino receive   GREEN WIRE   labeled TX on printer

SoftwareSerial mySerial(RX_PIN, TX_PIN);  // Declare SoftwareSerial obj first
Microchip_Thermal printer(&mySerial);
int sensorPin = A4;

LiquidCrystal lcd(3, 4, 5, 6, 7, 8);

dht DHT;
int buttonPin = 2;
int buttonState = 0;
int sensorValue = 0;
#define blu1 10
#define blu2 11
#define red1 0
#define red2 1
#define B_PIN A5

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);  // Initialize SoftwareSerial
  //Serial1.begin(19200); // Use this instead if using hardware serial
  printer.begin();

  lcd.begin(16, 2);

  lcd.print("<<Designed by ");
  lcd.setCursor (0, 1);
  lcd.print("     Tharindu>>");
  delay(8000);

  lcd.clear();

  pinMode(buttonPin, INPUT);
  pinMode( blu1, OUTPUT);
  pinMode( blu2, OUTPUT);
  pinMode( red1, OUTPUT);
  pinMode( red2, OUTPUT);
  pinMode( B_PIN, OUTPUT);
}

void loop() {
  DHT.read11(dht_dpin);
  sensorValue = analogRead(sensorPin);
  buttonState = digitalRead(buttonPin);
  delay(2);

  lcd.setCursor (0, 0);
  lcd.print("Pct=");
  lcd.setCursor (4, 0);
  lcd.print(sensorValue / 10 * 2, DEC); // prints the value read
  lcd.setCursor (6, 0);
  lcd.print("%    T=");  // prints the value read
  delay(3);

  lcd.setCursor (11, 1);
  lcd.print("H= ");
  lcd.setCursor (13, 1);
  lcd.print(DHT.humidity);
  lcd.setCursor (15, 1);
  lcd.print("%  .");
  lcd.setCursor (13, 0);
  lcd.print(DHT.temperature);
  lcd.setCursor (15, 0);
  lcd.print("C");
  delay(10);
  if (sensorValue < 100) {
    lcd.setCursor (0, 0);
    lcd.print("Pct=00");
    lcd.setCursor (0, 2);
    lcd.print("no liquor");

  }
  if (sensorValue > 109) {
    digitalWrite( blu1, HIGH);
    lcd.setCursor (0, 2);
    lcd.print("Value=Low ");
  }
  else {
    digitalWrite( blu1, LOW);
  }
  if (sensorValue > 150) {
    digitalWrite( blu2, HIGH);
    lcd.setCursor (0, 2);
    lcd.print("Value=Mid ");
  }
  else {
    digitalWrite( blu2, LOW);
  }
  if (sensorValue > 250) {
    digitalWrite( red1, HIGH);
    lcd.setCursor (0, 2);
    lcd.print("Value=High");
  }

  else {
    digitalWrite( red1, LOW);
  }


  if (buttonState == 1) {
    Serial.println("1");
    printer.justify('C');
    printer.setSize('M');
    printer.println("Alcohol Testing Unit");

    if  (sensorValue < 100) {
      printer.setSize('S');
      printer.println("No liquor");
      printer.print("Alcohol percentage=00 ");
      printer.println("%");
      printer.setSize('S');
      printer.justify('C');
      printer.println("....Made In Sri Lanka....");
      printer.setSize('S');
      printer.justify('C');
      printer.print(">>..Design By Tharindu..<<");
      printer.setSize('S');
      printer.justify('C');
      printer.println(">>  T.P 0773530119  <<");
    }



    if  (sensorValue > 250) {
      printer.setSize('S');
      printer.println("Alcohol Value=High");
      printer.print("Alcohol percentage= ");
      printer.print(sensorValue / 10 * 2);
      printer.println("%");
      printer.setSize('S');
      printer.justify('C');
      printer.println("....Made In Sri Lanka....");
      printer.setSize('S');
      printer.justify('C');
      printer.println(">>..Design By Tharindu..<<");
      printer.setSize('S');
      printer.justify('C');
      printer.println(">>  T.P 0773530119  <<");
    }

    else if  (sensorValue > 150) {
      printer.setSize('S');
      printer.println("Alcohol Value=Mid");
      printer.print("Alcohol percentage= ");
      printer.print(sensorValue / 10 * 2);
      printer.println("%");
      printer.setSize('S');
      printer.justify('C');
      printer.println("....Made In Sri Lanka....");
      printer.setSize('S');
      printer.justify('C');
      printer.println(">>..Design By Tharindu..<<");
      printer.setSize('S');
      printer.justify('C');
      printer.println(">>  T.P 0773530119  <<");
    }


    else if  (sensorValue > 102) {
      printer.setSize('S');
      printer.println("Alcohol Value=Low");
      printer.print("Alcohol percentage= ");
      printer.print(sensorValue / 10 * 2);
      printer.println("%");
      printer.setSize('S');
      printer.justify('C');
      printer.println("....Made In Sri Lanka....");
      printer.setSize('S');
      printer.justify('C');
      printer.println(">>..Design By Tharindu..<<");
      printer.setSize('S');
      printer.justify('C');
      printer.println(">>  T.P 0773530119  <<");
    }


    printer.feed(2);

    printer.sleep();      // Tell printer to sleep
    delay(4000);         // Sleep for 3 seconds
    printer.wake();       // MUST wake() before printing again, even if reset
    printer.setDefault(); // Restore printer to defaults
  }

  else {

    Serial.println("0");      // Tell printer to sleep
  }
  delay(100);
}


