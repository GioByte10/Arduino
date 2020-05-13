#include <ESP8266WiFi.h>
#include <time.h>

const char* ssid = "ARRIS-BBB2";
const char* password = "F3A015C34864B2BE";

int ledPin = 2;

int timezone = 6 * 3600;
int dst = 0;

int hour, minute, second;
int elapsed;

void setup() {
  
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);

  Serial.begin(115200);
  Serial.println();
  Serial.print("Wifi connecting to ");
  Serial.println( ssid );

  WiFi.begin(ssid,password);

  Serial.println();
  
  Serial.print("Connecting");

  while( WiFi.status() != WL_CONNECTED ){
      delay(500);
      Serial.print(".");        
  }

  digitalWrite( ledPin , HIGH);
  Serial.println();

  Serial.println("Wifi Connected Success!");
  Serial.print("NodeMCU IP Address : ");
  Serial.println(WiFi.localIP() );

  configTime(timezone, dst, "pool.ntp.org","time.nist.gov");
  Serial.println("\nWaiting for Internet time");

  while(!time(nullptr)){
     Serial.print("*");
     delay(1000);
  }
  Serial.println("\nTime response....OK");   
}

void loop() {
  
  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);

  hour = p_tm->tm_hour;
  minute = p_tm->tm_min;
  second = p_tm->tm_sec;

  elapsed = hour * 3600 + minute * 60 + second;

  Serial.println(elapsed);
  
  delay(1000);

}