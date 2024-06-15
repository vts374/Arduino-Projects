
  #include<Servo.h>
  Servo myservo;
  
void setup() {
//  put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(A0,OUTPUT);
//  to rotate
    myservo.attach(9);
    
//    myservo.write(90);
//    delay(5000);
//    myservo.write(0);


}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(A0));
   if(analogRead(A0)<500)
    {
      myservo.write(90);
    }
    else
    {
      myservo.write(0);
    }

//  to understand pwm motor
//  forward
//  for(int i=0;i<255;i++)
//  {
//    analogWrite(9,i);
//  delay(50);
//  }
 
//  backward
//   for(int i=255;i>0;i--)
//  {
//    analogWrite(9,i);
//  delay(100);
//  }

//    for(int pos=0;pos<180;pos++)
//    {
//      myservo.write(pos);
//      delay(15);
//    }
//    delay(1000);
//  
//      for(int pos=0;pos<180;pos+=45)
//    {
//      myservo.write(pos);
//      delay(150);
//    }
//     delay(5000);
//    
  

}
