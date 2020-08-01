#include <Servo.h>

Servo takePic;

void setup() {
  
  takePic.attach(9);
  pinMode(8, INPUT);                     //Una punta del switch de limite va conectada a positivo, y la otra al PIN 8
  Serial.begin(9600);

}

void loop() {

  if(digitalRead(8)){
    takePic.write(90);
    delay(200);
  }

  takePic.write(150);

  Serial.println(digitalRead(8));

}
