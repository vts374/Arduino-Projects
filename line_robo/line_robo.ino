 void pinConfig()
{
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(5,OUTPUT); //pwm1
  pinMode(6,OUTPUT); //pwm2
  pinMode(A0,INPUT);
  pinMode(A2,INPUT);
  pinMode(A5,INPUT);
}
  void speed(int left,int right)
{
  analogWrite(5,left);
  analogWrite(6,right); 
}
  void forward()
{
  digitalWrite(13,1);
  digitalWrite(12,0);
  digitalWrite(11,0);
  digitalWrite(10,1);
}
 
void setup() {
  // put your setup code here, to run once:
   pinConfig();
   Serial.begin(9600);
}

   void loop() {
  // put your main code here, to run repeatedly:
    
   Serial.println( analogRead(A0)); //leftsensor
   Serial.println( analogRead(A1));//front
   Serial.println( analogRead(A3)); //rightsensor
   //forward
   if(analogRead(((A0)>200) && ((A1)<200 ) &&((A3)>200)) //B W B
   {
    forward();
    speed(127,127);
    
   }
   //left
   else if(analogRead(((A0)<200) && ((A1)>200 ) &&((A3)>200))   {
    forward();
    speed(90,127);
    
   }
   //right turn 
   else if (analogRead(((A0)>200) && ((A1)>200 ) &&((A3)<200)) //
   {
    forward();
    speed(127,90);
    
   }
   else{
    forward();
    speed(0,0);
    delay(300);
   }
   

}
