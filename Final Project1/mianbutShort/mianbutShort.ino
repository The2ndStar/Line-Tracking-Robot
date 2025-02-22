// black < 40,white <1000

#include <Servo.h>

#define IRFR A0 // Analog pin for Front Right sensor
#define IRFM A1 // Analog pin for Front Middle sensor
#define IRFL A2 // Analog pin for Front Left sensor
#define IRR A3  // Analog pin for Right sensor
#define IRL A4  // Analog pin for Left sensor
#define MR 13 // Digital pin for Right Motor
#define MR_EN 11 
#define ML 12    // Digital pin for Left Motor
#define ML_EN 10
#define C 4      // Digital pin for C button
#define B 5      // Digital pin for B button
#define OK 3     // Digital pin for OK button

Servo Gripper;

void setup() {
  pinMode(MR, OUTPUT);
  pinMode(ML, OUTPUT);
  pinMode(MR_EN, OUTPUT);
  pinMode(ML_EN, OUTPUT);
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
  int N = 1 ;

  SENFR = analogRead(IRFR); //Front Right sensor
   Serial.print("SENFR = ");
   Serial.println(SENFR);
   SENFM = analogRead(IRFM);//Front Middle sensor
   Serial.print("SENFM = ");
   Serial.println(SENFM);
   SENFL = analogRead(IRFL);//Front Left senser
   Serial.print("SENFL = ");
   Serial.println(SENFL);
   SENR = analogRead(IRR);//Right sensor
   Serial.print("SENR = ");
   Serial.println(SENR);
   SENL = analogRead(IRL);//Left sensor
   Serial.print("SENL = ");
   Serial.println(SENL);

  if (digitalRead(C) == HIGH || digitalRead(B)== HIGH) {
    if (SENFM > 40 && SENFR > 40 && SENFL > 40 || SENR < 40 || SENL < 40 ){
      digitalWrite(ML, LOW);
      digitalWrite(ML_EN, 0);
    } else if (SENFM < 40 && SENFR < 40 && SENFL > 40 && SENR > 40 && SENL > 40 ){//pass C1 
      digitalWrite(MR, LOW);
      digitalWrite(MR_EN, 0);
    } else if (SENFM < 40 || SENFL < 40 || SENL < 40){
      digitalWrite(MR, HIGH);
      digitalWrite(MR_EN, 200);
    } else if (SENFM > 40 && SENFR > 40 && SENFL > 40 && SENR > 40 && SENL < 40 ){
      digitalWrite(ML, HIGH);
      digitalWrite(ML_EN, 200);
    } else if (SENFM < 40 && SENFR > 40 && SENFL < 40 && SENR > 40 && SENL < 40 ){//pass C1 
      digitalWrite(ML, LOW);
      digitalWrite(ML_EN, 0 );
    } else if (SENFM < 40 || SENFR < 40 || SENR < 40){
      digitalWrite(ML, HIGH);
      digitalWrite(ML_EN, 200 );
    } else if (SENFM < 40 && SENFR < 40 && SENFL < 40 && SENR > 40 && SENL > 40) {
      digitalWrite(ML, LOW);
      digitalWrite(ML_EN, 0); 
    } else {
      digitalWrite(MR, LOW);
      digitalWrite(ML, LOW);
      digitalWrite(MR_EN, 0); 
      digitalWrite(ML_EN, 0); 
    }
  }  
 else if (digitalRead(C) == LOW && digitalRead(B)== LOW) {
   if (SENFM < 40 && SENFR > 40 && SENFL > 40 && SENR > 40 && SENL > 40){// go straight 
      digitalWrite(MR, HIGH);
      digitalWrite(ML, HIGH);
      digitalWrite(MR_EN,200);
      digitalWrite(ML_EN,200);
    }
   else if (SENFM < 40 && SENFR < 40 && SENFL < 40 && SENR > 40 && SENL > 40){
        digitalWrite(MR, HIGH);
        digitalWrite(MR_EN,200);
     switch (N) {
     case 1:
     case 3:
         digitalWrite(ML, HIGH);
         digitalWrite(ML_EN,200);
         N = N+1;   
         break;
     case 2:
        digitalWrite(ML, LOW);
        digitalWrite(ML_EN,0);
        N = N+1;
        break;
     }
     
    }else if (SENFM > 40 && SENFR > 40 && SENFL > 40 && SENR <40 && SENL >40 ){//Nor right 
        digitalWrite(MR, HIGH);
        digitalWrite(ML, HIGH);
        digitalWrite(MR_EN,200);
        digitalWrite(ML_EN,200);  
    }else if (SENFM > 40 && SENFR > 40 && SENFL > 40 && SENR > 40 && SENL < 40 ){//Nor left
        digitalWrite(MR, HIGH);
        digitalWrite(ML, LOW);
        digitalWrite(MR_EN,200);
        digitalWrite(ML_EN,0);  
    }
    
     if (digitalRead(OK) == HIGH){ //gripper 
        Gripper.write(180);
        delay(1000);
        digitalWrite(MR, HIGH);
        digitalWrite(ML, HIGH);
        digitalWrite(MR_EN,-200);
        digitalWrite(ML_EN,-200);
     } else {
        Gripper.write(0);
        delay(1000);
     }
 }
}
