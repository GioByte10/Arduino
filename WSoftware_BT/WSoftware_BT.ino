  const int LED = 13;
  const int Btooth = 12;

  char BtoothName[11] = "MasterSlave10";
  char pin[5] = "3510";
  char sp = '4';
  char mode = '0';
  
void setup() {
  pinMode (LED, OUTPUT);
  pinMode (Btooth, OUTPUT);

  Serial.begin (38400);

  digitalWrite (LED, HIGH);
  delay (4000);
  digitalWrite (LED, LOW);
  
  digitalWrite (Btooth, HIGH);

  Serial.print ("AT\r\n");

  Serial.print ("AT+NAME:");
  Serial.print (BtoothName);
  Serial.print ("\r\n");

  Serial.print ("AT+PIN:");
  Serial.print (pin);
  Serial.print ("\r\n");

  Serial.print ("AT+BAUD:");
  Serial.print (sp);
  Serial.print ("\r\n");

  Serial.print ("AT+MODE:");
  Serial.print (mode);
  Serial.print ("\r\n");

  digitalWrite (LED, HIGH);
}

void loop() {
  

}
