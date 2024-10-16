
void setup()
{
  Serial.begin(9600);
 } 
void loop()
{
  int month=13;
  switch(month){
    case 1: Serial.println("January"); break;
    case 2: Serial.println("February"); break;
    case 3: Serial.println("Mars"); break;
    case 4: Serial.println("April"); break;
    case 5: Serial.println("may"); break;
    case 6: Serial.println("June"); break;
    case 7: Serial.println("July"); break;
    case 8: Serial.println("August"); break;
    case 9: Serial.println("September"); break;
    case 10: Serial.println("October"); break;
    case 11: Serial.println("November"); break;
    case 12: Serial.println("December"); break;
    default :Serial.println("invaild month");
   } 
    
}