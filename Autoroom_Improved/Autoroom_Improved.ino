#define fan 0
#define light 2
#define desktop_light 3
#define motion_1 8
#define motion_2 10

//int mode = 0;                        // 1 = In the room     2 = Not in the room     3 = Night
int people = 1;
int once = 0;
int motionCou = 0;
int start = 0;
bool night = false;
bool nightLock = false;

void setup() {

  Serial.begin(9600);

  pinMode(motion_1, INPUT);
  pinMode(motion_2, INPUT);
  pinMode(6, INPUT);          // Night INPUT
  
  pinMode(fan, OUTPUT);
  pinMode(light, OUTPUT);
  pinMode(desktop_light, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(12, OUTPUT);

  digitalWrite(13, LOW);      // Built-in LED
  
  digitalWrite(4, LOW);       // Desktop Light LOW
  digitalWrite(5, LOW);       // Night LOW
  
  digitalWrite(7, HIGH);      // Night HIGH
  digitalWrite(9, HIGH);      // Motion_1 HIGH
  digitalWrite(11, HIGH);     // Motion_2 HIGH
  digitalWrite(12, HIGH);     // Desktop Light HIGH

  turnOn();
    delay(90000);
  Serial.println("Ready...");
  
}

void turnOff(){

  Serial.println("Turning Off");

  digitalWrite(fan, LOW);
  digitalWrite(light, LOW);
  digitalWrite(desktop_light, LOW);
  
}

void turnOn(){

  Serial.println("Turning On");

  digitalWrite(fan, HIGH);
  digitalWrite(light, HIGH);
  digitalWrite(desktop_light, HIGH);
  
}

void turnNight(){

  Serial.println("Turning Night");

  digitalWrite(fan, HIGH);
  digitalWrite(light, LOW);
  digitalWrite(desktop_light, LOW);
  
}

void loop() {

  if(!nightLock){

    while(digitalRead(motion_1)){
      while(digitalRead(motion_2)){
        
        digitalWrite(13, HIGH);

        if(motionCou == 0){

          Serial.println("Getting Out");
          
          if(people != 0 && !(people < 0)){
            people--;
          }
        
          if(people == 0){
            turnOff();
          }
          
          motionCou++;
        }
      }
      
    motionCou = 0;
    digitalWrite(13, LOW);
    
    }while(digitalRead(motion_2)){
      while(digitalRead(motion_1)){
        
        digitalWrite(13, HIGH);
        
        if(motionCou == 0){        

          Serial.println("Getting In");

          people++;
          turnOn();
          motionCou++;
        
        }   
      }
    }
    motionCou = 0;
    digitalWrite(13, LOW);
  }

  

  if(digitalRead(6) && !night){
    night = true;

    for(int i = 0; i < 6; i++){
      digitalWrite(13, HIGH);
      delay(300);
      digitalWrite(13, LOW);
      delay(300);
      Serial.println(i);
    }
    
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

      if(digitalRead(motion_2)){
        turnOn();
        delay(5000);
        turnNight();
       }

      if(!digitalRead(6)){
        night = false;
        nightLock = false;
        turnOn();
        once = 0;
        start = 0;
      }
      
    }
    
  }
}
