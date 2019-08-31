#include <SoftwareSerial.h>        //Include the library for Virtual Tx and Rx

const int led = 13;
const int rele = 2;
const int boom = 4;
char numbers[25];                 //Array for the Numbers "State" of selection
String state;
char letters[25];                 //Array for the letters "MODE" of selection
String MODE = "mode";
int n = 0;                        //Counter for letters Array
int num = 0;                      //Counter for numbers Array
int count = 0;                    //For blinking indicator Protocol


SoftwareSerial Bluet (11, 10);          //Tx & Rx of Bluetooth module

void setup() {
  pinMode (led, OUTPUT);                 //Declare
  pinMode (rele, OUTPUT);
  pinMode (boom, OUTPUT);

  Serial.begin(9600);                    //Declare the Serial
  Bluet.flush();                         //"Start" the Bluetooth module
  delay (500);
  Bluet.begin(9600);                     //Declare Bluetooth module speed

}

void loop() {



  if (Bluet.available() > 0)                                 //If Bluetooth receive Bytes
  {
    Serial.println("Receiving Bytes...");                     //Advice we are receiving Information

    if (MODE == "mode") {                                //If MODE == mode (For selecting a Protocol)
      while (Bluet.available() > 0) {                    //We are adding characters to letters Array until we have no more bytes
        letters[n] = char(Bluet.read());                 //Characters = The informaton received by the Module
        Serial.println("Byte rcvd = True");              //Just esthetic
        n++;

      }

      MODE = letters;                           //Once Array is completed, we equal our 'MODE' to the String of Array
      Serial.print("\n");
      Serial.print("Mode:");
      Serial.println (MODE);
      Serial.print("\n");

      if (!((MODE == "lights") || (MODE == "fan")))            //If our MODE is NOT a valid Protocol
        MODE = String ("mode");                                      //Then, ask again

      while (n >= 0) {
        letters[n] = '\0';        //Clear or Array
        if (n == 0)
          break;                    //Prevents our counter to get a negative value

        n--;
      }

      ///////////////////////////////////////////// ELSE's TURN ///////////////////////////////////////////

      //** IN THIS PART WE TAKE THE NUMBERS SENT AS CHARACTERS (char) DUE TO DIFFICULTIES WITH NUMBERS AND (int)'s **\\


    } else {                                        //If our MODE = A valid Protocol. Then
      while (Bluet.available() > 0) {                //We are adding characters to numbers Array until we have no more bytes
        numbers[num] = char(Bluet.read());            //Characters = The informaton received by the Module
        Serial.println("Byte rcvd = True");           //Just esthetic
        num++;

      }

      state = numbers;                             //Once Array is completed, we equal our 'state' to the String of Array
      Serial.print("\n");
      Serial.print("State:");
      Serial.println(state);
      Serial.print("\n");

      while (num >= 0) {
        numbers[num] = '\0';             //Clear or Array
        if (num == 0)
          break;                           //Prevents our counter to get a negative value

        num--;
      }

    }
  }

  ///////////////////////////////////////// SELECTION TIME ////////////////////////////////////////

  if (MODE != "mode")
  {
    if (MODE == "lights") {          //If our 'MODE' == "lights" we start the 1st Protocol
      //DESCRIPTION:
      //This protocol is made on Digital options, ON || OFF
      if (count == 0) {
        delay(300);
        digitalWrite (led, HIGH);       //Here we generate a Blinking Indicator to our protocol. 1st = 1 Blink
        delay(700);
        count = 1;
      }

      if (!((state == "0") || (state == "1"))) {        //If any option has been selected we remain in wait mode
        digitalWrite (led, HIGH);
        delay(100);
        digitalWrite (led, LOW);
        delay(900);
      }

      if (state == "0") {
        digitalWrite (rele, LOW);
        digitalWrite (boom, LOW);
      }

      if (state == "1") {
        digitalWrite (rele, HIGH);
        digitalWrite (boom, HIGH);
      }
    }


    else if (MODE == "fan") {           //If our 'MODE' == "detonator" we start the 2nd Protocol
      //DESCRIPTION:
      //This Protocol is made for "Remote Detonator", Once activated, it deactivates for avoiding possible
      //electrical fails in the components
      if (count == 0) {
        delay(300);
        digitalWrite (led, HIGH);
        delay(700);                            //Here we generate a Blinking Indicator to our protocol. 2nd = 2 Blinks
        digitalWrite (led, LOW);
        delay(200);
        digitalWrite (led, HIGH);
        delay(700);
        digitalWrite (led, LOW);

        count = 1;
      }


      if (!((state == "0") || (state == "1"))) {      //If any option has been selected we remain in wait mode
        digitalWrite (led, HIGH);
        delay(100);
        digitalWrite (led, LOW);
        delay(900);
      }

      if (state == "1") {
        digitalWrite (rele, HIGH);
        delay (1000);
        state = "0";
      }

      if (state == "0") {
        digitalWrite (rele, LOW);
      }
    }
    if (state == "mode") {
      MODE = String ("mode");
      count = 0;
      state = String('\0');
    }
  }
}
