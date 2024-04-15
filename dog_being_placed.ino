#include <Servo.h>

const int switch_dog = 2; // the number of the cooper tape
const int switch_heart = 4; // the number of the cooper tape where the user puts the heart

const int switch_led = 7; // the number of the cooper tape where sophie is placed
const int blue_led = 13; // pin where the blue led is placed
//const int white_led = 14; // pin where the white led is placed

int push_led = 0;

Servo myservo;  // create servo object to control a servo
Servo fianlly;  // servo that moves the final challenge, placing the heart

void setup() {
  pinMode(switch_dog, OUTPUT); // dog placement
  pinMode(switch_heart, OUTPUT); // heart placement 

  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(90);   //starting angle (door closed)

  fianlly.attach(8); // where the servo is attached
  fianlly.write(180); // starting angle

  pinMode(blue_led, OUTPUT); // initialize the blue_led as the output
  pinMode(switch_led, INPUT); // initialize the switch_leg as the input
}

void loop() {
  push_led = digitalRead(switch_led);

  if (digitalRead(switch_dog) == HIGH) { //check if the dog has been placed and completed the copper tape circuit
    myservo.write(0); //open the door
  }
  if (digitalRead(switch_heart) == HIGH){
    fianlly.write(0); // turn the platform 180, keep it at that if the heart is removed
  } 

  if (push_led == HIGH){
    digitalWrite(blue_led, HIGH);
  } else{
    digitalWrite(blue_led, LOW);
  }
}