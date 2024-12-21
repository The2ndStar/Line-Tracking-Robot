#include <Servo.h>

const int BUTTON_PIN = 12; 
const int SERVO_PIN  = 13;

int angle = 180;

Servo servo; 

void setup() 
{
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP); 
  servo.attach(SERVO_PIN);
}

void loop() 
{
  servo.write(0);
  delay(15);
  servo.write(180);
}
