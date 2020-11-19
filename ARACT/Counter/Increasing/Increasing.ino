int a = 6;
int b = 5;
int c = 10;
int d = 11;
int e = 12;
int f = 7;
int g = 9;

int secs = 1000;

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

  secs = increasing(secs, 20);
  if (secs < 300)
    secs = 300;
  secs = decreasing(secs, 20);
  if (secs < 300)
    secs = 300;

}

int increasing(int secs, int interval){

  zero(secs);
  secs -= interval;
  one(secs);
  secs -= interval;
  two(secs);
  secs -= interval;
  three(secs);
  secs -= interval;
  four(secs);
  secs -= interval;
  five(secs);
  secs -= interval;
  six(secs);
  secs -= interval;
  seven(secs);
  secs -= interval;
  eight(secs);
  secs -= interval;
  nine(secs);
  secs -= interval;

  return secs;
  
}

int decreasing(int secs, int interval){

  eight(secs);
  secs -= interval;
  seven(secs);
  secs -= interval;
  six(secs);
  secs -= interval;
  five(secs);
  secs -= interval;
  four(secs);
  secs -= interval;
  three(secs);
  secs -= interval;
  two(secs);
  secs -= interval;
  one(secs);
  secs -= interval;

  return secs;
  
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
