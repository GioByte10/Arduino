#include <Servo.h> 

#define STEPPER_1 12
#define STEPPER_2 11
#define STEPPER_3 10
#define STEPPER_4 9
#define LED 8
#define servo 7
#define buzzer 6

Servo serv;

int stepn = 0;
bool stepOn = false;

char option = ' ';

void setup() {

  Serial.begin(9600);

  serv.attach(servo);
  
  pinMode(STEPPER_1, OUTPUT);
  pinMode(STEPPER_2, OUTPUT);
  pinMode(STEPPER_3, OUTPUT);
  pinMode(STEPPER_4, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(buzzer, 9);


  Serial.println("Seleccione una opcion");
  Serial.println("1.- encender motor a pasos");
  Serial.println("2.- encender LED");
  Serial.println("3.- encender Servo");
  Serial.println("4.- encender Buzzer");
  Serial.println("5.- resetear todo\n");
  

}

void loop() {

  if(Serial.available() > 0)
    option = Serial.read();


  switch(option){

    case '1':
      stepOn = true;
      Serial.println("Encendiendo motor a pasos\n");
      break;

    case '2':
      digitalWrite(LED, HIGH);
      Serial.println("Encendiendo LED\n");
      break;

    case '3':
      serv.write(180);
      Serial.println("Encendiendo servo\n");
      break;

    case '4':
      analogWrite(buzzer, 170);
      Serial.println("Encendiendo buzzer\n");
      break;

    case '5':
      Serial.println("Reseteando todo\n");
      reset();

    case ' ':
      break;

    default:
      Serial.println("Por favor seleccione una opcion valida\n");
    
  }

  option = ' ';
 
  step_(stepOn);
  delay(2);
  
}


void step_(bool stepOn){

  if (stepOn){
    switch(stepn){
      
      case 0:
        digitalWrite(STEPPER_1, HIGH);
        digitalWrite(STEPPER_2, LOW);
        digitalWrite(STEPPER_3, LOW);
        digitalWrite(STEPPER_4, LOW);
        break;
      
      case 1:
        digitalWrite(STEPPER_1, LOW);
        digitalWrite(STEPPER_2, HIGH);
        digitalWrite(STEPPER_3, LOW);
        digitalWrite(STEPPER_4, LOW);
        break;
      
      case 2:
        digitalWrite(STEPPER_1, LOW);
        digitalWrite(STEPPER_2, LOW);
        digitalWrite(STEPPER_3, HIGH);
        digitalWrite(STEPPER_4, LOW);
        break;
      
      case 3:
        digitalWrite(STEPPER_1, LOW);
        digitalWrite(STEPPER_2, LOW);
        digitalWrite(STEPPER_3, LOW);
        digitalWrite(STEPPER_4, HIGH);
        break;
    } 
  
  
    stepn++;
    
    if(stepn > 3)
      stepn = 0;
    
  }
}

void reset(){

  digitalWrite(LED, LOW);
  analogWrite(buzzer, 0);
  stepOn = false;
  serv.write(0);

}
