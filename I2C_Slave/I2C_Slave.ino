
#include <Wire.h>

// Define string with response to Master
String answer = "";
int i = 0, j = 0, value;

void setup() {

  Wire.begin(9);
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
   
  //Serial.begin(9600);
  //Serial.println("I2C Slave Demonstration");

  
  
}

void receiveEvent() {

 i = 0;

  while (0 < Wire.available()) {
    byte x = Wire.read();
    answer += (char) x;
  }

  //Serial.println(answer);
}

void requestEvent() {

  byte response[3];

  value = analogRead(A0) * 0.3515;

  for(j = 1; j <= 3; j++){

     if((int)(value / pow(10, j)) == 0)
       break;
    
  }

  for(j = 3 - j; j > 0; j--){

    answer += '0';
    
  }

  answer += String(value);
  
  for (i = 0; i < 5; i++) {
    response[i] = (byte)answer.charAt(i);
  }
  
  Wire.write(response, sizeof(response));

  //Serial.println(answer);

  answer = "";
  
}

void loop() {

  //delay(50);
  requestEvent();
  
}
