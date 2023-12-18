#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);
#define LEDPIN 12
char tag[] = "5300292DD087";
//ReplacewithyourownTagID
char input[12];
//AvariabletostoretheTagIDbeingpresented
int count = 0;  // Acounter variable to navigate through the input[] characterarray
boolean flag = 0;
//AvariabletostoretheTagmatchstatus
void setup() {
  Serial.begin(9600);  // Initialise Serial Communication with the Serial Monitor
  mySerial.begin(9600);
  pinMode(LEDPIN, OUTPUT);  //WRONGTAGINDICATOR
}


void loop() {
  if (mySerial.available())  //Checkif there is incomingdata intheRFIDReaderSerial Buffer.
  {
    count = 0;  //Resetthecountertozero /*KeepreadingBytebyBytefromtheBuffer till theRFIDReaderBuffer is empty  ortill12Bytes(theIDsizeofourTag)isread*/
    while (mySerial.available() && count < 12) {
      input[count] = mySerial.read();  //Read1Byteofdataandstoreitintheinput[]variable
      Serial.write(input[count]);
      count++;
      delay(5);
    }
    /*Whenthecounterreaches12(thesizeoftheID)westopandcompareeach value   oftheinput[]tothecorrespondingstoredvalue*/
    if (count == 12)  //
    {
      count = 0;
      //resetcountervaribaleto0
      flag = 1; /*Iterate through each value and compare till either the 12values are 
    all matching or till the first mistmatchoccurs*/
      while (count < 12 && flag != 0) {
        if (input[count] == tag[count])
          flag = 1;
        //everytimethevaluesmatch,wesettheflagvariable to1
        else
          flag = 0;
        count++;  //incrementi
      }
    }
    if (flag == 1) {
      Serial.println("AccessAllowed!");
      digitalWrite(LEDPIN, HIGH);
      delay(2000);
      digitalWrite(LEDPIN, LOW);
    } else {
      Serial.println("AccessDenied");  //IncorrectTagMessage
      digitalWrite(LEDPIN, LOW);
      delay(2000);
    } /*Filltheinputvariablearraywithafixedvalue'F' tooverwrite allvaluesgettingit emptyforthenextreadcycle*/
    for (count = 0; count < 12; count++) {
      input[count] = 'F';
    }
    count = 0;  //Resetcountervariable
  }
}
