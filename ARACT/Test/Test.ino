// El primer error se encuentra en la linea 6 del codigo original
// ya que hace falta un ; despues del pinMode

// El segundo error se encuentra en la linea 10 del codigo original
// ya que al estar leyendo u obteniendo el valor analogo
// se debe usar analogRead en vez de analogWrite

// El tercer error se encuentra en la linea 11 del codigo original.
// Esto se debe a que se trata de imprimir una variable que no
// ha sido declarada, ya que Luz y luz son dos variables distintas.
// Se debe de escribir la variable de manera correcta
// siendo esta: "luz"

// Tomando en cuenta que el LED esta conectado al PIN 7,
// el cuarto error se encuentra en la linea 16 del codigo original
// ya que se apaga el PIN 3, en vez del 7
// por ende, el LED nunca se apaga


int luz = 0;

void setup() {
  
  Serial.begin(9600);
  pinMode(A3, INPUT);
  pinMode(7, OUTPUT);

}

void loop() {

  luz = analogRead(A3);
  Serial.println(luz);

  if(luz > 200){
    digitalWrite(7, HIGH);
  } else{
    digitalWrite(7, LOW);
  }
  
}
