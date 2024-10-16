int P1;
int P1m;
void setup() {
 pinMode(A0,INPUT);
Serial.begin(9600);
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
}

void loop() {
  P1=analogRead(A0);
  Serial.println(P1m);
 P1m=map(P1,0,1023,0,255);
 analogWrite(3,P1m);
  analogWrite(5,P1m);
  analogWrite(6,P1m);

}
