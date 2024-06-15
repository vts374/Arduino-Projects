#include<LiquidCrystal.h>
//LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
LiquidCrystal lcd(12,11,5,4,3,2);
int temp_value;

void setup() {
  // put your setup code here, to run once:
    lcd.begin(16,2);
    pinMode(A0,INPUT);
    pinMode(8,OUTPUT);
    pinMode(9,OUTPUT);
    lcd.print("Hurrey!");
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.scrollDisplayLeft();
  delay(500);
  temp_value= analogRead(A0)/2;
  lcd.setCursor(0,1);
  lcd.print(temp_value);
  delay(100);
//  lcd.print(analogRead(A0));
//  if(analogRead(A0)<500)
//  {
//    digitalWrite(8,HIGH); //LED ON
//    delay(100);
//  }
//  else
//  {
//     digitalWrite(8,LOW); //LED OFF
//     delay(100);
//  }
//  delay(100);

//  if(analogRead(A0)<100)
//  {
//    digitalWrite(8,1);
//  }
//  else if(analogRead>100 && analogRead<300)
//  {
//     digitalWrite(8,1);
//  }
//  else
//  {
//     digitalWrite(8,0);
//  }
//  delay(100);
//
//  if(analogRead(A5)<500)  //for connection in A5
//  {
//       digitalWrite(9,0);
//       digitalWrite(8,1);
//       delay(100);
//       digitalWrite(8,0);
//       delay(100);
////  }
////  else
////  {
////    
//       digitalWrite(9,1);
//       digitalWrite(8,0);
//       delay(100);
//       digitalWrite(8,1);
//       delay(100);
}
