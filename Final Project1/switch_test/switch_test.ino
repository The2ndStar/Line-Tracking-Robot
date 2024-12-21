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
#define B 8
#define C 4     // Digital pin for C button
#define A 7      // Digital pin for B button
#define OK 13     // Digital pin for OK button
Servo Gripper;

void forward (){
      digitalWrite(MR, HIGH);
      digitalWrite(MR_B, LOW);
      analogWrite(MR_EN, 150);
      digitalWrite(ML, HIGH);
      digitalWrite(ML_B, LOW);
      analogWrite(ML_EN, 150);
  }
void right () {
      digitalWrite(ML,HIGH);
      digitalWrite(ML_B,LOW);
      analogWrite(ML_EN, 150);
      digitalWrite(MR,LOW);
      digitalWrite(MR_B,HIGH);
      analogWrite(MR_EN,50);
  }
void left (){
      digitalWrite(MR, HIGH);
      digitalWrite(MR_B, LOW);
      analogWrite(MR_EN,150);
      digitalWrite(ML,LOW);
      digitalWrite(ML_B,HIGH);
      analogWrite(ML_EN,50);
  }

void setup() {
  
  pinMode(MR, OUTPUT);
  pinMode(ML, OUTPUT);
  pinMode(MR_EN, OUTPUT);
  pinMode(ML_EN, OUTPUT);
  pinMode(MR_B, OUTPUT);
  pinMode(ML_B, OUTPUT);
  pinMode(A, INPUT);
  pinMode(C, INPUT);
  pinMode(B, INPUT);
  pinMode(OK, INPUT);

  //Gripper.attach(8);
  Serial.begin(9600);
}

void loop() {
  int black = 500;
  int white = 150 ;
  int SENFR = analogRead(IRFR);
  int SENFM = analogRead(IRFM);
  int SENFL = analogRead(IRFL);
  int SENR = analogRead(IRR);
  int SENL = analogRead(IRL);
  int N = 1 ;
  int M = 1 ;
  int S =1 ;
  int O = 1 ;
  int P = 1 ;

  char buff[99]; // Fix: Use square brackets for array declaration
  sprintf(buff, "Switch 1: %d, Switch 2: %d Switch 3: %d, Switch 4: %d", digitalRead(4),digitalRead(8),digitalRead(7)); // Fix: Use sprintf correctly
  
  Serial.println(buff);
 

}
  
