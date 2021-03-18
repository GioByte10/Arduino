#include <Keypad.h>
#include <Servo.h>

Servo serv;

const byte filas = 4; 
const byte columnas = 4; 
char teclas[filas][columnas] = { 
  {'1','2','3','A'},    
  {'4','5','6','R'},       
  {'7','8','9','C'},    
  {'*','0','#','T'}
};
byte pinesf[filas] = {11, 10, 9, 8}; 
byte pinesc[columnas] = {7, 6, 5, 4}; 

Keypad teclado = Keypad( makeKeymap(teclas), pinesf, pinesc, filas, columnas); 

char clave[11];
char clavedefinida[11]= "ARACT78930";
byte cursor=0;
byte revisar=0;

void setup(){
  
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);

  serv.attach(12);
  serv.write(180);
  
}
  
void loop(){

  char tecla = teclado.getKey();
    
  if (tecla){
   Serial.println(tecla);
   clave[cursor]= tecla;
   cursor++;
   
   }
  
  if (cursor == 10){
   for(int i=0;i<10;i++){
    Serial.println(clave[i]);
    
    if (clave[i]==clavedefinida[i]){
        revisar++;
        }
    }
    if (revisar == 10){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
      Serial.println("Bienvenido\n");
      serv.write(0);
      }
      else{digitalWrite(3, HIGH);
           digitalWrite(2, LOW);
          Serial.println("error en la contrasena\n");
          serv.write(180);}
    cursor=0;
    revisar=0;
  }
  }
