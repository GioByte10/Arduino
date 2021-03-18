#define forward 6
#define backward 5 

int y_value = 0;

int _speed = 0;

void setup() {

  Serial.begin(9600);
  pinMode(forward, OUTPUT);
  pinMode(backward, OUTPUT);

}

void loop() {
  
  y_value = 1023 - analogRead(A1);
  Serial.println(y_value);

  if (y_value > 600){
    _speed = map(y_value, 600, 1023, 0, 255);
    analogWrite(forward, _speed);
    digitalWrite(backward, LOW);
    
  } else if(y_value < 400){
    _speed = map(y_value, 400, 0, 0, 255);
    analogWrite(backward, _speed);
    digitalWrite(forward, LOW);
    
  }else{
    digitalWrite(forward, LOW);
    digitalWrite(backward, LOW);
  }

}
