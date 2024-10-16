#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int x;
int y;
void setup()
{
lcd.init();
lcd.backlight();
lcd.print("MQ-2 worming"); 
delay(20000);
}
void loop()
{
x=digitalRead(11);
y=analogRead(A0);
lcd.ScroldisplayRIGHT();
lcd.setCursor(0,0);
if (x==1||y>=500)
{print("fire");}
else {icd.clear()
}
}
