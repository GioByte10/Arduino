double value;
int button = 0;

void setup() {

   Serial.begin(9600);
   pinMode(11, OUTPUT);              //Motor Controller
   pinMode(9, OUTPUT);               //LED
   pinMode(7, INPUT);                //Button


   pinMode(8, OUTPUT);               //Ground
   pinMode(5, OUTPUT);               //Ground
   pinMode(3, OUTPUT);               //Ground

   pinMode(4, OUTPUT);               //VCC
   digitalWrite(4, HIGH);
   pinMode(2, OUTPUT);               //VCC
   digitalWrite(2, HIGH);     

   pinMode(6, OUTPUT);               //Relay
   digitalWrite(6, HIGH);
   

}

void loop() {

   value = analogRead(A0) * 0.0195;
   Serial.println(value);
   analogWrite(11, value + 190);
   

   if(value > 12)
      analogWrite(9, 25);
   else
      digitalWrite(9, LOW);

      Serial.println(digitalRead(7));

   if(digitalRead(7)){

      digitalWrite(6, LOW);
      delay(27);
      digitalWrite(6, HIGH);
      delay(1000);
    
   }
      
   
   
    
}
