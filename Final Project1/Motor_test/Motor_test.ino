const int IRFR = A0;
const int IRFM = A1;
const int IRFL = A2;
const int IRR  = A3;
const int IRL  = A4;
int servoPin = 13;
int black = 500;
int white = 150;
int speed = 200;
int SENFR = analogRead(IRFR);
int SENFM = analogRead(IRFM);
int SENFL = analogRead(IRFL);
int SENR = analogRead(IRR);
int SENL = analogRead(IRL);
int N = 1;
int S = 1;
int i = 1 ;
void C1();
void C2();
void C3();
void forward();
void backward();
void left();
void right();
void STOP();
void OKfunc();
void IR();
void moveServo(int angle);
#define MR 11
#define MR_B 10
#define MR_EN 9
#define ML 6
#define ML_B 5
#define ML_EN 3
#define C 4
#define B 8
#define A 7
#define OK 13

/*--------------------------------------------------SETUP------------------------------------------------*/
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
  pinMode(servoPin, OUTPUT);
  Serial.begin(9600);
}
void loop(){
    if (SENFM >= black) {
    forward();
  }
  }
void forward() {
  digitalWrite(MR, HIGH);
  digitalWrite(MR_B, LOW);
  analogWrite(MR_EN, speed);
  digitalWrite(ML, HIGH);
  digitalWrite(ML_B, LOW);
  analogWrite(ML_EN, speed);
}

void right() {
  digitalWrite(ML, HIGH);
  digitalWrite(ML_B, LOW);
  analogWrite(ML_EN, speed);
  digitalWrite(MR, LOW);
  digitalWrite(MR_B, HIGH);
  analogWrite(MR_EN, 50);
}

void left() {
  digitalWrite(MR, HIGH);
  digitalWrite(MR_B, LOW);
  analogWrite(MR_EN, speed);
  digitalWrite(ML, LOW);
  digitalWrite(ML_B, HIGH);
  analogWrite(ML_EN, 50);
}

void backward() {
  digitalWrite(MR, LOW);
  digitalWrite(MR_B, HIGH);
  analogWrite(MR_EN, speed);
  digitalWrite(ML, LOW);
  digitalWrite(ML_B, HIGH);
  analogWrite(ML_EN, speed);
}
void STOP () {
  digitalWrite(MR, LOW);
  digitalWrite(MR_B, LOW);
  analogWrite(MR_EN, 0);
  digitalWrite(ML, LOW);
  digitalWrite(ML_B, LOW);
  analogWrite(ML_EN, 0);
}
/*----------------------------------------------SERVO-----------------------------------------------*/
void moveServo(int angle) {
  int pulseWidth = map(angle, 0, 180, 1000, 2000);
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(pulseWidth);
  digitalWrite(servoPin, LOW);
  delay(17000);
}

/*-------------------------------------------OKFUNC-------------------------------------------------*/

void OKfunc () {
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
void C1() {
  if (SENFM >= black) {
    forward();
  } else if (SENFR >= black) {
    right();
  } else if (SENFL >= black) {
    left();
  } else if (SENFL >= black && SENFM >= black && SENFR >= black) {
    forward();
  } else if (SENFM <= white && SENFL <= white && SENFR <= white && SENR >= black && SENL >= black) {
    right();
  } else if (SENFL <= white && SENFR >= black && SENFM >= black) {
    if (i < 2) {
      forward();
      OKfunc();
      delay(1500);
      moveServo(180);
      backward();
      forward();
      delay (3000);
    } else {
      forward();
    }
  } else if (SENFL >= black && SENFM >= black && SENFR >= white) {
    left();
  } else if (SENFM >= black && SENFL >= black && SENFR >= black  && SENR >= black && SENL >= black) {
    STOP();
  }
}
