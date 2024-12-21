const int IRFR = A0;
const int IRFM = A1;
const int IRFL = A2;
const int IRR  = A3;
const int IRL  = A4;
int black = 500;
int white = 100;
int speed = 80;
int SENFR = analogRead(IRFR);
int SENFM = analogRead(IRFM);
int SENFL = analogRead(IRFL);
int SENR = analogRead(IRR);
int SENL = analogRead(IRL);
int N = 1;
int S = 1;
int i = 1 ;
/*-------------------------------------Function--------------------------------------------*/
void C1();
void sensor();
void C3();
void forward();
void backward();
void left();
void right();
void STOP();
void OKfunc();
void left_s();
void right_s();
void moveServo(int angle);


/*--------------------------------------------------define pin--------------------------------------------------*/
#define MR 11
#define MR_B 10
#define MR_EN 9
#define ML 6   
#define ML_B 5
#define ML_EN 3
#define C 4
#define B 8
#define A 7
#define OK 12

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
  Serial.begin(9600);
}

/*---------------------------------------------------VOID LOOP----------------------------------------*/
void loop() {
  sensor();
  if (SENFM >= black) { //right
    forward();
  } else if (SENFR >= black) {
    right_s();
  } else if (SENFL >= black) {
    left_s();
  }  else if (SENL >= black) {
    left(); 
  }  else if (SENR >= black) {
    right();
  } else if (SENFM <= white && SENFL <= white && SENFR <= white && SENR >= black && SENL >= black) {
    right();
  } }
/*-----------------------------------FUNCTION C1----------------------------------------------------*/
void C1() { //left
  if (SENFM >= black) {
    forward();
    delay(3000);
    STOP();
  } else if (SENFR >= black) {
    right_s();
  } else if (SENFL >= black) {
    left_s();
  }  else if (SENL >= black) {
    left(); 
  }  else if (SENR >= black) {
    right();
  } else if (SENFM <= white && SENFL <= white && SENFR <= white && SENR >= black && SENL >= black) {
    left();
  } else if (SENFM >= black && SENFL >= black && SENFR >= black) {
    forward();
  } else if (SENFM >= black && SENFL >= black && SENFR >= black && SENR >= black && SENL >= black){
    backward();
    delay(1000);
    STOP();
  }
  }
/*------------------------------------------------ FUNCTION C2----------------------------------------*/
void C2(){
  if (SENFM >= black) { //right
    forward();
  } else if (SENFR >= black) {
    right_s();
  } else if (SENFL >= black) {
    left_s();
  }  else if (SENL >= black) {
    left(); 
  }  else if (SENR >= black) {
    right();
  } else if (SENFM <= white && SENFL <= white && SENFR <= white && SENR >= black && SENL >= black) {
    right();
  } else if (SENFM >= black && SENFL >= black && SENFR >= black) {
    forward();
  } else if (SENFM >= black && SENFL >= black && SENFR >= black && SENR >= black && SENL >= black){
    backward();
    delay(1000);
    STOP();
  }}
  /*----------------------------------------------- FUNCTION C3 ------------------------------------------*/
/*void C3() {
     if (SENFM >= black) {
     forward();
   } else if (SENFR >= black && SENR <= white) {
     right();
   } else if (SENFL >= black && SENL <= white) {
     left();
   } else if (SENFL >= black && SENFM >= black && SENFR >= black) {
     forward();
   } else if (SENFM <= white && SENFL <= white && SENFR <= white && SENR >= black && SENL >= black) {
     right();
   } else if (SENFL <= black && SENFR >= white && SENFM >= black) {
     if (S < 4) {
       forward();
       S++;
     } else if(S==4) {
       left();
       delay(500);
       IR();
       forward();
       delay(1500);
       OKfunc();
       delay(1500);
       moveServo(180);
       IR();
       backward();
       forward();
       delay (3000);
       S =S-1;
     }
   }else if (SENFM >= black && SENFL >=black && SENFR >=black  && SENR >= black && SENL >= black) {
     STOP();
     }}
  /*-------------------------------------------------Move--------------------------------------------------*/
void forward() {
  digitalWrite(MR, LOW);
  digitalWrite(MR_B,HIGH);
  analogWrite(MR_EN, speed);
  digitalWrite(ML,HIGH);
  digitalWrite(ML_B,LOW);
  analogWrite(ML_EN, speed);
}

void right() {
  digitalWrite(ML, HIGH);
  digitalWrite(ML_B, LOW);
  analogWrite(ML_EN, speed);
  digitalWrite(MR, LOW);
  digitalWrite(MR_B, HIGH);
  analogWrite(MR_EN, 0);
}


void left() {
  digitalWrite(MR, HIGH);
  digitalWrite(MR_B, LOW);
  analogWrite(MR_EN, speed);
  digitalWrite(ML, LOW);
  digitalWrite(ML_B, HIGH);
  analogWrite(ML_EN,0);
}

void left_s() {
  digitalWrite(MR, HIGH);
  digitalWrite(MR_B, LOW);
  analogWrite(MR_EN, 50);
  digitalWrite(ML, LOW);
  digitalWrite(ML_B,LOW);
  analogWrite(ML_EN,0);
}
void right_s() {
  digitalWrite(ML, HIGH);
  digitalWrite(ML_B, LOW);
  analogWrite(ML_EN, 50);
  digitalWrite(MR, LOW);
  digitalWrite(MR_B,LOW);
  analogWrite(MR_EN, 0);
}

void backward() {
  digitalWrite(MR, LOW);
  digitalWrite(MR_B, HIGH);
  analogWrite(MR_EN, speed);
  digitalWrite(ML, LOW);
  digitalWrite(ML_B, HIGH);
  analogWrite(ML_EN, speed);
}
void STOP() {
  digitalWrite(MR, LOW);
  digitalWrite(MR_B, LOW);
  analogWrite(MR_EN, 0);
  digitalWrite(ML, LOW);
  digitalWrite(ML_B, LOW);
  analogWrite(ML_EN, 0);
}
/*----------------------------------------------SERVO-----------------------------------------------*/
/*void moveServo(int angle) {
  int pulseWidth = map(angle, 0, 180, 1000, 2000);
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(pulseWidth);
  digitalWrite(servoPin, LOW);
  delay(17000);
}
*/
/*-------------------------------------------OKFUNC-------------------------------------------------*/

/*void OKfunc () {
  if ( digitalRead(OK) == HIGH) {
    Serial.println("A");
    moveServo(180);
  }
  else {
    Serial.println("ERROR");
    moveServo(0);
  }
}*/

/*------------------------------------------------IR SENSOR OFF-----------------------------------------------*/
void sensor() {
  SENFR = analogRead(IRFR); //Front Right sensor
  SENFM = analogRead(IRFM); //Front Right sensor
  SENFL = analogRead(IRFL); //Front Right sensor
  SENR = analogRead(IRR); //Front Right sensor
  SENL = analogRead(IRL); //Front Right sensor
  Serial.print("Sensors :");
  Serial.print(SENFR);
  Serial.print("  ");
  Serial.print(SENFM);
  Serial.print("  ");
  Serial.print(SENFL);
  Serial.print("  ");
  Serial.print(SENR);
  Serial.print("  ");
  Serial.print(SENL);
  Serial.print("  ");
  Serial.println(" ");


}
