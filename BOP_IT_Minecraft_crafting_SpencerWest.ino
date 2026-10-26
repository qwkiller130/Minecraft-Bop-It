const int leds[4] = {7, 8, 9, 10}; //Led pin aragnment
const int buttons[4] = {3, 2, 5, 4}; //Button pins, button 0 matches led 0 and so on VERY INPORATANT
const int success_led = 6; //Lights up when the user gets it right
const int start_button = A1; //Button that starts the thing 





int last_state_Buttons[4] = {HIGH, HIGH, HIGH, HIGH}; //Last state of each answer button
int last_state_start= HIGH; //Last state of the start button
bool hit[4] = {false, false, false, false}; //Which correct buttons have been pressed this round
bool crafting_on = false; //True after button is pressed 
int a; //1st random led chosen
int b; //2cd random led chosen
int score = 0; //Total successful rounds






void setup() 
{
  for (int i = 0; i < 4; i++) pinMode(leds[i], OUTPUT); //Sets all leds as outputs
  for (int i = 0; i < 4; i++) pinMode(buttons[i], INPUT_PULLUP); //Sets all answer buttons as inputs
  pinMode(start_button, INPUT_PULLUP); //Sets the start button as an input
  pinMode(success_led, OUTPUT); //Sets success led as an output
  randomSeed(analogRead(A0)); // Random number generator start, with pin A0 unconnected
}




void loop() 
{
  //Start button
  int start_state = digitalRead(start_button); //Current state of the start button

  if (start_state != last_state_start) //start button changed (pressed OR released)
  {
    delay(50); //button delay fter first click
    start_state = digitalRead(start_button); //read again after it is clicked

    if (start_state != last_state_start) //still changed, so it's real
    {
      last_state_start = start_state;

      if (start_state == LOW && !crafting_on) //Pressed while no round is running
      {
        new_round(); //Picks a new pair and lights them
      }
    }
  }

  //Answer buttons
  for (int i = 0; i < 4; i++) //Checks each button
  {
    int state = digitalRead(buttons[i]); //Current state of this button

    if (state != last_state_Buttons[i]) //button changed (pressed OR released)
    {
      delay(50); //button delay
      state = digitalRead(buttons[i]); //read again after button has been hin

      if (state != last_state_Buttons[i]) //still changed, so it's real
      {
        last_state_Buttons[i] = state;

        if (state == LOW && crafting_on) //Button was pressed during a round
        {
          if (i == a || i == b) //Pressed one of the two lit leds
          {
            hit[i] = true; //Remember it was pressed
          }
          else //Pressed a wrong button
          {
            hit[a] = false; //Progress resets
            hit[b] = false;
          }
        }
      }
    }
  }

  if (crafting_on && hit[a] && hit[b]) //Both correct buttons have been pressed
  {
    score++; //Adds 1 to the total score
    digitalWrite(success_led, HIGH); //Success led on
    delay(1000); //Holds it for 1 second
    digitalWrite(success_led, LOW); //Success led off
    for (int i = 0; i < 4; i++) digitalWrite(leds[i], LOW); //Turns all target leds off
    crafting_on = false; //Waits for the start button again
  }
}




void new_round() 
{
  for (int i = 0; i < 4; i++) 
  {
    digitalWrite(leds[i], LOW); //Turns all LEDS off first
    hit[i] = false; //Clears the pressed buttons
  }

  a = random(4); //1st random Led light chosen to turn on
  b = random(4); //2cd random Led light chosen to turn on
  while (b == a) b = random(4); //Picks again if b and a are the same light

  digitalWrite(leds[a], HIGH); // Turns on led a
  digitalWrite(leds[b], HIGH); // Turns on led b
  crafting_on = true; //Round is now running
}