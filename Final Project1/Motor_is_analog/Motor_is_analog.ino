#include <Servo.h>

#define IRFR A0 // Analog pin for Front Right sensor
#define IRFM A1 // Analog pin for Front Middle sensor
#define IRFL A2 // Analog pin for Front Left sensor
#define IRR A3  // Analog pin for Right sensor
#define IRL A4  // Analog pin for Left sensor
#define MR 13    // Digital pin for Right Motor
#define ML 12    // Digital pin for Left Motor
#define C 4      // Digital pin for C button
#define B 5      // Digital pin for B button
#define OK 3     // Digital pin for OK button

Servo Gripper;

void setup() {
  pinMode(MR, OUTPUT);
  pinMode(ML, OUTPUT);
  pinMode(C, INPUT);
  pinMode(B, INPUT);
  pinMode(OK, INPUT);
  
  Gripper.attach(6);
  Serial.begin(9600);
}

void loop() {
  int SENFR = analogRead(IRFR);
  int SENFM = analogRead(IRFM);
  int SENFL = analogRead(IRFL);
  int SENR = analogRead(IRR);
  int SENL = analogRead(IRL);

  // Map sensor values to motor speeds (0 to 255)
  int motorSpeedR = map(SENFR, 0, 1023, 0, 255);
  int motorSpeedL = map(SENFL, 0, 1023, 0, 255);

  // Control motors based on sensor values and button states
  if (digitalRead(C) == HIGH || digitalRead(B) == HIGH) {
    if (SENFM < 1000 && SENFR > 900 && SENFL > 900 && SENR > 900 && SENL > 900) {
      analogWrite(MR, motorSpeedR);
      analogWrite(ML, motorSpeedL);
    } else if (SENFM > 1000 && SENFR > 900 && SENFL > 900 && SENR < 100 && SENL > 900) {
      analogWrite(MR, motorSpeedR / 2);
      analogWrite(ML, motorSpeedL);
    } else if (SENFM > 1000 && SENFR > 900 && SENFL > 900 && SENR > 900 && SENL < 100) {
      analogWrite(MR, motorSpeedR);
      analogWrite(ML, motorSpeedL / 2);
    } else {
      analogWrite(MR, 0);
      analogWrite(ML, 0);
    }

    if (SENFM < 1000 && SENFR > 900 && SENFL > 900 && SENR < 100 && SENL < 100) {
      if (digitalRead(C) == HIGH) {
        analogWrite(MR, motorSpeedR / 2);
        analogWrite(ML, motorSpeedL);
      } else if (digitalRead(B) == HIGH) {
        analogWrite(MR, motorSpeedR);
        analogWrite(ML, motorSpeedL / 2);
      }

      if (digitalRead(OK) == HIGH) {
        Gripper.write(180);
        delay(1000);
        analogWrite(MR, motorSpeedR);
        analogWrite(ML, motorSpeedL);
      } else {
        Gripper.write(0);
        delay(1000);
      }
    }
  }
}
