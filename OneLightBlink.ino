void setup() {
  pinMode(7, INPUT_PULLUP);  

  pinMode(8, OUTPUT);        
  pinMode(9, OUTPUT);        
  pinMode(10, OUTPUT);       
}

void loop() {

  if (digitalRead(7) == LOW) {

    
    digitalWrite(8, HIGH);
    delay(500);
    digitalWrite(8, LOW);

    digitalWrite(9, HIGH);
    delay(500);
    digitalWrite(9, LOW);

    digitalWrite(10, HIGH);
    delay(500);
    digitalWrite(10, LOW);
  }

  else {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
  }
}
//Hi Its Quinten
