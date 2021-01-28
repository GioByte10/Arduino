#include <DHT.h>

#define led 2
#define sensor A0

DHT dht(sensor, DHT11);

int temp = 0;
int hum = 0;

void setup() {
  
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);

  dht.begin();

}

void loop() {

  hum = dht.readHumidity();
  temp = dht.readTemperature();

  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println(" C");
  
  Serial.print("Humedad: ");
  Serial.print(hum);
  Serial.println(" %");
  Serial.println();

  delay(1000);

  while(temp >= 25){

    Serial.println("Led encendido");
    digitalWrite(led, HIGH);
    temp = dht.readTemperature();
    delay(2000);
    
  }

  digitalWrite(led, LOW);
}
