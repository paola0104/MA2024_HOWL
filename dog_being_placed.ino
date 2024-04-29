#include <Servo.h>

const int switch_dog = 2; // the number of the cooper tape
const int switch_heart = 4; // the number of the cooper tape where the user puts the heart

//const int switch_led = 10; // the number of the cooper tape where sophie is placed
//const int blue_led = 6; // pin where the blue led is placed

const int switch_trap_heart = 5;

const int switch_trap_door = 12; // where sophie will be 

//const int white_led = 14; // pin where the white led is placed

//int push_led = 0;

Servo myservo;  // create servo object to control a servo
Servo fianlly;  // servo that moves the final challenge, placing the heart
Servo bush; // servo that reveals the heart 
Servo trap_door; 

void setup() {
  pinMode(switch_dog, OUTPUT); // dog placement
  pinMode(switch_heart, OUTPUT); // heart placement 
  pinMode(switch_trap_heart, OUTPUT); // star placement 
  pinMode(switch_trap_door, OUTPUT); // Sophie placemenet 

  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(90);   //starting angle (door closed)

  fianlly.attach(8); // where the servo is attached
  fianlly.write(180); // starting angle

  bush.attach(11);
  bush.write(0);

  trap_door.attach(6);
  trap_door.write(20);
  

  //pinMode(blue_led, OUTPUT); // initialize the blue_led as the output
  //pinMode(switch_led, INPUT); // initialize the switch_leg as the input

}

void loop() {
  // push_led = digitalRead(switch_led);
  bool heart = false; 

  if (digitalRead(switch_dog) == HIGH) { //check if the dog has been placed and completed the copper tape circuit
    myservo.write(0); //open the door
  }
  if (digitalRead(switch_heart) == HIGH){
    fianlly.write(0); // turn the platform 180, keep it at that if the heart is removed
  } 
//
  if (digitalRead(switch_trap_heart) == HIGH){
    bush.write(90);
    trap_door.write(90);
    //bool heart = true;
  } 
  // else{
  //   bush.write(0);
  // }

  // if (digitalRead(switch_trap_door) == HIGH && (heart) == true) {
  //   trap_door.write(90);
  // }

  // if (digitalRead(switch_led) == HIGH){
  //   digitalWrite(blue_led, HIGH);
  // } else{
  //   digitalWrite(blue_led, LOW);
  // }

}
