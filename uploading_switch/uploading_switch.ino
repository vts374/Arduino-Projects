#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
//Replace your wifi credentials here
const char* ssid = "ssid"; //Replace with your Wifi Name
const char* password = "password"; // Replace with your 
wifi 
WiFiClient client;
//---------Channel Details---------//
unsigned long Channel_Number = 1946674; // Channel ID
const char * Write_APIKey = "KC3V2GFL8OATW0QW"; // Read API Key
const int Field_1 = 1; // Field to read
int number = 0;
const int Switch_Pin = D1;
const int LED_Pin = D2;
int Switch_Current_State=0;
int Switch_Last_State=0;
int Status_Code = 0;
void setup()
{
pinMode(Switch_Pin, INPUT);
pinMode(LED_Pin, OUTPUT);
Serial.begin(9600);
WiFi.mode(WIFI_STA);
ThingSpeak.begin(client);
}
void loop() {
 //----------------- Network -----------------//
if (WiFi.status() != WL_CONNECTED)
{
 Serial.print("Connecting to ");
 Serial.print(ssid);
 Serial.println(" ....");
 while (WiFi.status() != WL_CONNECTED)
 {
 WiFi.begin(ssid, password);
 delay(3000);
 }
 Serial.println("Connected to Wi-Fi Succesfully.");
}
//---------------------------------------------//
Switch_Current_State = digitalRead(Switch_Pin);
Serial.println(Switch_Current_State);
if (Switch_Current_State != Switch_Last_State)
{
 if (Switch_Current_State == HIGH)
 {
 digitalWrite(LED_Pin, HIGH);
// Switch_Value = 1;
 Serial.println("Switch Released");
 
 } 
 else
 {
 digitalWrite(LED_Pin, LOW);
// Switch_Value = 0;
 Serial.println("Switch Pressed");
 }
 
 Status_Code = ThingSpeak.writeField(Channel_Number, Field_1 ,
Switch_Current_State , Write_APIKey);
 if(Status_Code == 200)
 {
 Serial.println("Channel Field_1 Update Successful.");
 }
 else
 {
 Serial.println("Problem updating channel. HTTP error code " +
String(Status_Code));
 }
 Switch_Last_State = Switch_Current_State ;
}
delay(3000); // Wait 20 seconds to update the channel again
}
