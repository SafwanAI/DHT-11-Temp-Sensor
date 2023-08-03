#include <DHT.h>
#define Type DHT11
#include <LiquidCrystal.h>
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12; 
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int sensePin=2;
DHT HT(sensePin,Type);
float humidity;
float tempC;
int setTime=500;
int dt = 2000;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
HT.begin();
delay(setTime);
lcd.begin(16,2);

}

void loop() {
  // put your main code here, to run repeatedly:
humidity=HT.readHumidity();
tempC=HT.readTemperature();

lcd.setCursor(0,0);
lcd.print("Temp: ");
lcd.print(tempC);
lcd.print(" C");
lcd.setCursor(0,1);
lcd.print("Humidity: ");
lcd.print(humidity);
lcd.print("%");
delay(500);
lcd.clear();

Serial.print("Humidity: ");
Serial.print(humidity); 
Serial.print("%");
Serial.print(" Temperature: ");
Serial.print(tempC);
Serial.println(" C ");

}
