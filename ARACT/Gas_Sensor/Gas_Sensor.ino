int gas = 0;
int pt = 0;

void setup() {
  
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);

}

void loop() {

  gas = analogRead(A0);
  Serial.println(gas);

  

  if(gas > 600){
    Serial.println("Danger!");
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    
    while(analogRead(A0) > 600){
      pt = map(analogRead(A2), 0, 1023, 0, 255);
      analogWrite(9, pt);

      Serial.println(analogRead(A2));

    }
      
  }else{
    Serial.println("Status: Safe");
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(9, LOW);

    while(analogRead(A0) < 600);
  }

}
