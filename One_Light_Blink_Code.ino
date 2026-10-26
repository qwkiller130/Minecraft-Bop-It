void setup() 
{
  // defines output pin
  pinMode(8,OUTPUT);
  pinMode(2, INPUT_PULLUP);
}

void loop() 
{
  if(digitalRead(2)== LOW)
  {
  // turns in pin and off
  digitalWrite(8, HIGH);
  delay(1000);
  digitalWrite(8,LOW);
  delay(1000);
  }
  else
  {
  digitalWrite(8,LOW);
  }
}
