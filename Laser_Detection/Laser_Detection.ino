#include<Wire.h>
#include <DS3231.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
DS3231 rtc(SDA, SCL);

void setup(){

  Serial.begin(9600);

  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  
  rtc.begin();
  lcd.begin();

  lcd.print("I do stuff");
  
  //rtc.setDOW(FRIDAY);          // Set Day-of-Week to SUNDAY
  //rtc.setTime(19, 31, 0);      // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(27, 11, 2020);   // Set the date to DD/MM/YY
 
}
void loop(){ 

  Serial.println(analogRead(A0));

  if (analogRead(A0) > 900)
    detected();
    
}

void detected(){

  lcd.setCursor(0,0);
  lcd.print("Person detected at ");
  
  lcd.setCursor(0,1);
  lcd.print(rtc.getTimeStr());

  while(true){
    
    lcd.backlight();
    delay(500);
    lcd.noBacklight();
    delay(200);
    
  }

  
  //lcd.print("Date: ");
  //lcd.print(rtc.getDateStr());
  //lcd.print(rtc.getMonthStr());
}
