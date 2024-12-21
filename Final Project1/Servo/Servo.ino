// Pin to which the servo is connected
int servoPin = 13; // You can use any PWM-enabled pin

void setup() {
  // Set the servo pin as an output
  pinMode(servoPin, OUTPUT);
}

void loop() {
  // Move the servo to the 0-degree position
  moveServo(0);
  delay(1000);

  // Move the servo to the 90-degree position
 // moveServo(90);
 // delay(1000);

  // Move the servo to the 180-degree position
  moveServo(0);                                                                                                                                                                                     0);
  delay(1000);
}

void moveServo(int angle) {
  // Convert the angle to a pulse width in microseconds
  int pulseWidth = map(angle, 0, 360, 1000, 2000);

  // Send the PWM signal to the servo
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(pulseWidth);
  digitalWrite(servoPin, LOW);

  // Wait for the servo to reach the desired position
  delay(20);
}
