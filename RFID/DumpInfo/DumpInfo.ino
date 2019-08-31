/*
 * ----------------------------------------------------------------------------
 * This is a MFRC522 library example; see https://github.com/miguelbalboa/rfid
 * for further details and other examples.
 * 
 * NOTE: The library file MFRC522.h has a lot of useful info. Please read it.
 * 
 * Released into the public domain.
 * ----------------------------------------------------------------------------
 * Example sketch/program which will try the most used default keys listed in 
 * https://code.google.com/p/mfcuk/wiki/MifareClassicDefaultKeys to dump the
 * block 0 of a MIFARE RFID card using a RFID-RC522 reader.
 * 
 * Typical pin layout used:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 *
 */

 #include <SPI.h>
 #include <MFRC522.h>

 #define RST 9
 #define SS  10

 MFRC522 RFID(SS, RST);
 

 void setup(){

  Serial.begin(9600);
  while(!Serial);
  SPI.begin();
  RFID.PCD_Init();
  RFID.PCD_DumpVersionToSerial();
  Serial.println("Scan PICC to see UID:");
 
 }

 void loop(){
  
  if (! RFID.PICC_IsNewCardPresent())
    return;

  if (! RFID.PICC_ReadCardSerial())
    return;

  //RFID.PICC_DumpToSerial(&(RFID.uid));

  for (byte i = 0; i < RFID.uid.size; i++){
    if (RFID.uid.uidByte[i] < 0x10){
      Serial.print(" 0");
    }else{
      Serial.print(" ");
    }

      Serial.print(RFID.uid.uidByte[i], HEX);
    
  }

  Serial.println(" ");
  RFID.PICC_HaltA();
  
}
