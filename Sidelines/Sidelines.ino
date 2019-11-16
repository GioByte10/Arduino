int value;

void setup() {

   Serial.begin(9600);
   pinMode(10, OUTPUT);

}

void loop() {

   value = analogRead(A0) * 0.24;
   Serial.println(value);
   analogWrite(10, value);

}
