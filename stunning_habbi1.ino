int Led1=13;
int Led2=12;
int Led3=11;
int Button=7;
int S=0;
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(7,INPUT);
}

void loop()
{
  S=digitalRead(7);
  if (S==1)
  {
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000); 
  digitalWrite(12,HIGH);
  delay(1000);
  digitalWrite(12, LOW);
  delay(1000); 
  digitalWrite(11,HIGH);
  delay(1000);
  digitalWrite(11, LOW);
  delay(1000); 
  }
  else 
  {
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    delay(1000);
  }
}