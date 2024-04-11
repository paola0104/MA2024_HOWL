#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 0;            // variable to store the servo position
bool dogPlaced = true;  //checking if copper tape dog circuit has been completed

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(0);   //resets the servo to the starting position (door closed)
}

void loop() {
  if (dogPlaced) { //check if the dog has been placed and completed the copper tape circuit
    myservo.write(90); //open the door
  } else {
    myservo.write(0); //keep door closed or reset to closed position
  }
}

