//Lights Project

#include <SoftwareSerial.h>

SoftwareSerial Bluetooth (11, 10);   //Tx & Rx

char numbers [25];
String state;
int light = 12;
int fan = 11;
int n = 0;


void setup() {
  Serial.begin(9600);
  pinMode(light, OUTPUT);
  pinMode(fan, OUTPUT);
  Bluetooth.flush();
  delay(500);
  Bluetooth.begin(9600);

}

void loop() {

  if (Bletooth.available() > 0){
    while (Bluetooth.available() > 0){
      numbers[n] = char(Bluetooth.read());
      Serial.print ("State:");
      Serial.println (numbers);
      n++
      
    }
    state = numbers
    Serial.print ("STATE:");
    Serial.println(state);

    while (n >= 0){
      numbers[n] = '\0';
      if (n == 0)
       break;
       
      n--;
    }
  }

  if (state == "1l"){
  digitalWrite (light, HIGH);
  
  }else if (state == 0l

  

}
