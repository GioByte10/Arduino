int incomingByte = 0; // for incoming serial data

void setup() {

  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);

  delay(1000);
  
  Serial.begin(1200); // opens serial port, sets data rate to 9600 bps
  
  
}

void loop() {

    Serial.println("Starting");
    delay(1000);

    digitalWrite(8, LOW);
    delay(6.6666);
    digitalWrite(8, HIGH);

    if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
  }

  delay(5000);
  
}
