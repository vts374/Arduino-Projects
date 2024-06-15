 void pinConfig()
{
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
//  pinMode(5,OUTPUT); //pwm1
//  pinMode(6,OUTPUT); //pwm2
  
  
}
//void speed(int left,int right)
//{
//  analogWrite(5,left);
//  analogWrite(6,right); 
//}

void forward()
{
  digitalWrite(13,1);
  digitalWrite(12,0);
  digitalWrite(11,0);
  digitalWrite(10,1);
}
void reverse()
{
  digitalWrite(13,0);
  digitalWrite(12,1);
  digitalWrite(11,1);
  digitalWrite(10,0);
}
void stop()
{
  digitalWrite(13,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
}

void rightTurn()
{
  digitalWrite(13,1);
  digitalWrite(12,0);
  digitalWrite(11,0);
  digitalWrite(10,0);
}
void leftTurn()
{
  digitalWrite(13,0);
  digitalWrite(12,1);
  digitalWrite(11,1);
  digitalWrite(10,1);
}

void setup() {
  // put your setup code here, to run once:
  
  pinConfig();


}

void loop() {
    forward();
    delay(3000);
    reverse();
    delay(3000);
    stop();
    



 
  
}
