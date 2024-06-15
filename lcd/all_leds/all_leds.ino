void setup() {
  // put your setup code here, to run once:
  DDRD |= 0b11111111; //all pins of PORTD o/p

}

void loop() {
  // put your main code here, to run repeatedly:
  
//  PORTD |=  0b11111111; //all led on
//  delay(500);
  PORTD &= 0b00000000; //all LEDs off
  delay(500);
  //for shift in forward dirn
//  for(int i=0;i<8; i++)
//  {
//    PORTD &= 0b00000001<<i;
//    delay(500);
//  }

 // for shift in backward dirn
for(int i=7;i>=8; i--)
  {
    PORTD &= 0b00000001<<i;
    delay(500);
  }

}
