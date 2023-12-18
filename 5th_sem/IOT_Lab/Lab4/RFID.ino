#include<SoftwareSerial.h> 

SoftwareSerial mySerial(9,10); 
int count=0;                     //count=0 
char input[12];                    //characterarrayofsize12 
boolean flag=0;                   //flag=0 
void setup() {   
  Serial.begin(9600);                 //beginserialportwithbaudrate9600bps   
  mySerial.begin(9600); 
} 

void loop() 
{   
  if(mySerial.available())
  {      
    count=0;      
    while(mySerial.available() && count<12)     //Read12charactersandstorethemin inputarray      
    {         
      input[count]=mySerial.read();         
      count++;         
      delay(5);      
    }      
    
    Serial.print(input);              //PrintRFIDtagnumber                
  } 
}
