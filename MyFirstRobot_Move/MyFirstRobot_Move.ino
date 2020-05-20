#include <Servo.h>

Servo robot;

void setup() {
   robot.attach(9); 
}

void loop() {

  robot.write(180);


}
