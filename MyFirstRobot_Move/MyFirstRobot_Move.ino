#include <Servo.h>

Servo robot;

int degToServo = 0;

void setup() {
   robot.attach(6); 
}

void loop() {

 degToServo = 90 / 1.2;

  robot.write(degToServo);


}
