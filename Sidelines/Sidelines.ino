double value;

void setup() {

   Serial.begin(9600);
   pinMode(10, OUTPUT);

}

void loop() {

   value = analogRead(A0) * 0.0634;
   Serial.println(value);
   analogWrite(10, value + 190);
    
}
