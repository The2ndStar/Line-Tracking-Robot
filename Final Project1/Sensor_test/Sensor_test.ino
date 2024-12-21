
#define IRFR A0 // Analog pin for Front Right sensor
#define IRFM A1 // Analog pin for Front Middle sensor
#define IRFL A2 // Analog pin for Front Left sensor
#define IRR A3  // Analog pin for Right sensor
#define IRL A4  // Analog pin for Left sensor
#define MR 13    // Digital pin for Right Motor
#define ML 12    // Digital pin for Left Motor
#define C 4      // Digital pin for C button
#define B 5      // Digital pin for B button
#define OK 3     // Digital pin for OK button
int black = 0;

void setup() {
  pinMode(MR, OUTPUT);
  pinMode(ML, OUTPUT);
  pinMode(C, INPUT);
  pinMode(B, INPUT);
  pinMode(OK, INPUT);

  Serial.begin(9600);
}

void loop() {
  int SENFR = analogRead(IRFR);
  int SENFM = analogRead(IRFM);
  int SENFL = analogRead(IRFL);
  int SENR = analogRead(IRR);
  int SENL = analogRead(IRL);
    
   SENFR = analogRead(IRFR); //Front Right sensor
   Serial.print("SENFR = ");
   Serial.println(SENFR);
   SENFM = analogRead(IRFM); //Front Right sensor
   Serial.print("SENFM = ");
   Serial.println(SENFM);
   SENFL = analogRead(IRFR); //Front Right sensor
   Serial.print("SENFL = ");
   Serial.println(SENFL);
   SENR = analogRead(IRR); //Front Right sensor
   Serial.print("SENR = ");
   Serial.println(SENR);
   SENL = analogRead(IRL); //Front Right sensor
   Serial.print("SENL = ");
   Serial.println(SENL);
   delay(1000);

}
   
