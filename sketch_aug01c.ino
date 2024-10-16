#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int x;
int y;
void setup()
{ lcd.init(); 
lcd.backlight();
pinMode(8,INPUT);
pinMode(11,OUTPUT);
}
void loop()
{ 
  x=digitalRead(11);
y=analogRead(A0);
lcd.setCursor(0,0);
if (x==1||y>=500)
{lcd.print("fire");
digitalWrite(11,1);}
else {
 lcd.clear();
lcd.setCursor(0,0);
lcd.print("NO Fire Detected");
digitalWrite(11,0);
}
}
