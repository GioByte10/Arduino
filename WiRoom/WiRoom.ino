#include <IRrecv.h>
#include <IRremoteESP8266.h>
#include <IRutils.h>

uint16_t PIN = 14;
const int light = 5;
const int desktop = 4;
const int fan = 16;
bool state = true;
int timer = 0;
bool frez = false;

IRrecv irrecv (PIN);
decode_results code;

void setup() {
  irrecv.enableIRIn();
  Serial.begin(115200);
  pinMode (0, INPUT);
  pinMode (2, OUTPUT);
  pinMode (light, OUTPUT);
  pinMode (desktop, OUTPUT);
  pinMode (fan, OUTPUT);
  delay(1500);


}

void loop() {

  digitalWrite(2, HIGH);
  
  if (irrecv.decode(&code)){
    serialPrintUint64(code.value, HEX);
    Serial.println(" ");

    if (code.value == 0xFFE21D){
      state = !state; 
      
    }   

    if (code.value == 0xFF6897){
      frez = !frez;
      
    }
   
  delay(500);
  irrecv.resume();
  
  }

  if (digitalRead(0) == HIGH && frez == false){
 
    state = !state;
    timer = 1;
    }else if (frez == true){
      state = false;
    }

  if (state == false){
    digitalWrite (light, LOW);
    digitalWrite (desktop, LOW);
    digitalWrite (fan, HIGH);
    }

  if (state == true)
  {
    digitalWrite (light, HIGH);
    digitalWrite (desktop, HIGH);
    digitalWrite (fan, LOW);
    }

  if (timer == 1) {
    digitalWrite (2, LOW);
    delay (6000);
    digitalWrite (2, HIGH);
    timer = 0;

  }

}
