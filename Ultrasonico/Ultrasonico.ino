int Trig = 2;
int Echo = 4;
long duracion, distancia;

void setup() {
  Serial.begin(9600);
  pinMode (Trig, OUTPUT);
  pinMode (Echo, INPUT);
  pinMode (13, OUTPUT);
  

}

void loop() {
  digitalWrite (Trig, LOW);
  delayMicroseconds(5);
  digitalWrite (Trig, HIGH);


   duracion = pulseIn(Echo, HIGH);
   duracion = duracion / 2;
   distancia = 0.034 * duracion;

   Serial.print("Distancia ");
   Serial.print(distancia);
   Serial.println(" Cm");
   


}
