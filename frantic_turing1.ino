int p1;
int led1=3;
int led2=5;
int led3=6;
int i;
void setup()
{
Serial.begin(9600);
 pinMode(3,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(A1,INPUT);
void loop(){
p1=analogRead(A1);
  if (p1==HIGH){
  for (0<i<255;i++){
    analogWrite(3,p1);
  }
    for(0<i<255;i++)
    {
  analogWrite(5,p1);
    }
    for (0<i<255;i++)
    {
analogWrite(6,p1);
    }
  }
}