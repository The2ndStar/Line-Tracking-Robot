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
#define B 8     // Digital pin for B button

int speed =250;
void forwardslow (){
      digitalWrite(MR, HIGH);
      digitalWrite(MR_B, LOW);
      analogWrite(MR_EN, 150);
      digitalWrite(ML, HIGH);
      digitalWrite(ML_B, LOW);
      analogWrite(ML_EN, 150);
  }
void forward (){
      digitalWrite(MR, HIGH);
      digitalWrite(MR_B, LOW);
      analogWrite(MR_EN, speed);
      digitalWrite(ML, HIGH);
      digitalWrite(ML_B, LOW);
      analogWrite(ML_EN, speed);
  }
void right () {
      digitalWrite(ML,HIGH);
      digitalWrite(ML_B,LOW);
      analogWrite(ML_EN, speed);
      digitalWrite(MR,LOW);
      digitalWrite(MR_B,LOW);
      analogWrite(MR_EN,0);
  }
void left (){
      digitalWrite(MR, HIGH);
      digitalWrite(MR_B, LOW);
      analogWrite(MR_EN,speed);
      digitalWrite(ML,LOW);
      digitalWrite(ML_B,HIGH);
      analogWrite(ML_EN,50);
  }
void backward(){
      digitalWrite(MR, HIGH);
      digitalWrite(MR_B, LOW);
      analogWrite(MR_EN,50);
      digitalWrite(ML,LOW);
      digitalWrite(ML_B,HIGH);
      analogWrite(ML_EN,speed);
  }  
void moveServo(int angle) {
  // Convert the angle to a pulse width in microseconds
  int pulseWidth = map(angle, 0, 180, 1000, 2000);

  // Send the PWM signal to the servo
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(pulseWidth);
  digitalWrite(servoPin, LOW);

  // Wait for the servo to reach the desired position
  delay(17000);
} 
  

void setup() {
  
  pinMode(MR, OUTPUT);
  pinMode(ML, OUTPUT);
  pinMode(MR_EN, OUTPUT);
  pinMode(ML_EN, OUTPUT);
  pinMode(MR_B, OUTPUT);
  pinMode(ML_B, OUTPUT);
  pinMode(C, INPUT);
  pinMode(B, INPUT);
  pinMode(servoPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  
  int SENFR = analogRead(IRFR);
  int SENFM = analogRead(IRFM);
  int SENFL = analogRead(IRFL);
  int SENR = analogRead(IRR);
  int SENL = analogRead(IRL);
  int black = 500;
  int white = 150 ;
  int N = 1 ;
  int M = 1 ;
  int S =1 ;
  int O = 1 ;
  int P = 1 ;
  forward();
}
  
