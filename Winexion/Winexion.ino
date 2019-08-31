#include <ESP8266WiFi.h>

const char * ssid = "ARRIS-BBB2";
const char * PASS = "F3A015C34864B2BE";
const char * host = "www.youtube.com";

void setup() {

  Serial.begin(115200);
  Serial.print("Connecting");
  WiFi.begin(ssid, PASS);
  

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println(" ");
  Serial.print("CONNECTED TO ");
  Serial.println(ssid);
  Serial.print("IP Address");
  Serial.println(WiFi.localIP());
 
}

void loop() {
  WiFiClient client;
  Serial.print("Connecting to ");
  Serial.println(host);

  if (client.connect(host, 80)){
    Serial.println("Connected");
    Serial.println("SENDING_REQUEST.GET");
    client.println(String (" GET / ") + "HTTP/1.1\r\n" + "Host:" + host + "\r\n" + "Conexion: Closed" + "\r\n");

    while (client.connected()){
      if (client.available()){
        String line = client.readStringUntil('\n'); Serial.println(line);
      }
    }
    client.stop();
    Serial.println("Disconnected");
  }else{
    Serial.println("Failed"); client.stop();
  }
delay(5000);
}
