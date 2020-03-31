#define pin 8
#define baud 1000

void setup() {

  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);

  delay(1000);
  delay(5000);
  
  //Serial.begin(baud); 
  
}
void loop() {

  digitalWrite(8, LOW);
  delayMicroseconds(1000000 / baud);
  
  digitalWrite(8, LOW);
  delayMicroseconds(1000000 / baud);

  digitalWrite(8, HIGH);
  delayMicroseconds((1000000 / baud) * 2);

  digitalWrite(8, LOW);
  delayMicroseconds((1000000 / baud) * 3);

  digitalWrite(8, HIGH);
  delayMicroseconds((1000000 / baud) * 2);

  //delay(3000);
  

}
