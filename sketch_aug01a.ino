#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
lcd.init(); 
lcd.backlight();
lcd.print("Aya&Hoda");
lcd.setCursor(7,1);
lcd.print("2023");
}
void loop() {
for(int i=0;i<15;i++){
lcd.scrollDisplayRight();
delay(200); }
for(int i=0;i<15;i++){
lcd.scrollDisplayLeft();
delay(200); }
}
