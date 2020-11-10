int a = 6;
int b = 5;
int c = 10;
int d = 11;
int e = 12;
int f = 7;
int g = 9;

void setup() {

  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

}

void loop() {

  increasing(500);
  decreasing(500);

}

void increasing(int secs){

  zero(secs);
  one(secs);
  two(secs);
  three(secs);
  four(secs);
  five(secs);
  six(secs);
  seven(secs);
  eight(secs);
  nine(secs);
  
}

void decreasing(int secs){

  eight(secs);
  seven(secs);
  six(secs);
  five(secs);
  four(secs);
  three(secs);
  two(secs);
  one(secs);
  
}

void one(int secs){
  
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);

  delay(secs);

  digitalWrite(b, LOW);
  digitalWrite(c, LOW);

  
}

void two(int secs){
  
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(a, HIGH);

  delay(secs);

  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(g, LOW);
  digitalWrite(b, LOW);
  digitalWrite(a, LOW);
  
}

void three(int secs){
  
  digitalWrite(d, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(a, HIGH);

  delay(secs);

  digitalWrite(d, LOW);
  digitalWrite(c, LOW);
  digitalWrite(g, LOW);
  digitalWrite(b, LOW);
  digitalWrite(a, LOW);
  
}

void four(int secs){
  
  digitalWrite(c, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(f, HIGH);

  delay(secs);

  digitalWrite(c, LOW);
  digitalWrite(b, LOW);
  digitalWrite(g, LOW);
  digitalWrite(f, LOW);
  
}

void five(int secs){
  
  digitalWrite(d, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(a, HIGH);

  delay(secs);

  digitalWrite(d, LOW);
  digitalWrite(c, LOW);
  digitalWrite(g, LOW);
  digitalWrite(f, LOW);
  digitalWrite(a, LOW);
  
}

void six(int secs){
  
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(a, HIGH);

  delay(secs);

  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(g, LOW);
  digitalWrite(f, LOW);
  digitalWrite(a, LOW);
  
}

void seven(int secs){
  
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);

  delay(secs);

  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);

  
}

void eight(int secs){
  
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);

  delay(secs);

  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  
}

void nine(int secs){
  
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);

  delay(secs);

  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);

  
}

void zero(int secs){
  
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);

  delay(secs);

  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  
}
