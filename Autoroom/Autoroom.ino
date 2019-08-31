#include <IRremote.h>

const int PIN = 2;
const int light = 4;
const int desktop = 5;
const int fan = 6;
bool state = false;
int timer = 0;
bool frez = false;

IRrecv irrecv (PIN);
decode_results code;

void setup() {
  irrecv.enableIRIn();
  Serial.begin(9600);
  pinMode (3, INPUT);
  pinMode (13, OUTPUT);
  pinMode (light, OUTPUT);
  pinMode (desktop, OUTPUT);
  pinMode (fan, OUTPUT);

}

void loop() {
  

  if (irrecv.decode(&code)){
    Serial.println (code.value, HEX);

    if (code.value == 0xFFE21D){
      state = !state; 
    }   

    if (code.value == 0xFF6897){
      frez = !frez;
    }
   
  delay(500);
  irrecv.resume();
  
  }

  if (digitalRead(3) == HIGH && frez == false){
    Serial.println(digitalRead (3));

    state = !state;
    timer = 1;
    }else if (frez == true){
      state = false;
    }

  if (state == true){
    digitalWrite (light, HIGH);
    digitalWrite (desktop, HIGH);
    digitalWrite (fan, HIGH);
    }

  if (state == false)
  {
    digitalWrite (light, LOW);
    digitalWrite (desktop, LOW);
    digitalWrite (fan, LOW);
    }

  if (timer == 1) {
    digitalWrite (13, HIGH);
    delay (6000);
    digitalWrite (13, LOW);
    timer = 0;

  }

}
