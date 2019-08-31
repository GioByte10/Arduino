#include <ESP8266WiFi.h>

 IPAddress local_IP ( 192 , 168 , 2 , 22 );
 IPAddress gateway ( 192, 168 , 2 , 9 );
 IPAddress subnet ( 255 , 255 , 255 ,0 );

void setup() {
 WiFi.softAPConfig(local_IP, gateway, subnet);
 
 WiFi.softAP("Cube_Inc", "ESP8266100") ? "Ready" : "Failed!" ;


}

void loop() {
 

}
