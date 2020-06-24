#include <SoftwareSerial.h>
#include <Servo.h>
#include <math.h>

SoftwareSerial Bluet (11, 10);   //Tx Rx
Servo servoX, servoY;
// 316, 464
const int numC = 100;

String aux = "";
unsigned long time;

int x[numC];
int y[numC];
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
  
  servoX.write(90);
  servoY.write(90);
  
}

void loop() {

  if (Bluet.available() > 0){
    Serial.println("Receiving Bytes...");
    
    time = millis();

    while (Bluet.available() > 0){
      c = char(Bluet.read());
      if(!(c == '(' || c == ')')){
        if(!(c == ' ')){
          aux += c;
          
        }else{
          
          if(turn == 1){
            Serial.println(aux);
            x[n] = aux.toInt();
            xc = aux.toInt();
            toWriteX = 90 + (atan((xc - 158) / 381.445) * (180 / M_PI));
            aux = "";
            turn++;
            
        }else if(turn == 2){
            y[n] = aux.toInt();
            yc = aux.toInt();
            toWriteY = 90 + (atan((yc - 232) / 560.097) * (180 / M_PI));
            aux = "";
            turn = 1;
            n++;
            servoX.write(toWriteX);
            servoY.write(toWriteY);
        }
        }
      }
          
    }
  }

  if(millis() - time > 5000){                              //Giving a 5 seconds timeout for the Bluetooth "packages"
    n = 0;
    if(x[0] >= 0){

      showCoords();

      delay(5000);
      reset();
     
    }
  }
}

void reset(){
  for(int i = 0; i < numC; i++){
    x[i] = -1;
    y[i] = -1;
  }
}


void showCoords(){

  for(int i = 0; i < numC; i++){

    Serial.print("X[");
    Serial.print(i);
    Serial.print("]: ");
    Serial.print(x[i]);
    Serial.print("   Y[");
    Serial.print(i);
    Serial.print("]: ");
    Serial.println(y[i]);
    
  } 
}
