int Led1=13;
int Led2=12;
int Led3=11;
int d=500;
void setup() {
  pinMode(Led1,OUTPUT);
  pinMode(Led2,OUTPUT);
  pinMode(Led3,OUTPUT);
  Serial.begin(9600);
  pinMode(7,INPUT);

}

void loop() {
int s=digitalRead(7);
Serial.println(s);
if(s==1){
  digitalWrite(Led1,HIGH);
 digitalWrite(Led2,HIGH);
  digitalWrite(Led3,HIGH);
  delay(d);
   }
 else{ digitalWrite(Led1,LOW);
  digitalWrite(Led2,LOW);
 digitalWrite(Led3,LOW);
 delay(d);}
  

}
