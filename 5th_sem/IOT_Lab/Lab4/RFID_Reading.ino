#include &lt;SoftwareSerial.h&gt; //Reading sinngle tag
SoftwareSerial mySerial(9, 10);
void setup()
{
  mySerial.begin(9600); // Setting the baud rate of Software Serial Library  
  Serial.begin(9600);  //Setting the baud rate of Serial Monitor
 }void loop()
{
    
 if(mySerial.available()&gt;0)
  {
  Serial.write(mySerial.read());
  }
}
