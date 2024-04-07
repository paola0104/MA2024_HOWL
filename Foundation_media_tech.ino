// when you click the switch it starts a 3 second timer, when it ends
// it moves the servo 

#include <Servo.h>
const int switchPin = 8; // change this 
Servo myservo; 
unsigned long timerVal;
unsigned long currentTime;
long timerLength = 3000;  // change this 

bool timer = false; 
int switchVal = 0;
int prevSwitchVal = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);
  myservo.attach(10);
  myservo.write(0);
}

void loop() {
  currentTime = millis();
  // put your main code here, to run repeatedly:
  switchVal = digitalRead(switchPin);
  if (switchVal != prevSwitchVal){
    if (switchVal == HIGH){
      timerVal = currentTime;
      timer = true;
    }
  }
  if (timer == true){
    if (currentTime - timerVal >= timerLength){
      myservo.write(180);
    }
  }
}
