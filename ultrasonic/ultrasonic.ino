void ultrasonicPinconfig()
{
  pinMode(3,OUTPUT);//TRIGGER PIN
  pinMode(4,INPUT);//Echo
  
}
void trigger()
{
  digitalWrite(3,1);
  delayMicroseconds(10); //10us delay
  digitalWrite(3,0);
}
void setup() {
  // put your setup code here, to run once:
  ultrasonicPinconfig();
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  trigger();
  int duration = pulseIn(4,1);
  int distance= (duration*0.034)/2; //0.000001*340*100=0.034
  Serial.println(distance);
  delay(100);
   
}
