//0 = black,1=White raedbalck 2 cm
//motor 0-255


#include <Servo.h>
#define IRFR 11
#define IRFM 10
#define IRFL 9
#define IRR 8
#define IRL 7
#define MR 13
#define ML 12
#define C 4 
#define B 5
#define OK 3
Servo Gripper;

int SENFR = 0 ;
int SENFM = 0 ;
int SENFL = 0 ;
int SENR = 0 ;
int SENL = 0 ;
int stamp = 0 ;

void setup() {
  pinMode(IRFR,INPUT);
  pinMode(IRFL,INPUT);
  pinMode(IRFM,INPUT);
  pinMode(IRR,INPUT);
  pinMode(IRL,INPUT);
  pinMode(MR,OUTPUT);
  pinMode(ML,OUTPUT);
  pinMode(OK,INPUT);
  Gripper.attach(6);

  Serial.begin(9600);
}

void loop() {

   SENFR = digitalRead(IRFR); //Front Right sensor
   Serial.print("SENFR = ");
   Serial.println(SENFR);
   SENFM = digitalRead(IRFM);//Front Middle sensor
   Serial.print("SENFM = ");
   Serial.println(SENFM);
   SENFL = digitalRead(IRFR);//Front Left senser
   Serial.print("SENFL = ");
   Serial.println(SENFL);
   SENR = digitalRead(IRR);//Right sensor
   Serial.print("SENR = ");
   Serial.println(SENR);
   SENL = digitalRead(IRL);//Left sensor
   Serial.print("SENL = ");
   Serial.println(SENL);

      digitalWrite(MR,HIGH);
      digitalWrite(ML,HIGH);


//normal work

if (digitalRead(C),HIGH){
   if (SENFM == 0 && SENFR == 1 && SENFL ==1 && SENR == 1 && SENL ==1 )
   {
      digitalWrite(MR,HIGH);
      digitalWrite(ML,HIGH);
   }

     else if (SENFM == 1 && SENFR == 1 && SENFL ==1 && SENR == 0 && SENL == 1 ) // turn right

     {
      digitalWrite(MR,LOW);
      digitalWrite(ML,HIGH);
     }   
        else if (SENFM == 1 && SENFR == 1 && SENFL ==1 && SENR == 1 && SENL == 0 ) // turn left

     {
      digitalWrite(MR,LOW);
      digitalWrite(ML,HIGH);
     }   
     
     else if (SENFM == 0 && SENFR == 0 && SENFL ==0 && SENR == 0 && SENL == 0 ) //STOP

     {
      digitalWrite(MR,LOW);
      digitalWrite(ML,LOW);
     }   
    else if (SENFM == 1 && SENFR == 1 && SENFL ==1 && SENR == 1 && SENL == 1) //STOP

     {
      digitalWrite(MR,LOW);
      digitalWrite(ML,LOW);
     }   

    //T zone

      else if (SENFM == 0 && SENFR == 0 && SENFL == 0 && SENR == 1 && SENL == 1) //T zone Front meet black

     {
      digitalWrite(MR,HIGH);
      digitalWrite(ML,HIGH);
     }   

     else if (SENFM == 0 && SENFR == 1 && SENFL == 1 && SENR == 0 && SENL == 0) //T zone

     {
      digitalWrite(MR,HIGH);
      digitalWrite(ML,HIGH);
     }

       else if (SENFM == 1 && SENFR == 1 && SENFL ==1 && SENR == 0 && SENL == 0 ) //T zone turn right

     {
      digitalWrite(MR,LOW);
      digitalWrite(ML,HIGH);
     }   
      else if (SENFM == 0 && SENFR == 1 && SENFL ==1 && SENR == 1 && SENL == 1 ) // go to checkpoint c

     {
      digitalWrite(MR,LOW);
      digitalWrite(ML,HIGH);
       if (OK == HIGH ){ //electric
        Gripper.write(180); 
        delay(1000);
        digitalWrite(MR,HIGH);
        digitalWrite(ML,LOW);
          }
      else { // No electric
        Gripper.write(0);
        delay(1000);
        }
     }
  } 



  
   else if (digitalRead(B),HIGH){
   if (SENFM == 0 && SENFR == 1 && SENFL ==1 && SENR == 1 && SENL ==1 )
   {
      digitalWrite(MR,HIGH);
      digitalWrite(ML,HIGH);
   }

     else if (SENFM == 1 && SENFR == 1 && SENFL ==1 && SENR == 0 && SENL == 1 ) // turn right

     {
      digitalWrite(MR,LOW);
      digitalWrite(ML,HIGH);
     }   
        else if (SENFM == 1 && SENFR == 1 && SENFL ==1 && SENR == 1 && SENL == 0 ) // turn left

     {
      digitalWrite(MR,LOW);
      digitalWrite(ML,HIGH);
     }   
     
     else if (SENFM == 0 && SENFR == 0 && SENFL ==0 && SENR == 0 && SENL == 0 ) //STOP

     {
      digitalWrite(MR,LOW);
      digitalWrite(ML,LOW);
     }   
    else if (SENFM == 1 && SENFR == 1 && SENFL ==1 && SENR == 1 && SENL == 1) //STOP

     {
      digitalWrite(MR,LOW);
      digitalWrite(ML,LOW);
     }   

    //T zone

      else if (SENFM == 0 && SENFR == 0 && SENFL == 0 && SENR == 1 && SENL == 1) //T zone Front meet black

     {
      digitalWrite(MR,HIGH);
      digitalWrite(ML,HIGH);
     }   

     else if (SENFM == 0 && SENFR == 1 && SENFL == 1 && SENR == 0 && SENL == 0) //T zone

     {
      digitalWrite(MR,HIGH);
      digitalWrite(ML,HIGH);
     }

       else if (SENFM == 1 && SENFR == 1 && SENFL ==1 && SENR == 0 && SENL == 0 ) //T zone turn right

     {
      digitalWrite(MR,LOW);
      digitalWrite(ML,HIGH);
     }   
     
      else if (SENFM == 0 && SENFR == 0 && SENFL ==1 && SENR == 1 && SENL == 0 ) // go to checkpoint c

     {
      digitalWrite(MR,LOW);
      digitalWrite(ML,HIGH);

     } 
    else if (SENFM == 0 && SENFR == 1 && SENFL ==1 && SENR == 1 && SENL == 0 ) // go to checkpoint B
    {
      digitalWrite(MR,HIGH);
      digitalWrite(ML,LOW);

       if (OK == HIGH ){ //electric
        Gripper.write(180); 
        delay(1000);
        digitalWrite(MR,HIGH);
        digitalWrite(ML,LOW);
          }
      else { // No electric
        Gripper.write(0);
        delay(1000);
        }
    }


else {
  if (SENFM == 0 && SENFR == 1 && SENFL ==1 && SENR == 1 && SENL ==1 )
   {
      digitalWrite(MR,HIGH);
      digitalWrite(ML,HIGH);
   }

     else if (SENFM == 1 && SENFR == 1 && SENFL ==1 && SENR == 0 && SENL == 1 ) // turn right

     {
      digitalWrite(MR,LOW);
      digitalWrite(ML,HIGH);
     }   
        else if (SENFM == 1 && SENFR == 1 && SENFL ==1 && SENR == 1 && SENL == 0 ) // turn left

     {
      digitalWrite(MR,LOW);
      digitalWrite(ML,HIGH);
     }   
     
     else if (SENFM == 0 && SENFR == 0 && SENFL ==0 && SENR == 0 && SENL == 0 ) //STOP

     {
      digitalWrite(MR,LOW);
      digitalWrite(ML,LOW);
     }   
    else if (SENFM == 1 && SENFR == 1 && SENFL ==1 && SENR == 1 && SENL == 1) //STOP

     {
      digitalWrite(MR,LOW);
      digitalWrite(ML,LOW);
     }   

    //T zone

      else if (SENFM == 0 && SENFR == 0 && SENFL == 0 && SENR == 1 && SENL == 1) //T zone Front meet black

     {
      digitalWrite(MR,HIGH);
      digitalWrite(ML,HIGH);
     }   

     else if (SENFM == 0 && SENFR == 1 && SENFL == 1 && SENR == 0 && SENL == 0) //T zone

     {
      digitalWrite(MR,LOW);
      digitalWrite(ML,HIGH);
     }

     else if (SENFM == 0 && SENFR == 0 && SENFL == 0 && SENR == 1 && SENL == 1) //T zone Front meet black

     {
      digitalWrite(MR,HIGH);
      digitalWrite(ML,LOW);
     }   
     else if (OK == HIGH ){ //electric
        Gripper.write(180); 
        delay(1000);
        digitalWrite(MR,HIGH);
        digitalWrite(ML,LOW);
          }
      else { // No electric
        Gripper.write(0);
        delay(1000);
        }

  }
}

  
  
}  
