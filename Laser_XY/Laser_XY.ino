#include <Servo.h>

Servo servoX, servoY;

int x, y, toWriteX = 450, toWriteY = 450;

void setup() {

  
   servoX.attach(9); 
   servoY.attach(6);
}

void loop() {

   x = 90 - (analogRead(A0) / 11) + 45;
   y = 60 - (analogRead(A1) / 17);

   servoX.write(x);
   servoY.write(y);
}

/*
int readX(){

  int rx = (x / 19) * 2;

  if(toWriteX < 1000){

    if(toWriteX + rx > 1000)
      toWriteX = 1000;

    else
      toWriteX += rx;
  }
   return toWriteX + 1000;
}

int readY(){                                               A more complex idea

  int ry = (y / 19) * 2;

  if(toWriteY < 1000){

    if(toWriteY + ry > 1000)
      toWriteY = 1000;

    else
      toWriteY += ry;
  }
   return toWriteY + 1000;
}

*/
