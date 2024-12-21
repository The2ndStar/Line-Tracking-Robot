#include<Servo.h>
Servo myservo[3];
#define dir1A 11
#define dir2A 10
#define pwmA 9
#define dir1B 3
#define dir2B 5
#define pwmB 6


#define sensor 5
int pin[sensor] = {A0, A1, A2, A3, A4};
int Min[sensor] = {32 ,30 , 30 ,32 , 34};
int Max[sensor] = {868 , 970 ,869 , 988 , 998};
unsigned long F[sensor];
int leftmotor, rightmotor, Integral = 0;
int error, last_error;
int Power_Motor;
int Position = 0;
int last_value = 0;
int maxspeed = 255 ;
int basespeed = 200 ;

void setup() {
  Serial.begin(9600);
  pinMode(dir1A, OUTPUT);
  pinMode(dir2A, OUTPUT);
  pinMode(pwmA, OUTPUT);
  pinMode(dir1B, OUTPUT);
  pinMode(dir2B, OUTPUT);
  pinMode(pwmB, OUTPUT);
  //    view();
  //    viewReadLine();
  delay(1000);
  Track(80, 0.035, 0.2);
  Move(90,90,200);
  Left();
  Track(80, 0.035, 0.2);
  //  motor(100, 100);
  //  delay(10000);
  motor(0, 0);
}

void loop() {

}

void viewReadLine() {
  while (1) {
    for (int i = 0; i < sensor; i++) {
      Serial.print(F[i]);
      Serial.print(",\t");
    }
    Serial.println(ReadLine(F));
  }
}
void view() {
  while (1) {
    for (int i = 0; i < sensor; i++) {
      Serial.print(analogRead(pin[i]));
      Serial.print('\t');
      Serial.print(',');
    }
    Serial.println(" ");
  }
}
void Move(int a, int b, int c) {
  motor(a, b);
  delay(c);
}
void motor(int l, int r) {
  l = (l * maxspeed) / 100;
  r = (r * 255) / 100;
  if (l == 0) {
    digitalWrite(dir1A, HIGH);
    digitalWrite(dir2A, HIGH);
    analogWrite(pwmA, 0);
  }
  else if (l > 0) {
    digitalWrite(dir1A, HIGH);
    digitalWrite(dir2A, LOW);
    analogWrite(pwmA, l);
  }
  else {
    digitalWrite(dir1A, LOW);
    digitalWrite(dir2A, HIGH);
    analogWrite(pwmA, -l);
  }
  if (r == 0) {
    digitalWrite(dir1B, HIGH);
    digitalWrite(dir2B, HIGH);
    analogWrite(pwmB, 0);
  }
  else if (r > 0) {
    digitalWrite(dir1B, HIGH);
    digitalWrite(dir2B, LOW);
    analogWrite(pwmB, r);
  }
  else {
    digitalWrite(dir1B, LOW);
    digitalWrite(dir2B, HIGH);
    analogWrite(pwmB, -r);
  }
}
void TrackNormal(int BaseSpeed, float Kp , float Kd) {
  Position = ReadLine(F);
  error = Position - 2000;
  Power_Motor = (Kp * error) + (Kd * (error - last_error));
  last_error = error;
  leftmotor = BaseSpeed + Power_Motor;
  rightmotor = BaseSpeed - Power_Motor;
  if (leftmotor > 100) leftmotor =  100;
  if (leftmotor <= 0) leftmotor = -10;
  if (rightmotor > 100) rightmotor = 100;
  if (rightmotor <= 0) rightmotor = -10;
  Move(leftmotor, rightmotor, 0);
}

void TrackTime(int BaseSpeed, float Kp, float Kd, int Timer) {
  unsigned long Last_Time =  millis();
  while ((millis() - Last_Time) <= Timer) {
    TrackNormal(BaseSpeed, Kp, Kd);
  }
}
void Track(int BaseSpeed, float Kp, float Kd) {
  ReadLine(F);
  while (F[0] < 200 || F[4] < 200) {
    TrackNormal(BaseSpeed, Kp, Kd);
  }
}
void Left() {
  Move(-100, 100, 100);
  Move(-80, 80, 0);
  ReadLine(F);
  while (F[0] < 200) {
    ReadLine(F);
  }
}

void Right() {
  Move(100, -100, 100);
  Move(80, -80, 0);
  ReadLine(F);
  while (F[4] < 200) {
    ReadLine(F);
  }
}
void readPrivate(unsigned long * sensorValues)
{
  unsigned char i, j;

  for (i = 0; i < sensor; i++) {
    sensorValues[i] = 0;
  }
  for (i = 0; i < sensor; i++)
  {
    sensorValues[i] = analogRead(pin[i]);
  }
}
void Read(unsigned long *sensorValues)
{
  int i;
  signed int x;
  readPrivate(sensorValues);
  for (i = 0; i < sensor; i++)
  {
    x = map(sensorValues[i], Min[i], Max[i], 0, 1000);
    if (x < 0)
      x = 0;
    else if (x > 1000)
      x = 1000;
    sensorValues[i] = x;
  }
}
int ReadLine(unsigned long *sensorValues) {
  int k;
  int on_line = 0;
  unsigned long avg = 0;
  unsigned int sum = 0;
  on_line = 0;
  Read(sensorValues);
  for (int i = 0; i < sensor; i++) {
    if (sensorValues[i] > 90) on_line = 1;
    if (sensorValues[i] > 50) {
      avg += sensorValues[i] * (i * 1000);
      sum += sensorValues[i];
    }
  }
  if (on_line == 0) {
    if (last_value < ((sensor - 1) * 1000) / 2) {
      return 0;
    }
    else {
      return (sensor - 1) * 1000;
    }
  }
  last_value = avg / sum;
  return last_value;
}

void servo(uint8_t ch, signed int angle) {
  if (ch == 1) {
    if (angle == -1) myservo[0].detach();
    else {
      if (!myservo[0].attached()) myservo[0].attach(8);
      myservo[0].write(angle);
    }
  }
  else if (ch == 2) {
    if (angle == -1) myservo[1].detach();
    else {
      if (!myservo[1].attached()) myservo[1].attach(9);
      myservo[1].write(angle);
    }
  }
  else if (ch == 3) {
    if (angle == -1) myservo[2].detach();
    else {
      if (!myservo[2].attached()) myservo[2].attach(10);
      myservo[2].write(angle);
    }
  }
}
