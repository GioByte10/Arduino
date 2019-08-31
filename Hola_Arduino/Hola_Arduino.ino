void setup() {
 pinMode (13, OUTPUT);   //Aqui declaramos los puertos que vamos a usar
 pinMode (12, OUTPUT);
}

void loop() {
   digitalWrite (12, HIGH);  //Enciende el led
   delay (100);

   digitalWrite (12, LOW);  //Apaga el led
   delay (100);
  
 
}
