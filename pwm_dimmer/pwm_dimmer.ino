const int ledPin = D4; 
void setup() {
}
void loop() {
// increase the LED brightness
for(int dutyCycle = 0; dutyCycle < 255; dutyCycle++){ 
 // changing the LED brightness with PWM
 analogWrite(ledPin, dutyCycle);
 delay(2);
}
// decrease the LED brightness
for(int dutyCycle = 255; dutyCycle > 0; dutyCycle--){
 // changing the LED brightness with PWM
 analogWrite(ledPin, dutyCycle);
 delay(2);
}
}
