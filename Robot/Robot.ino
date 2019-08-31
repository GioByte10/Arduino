#include <Servo.h>
Servo cabeza;

#define izq_atras 5 // llanta izquiera atras 
#define der_adel 6 // llanta derecha adelante 
#define izq_adel 9 // llanta izquiera adelante
#define der_atras 10 // llanta derecha atras  
#define push1 7
#define push2 8
#define trigger A0
#define echo A1
#define LDR A4

int luz;
int duracion;
int distancia;
int grados = 0;

void distance(){
  digitalWrite (trigger, LOW);
  delayMicroseconds(5);
  digitalWrite (trigger, HIGH);


   duracion = pulseIn(echo, HIGH);
   duracion = duracion / 2;
   distancia = 0.034 * duracion;
}

void setup() {

  cabeza.attach(11);
  cabeza.write(90);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT); 

  pinMode (12,OUTPUT);
  pinMode (13,OUTPUT);
  pinMode (4,OUTPUT);
  pinMode (A2,OUTPUT);
  pinMode (A3,OUTPUT);

  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(4, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);

}

void loop() {

  if (push1 == HIGH){

  distance();
  digitalWrite(13, HIGH);

   if (distancia > 100){

          digitalWrite(der_adel, 150);
          digitalWrite(izq_adel, 150);
          delay(1000);
          digitalWrite(der_adel, 0);
          digitalWrite(izq_adel, 0);
          delay(10);

          digitalWrite(der_atras, 150);
          digitalWrite(izq_atras, 150);
          delay(300);
          digitalWrite(der_atras, 0);
          digitalWrite(izq_atras, 0);
          delay(10);

          cabeza.write(0);

          distance();

          if(distancia < 40){
            grados = 10;

            for(int i = 0; i < 8; i++){
              
              cabeza.write(grados);
              grados += 10;
              delay(400);
              
            }
          }else{
              cabeza.write(180);
            }
          }
   }
   if (push2 == HIGH){

      luz=analogRead(LDR);

      if(luz<100) {
        
         digitalWrite (12,HIGH);
         digitalWrite (4, HIGH ); 
         digitalWrite (13 ,HIGH );
         digitalWrite (A2,HIGH);
         digitalWrite (A3, HIGH ); 
  }else {
    
   digitalWrite (12,LOW);
   digitalWrite (4 ,LOW ); 
   digitalWrite (13 ,LOW );
   digitalWrite (A2,LOW);
   digitalWrite (A3 ,LOW ); 
    
  }

     digitalWrite(der_adel, 150);
     digitalWrite(izq_adel, 150);
     delay(1500);

     digitalWrite(der_adel, 0);
     digitalWrite(izq_adel, 0);
     delay(150);

     digitalWrite(der_atras, 150);
     digitalWrite(izq_atras, 150);
     delay(1500);

     digitalWrite(der_adel, 0);
     digitalWrite(izq_adel, 0);
     delay(150);

     digitalWrite(der_adel, 150);
     digitalWrite(izq_atras, 150);
     delay(500);

     digitalWrite(der_adel, 0);
     digitalWrite(izq_atras, 0);
     delay(30);

     digitalWrite(der_adel, 150);
     digitalWrite(izq_adel, 150);
     delay(500);

     digitalWrite(der_adel, 0);
     digitalWrite(izq_adel, 0);
     delay(30);

     digitalWrite(der_adel, 150);
     digitalWrite(izq_atras, 150);
     delay(500);

     digitalWrite(der_adel, 0);
     digitalWrite(izq_atras, 0);
     delay(30);

     digitalWrite(der_atras, 150);
     digitalWrite(izq_atras, 150);
     delay(500);

     digitalWrite(der_atras, 0);
     digitalWrite(izq_atras, 0);
     delay(30);

   }
  }
