// Works by using copper tape to trigger the servo to move once it is triggered. Maintains put in place after it is triggered.

#include <Servo.h>

const int switchPin = 2; // where the cooper tape is connected 
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, OUTPUT);
  myservo.attach(13); // might need to change
  myservo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(switchPin) == HIGH){
    myservo.write(180);
  } 
  // else{
  //   myservo.write(0);
  // }
}
