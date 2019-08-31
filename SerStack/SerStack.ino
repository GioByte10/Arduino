#include <Servo.h>

Servo stack;

void setup(){
  stack.attach(8);
  stack.write(125);
  delay(5000);
  stack.write(90);
  delay(200);
  stack.write(125);
  delay(750);

}

void loop(){
  stack.write(90);  
  delay(200);
  stack.write(125);
  delay(600);
}
