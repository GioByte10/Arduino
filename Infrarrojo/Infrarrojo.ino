#include <IRremote.h>
#include <SoftwareSerial.h>

SoftwareSerial Bluetooth (11, 10); //Tx & Rx

int infra = 3;
const int light = 4;
const int desktop = 5;
const int fan = 6;
//bool state = false;
bool li = false;
bool des = false;
bool fa = false;
int timer = 0;
String words;
char text[25];
int n = 0;
int modes = 1;
const int photo = 9;
const int sound = 8;
const int BT = 7;


IRrecv irrecv(infra);
decode_results code;


void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  Bluetooth.flush();
  delay(500);
  Bluetooth.begin(9600);
  pinMode (light, OUTPUT);
  pinMode (desktop, OUTPUT);
  pinMode (fan, OUTPUT);
  pinMode (BT, OUTPUT);
  pinMode (12, INPUT);
  pinMode (sound, OUTPUT);
  pinMode (photo, OUTPUT);

}

void loop() {

 digitalWrite(BT, HIGH);
  while (modes == 1){
  if (irrecv.decode(&code) || (Bluetooth.available() > 0)){
    Serial.println(code.value, HEX);
     while (Bluetooth.available() > 0){
      text[n] = char(Bluetooth.read());
      Serial.println (text);
      n++;
  }
    words = text;
    Serial.print(words);
  //Serial.println(code.value, HEX);
    if (code.value==0xFF30CF || words == "li"){
      li = !li;
      
    }else if (code.value==0xFF18E7 || words == "des"){
      des = !des;
      
    }else if (code.value==0xFF7A85 || words == "fa"){
      fa = !fa;

    }else if (code.value==0xFFE21D || words == "all"){
     li = false;
     des = false;
     fa = false;
     
    }else if (code.value==0xFFA25D || words == "none"){
      li = true;
      des = true;
      fa = true;
      
    }else if (code.value == 0xFF9867){
      modes = 2;

    }else if (code.value == 0xFFB04F)
      modes = 3;
  
  //timer = 1;
  delay(500);
  irrecv.resume();
  }

 if (li == false){
  digitalWrite (light, LOW);
 }else
  digitalWrite (light, HIGH);

 if (des == false){
  digitalWrite (desktop, LOW);
 }else
  digitalWrite (desktop, HIGH);

 if (fa == false){
  digitalWrite (fan, LOW);
 }else
  digitalWrite (fan, HIGH);

  words = "xyz";
    while (n >= 0){
      text[n] = '\0';
      if (n == 0)
      break;                           
      
      n--;
    }
  }

  digitalWrite(BT, LOW);
  digitalWrite(photo, HIGH);
  digitalWrite(fan, HIGH); 
  
  while (modes == 2){
    if (irrecv.decode(&code)){

       if (code.value == 0xFF6897)
        modes = 1;

      if (code.value == 0xFFB04F)
        modes = 3;

        delay(500);
    irrecv.resume();
    }

    
    Serial.println (analogRead(A0));
    if (analogRead(A0) > 500){
      digitalWrite (light, HIGH);
      digitalWrite (desktop, HIGH);
      
    }else{
      
      digitalWrite (light, LOW);
      digitalWrite (desktop, LOW);
    }
    
   }
   digitalWrite(photo, LOW);
   digitalWrite(fan, digitalRead(desktop));
   digitalWrite(sound, HIGH);

  
  while (modes == 3){
    if (irrecv.decode(&code)){

       if (code.value == 0xFF6897)
        modes = 1;

      if (code.value == 0xFF9867)
        modes = 2;

     delay(500);
    irrecv.resume();
    }

    if (digitalRead(12) == LOW){
    
      digitalWrite(desktop, !digitalRead(desktop));
      digitalWrite(light, !digitalRead(light));
      digitalWrite(fan, !digitalRead(fan));

      delay(500);
    }
  }

  digitalWrite(sound, LOW);
}
