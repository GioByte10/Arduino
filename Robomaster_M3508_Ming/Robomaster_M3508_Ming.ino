int defaultpos = 120;

#include <Servo.h>
Servo myservo1; // declare servo
Servo myservo2;
Servo ESC;
String comdata;
int blinktime;
int integerdata = defaultpos;

void setup ()
{
  Serial.begin(9600);
  myservo1.attach(6);
  myservo2.attach(10);
  delay(250);
  myservo1.write(defaultpos);
  myservo2.write(defaultpos);
  //ESC.attach(4,1000,2000); // between 1ms and 2ms
  //ESC.write(defaultpos);
}

void loop ()
{
  SerialChecker();
  
   myservo1.write(integerdata);
   myservo2.write(integerdata);
   //ESC.write(integerdata);
  
  delay(50);

}

void SerialChecker()
{
  //read string from serial monitor
  if (Serial.available() > 0) // if we get a valid byte, read analog ins:
  {
    comdata = ""; //reset the old values
    while (Serial.available() > 0)
    {
      comdata += char(Serial.read()); //Add the character value to comdata
      delay(2);//so that whole message is sent before the arduino reads it
      integerdata = comdata.toInt(); //converts our character data into a number
      blinktime = integerdata;
    }
    Serial.println(comdata);//prints out what you are typing
  }
}
