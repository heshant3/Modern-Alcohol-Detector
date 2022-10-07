#include <LiquidCrystal.h>
#include <dht.h>

#define dht_dpin A0 //no ; here. Set equal to channel sensor is on

#define blu1 10
#define blu2 11
#define red1 0
#define red2 1
#define B_PIN A5

int sensorValue;
LiquidCrystal lcd(3, 4, 5, 6, 7, 8);
dht DHT;

void setup() {
  

  Serial.begin(9600);
  lcd.begin(16, 2);
  
  lcd.print("<<Design by ");
  lcd.setCursor (0,1);
  lcd.print("     Tharindu>>");
  delay(80);
  
  lcd.clear();

  pinMode( blu1, OUTPUT);
  pinMode( blu2, OUTPUT);
  pinMode( red1, OUTPUT);
  pinMode( red2, OUTPUT);
  pinMode( B_PIN, OUTPUT);
  lcd.setCursor (0,1);
  lcd.print("No liquor |");
}

void loop() {
  DHT.read11(dht_dpin);
  sensorValue = analogRead(A4);       // read analog input pin 0
  lcd.setCursor (0,0);
  lcd.print("Pre=");
  lcd.setCursor (4,0);
  lcd.print(sensorValue/10, DEC);  // prints the value read
  lcd.setCursor (6,0);
  lcd.print("%   |T=");  // prints the value read
  delay(35); 

    lcd.setCursor (11,1);
    lcd.print("H= ");
    lcd.setCursor (13,1);
    lcd.print(DHT.humidity);
    lcd.setCursor (15,1);
    lcd.print("%  .");
    lcd.setCursor (13,0);
    lcd.print(DHT.temperature);
    lcd.setCursor (15,0); 
    lcd.print("C");
  
  

   if (sensorValue > 110) {
   digitalWrite( blu1, HIGH);
   lcd.setCursor (0,2);
   lcd.print("Value=low ");
   }
   
else {
    digitalWrite( blu1, LOW);
    digitalWrite( B_PIN, LOW);
    }
  
   if  (sensorValue > 150) {
   digitalWrite( blu2, HIGH);
   digitalWrite( B_PIN, HIGH);
   lcd.setCursor (0,2);
   lcd.print("Value=mid ");
   }

   else {
    digitalWrite( blu2, LOW);
    }

   if  (sensorValue > 230) {
   digitalWrite( red1, HIGH);
   lcd.setCursor (0,2);
   lcd.print("Value=high");
   }

   else {
   digitalWrite( red1, LOW);
    }

    if  (sensorValue > 260) {
    digitalWrite( red2, HIGH);
    lcd.setCursor (0,2);
    lcd.print("Value=high");
    }

    else {
    digitalWrite( red2, LOW);
    }
    }

