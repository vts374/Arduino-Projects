#include <Arduino.h>
#include <LiquidCrystalIO.h>
#include <IoAbstractionWire.h>
#include <Wire.h>
LiquidCrystalI2C_RS_EN(lcd, 0x27, false)
const int sensorPin = 2;
const int ledPin = 10;
int cnt=0;
void setup() {
 Serial.begin(115200);
 pinMode(sensorPin, INPUT);
pinMode(ledPin, OUTPUT);
 Serial.println("Starting LCD example");
 // for i2c variants, this must be called first.
 Wire.begin();
 Serial.println("Configure LCD");
 lcd.begin(16, 2);
 lcd.configureBacklightPin(3);
 lcd.backlight();
 lcd.print("Counter: ");


}
void loop() {
 int val = digitalRead(sensorPin);
if (val == LOW) {
 cnt++;
}
 lcd.setCursor(0, 1);
 lcd.print(cnt);
 delay(1000);

}
