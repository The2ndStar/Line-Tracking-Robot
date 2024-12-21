
#include <Servo.h>
const int IRFR = A0 ; // Analog pin for Front Right sensor
const int IRFM = A1 ;// Analog pin for Front Middle sensor
const int IRFL = A2 ;// Analog pin for Front Left sensor
const int IRR  = A3 ; // Analog pin for Right sensor
const int IRL  = A4 ;  // Analog pin for Left sensor
#define MR 11 // Digital pin for Right Motor
#define MR_B 10
#define MR_EN 9
#define ML 6   
#define ML_B 5
#define ML_EN 3
#define C 4      // Digital pin for C button
#define B 12      // Digital pin for B button
#define OK 13     // Digital pin for OK button
Servo Gripper;

void setup() {
 pinMode(MR, OUTPUT);
  pinMode(ML, OUTPUT);
  pinMode(MR_EN, OUTPUT);
  pinMode(ML_EN, OUTPUT);
  pinMode(MR_B, OUTPUT);
  pinMode(ML_B, OUTPUT);
  pinMode(C, INPUT);
  pinMode(B, INPUT);
  pinMode(OK, INPUT);

  Gripper.attach(13);
  Serial.begin(9600);
  }

void loop() {
 /* if (digitalRead(OK) == HIGH){ //gripper 
        Serial.println("OK");
       */ Gripper.write(0);
        delay(1000);
        /*digitalWrite(MR, LOW);
        digitalWrite(ML, LOW);
        digitalWrite(ML_B,HIGH);
        digitalWrite(ML_B,HIGH);
        analogWrite(MR_EN,-200);
        analogWrite(ML_EN,-200);
     } else {
        Gripper.write(0);
        delay(1000);
     }
*/
}
