#include <SoftwareSerial.h>

SoftwareSerial Bluet (11, 10);

String coordinates;
int n = 0;

void setup() {

  Serial.begin(38400);
  Bluet.flush();
  delay(500);
  Bluet.begin(38400);
  
}

void loop() {

  if (Bluet.available() > 0){
    Serial.println("Receiving Bytes...");

    n = 0;
    while (Bluet.available() > 0){
        coordinates += char(Bluet.read());             
        n++;

    }

    Serial.println(coordinates);
    coordinates = "";    
  }
}
