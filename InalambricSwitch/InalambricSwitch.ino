#include <SoftwareSerial.h>

SoftwareSerial Bluet (11, 10); // Tx & Rx

char letters[25];
String Csec;
int seconds;
int n = 0;

void setup() {

  Serial.begin(9600);
  Bluet.flush();
  delay(500);
  Bluet.begin(9600);

}

void loop() {

  if (Bluet.available() > 0){

    Serial.println("Receiving Data...");

    while (Bluet.available() > 0){
      letters[n] = char(Bluet.read());
      Serial.println("Byte Received");
      n++;
      
    }

    Csec = letters;
    Serial.println(Csec);

    for(n -= 1; n >= 0; n--){
       letters[n] = '\0';
    }

    if(!((Csec == "indeterminate") || (Csec == "INDETERMINATE") || (Csec == "Indeterminate"))){
    
    seconds = Csec.toInt();
    Serial.print("\n");
    Serial.print("Seconds = ");
    Serial.println(seconds);
    
    }else{
      Serial.println("Indeterminate");
    }
    
  }
  

}
