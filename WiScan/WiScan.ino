#include "ESP8266WiFi.h"
int wifi;

void setup() {
  
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(500);
  Serial.print(" ");
  Serial.println("Configuration ready");
  Serial.println("Looking for notworks");
  delay(1000);
  
  
}

void loop() {

  wifi = WiFi.scanNetworks();

  if (wifi <= 3){
    Serial.print("There are ");
    Serial.print(wifi);
    Serial.println("Networks");
    digitalWrite(2, HIGH);
    delay (500);
    digitalWrite(2, LOW);
    delay(500);
  }else{
    Serial.print("There are ");
    Serial.print(wifi);
    Serial.println("Networks");
    digitalWrite(2, LOW);
  }
  
  

}
