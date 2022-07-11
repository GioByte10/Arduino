#include <Servo.h>
#include <DS3231.h>

Servo servo;

DS3231  rtc(SDA, SCL);
Time t;

void setup() {
  
  rtc.begin();
  
  servo.attach(9);
  servo.write(90);
  
}

void loop() {

  t = rtc.getTime();

  if(t.hour >= 4 && t.min >= 20 ){
    delay(3000);
    servo.write(160);
  
    delay(700);
    servo.write(90);
    delay(1000);
    
    exit(0);
  }
}
