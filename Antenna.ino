/*
  Antenna.ino
  
  Created: October 14, 2020
  Author: Andrew Donatelli andrew@donatelli.net
  
  Uses a continuous servo to move an antenna on a rack and pinion with microswitch endpoints.
  
  https://www.thingiverse.com/thing:4619438
  https://youtu.be/BhXsyKlJ74U
  https://youtu.be/MdO_4W80xlg

*/
#include <Servo.h>

Servo antServo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int iEndpoint1 = 0;
int iEndpoint2 = 0;
int iUp = 0;
int iDown = 0;

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {

    iEndpoint1 = digitalRead(2);
    iEndpoint2 = digitalRead(3);

    iUp = digitalRead(5);
    iDown = digitalRead(6);
    Serial.println(iUp);
    if ((iEndpoint1 == 0 or iEndpoint2 == 0) and iUp !=0 and iDown !=0){
      antServo.detach();          
    }

    if (iUp == 0 ){
      antServo.attach(9); 
      antServo.write(180); 
    }

    if (iDown == 0 ){
      antServo.attach(9); 
      antServo.write(0); 
    }
   

   
 
  
}
