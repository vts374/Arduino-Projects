const int sensorPin = 8;
const int ledPin = 10;
void setup() {
pinMode(sensorPin, INPUT);
pinMode(ledPin, OUTPUT);
}
void loop() {
int val = digitalRead(sensorPin);
if (val == HIGH) {
 digitalWrite(ledPin, LOW);
}
else {
 digitalWrite(ledPin, HIGH);
}
}
