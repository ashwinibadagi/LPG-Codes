#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;  
LiquidCrystal lcd(12, 11, 5, 4, 13, 2); 
SoftwareSerial mySerial(9, 10);

int sensor=7;
int speaker=8;
int relay=6;
int gas_value,Gas_alert_val, Gas_shut_val;
int Gas_Leak_Status;
int sms_count=0;
int led=1;
void setup()
{

pinMode(sensor,INPUT);
pinMode(speaker,OUTPUT);
pinMode(relay,OUTPUT);
pinMode(led,OUTPUT);
mySerial.begin(9600);   
Serial.begin(9600);
lcd.begin(16,2);  
myservo.attach(3);  
delay(500);

}

void loop()
{
CheckGas();
CheckShutDown();
}

void CheckGas()
{

lcd.setCursor(0,0);
lcd.print("Gas Scan - ON");
Gas_alert_val=ScanGasLevel();
if(Gas_alert_val==LOW)
{
 SetAlert(); // Function to send SMS Alerts
}}

int ScanGasLevel()
{
gas_value=digitalRead(sensor); 

return gas_value; 
}

void SetAlert()
{
digitalWrite(speaker,HIGH); 
digitalWrite(relay,HIGH);  
digitalWrite(led,HIGH); 
lcd.setCursor(0,1);
lcd.print("Gas Leakage");

Serial.println("Gas Leakage");
for(pos = 180; pos>=10; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
while(sms_count<1) 
{  
  SendTextMessage(); 
}
Gas_Leak_Status=1; 

delay(1000);
}

void CheckShutDown()
{
if(Gas_Leak_Status==1)
{

Gas_shut_val=ScanGasLevel();
if(Gas_shut_val==HIGH)
{

lcd.setCursor(0,1);
lcd.print("No Gas Leak");

Serial.print("No Gas Leak");
digitalWrite(speaker,LOW);
digitalWrite(relay,LOW);
digitalWrite(led,LOW);
sms_count=0;
Gas_Leak_Status=0;
}}}

void SendTextMessage()
{
 curl -X POST  https://rest.nexmo.com/sms/json 
-d api_key=0665ff2b 
-d api_secret=b4080e7bd9707060 
-d to=919483723289 
-d from="LPG Detection System" 
-d text="Gas leaking"
 
}

