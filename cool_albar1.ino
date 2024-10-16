int Led1=13;
int Led2=12;
int Led3=11;
int Led4=10;
int Led5=9;
int Button=7;
int S=0;
int C=0;
void setup()
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  PinMode(7,INPUT);
}

void loop()
{
  S=digitalRead(7);
  if (S==1){
    C++;}
  if (C==1){
  digitalWrite(13,HIGH);
  delay(7000);
    C++;}
  if (C==2){
  digitalWrite(13,HIGH);
  digitalWrite(12,HIGH);
  delay(5000); 
    C++;
  }
  if(C==3){
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    delay(3000);
    C++;
  }
  if(C==4){
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,HIGH);
    delay(2000);
    C++;
  }
  if(C==5){
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(9,HIGH);
    delay(1000);}
  else {
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
  }
    
}