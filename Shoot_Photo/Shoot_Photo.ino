#include <Servo.h>

Servo takePic;

void setup() {
  
  takePic.attach(9);
  pinMode(8, INPUT);                     //Una punta del switch de limite va conectada a positivo, y la otra al PIN 8

}

void loop() {

  if(digitalRead(8)){
    takePic.write(60);
    delay(200);
  }

  takePic.write(120);

}
