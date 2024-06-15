int sensor_A;
void forward()

{
  digitalWrite(10,0);
   digitalWrite(11,1); 
   digitalWrite(12,1);
    digitalWrite(13,0);
  
}
void reverse()
{
  digitalWrite(10,1);
   digitalWrite(11,0); 
   digitalWrite(12,0);
    digitalWrite(13,1);
}


void stop()

{
  digitalWrite(10,LOW);
   digitalWrite(11,LOW); 
   digitalWrite(12,LOW);
    digitalWrite(13,LOW);
  
}
void speed(int left,int right)
{
  analogWrite(5,left);
  analogWrite(6,right);
  delay(100);
}




void setup() {

  Serial.begin(9600);
  
  

pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);


}


void loop()
{
  
 for(int i=0;i<255;i=i+50)
 {
   forward();
   speed(50+i,50+i);
   delay(2000);
 }
}
