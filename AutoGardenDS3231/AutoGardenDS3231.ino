#include <DS3231.h>
DS3231 rtc(SDA, SCL);

int minut;
int hou;

const int Rele_valve = 12;

void setup(){

  pinMode(Rele_valve, OUTPUT);
  pinMode(13, OUTPUT);

//  rtc.halt(false);
  //rtc.writeProtect(false);

  Serial.begin(9600);
  rtc.begin();

  // The following lines can be commented out to use the values already stored in the DS1302
  //rtc.setDOW(THURSDAY);     // Set Day-of-Week  
  //rtc.setTime(1, 19, 00);     // Set the time (24hr format)
  //rtc.setDate(11, 11, 2019);   // Set the date 
   
  
}

void loop(){

  minut = (rtc.getTime().min >> 4) * 10 + (rtc.getTime().min & 0x0F);
  hou = (rtc.getTime().hour >> 4) * 10 + (rtc.getTime().hour & 0x0F);

  Serial.print("Time:   ");
  Serial.print(minut);
  Serial.print("   ");
  Serial.println(hou);
 

  if (hou == 1 && minut >= 30 && minut <= 50){
    digitalWrite(Rele_valve, HIGH);
    digitalWrite(13, HIGH);
  }else{
        digitalWrite(13, LOW);
        digitalWrite(Rele_valve, LOW);
  }
  
  delay(1000);

  
}
