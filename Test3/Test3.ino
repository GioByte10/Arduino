#include <ESP8266WiFi.h>
 
const char * ssid = "MySpectrumWiFie0-2G";
const char * PASS = "lightcountry610";
 
int ledPin = 2; // GPIO13
WiFiServer server(80);
 
void setup() {
  Serial.begin(9600);
 
}
 
void loop() {

   while(Serial.available() == 0);

   char x = Serial.read();
   String wor += x;

   Serial.println(wor);
 
}
 
