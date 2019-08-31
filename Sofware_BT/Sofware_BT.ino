   //Code for setup and configuration of a HC-05                       ~By Giovanni Bernal
   //Arduino Bluetooth module

#include <SoftwareSerial.h>                                            //BEFORE CONNECTING the module to +5, run the code and, if your module has a button, keep it pressed and
//                                                                        connect to +5 while pressing

 SoftwareSerial Bluetooth (11, 10); //Tx & Rx of Module
 const int LED = 13;               //Declare a LED indicator
//                                                                    Once the code is running and the module is slowly blinking open the Serial monitor    ********      Up in the corner

//                                                                    CONFIGURATION IN SERIAL PANEL:     IF AT FIRST NOT WORKS, do not worry, try with other commands and it 
//                                                                                                       will work with the time

//                                                                    Write in the Monitor with 9600 BAUD and with "Both NL & CR"
//                                                                    AT = OK
//                                                                    AT +NAME:________ (Show or change the name)
//                                                                    AT +PSWD:________ (Show or change PIN)
//                                                                    AT +UART:________ (Show or change speed. It should be in 9600,0,0)
//                                                                    AT +ROLE:________ (Show or change role. Master - Slave)
void setup() {                                       
  pinMode (LED, OUTPUT);           //Declare Output
  
 Serial.begin(9600);               //Declare the monitor

 while (!Serial){                  //For Leonard's
  ;
 }
 Bluetooth.begin(38400);            //Bluetooth modules are configured at this speed


 Serial.println("Configuration");            //A print indicator

}

void loop() {
  if (Bluetooth.available())                
    Serial.write(Bluetooth.read());
                                            //For transmition and reception of data trough Arduino and Computer
  if (Serial.available())
    Bluetooth.write(Serial.read());

}
