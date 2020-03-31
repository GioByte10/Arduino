#include <ESP8266WiFi.h>

#include <Servo.h>

Servo telegraph;

#define FIREBASE_HOST ""
#define FIREBASE_AUTH ""
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

WiFiServer server(80);

String wordToMorse = "0123456789?.,";
int timeDot = 300;
int timeDash = 3 * timeDot;
int timeWord = 7 * timeDot;

bool repeat = true;

void setup() {

   Serial.begin(9600);
   delay(10);
   pinMode(2, OUTPUT);
   digitalWrite(2, HIGH);
   
   telegraph.attach(12);

   Serial.println();
   Serial.println();
   Serial.print("Connecting to ");
   Serial.println(ssid);
 
   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
 
   while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.print(".");
   }
   Serial.println("");
   Serial.println("WiFi connected");
   

}

void loop() {

  if(repeat)
  Morse(wordToMorse);
  
  repeat = false;

}

void Morse (String wordm){

   for(int i = 0; i < wordm.length(); i++){

    if(wordm.charAt(i) == ' '){
       delay(timeWord - timeDot);

    }else if(wordm.charAt(i) == 'A' || wordm.charAt(i) == 'a'){
       Dot();
       Dash();
       delay(timeDash);
                     
    }else if (wordm.charAt(i) == 'B' || wordm.charAt(i) == 'b'){
       Dash();
       Dot();
       Dot();
       Dot();
       delay(timeDash);
      
    }else if (wordm.charAt(i) == 'C' || wordm.charAt(i) == 'c'){
       Dash();
       Dot();
       Dash();
       Dot();
       delay(timeDash);
      
    }else if (wordm.charAt(i) == 'D' || wordm.charAt(i) == 'd'){
       Dash();
       Dot();
       Dot();
       delay(timeDash);
      
    }else if (wordm.charAt(i) == 'E' || wordm.charAt(i) == 'e'){
      Dot();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == 'F' || wordm.charAt(i) == 'f'){
      Dot();
      Dot();
      Dash();
      Dot();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == 'G' || wordm.charAt(i) == 'g'){
      Dash();
      Dash();
      Dot();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == 'H' || wordm.charAt(i) == 'h'){
      Dot();
      Dot();
      Dot();
      Dot();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == 'I' || wordm.charAt(i) == 'i'){
      Dot();
      Dot();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == 'J' || wordm.charAt(i) == 'j'){
      Dot();
      Dash();
      Dash();
      Dash();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == 'K' || wordm.charAt(i) == 'k'){
      Dash();
      Dot();
      Dash();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == 'L' || wordm.charAt(i) == 'l'){
      Dot();
      Dash();
      Dot();
      Dot();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == 'M' || wordm.charAt(i) == 'm'){
      Dash();
      Dash();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == 'N' || wordm.charAt(i) == 'n'){
      Dash();
      Dot();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == 'O' || wordm.charAt(i) == 'o'){
      Dash();
      Dash();
      Dash();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == 'P' || wordm.charAt(i) == 'p'){
      Dot();
      Dash();
      Dash();
      Dot();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == 'Q' || wordm.charAt(i) == 'q'){
      Dash();
      Dash();
      Dot();
      Dash();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == 'R' || wordm.charAt(i) == 'r'){
      Dot();
      Dash();
      Dot();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == 'S' || wordm.charAt(i) == 's'){
      Dot();
      Dot();
      Dot();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == 'T' || wordm.charAt(i) == 't'){
      Dash();
      delay(timeDash);
    }else if (wordm.charAt(i) == 'U' || wordm.charAt(i) == 'u'){
      Dot();
      Dot();
      Dash();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == 'V' || wordm.charAt(i) == 'v'){
      Dot();
      Dot();
      Dot();
      Dash();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == 'W' || wordm.charAt(i) == 'w'){
      Dot();
      Dash();
      Dash();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == 'X' || wordm.charAt(i) == 'x'){
      Dash();
      Dot();
      Dot();
      Dash();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == 'Y' || wordm.charAt(i) == 'y'){
      Dash();
      Dot();
      Dash();
      Dash();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == 'Z' || wordm.charAt(i) == 'z'){
      Dash();
      Dash();
      Dot();
      Dot();
      delay(timeDash);
    }else if (wordm.charAt(i) == '?'){
      Dot();
      Dot();
      Dash();
      Dash();
      Dot();
      Dot();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == '1'){
      Dot();
      Dash();
      Dash();
      Dash();
      Dash();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == '2'){
      Dot();
      Dot();
      Dash();
      Dash();
      Dash();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == '3'){
      Dot();
      Dot();
      Dot();
      Dash();
      Dash();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == '4'){
      Dot();
      Dot();
      Dot();
      Dot();
      Dash();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == '5'){
      Dot();
      Dot();
      Dot();
      Dot();
      Dot();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == '6'){
      Dash();
      Dot();
      Dot();
      Dot();
      Dot();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == '7'){
      Dash();
      Dash();
      Dot();
      Dot();
      Dot();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == '8'){
      Dash();
      Dash();
      Dash();
      Dot();
      Dot();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == '9'){
      Dash();
      Dash();
      Dash();
      Dash();
      Dot();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == '0'){
      Dash();
      Dash();
      Dash();
      Dash();
      Dash();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == '.'){
      Dot();
      Dash();
      Dot();
      Dash();
      Dot();
      Dash();
      delay(timeDash);
      
    }else if (wordm.charAt(i) == ','){
      Dash();
      Dash();
      Dot();
      Dot();
      Dash();
      Dash();

      delay(timeDash);

    }
    
   }
  
}

void Dot (){
  
   digitalWrite(2, LOW);
   delay(timeDot);
   digitalWrite(2, HIGH);
   delay(timeDot);
   
}

void Dash (){

   digitalWrite(2, LOW);
   delay(timeDash);
   digitalWrite(2, HIGH);
   delay(timeDot);
  
}
