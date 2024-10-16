const int red = 3;
String reading; // data type used to store a character 
void setup( )
{
pinMode(red, OUTPUT);
Serial.begin(9600); // Adjust speed of serial monitor 
}
void loop( ) {
if(Serial.available()>0) {
reading=Serial.readString();
if (reading=="turn on"){ digitalWrite(red,0);}
else if (reading=="turn off"){
digitalWrite(red,1); }
}}
