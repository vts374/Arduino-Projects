#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
//Replace your wifi credentials here
const char* ssid = "Vatsa"; //Replace with your Wifi Name
const char* password = "zxcvbnm7"; // Replace with your 

//---------Channel Details---------//
unsigned long Channel_Number = 1946674; // Channel ID
const char * Read_APIKey = "KC3V2GFL8OATW0QW"; // Read API Key
const int Field_1 = 1; // Field to read
const int Field_2 = 2; // Field to read
//-------------------------------//
int Status_Code = 0;
long LED_1_Value = 0;
long LED_2_Value = 0;
const int LED_Pin_1 = D1;
const int LED_Pin_2 = D2;
WiFiClient client;
void setup()
{
 pinMode(LED_Pin_1, OUTPUT);
 pinMode(LED_Pin_2, OUTPUT);
Serial.begin(9600);
WiFi.mode(WIFI_STA);
ThingSpeak.begin(client);
}
void loop()
{
//----------------- Network -----------------//
if (WiFi.status() != WL_CONNECTED)
{
 Serial.print("Connecting to ");
 Serial.print(ssid);
 Serial.println(" ....");
 while (WiFi.status() != WL_CONNECTED)
 {
 WiFi.begin(ssid, password);
 delay(5000);
 }
 Serial.println("Connected to Wi-Fi Succesfully.");
}
//led2

LED_1_Value = ThingSpeak.readLongField(Channel_Number, Field_1,
Read_APIKey);
Status_Code = ThingSpeak.getLastReadStatus();
if (Status_Code == 200)
{
 Serial.print("LED 1 = ");
 Serial.println(LED_1_Value);
 digitalWrite(LED_Pin_1,LED_1_Value );
}
else
{
 Serial.println("Unable to read channel / No internet connection");
}
delay(100);
//---------------------------------------------//
//---------------- For LED_2 ----------------//
LED_2_Value = ThingSpeak.readLongField(Channel_Number, Field_2,Read_APIKey);

Status_Code = ThingSpeak.getLastReadStatus();
if (Status_Code == 200)
{
 Serial.print("LED 2 = ");
 Serial.println(LED_2_Value);
 digitalWrite(LED_Pin_2,LED_2_Value);
}
else
{
 Serial.println("Unable to read channel / No internet connection");
}
delay(100);
//---------------------------------------------//
delay(5000); // To minimize number request over internet
}
