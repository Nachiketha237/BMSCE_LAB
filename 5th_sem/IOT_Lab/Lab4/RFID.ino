#include<SoftwareSerial.h> 

SoftwareSerialmySerial(9,10); 
int count=0;                     //count=0 
charinput[12];                    //characterarrayofsize12 
booleanflag=0;                   //flag=0 
void setup() {   
  Serial.begin(9600);                 //beginserialportwithbaudrate9600bps   
  mySerial.begin(9600); 
} 

voidloop() 
{   
  if(mySerial.available())
  {      
    count=0;      
    while(mySerial.available()&&count<12)     //Read12charactersandstorethemin inputarray      
    {         
      input[count]=mySerial.read();         
      count++;         
      delay(5);      
    }      
    
    Serial.print(input);              //PrintRFIDtagnumber                
  } 
}
