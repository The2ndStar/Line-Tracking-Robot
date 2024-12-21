#define C 4      // Digital pin for C button
#define B 8      // Digital pin for B button
#define A 7
#define OK 3     // Digital pin for OK button
#define MR 11
#define ML 6  
#define MR_EN 9
#define ML_EN 3
void setup() {

  pinMode(C, INPUT);
  pinMode(B, INPUT);
  pinMode(A, INPUT);
  pinMode(OK, INPUT);
  pinMode(MR, OUTPUT);
  pinMode(ML, OUTPUT); 
  pinMode(MR_EN, OUTPUT);
  pinMode(ML_EN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(C) == HIGH && digitalRead(A) == HIGH){
    Serial.println("C");
    digitalWrite(MR,HIGH);
    analogWrite(MR_EN,150);
    digitalWrite(ML,LOW);
    analogWrite(ML_EN,0);
    
  }
  else if (digitalRead(B) == HIGH && digitalRead(A) == HIGH) {
  Serial.println("B");
  digitalWrite(ML,HIGH);
  analogWrite(ML_EN,150);
      digitalWrite(MR,LOW);
    analogWrite(MR_EN,0);
  }
  else if ( digitalRead(A) == HIGH) {
  Serial.println("A");
  digitalWrite(ML,HIGH);
  digitalWrite(MR,HIGH);
  analogWrite(ML_EN,150);
  analogWrite(MR_EN,150);
  }
  else {
     Serial.println("ERROR");
  }
   delay(1000);
 
}
