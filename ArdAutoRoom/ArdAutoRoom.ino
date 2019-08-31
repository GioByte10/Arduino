#include <IRrecv.h>
#include <IRremoteESP8266.h>
#include <IRutils.h>

uint16_t PIN = 14;
const int light = 16;
const int desktop = 5;
const int fan = 4;
bool state = false;
int timer = 0;
bool frez = false;
bool night = false;
int nicou = 0;
int startt;
int finish;
int dif;
bool MotionLock = false;

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
  digitalWrite(2, LOW);
  delay(1500);
  digitalWrite(2, HIGH);


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

    if (code.value == 0xFF18E7){

      nicou = 0;
      night = true;
      state = false;
      MotionLock = false;

      if (night){
        digitalWrite(2, LOW);
        delay(1000);  
        digitalWrite(2, HIGH);
        delay(300);
        for (int i = 0; i < 7; i++){
          digitalWrite(2, LOW);
          delay(200);
          digitalWrite(2, HIGH);
          delay(100);   
        }
        }

        digitalWrite(2, HIGH);
      
    }
   
  delay(500);
  irrecv.resume();
  
  }
//Serial.println(digitalRead(0));
  if (digitalRead(0) == HIGH && !frez && !MotionLock){
    //Serial.println("Hola");
    state = !state;
    timer = 1;
    }else if (frez == true){
      state = false;
    }

  if (state == true){
    digitalWrite (light, LOW);
    digitalWrite (desktop, HIGH);
    digitalWrite (fan, HIGH);
       if (MotionLock){
           digitalWrite (light, LOW);
           digitalWrite (desktop, HIGH);
           digitalWrite (fan, LOW);
       }
    }

  if (state == false)
  {
    digitalWrite (light, HIGH);
    digitalWrite (desktop, LOW);
    digitalWrite (fan, LOW);
    }

  if (timer == 1) {
    digitalWrite (2, LOW);
    delay (6000);
    digitalWrite (2, HIGH);
    timer = 0;

  }

  if (night){
    while(nicou == 0){
      startt = millis();
      nicou++;
    }

    finish = millis();
    dif = finish - startt;
    
    if(dif >= 1020000){
      state = true;
      MotionLock = true;
      frez = false;
      nicou = 0;
      night = false;
    }
  }

}
