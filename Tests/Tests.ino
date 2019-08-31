void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(2, OUTPUT);

}

void loop() {
  Serial.println("Wht The FACK, It Works");
  digitalWrite(2, HIGH);
  delay(400);
  digitalWrite(2, LOW);
  delay(1000);

}
