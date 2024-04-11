#include <Servo.h>

Servo dogDoor;    // create servo object to control dog opened door
Servo heartDoor;  //create servo object to control heart trap door
Servo trapDoor;   //create servo object to control trap door pit
Servo finale;     //create servo object to control final scene flip image


int pos = 0;               // variable to store the servo position
bool dogPlaced = true;     //checking if copper tape dog circuit has been completed
bool starPlaced = true;    //checking if star has been moved and trapdoor should open
bool sophiePlaced = true;  //checking if Sophie has been placed down on trapdoor
bool heartPlaced = true;   //checking if Howl's heart has been returned
bool timerOver = true;     //check if timer has completed
bool timerLED = false;     //should timer LED be running

void setup() {
  dogDoor.attach(9);     // attaches the servo on pin 9 to the servo object
  heartDoor.attach(10);  //attaches the servo on pin 11 to the servo object
  trapDoor.attach(8);    //attached the servo on pin 6 to the servo object
  finale.attach(7);      //attaches the servo on pin 3 to the servo object

  dogDoor.write(0);    //resets the servo to the starting position (door closed)
  heartDoor.write(0);  //resets the servo to the starting position (door closed)
  trapDoor.write(0);   //resets the servo to the starting position (door closed)
  finale.write(0);     //resets the finale scene flip to the unflipped position

  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
}

void loop() {
  if (dogPlaced) {      //check if the dog has been placed and completed the copper tape circuit
    dogDoor.write(90);  //open the door
  } else {
    dogDoor.write(0);  //keep door closed or reset to closed position
  }

  if (starPlaced) {        //check if the star has been placed and completed the copper tape circuit
    heartDoor.write(180);  //open the trap door
  }

  if (sophiePlaced) { //check if Sophie is sitting on the trapdoor

    timerLED = true; //if Sophie has been placed on the door start running the timer
    if (timerOver) //checking if timerOver bool has been triggered (make a timer and attach here)
    {                       //if Sophie is on the trapdoor and the timer has completed;
      trapDoor.write(180);  //open trapDoor
    }
  }

  if (heartPlaced) { //if the heart has been returned to Howl
    finale.write(180); //flip the final scene
  }


}
