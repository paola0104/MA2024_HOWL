
// the setup function runs once when you press reset or power the board
int BLINKLOOP = 0; //set int value


void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  if (BLINKLOOP <= 2) // checking variable amount to see how many times to loop
  {
  delay(300); 
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(300);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW  
  BLINKLOOP ++;
  }
  if (BLINKLOOP >2)
  {
  delay(300); 
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(900);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW  
  BLINKLOOP ++;
  }
  if (BLINKLOOP == 6) //end of desired loop
  {
  BLINKLOOP = 0; //restart loop by resetting variable
  }
  

}
       // wait for a second

