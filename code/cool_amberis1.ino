
int grade=45;
void setup()
{
  Serial.begin(9600);
  if(grade>=50){if(grade>=90){Serial.println("grade:A");}
  else if(grade>=80){Serial.println("grade:B");}
  else
  {Serial.println("grade:C");}
    }               
  else
  {Serial.println("fail");}
}

void loop()
{
 
}