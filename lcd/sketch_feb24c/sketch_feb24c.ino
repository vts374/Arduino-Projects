void setup() {
  // put your setup code here, to run once:
   DDRD |= 0b11111111;
}

void loop() {
  // put your main code here, to run repeatedly:
   PORTD &= 0b00000000; //all LEDs off
   delay(300);
   for(int i=0; i<8; i++)
   {
    PORTD = 0b00010000>>i | 0b00001000<<i;// simultaneous blink from middle
    delay(300);
   }
}
