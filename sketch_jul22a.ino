 int lineTracker = 8; 
int led = 2; 
int x = 0; 
void setup() {
 Serial.begin(9600);
 pinMode(2,OUTPUT);
 pinMode(8,INPUT);
 }
void loop() {
 x=digitalRead(8)
digitalWrite(2,x); 
   
}
