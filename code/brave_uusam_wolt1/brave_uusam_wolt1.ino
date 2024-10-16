int number=0;
 void setup()
{
  Serial.begin(9600);
  if(number>0){ Serial.println("postive number");}
  else if(number<0){Serial.println("negative number");}
  else{Serial.println("zero");}
  
}

void loop()
{
  
}