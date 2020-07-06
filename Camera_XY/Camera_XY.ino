#include <SoftwareSerial.h>
#include <Servo.h>
#include <math.h>

SoftwareSerial Bluet (10, 11);   //Tx Rx
Servo servoX, servoY;

// 316, 464

const int maxX = 316, maxY = 464;
const double range = 90 * (M_PI/180);

String aux = "";
unsigned long time;

int turn = 1;

double xc, yc, toWriteX, toWriteY;

char c;
int n = 0;

boolean once = false;

void setup() {

  Serial.begin(38400);
  Bluet.flush();
  delay(500);
  Bluet.begin(38400);
  reset();

  servoX.attach(5);
  servoY.attach(6);
  
}

void loop() {

  if (Bluet.available() > 0){
    once = false;
    Serial.println("Receiving Bytes...");
    
    time = millis();

    while (Bluet.available() > 0){
      c = char(Bluet.read());
      //Serial.print(c);
      if(!(c == '(' || c == ')')){
        if(!(c == ' ')){
          aux += c;
          
        }else{
          
          if(turn == 1){
            xc = aux.toInt();
            toWriteX = 90 + (atan((xc - maxX/2) / ((maxX/2)/tan(range/2))) * (180 / M_PI));
            Serial.print(toWriteX);
            Serial.print("     ");
            aux = "";
            turn++;
            
        }else if(turn == 2){
            yc = aux.toInt();
            toWriteY = 80 + (atan((yc - maxY/2) / ((maxY/2)/tan(range/2))) * (180 / M_PI));
            Serial.println(toWriteY);
            aux = "";
            turn = 1;
            servoX.write(toWriteX);
            servoY.write(toRDeg(toWriteY));
        }
        }
      }
          
    }
  }

  if(millis() - time > 1000){                              //Giving a 5 seconds timeout for the Bluetooth "packages"

    if(!once){

      delay(1000);
      reset();
      once = true;
     
    }
  }
}

void reset(){

  servoX.write(90);
  servoY.write(toRDeg(80));
  
}

double toRDeg(double des){
  return des / 1.15;
}
