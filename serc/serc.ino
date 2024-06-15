int sensor_A;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //initialization of serial communication
  

}

void loop() {
  // put your main code here, to run repeatedly:
  sensor_A = analogRead(A0);
  Serial.println(sensor_A);
  delay(100);
  ;''''''''''''''''''''''''''''>

}
