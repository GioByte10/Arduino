//Turning One a Ledd with a normally open switch

bool state =0;                      //HIGH or LOW?
int output = 0;                    //On or Off?
bool last = 0;                      //state
const int timer = 10;              //Time detect the peaks
const int button = 9;              //Declare button
int scount = 1;


 boolean blocker (int pin){          //Initialize a function
  int counter = 0;
  boolean stat;
  boolean lasts;

   do{ 
    stat = digitalRead (pin);       //Read if button pressed or not
    if (stat != lasts){              //Checking if the signal has passed the peaks
      
    counter = 0;                     //If peaks still there reset the count
    lasts = stat;
    }
    else{
    counter++;
    }
    
    
     delay (1);
    
    }while (counter < timer);         //While the time to detect have not passed

 Serial.println (stat);
   return stat;                      //It could be True of False, On or Off
 
 }

void setup() {
  pinMode (button, INPUT);             //Declare the pins
  pinMode (12, OUTPUT);
  Serial.begin(9600);

}

void loop() {

  state = digitalRead (button);         //Reading switch state

  if (state != last){

    if (blocker (button)){          //Call our Function
    output = 1 - output;  

    //Serial.println (output);          //If true;                             
    }
  }
  
  last = state;
  
                            //Then, On or Off

  if (output == 1)
    digitalWrite (12, HIGH);
    
  else
    digitalWrite (12, LOW);
  
}
