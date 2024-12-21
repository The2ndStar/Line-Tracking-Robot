#include<Servo.h>
Servo myservo[8];
#define MR 11
#define MR_B 10
#define ML_EN 9
#define ML 6
#define ML_B 5
#define MR_EN 3
#define sensor 5
int S ;
int sensorValues[sensor];
float errors[sensor];
float integral[sensor];
float derivative[sensor];
float lastErrors[sensor];
int pin[sensor] = {A0, A1, A2, A3, A4};
int Min[sensor] = {32 ,30 , 30 ,32 , 34};
int Max[sensor] = {700 , 700,700 , 700 ,700}; 
int maxspeed = 255 ;
int basespeed = 200 ;
int MOTORPID;
int setpoint = 500;
int total,r,l = 0;
int MotorError = 0,lastMotorError = 0;
void right();
void left();
void go();
const float Kp = 1.2;
const float Ki = 0.1;
const float Kd = 0.5;


void setup() {
  Serial.begin(9600);
  pinMode(MR, OUTPUT);
  pinMode(ML, OUTPUT);
  pinMode(MR_B, OUTPUT);
  pinMode(ML_B, OUTPUT);
  pinMode(MR_EN, OUTPUT);
  pinMode(ML_EN, OUTPUT);
  motor(0,0);
}
void loop(){
  motor (100,100);

}

void SensorValues () {
   int sensorValues[sensor];
   for (int i = 0; i < sensor; i++) {
   sensorValues[i] = analogRead(pin[i]);
   Serial.println (sensorValues[i]);
   total += sensorValues[i];
   delay(1000);}
 }
void motor (int l , int r) {
  MotorError =  total-setpoint  ;
  Serial.print("Motor[i] : ");
  Serial.print(MotorError);
  l = maxspeed - MOTORPID;
  r = maxspeed + MOTORPID;

  r = constrain(r, -maxspeed, maxspeed);
  l = constrain(l, -maxspeed, maxspeed);
  

  if (r > 0) {
    digitalWrite(MR, HIGH);
    digitalWrite(MR_B, LOW);
  } else {
    digitalWrite(MR, LOW);
    digitalWrite(MR_B, HIGH);
  }analogWrite(9, abs(r));
  if (l>0){  
    digitalWrite(ML, HIGH);
    digitalWrite(ML_B, LOW);
  }else {
    digitalWrite(MR, LOW);
    digitalWrite(MR_B, HIGH);}
  analogWrite(3, abs(l));  
  lastMotorError = MotorError ; 
  }
 
void move(int a, int b, int c) {
  motor(a, b);
  delay(c);
}
void Diff() {
  for (int i = 0; i < sensor; i++) {
    // Calculate derivative
    derivative[i] = MotorError - lastMotorError;
    integral[i] += MotorError;
    // Calculate MOTORPID
    MOTORPID = Kp * MotorError + Ki * integral[i] + Kd * derivative[i];
    Serial.println(MOTORPID);
    delay(1000);
  }
}
