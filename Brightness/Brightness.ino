/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fade
*/

int LED = 11;          
int LED2 = 10;
int LED3 = 9;
int LED4 = 6;
int brightness = 0;    // how bright the LED is
int intb = 20;


void setup() {
  // declare pin 9 to be an output:
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  Serial.begin(9600);   //Declare the monitor/Plotter

}


void loop() {
  
  int xvalue = analogRead(A0) - 500;       //Declare the analog reading of resistence
  int yvalue = analogRead(A1) - 500;
  int sw = analogRead(A2);

  if (((xvalue > -2) && (yvalue > -3)) && ((xvalue < 1) && (yvalue < 1)))
  {
  brightness = intb;
  analogWrite (LED, brightness);
  analogWrite (LED2, brightness);
  analogWrite (LED3, brightness);
  analogWrite (LED4, brightness);
  }

 
  else if ((xvalue > 0) && (yvalue > 0))
  {
    brightness = intb + (xvalue * 0.22) + (yvalue * 0.22);
    analogWrite (LED, brightness);
    analogWrite (LED2, intb + (xvalue * 0.22));
    analogWrite (LED3, (intb) - ((xvalue * 0.02) + (yvalue * 0.02)));
    analogWrite (LED4, intb + (yvalue * 0.22));
  }
  
  else if ((xvalue < -2) && (yvalue > 1))
  {
    xvalue = -xvalue;
    brightness = intb + (xvalue * 0.22) + (yvalue * 0.22);
    analogWrite (LED4, brightness);
    analogWrite (LED3, intb + (xvalue * 0.22));
    analogWrite (LED2, (intb) - ((xvalue * 0.02) + (yvalue * 0.02)));
    analogWrite (LED, intb + (yvalue * 0.22));
  }

    else if ((xvalue < -2) && (yvalue < -2))
  {
    xvalue = -xvalue;
    yvalue = -yvalue;
    brightness = intb + (xvalue * 0.22) + (yvalue * 0.22);
    analogWrite (LED3, brightness);
    analogWrite (LED4, intb + (xvalue * 0.22));
    analogWrite (LED, (intb) - ((xvalue * 0.02) + (yvalue * 0.02)));
    analogWrite (LED2, intb + (yvalue * 0.22));
  }

    else if ((xvalue > 0) && (yvalue <-2))
  {
    yvalue = -yvalue;
    brightness = intb + (xvalue * 0.22) + (yvalue * 0.22);
    analogWrite (LED2, brightness);
    analogWrite (LED, intb + (xvalue * 0.22));
    analogWrite (LED4, (intb) - ((xvalue * 0.02) + (yvalue * 0.02)));
    analogWrite (LED3, intb + (yvalue * 0.22));
  }
  


  Serial.println(" ");
  Serial.print("X = ");             //Print the value in the monitor/Plotter
  Serial.print(xvalue);
  Serial.print(";");

  Serial.print("Y = ");             
  Serial.println(yvalue);
  

}
