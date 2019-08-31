#include <ESP8266WiFi.h>

int lx;

const char * ssid = "ARRIS-BBB2";
const char * PASS = "F3A015C34864B2BE";
const int LED = 5;

WiFiServer server(80);

void setup() {

  pinMode(2, OUTPUT);
  delay(100);
  digitalWrite(2, LOW);
  Serial.begin(115200);

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
    val = 0;
  }else if (req.indexOf("/on") != -1){
    val = 1;
  }else{
    Serial.println("FAILED REQUEST");
    client.stop();
    return;
  }
  digitalWrite(2, !val);
  client.flush();

    
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n><body style='background: url(http://fungyung.com/data/out/89/62928653-programming-wallpapers.png)'><p align='right'><font face='calibri' size='2' color='#ffffff'>By Giovanni Bernal Ramirez</font></p>\n<center><font face='Comic Sans MS' color='teal' size='7'> Cube Inc </font></center></body>"; 
   client.print(s);
 while(true){
  lx = analogRead(A0);
  String x = "<font color='ffffff'>";
    
    x += lx;
    x += "\r\n";
    x += "</font>";
 
  
    delay(1);

    client.print(x);

  delay(1);
  }
  s += "</html>\n";

Serial.println("CLIENT DISCONNECTED");
}


 
  
