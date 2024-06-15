const int trig = 2, echo = 3;
long duration, Distanceincm;
void setup() {
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);
pinMode(8, OUTPUT);
digitalWrite(8, HIGH);
}
void loop() {
digitalWrite(trig, HIGH);
delay(15);
digitalWrite(trig, LOW);
duration = pulseIn(echo, HIGH);
// The ultrasonic module is placed 20cm above from 1m tank.
Distanceincm = (duration / 58) - 20;
if (Distanceincm < 25) { // Above three quarter
 digitalWrite(11, HIGH);
}
else {
 digitalWrite(11, LOW); // Below three quarter
}
//
if (Distanceincm < 50) { // Above half level
 digitalWrite(10, HIGH);
}
else {
 digitalWrite(10, LOW); // Below half level
}
if (Distanceincm < 75) {
 digitalWrite(9, HIGH); // Above quarter level
}
else {
 digitalWrite(9, LOW); // Below quarter level
}
//Below quarter level, only LED at pin 8 will be ON.
}
