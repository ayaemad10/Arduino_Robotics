
char a='x';
String b="St smart";
void setup()
{
 Serial.begin(9600);
 Serial.println(a);
 Serial.println('a');
 Serial.println("a");
 Serial.println('a',DEC);
 Serial.println('a',BIN);
 Serial.write(97);
  }

void loop()
{
  
}