void pinConfig()
{
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(5,OUTPUT); //pwm1
  pinMode(6,OUTPUT); //pwm2
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A3,INPUT);
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
  int count=0;
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    
   Serial.println( analogRead(A0)); //leftsensor
   Serial.println( analogRead(A1));//front
   Serial.println( analogRead(A3)); //rightsensor
  //
   if((analogRead(A0)<50 && analogRead(A1)>50 && analogRead(A3)>50 && (count==0))
   {
     forward();
     speed(120,120);
     delay(200);
     speed(0,0);
     count ++;
     
   }
  
}
