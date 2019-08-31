int sound;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);

}

void loop() {

  sound = analogRead(A0);
  Serial.println(sound);
   
   if(sound <= 300){
    digitalWrite(13, HIGH);
   }else{
    digitalWrite(13, LOW);
   }
   

}
