void forward()

{
  digitalWrite(10,LOW);
   digitalWrite(11,HIGH); 
   digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
  
}
void stop()

{
  digitalWrite(10,LOW);
   digitalWrite(11,LOW); 
   digitalWrite(12,LOW);
    digitalWrite(13,LOW);
  
}
void left()
{
  digitalWrite(10,HIGH);
   digitalWrite(11,LOW); 
   digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
  
}
void right()
{
  digitalWrite(10,LOW);
   digitalWrite(11,HIGH); 
   digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
  
}
void speed(int left,int right)
{
  analogWrite(5,left);
 analogWrite(6,right);
  
}
void reverse()

{
  digitalWrite(10,HIGH);
   digitalWrite(11,LOW); 
   digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
  
}



void setup() {
 Serial.begin(9600); //baud rate
 
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);

}
int s=100;

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    int a=Serial.read();
    int up=Serial.read();
    
   
    
    Serial.println(a);
    if(a==97)
    {
      forward();
      speed(100,160);
      
      
    }
   else if(a==100)
    {
      forward();
      speed(160,100);
    }
   else if(a==119)
    {
      forward();
      speed(s,s);
      
    }
   else  if(a==115)
    {
      reverse();
      speed(s,s);
       
    }
  else  if(a==32)
    {
      speed(0,0);
    }
    else if(a==112)
    {
       
       s=s+50;
       if(s>255)
       {
        s=255;
       }
      // forward();
      speed(s,s);
       
    }
     else if(a==113)
    {
       
       s=s-50;
       if(s>255)
       {
        s=255;
       }
      // forward();
      speed(s,s);
       
    }
   
    
  }

}
