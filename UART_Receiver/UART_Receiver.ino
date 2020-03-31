int incomingByte;

void setup(){

  Serial.begin(1200);
  pinMode(8, INPUT);
  
}

void loop(){

  if (Serial.available() > 0) {
    
    incomingByte = Serial.read();

    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
    
  }
  

}
