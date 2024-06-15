void speed(int left , int right){
  analogWrite(5,left);
  analogWrite(6,right);
}
void pinConfig()
{
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(5,OUTPUT); //pwm1
  pinMode(6,OUTPUT); //pwm2

}
void forward()
{
  digitalWrite(13,0);
  digitalWrite(12,1);
  digitalWrite(11,1);
  digitalWrite(10,0);
}
void reverse()
{
  digitalWrite(13,1);
  digitalWrite(12,0);
  digitalWrite(11,0);
  digitalWrite(10,1);
}
int l=150,r=150;

 void setup() {
  // put your setup code here, to run once:
  pinConfig();
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    int receive= Serial.read(); 
    Serial.println(receive);

    if(receive== 87)
    {
      forward();
      speed(l,r);
      
    }
    if(receive==83)
    {
      reverse();
      speed(l,r);
    }
    if(receive==65)
    {
      forward();
      speed(l,0);
      
    }
    if(receive==68)
    {
      reverse();
      speed(0,r);
    }
    if(receive==32)
    {
      speed(0,0);
      
    }
    else if(receive==78)
    {
      l=l+30;
      r=r+30;
      if(l>255){
        l=255;
        r=255;
      }
      speed(l,r);
      receive=0;
    }
    else if(receive==66)
    {
      l=l-20;
      r=r-20;
      speed(l,r);
      receive=0; 
      
    }

  }
}
