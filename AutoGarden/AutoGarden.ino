
// DS1302:  CE pin    -> Arduino Digital 2
//          I/O pin   -> Arduino Digital 3
//          SCLK pin  -> Arduino Digital 4
#include <DS1302.h>

DS1302 rtc(2, 3, 4); // Reset;  Data Sig;  Clock Sig;
//Time clk = rtc.getTime();
const int Rele_valve = 12;
String days;  //***********************************************
char test[25];

void setup()
{
  pinMode(Rele_valve, OUTPUT);
  pinMode(13, OUTPUT);

  
  rtc.halt(false);               //Set the clock to Run Mode
  rtc.writeProtect(true);        //Enables Time Writting protection
  

Serial.begin(9600);
  // The following lines can be commented out to use the values already stored in the DS1302
  //rtc.setDOW(THURSDAY);     // Set Day-of-Week  
  //rtc.setTime(20, 28, 30);     // Set the time (24hr format)
  //rtc.setDate(11, 11, 2018);   // Set the date 
  
  
  
}

void loop()
{

  
//  Serial.print(rtc.getTimeStr());
  Serial.print("    ");
//  Serial.println(rtc.getDOWStr());         

  
  //Serial.println(clk.hour);


  if (clk.hour == 4 && clk.min >= 0 && clk.min <= 10){
    digitalWrite(Rele_valve, HIGH);
    digitalWrite(13, HIGH);
  }
    else{
    digitalWrite(Rele_valve, LOW);
    digitalWrite(13, LOW);


  }
  
 
  delay (1000);
}
