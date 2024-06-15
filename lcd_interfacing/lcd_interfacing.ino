  #include <LiquidCrystal.h>
  LiquidCrystal lcd(12,11,5,4,3,2);
  int sensor_v;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(A0,INPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor_v=analogRead(A0);
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Hello");
  delay(100);
}
