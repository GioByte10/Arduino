#define pin 8
#define baud 1000

void setup() {

  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);

  delay(1000);
  delay(5000);
  
  //Serial.begin(baud); 
  
}

void loop() {

   start();
   Bit(false, 1);
   Bit(true, 2);
   Bit(false, 3);
   Bit(true, 2);
   End();
  
}

  void start(){

    digitalWrite(pin, HIGH);
    delayMicroseconds(double(1000000/baud));
    
  }

  void Bit(bool state, int rep){

    if(state){
      digitalWrite(pin, HIGH);
      
    }else{      
      digitalWrite(pin, LOW);
    }

    delayMicroseconds(double((1000000 / baud) * rep));
    
  }

  void End(){

    digitalWrite(pin, HIGH);
    Serial.println("End");
   // delay(1000);
    
  }
