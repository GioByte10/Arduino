 int PWM3;            
 int PWM5;                //Declaring potentiometers
 int PWM6;
 int Red = 9;
 int Green = 10;          //Declaring the pins for RGB Led
 int Blue = 11;

void setup() {

 Serial.begin(9600);
 pinMode (Red, INPUT);
 pinMode (Green, INPUT);
 pinMode (Blue, INPUT);
 pinMode (10, OUTPUT);
 pinMode (11, OUTPUT);
 pinMode (12, OUTPUT);
 
}

void loop() {

  PWM3 = analogRead (A0) * 0.2492;
  PWM5 = analogRead (A1) * 0.2492;
  PWM6 = analogRead (A2) * 0.2492;

  analogWrite (Red, PWM6);
  analogWrite (Green, PWM5);
  analogWrite (Blue, PWM3);

  

  Serial.print("Red:");
  Serial.print(PWM6);
  Serial.print(";   ");

  Serial.print("Green:");
  Serial.print(PWM5);
  Serial.print(";   ");

  Serial.print("Blue:");
  Serial.println(PWM3);


}
