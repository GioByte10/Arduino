double value;

void setup(){

  Serial.begin(9600);
  pinMode(10, OUTPUT);
  
}

void loop(){

  value = analogRead(A0) * 0.249;

  analogWrite(10, value);
  Serial.print((value / 255) * 100);
  Serial.println("% of duty cycle");
  
}
