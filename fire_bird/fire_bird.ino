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
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  
  
  
}
void speed(int left,int right)
{
  analogWrite(5,left);
  analogWrite(6,right); 
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
//int sensor_D;
//int sensor_E;
//int sensor_F;
//int sensor_G;
void setup() {
  // put your setup code here, to run once:
   pinConfig();
    Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
//   forward();
//   speed(127,127);
//   delay(3000);
//   speed(0,0);
//   reverse();
//   speed(127,127);
//   delay(3000);
//   speed(0,0);
//   delay(1000);
//     sensor_D = analogRead(A2);
//     sensor_E = analogRead(A3);
//     sensor_F = analogRead(A4);
//     sensor_G = analogRead(A5);
     Serial.println(analogRead(A2));
     
     if (analogRead(A2)< 500)
     {
     forward();
     speed(127,127);
     delay(1000);
    
     }
     else if(analogRead(A3)<500)
     {
      forward();
      speed(0,127);
      delay(1000);
     }
      else if(analogRead(A4)<500)
     {
      forward();
      speed(127,0);
      delay(1000);
     }
      else if(analogRead(A5)<500)
     {
      reverse();
      speed(127,127);
      delay(1000);
     }
     
     else{
     forward();
     speed(127,127);
     }

}
