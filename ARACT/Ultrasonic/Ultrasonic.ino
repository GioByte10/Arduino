#define trig 7
#define echo 6
#define buzzer 9
#define led 10

int t = 0;
int distance = 0;
int intensity = 0;

void setup() {

  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

}

void loop() {

  digitalWrite(trig, LOW);
  delayMicroseconds(30);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);                      // Allow signal to get out of shield
  digitalWrite(trig, LOW);

  t = pulseIn(echo, HIGH);
  distance = 0.01716 * t;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  intensity = map(distance, 5, 100, 0, 255);

  analogWrite(buzzer, intensity);
  analogWrite(led, intensity);
  
}
