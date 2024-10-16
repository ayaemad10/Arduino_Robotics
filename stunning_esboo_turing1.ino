int b=2;
int a=3; 
int f=4;
int g=5; 
int e=6; 
int d=7;
int c=8; 
void setup()
{
  Serial.begin(9600);
  pinMode(2,OUTPUT); 
  pinMode(3,OUTPUT); 
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);  
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT); 
  pinMode(8,OUTPUT); 
  }
void zero(){ 
digitalWrite(a,1); 
digitalWrite(b,1); 
digitalWrite(c,1); 
digitalWrite(d,1); 
digitalWrite(e,1); 
digitalWrite(f,1); 
digitalWrite(g,0);
}
void one(){ 
digitalWrite(a,0); 
digitalWrite(b,1); 
digitalWrite(c,1); 
digitalWrite(d,0); 
digitalWrite(e,0); 
digitalWrite(f,0); 
digitalWrite(g,0);
}
void two(){ 
digitalWrite(a,1); 
digitalWrite(b,1); 
digitalWrite(c,0); 
digitalWrite(d,1); 
digitalWrite(e,1); 
digitalWrite(f,0); 
digitalWrite(g,1);
}
void loop(){ 
zero(); 
delay(1000); 
one(); 
delay(1000); 
two();
delay(1000); 

  }
   
