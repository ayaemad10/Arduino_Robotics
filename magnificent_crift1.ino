int i=3;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  while(i<3){
    Serial.println("st smart");
    i++;
  }
}