int ph = 0;
int toAnalog = 0;

void setup() {
  
  Serial.begin(9680);
  pinMode(6, OUTPUT);
  pinMode(A0, INPUT);

}

void loop() {

  ph = analogRead(A0);
  toAnalog = map(ph, 0, 400, 0, 255);

  Serial.print(toAnalog);
  Serial.print("    ");
  Serial.println(ph);
  
  analogWrite(6, 255 - toAnalog);

}
