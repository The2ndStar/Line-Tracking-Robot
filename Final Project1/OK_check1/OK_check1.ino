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
  Serial.println("Moving right motor backward");
  digitalWrite(MR, LOW);
  digitalWrite(MR_B, HIGH);
  analogWrite(MR_EN, 200);

  // Add a delay to observe the motor behavior
  delay(2000);

  // Stop the right motor
  Serial.println("Stopping right motor");
  digitalWrite(MR, LOW);
  digitalWrite(MR_B, LOW);
  analogWrite(MR_EN, 0);

  // Add a delay between movements
  delay(1000);
}
