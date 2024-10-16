#define flame 3
#define buzzer 5
int Val = 0;
void setup()
{ Serial.begin(9600);
pinMode(flame , INPUT);
pinMode(buzzer,OUTPUT);
}
void loop()
{ Val = digitalRead(flame);
Serial.print("value of flame:");
Serial.println(Val);
if (Val == LOW) { digitalWrite(buzzer, HIGH); }
else {digitalWrite(buzzer, LOW);}
}
}
