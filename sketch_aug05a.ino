#define DHTPIN 3
#define DHTTYPE DHT11
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);
void setup() {
pinMode(11,OUTPUT);
lcd.init();
lcd.backlight();
dht.begin();
}
void loop() {
delay(2000);
float h = dht.readHumidity();
float t = dht.readTemperature();
lcd.setCursor(0,0);
lcd.print("Temp=");
lcd.setCursor(5,0);
lcd.print(t);
lcd.setCursor(0,1);
lcd.print("Humidity=");
lcd.setCursor(9,1);
lcd.print(h);
if(t>=30){
  digitalWrite(11,1);
}else{
  digitalWrite(11,0);
}
}
