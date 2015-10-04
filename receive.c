/*Code to get data from Remote Tire to central arduino*/

#define rfReceivePin 4
#define ledpin 13
void setup()
{

  pinMode(ledpin, OUTPUT); 
  Serial.begin(9600);
}

void loop()
{
  while(1)
  {
    data = analogRead(rfReceivePin);
    if(data>upperThreashold)
    {
      digitalWrite(ledPin, LOW);   //If a LOW signal is received, turn LED OFF
      Serial.println(data);
    }
    if(data<lowerThreashold)
    {
      digitalWrite(ledPin, HIGH);   //If a HIGH signal is received, turn LED ON
      Serial.println(data);
    }
    delay(1000);
  }
   
  
}
