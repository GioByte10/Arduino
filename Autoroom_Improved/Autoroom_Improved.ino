#define fan 2
#define light 3
#define desktop_light 4
#define motion_1 8
#define motion_2 9

//int mode = 0;                        // 1 = In the room     2 = Not in the room     3 = Night
int people = 1;
int once = 0;
int start = 0;
bool night = false;
bool nightLock = false;

void setup() {

  pinMode(motion_1, INPUT);
  pinMode(motion_2, INPUT);
  pinMode(6, INPUT);
  pinMode(fan, OUTPUT);
  pinMode(light, OUTPUT);
  pinMode(desktop_light, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);

}

void turnOff(){

  digitalWrite(fan, LOW);
  digitalWrite(light, LOW);
  digitalWrite(desktop_light, LOW);
  
}

void turnOn(){

  digitalWrite(fan, HIGH);
  digitalWrite(light, HIGH);
  digitalWrite(desktop_light, HIGH);
  
}

void turnNight(){

  digitalWrite(fan, HIGH);
  digitalWrite(light, LOW);
  digitalWrite(desktop_light, LOW);
  
}

void loop() {

  if(!nightLock){

    if(digitalRead(motion_1) == HIGH){
      if(digitalRead(motion_2) == HIGH){

        people--;
        if(people == 0){
          turnOff();
        }
      
     }
    
    }else if(digitalRead(motion_2) == HIGH){
      if(digitalRead(motion_1)){

        people++;
        turnOn();
        
      }   
    }
  }

  if(digitalRead(6) == HIGH){
    night = true;
  }


  if(night){
    if(once == 0){
      start = millis();
      once++;
    }

      if(millis() - start > 1200000){
        nightLock = true;
        turnNight();
      }

    while(nightLock){

      if(digitalRead(motion_2) == HIGH){
        turnOn();
        delay(5000);
        turnNight();
       }

      if(digitalRead(6) == LOW){
        night = false;
        nightLock = false;
        turnOn();
        once = 0;
        start = 0;
      }
      
    }
    
  }
}
