#include <ESP8266WiFi.h>

const char * ssid = "MySpectrumWiFie0-2G";
const char * PASS = "lightcountry610";
const int LED = 5;

WiFiServer server(80);

void setup() {

  pinMode(2, OUTPUT);
  delay(100);
  digitalWrite(2, LOW);
  Serial.begin(9600);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  Serial.println();

  Serial.printf("Connecting to %s\n", ssid);
  WiFi.begin (ssid, PASS);
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay (400);
  }
  IPAddress IP = WiFi.localIP();
  
  Serial.println();
  Serial.println("CONNECTED");
  Serial.println("IP Address:");
  IPAddress sensor_ip = WiFi.localIP();
  server.begin();
  Serial.println("Server activated");
  Serial.print("WIFI IP: ");
  Serial.println(WiFi.localIP());
  
  for(int i = 0; i < 3; i++){
  digitalWrite(2,LOW);
  delay(200);
  digitalWrite(2, HIGH);
  delay(200);
  }
  
}

void loop() {

  WiFiClient client = server.available();

  if (!client){
    return;
  }

  Serial.println("CLIENT CONNECTED");

  while (!client.available()){
    delay(1);
  }

  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();


  int val;
  if (req.indexOf("/off") != -1){
    digitalWrite(2, HIGH);
  }else if (req.indexOf("/on") != -1){
    digitalWrite(2, LOW);
  }
  
  client.flush();

  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n><body style='background: url(http://fungyung.com/data/out/89/62928653-programming-wallpapers.png)'><p align='right'><font face='calibri' size='2' color='#000000'>By Giovanni Bernal Ramirez</font></p>\n<center><font face='Comic Sans MS' color='teal' size='7'> Cube Inc </font></center></body>";
  s += "</html>\n";

  client.print(s);
  delay(1);
  Serial.println("CLIENT DISCONNECTED");
}
