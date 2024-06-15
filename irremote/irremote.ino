#include "IRremote.h"
int receiver = 11; // Signal Pin of IR receiver to Arduino Digital Pin 11
IRrecv irrecv(receiver); // create instance of 'irrecv'
decode_results results; // create instance of 'decode_results'
void setup() 
{
Serial.begin(9600);
Serial.println("IR Receiver Button Decode"); 
irrecv.enableIRIn(); 
}
void loop() 
{
if (irrecv.decode(&results)) 
{
 translateIR(); 
 irrecv.resume();
} 
}
void translateIR() 
{
 Serial.print("IR CODE: ");
 Serial.println(results.value,HEX);
 Serial.print("DECODED VALUE: ");
 switch(results.value)
 { 
 case 0x1FE48B7: Serial.println(" POWER"); break;
 case 0x1FE58A7: Serial.println(" MODE"); break;
 case 0x1FE7887: Serial.println(" MUTE"); break;
 case 0x1FE807F: Serial.println(" PAUSE"); break; 
 case 0x1FEC03F: Serial.println(" FORWARD"); break; 
 case 0x1FE40BF: Serial.println(" REVERSE"); break;
 case 0x1FE20DF: Serial.println(" EQ"); break; 
 case 0x1FEA05F: Serial.println(" VOL-"); break;
 case 0x1FE609F: Serial.println(" VOL+"); break; 
 case 0x1FEE01F: Serial.println(" 0"); break; 
 case 0x1FE906F: Serial.println(" U/SD"); break; 
 case 0x1FE10EF: Serial.println(" RPT"); break;
 case 0x1FE50AF: Serial.println(" 1"); break;
 case 0x1FED827: Serial.println(" 2"); break;
 case 0x1FEF807: Serial.println(" 3"); break;
 case 0x1FE30CF: Serial.println(" 4"); break;
 case 0x1FEB04F: Serial.println(" 5"); break;
 case 0x1FE708F: Serial.println(" 6"); break;
 case 0x1FE00FF: Serial.println(" 7"); break;
 case 0x1FEF00F: Serial.println(" 8"); break;
 case 0x1FE9867: Serial.println(" 9"); break;
 default:
 Serial.println(" other button ");
 }
 Serial.println();
 delay(500); 
} 
