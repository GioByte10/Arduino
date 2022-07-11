int p;
int w;

void setup() {

  Serial.begin(9600);
  pinMode(9, OUTPUT);

}

void loop() {

  p = analogRead(A0);
  w = map(p, 0, 1023, 0, 255);
  
  Serial.println(w);
  
  analogWrite(9, w);

}
