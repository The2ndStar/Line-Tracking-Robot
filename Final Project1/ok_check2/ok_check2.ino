const int IRFR = A0 ; // Analog pin for Front Right sensor
const int IRFM = A1 ;// Analog pin for Front Middle sensor
const int IRFL = A2 ;// Analog pin for Front Left sensor
const int IRR  = A3 ; // Analog pin for Right sensor
const int IRL  = A4 ;  // Analog pin for Left sensor
int servoPin = 13;
#define MR 11 // Digital pin for Right Motor
#define MR_B 10 
#define MR_EN 9
#define ML 6
#define ML_B 5
#define ML_EN 3
#define C 4      // Digital pin for C button
#define B 8      // Digital pin for B button
#define OK 12     // Digital pin for OK button
#define A 7
#define OK 12     // Digital pin for OK button
/*---------------------------------------------------------------------*/


void setup() {

  pinMode(servoPin, OUTPUT);  
  pinMode(OK, INPUT);
  Serial.begin(9600);
}

void loop() {
if ( digitalRead(OK) == HIGH) {
  Serial.println("A");
   moveServo(180);
   delay(1000);

  
  }
  else {
     Serial.println("ERROR");
      moveServo(0);
      delay(1000);
  }
}

void moveServo(int angle) {

  int pulseWidth = map(angle, 0, 360, 1000, 2000);

  digitalWrite(servoPin, HIGH);
  delayMicroseconds(pulseWidth);
  digitalWrite(servoPin, LOW);

  delay(20);
}
