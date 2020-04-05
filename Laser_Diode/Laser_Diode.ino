void setup() {

  Serial.begin(9600);
  
}

void loop() {

  //Serial.println(analogRead(A0));
  
  if(analogRead(A0) < 50){
  Serial.println("     .... NO! ...                  ... MNO! ...");
  Serial.println("   ..... MNO!! ...................... MNNOO! ...");
  Serial.println(" ..... MMNO! ......................... MNNOO!! .");
  Serial.println("..... MNOONNOO!   MMMMMMMMMMPPPOII!   MNNO!!!! .");
  Serial.println(" ... !O! NNO! MMMMMMMMMMMMMPPPOOOII!! NO! ....");
  Serial.println("    ...... ! MMMMMMMMMMMMMPPPPOOOOIII! ! ...");
  Serial.println("   ........ MMMMMMMMMMMMPPPPPOOOOOOII!! .....");
  Serial.println("   ........ MMMMMOOOOOOPPPPPPPPOOOOMII! ...");
  Serial.println("    ....... MMMMM..    OPPMMP    .,OMI! ....");
  Serial.println("     ...... MMMM::   o.,OPMP,.o   ::I!! ...");
  Serial.println("         .... NNM:::.,,OOPM!P,.::::!! ....");
  Serial.println("          .. MMNNNNNOOOOPMO!!IIPPO!!O! .....");
  Serial.println("         ... MMMMMNNNNOO:!!:!!IPPPPOO! ....");
  Serial.println("           .. MMMMMNNOOMMNNIIIPPPOO!! ......");
  Serial.println("          ...... MMMONNMMNNNIIIOO!..........");
  Serial.println("       ....... MN MOMMMNNNIIIIIO! OO ..........");
  Serial.println("    ......... MNO! IiiiiiiiiiiiI OOOO ...........");
  Serial.println("  ...... NNN.MNO! . O!!!!!!!!!O . OONO NO! ........");
  Serial.println("   .... MNNNNNO! ...OOOOOOOOOOO .  MMNNON!........");
  Serial.println("   ...... MNNNNO! .. PPPPPPPPP .. MMNON!........");
  Serial.println("      ...... OO! ................. ON! .......");
  Serial.println("         ................................");
  Serial.println("\n\n\n\n\n\n");
    delay(2000);
  }

}
