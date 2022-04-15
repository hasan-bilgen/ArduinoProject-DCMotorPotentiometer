#include <DC_Motor.h>
DC_Motor motor(10,11,1);
int E1=3;
//int E2=3;
#define pot A0
float value;
float voltvalue=0;
float cnst=0.00488758553;
float lim1 = 2.3;
float lim2 = 2.7;
unsigned int s=20;

void setup() {
  Serial.begin(9600);
  pinMode(pot,INPUT); 
  pinMode(E1,OUTPUT);
}

void loop() {
 
 value = analogRead(pot);
             Serial.print("Your value is: ");
             Serial.println(value);
             delay(100);
 voltvalue=cnst*value;
 Serial.println(voltvalue);

if(voltvalue<lim2 && voltvalue >= 0.0) {
  //s = 20;
  digitalWrite(E1,1);
  Serial.println("x1");
  while(voltvalue<lim1 && voltvalue >= 0.0){
  Serial.println("x2");
  motor.set_speed(s);
  motor.forward_with_set_speed();
  value = analogRead(pot);
  voltvalue=cnst*value;
 //s=s-3.0;
  }
  
  Serial.println("x3");
  motor.motor_speed_zero();
  digitalWrite(E1,0);
  
}

else if(voltvalue>lim1 && voltvalue <= 5.0) {
 //s = 20;
  digitalWrite(E1,1);
  Serial.println("x4");
  while(voltvalue>lim2 && voltvalue <= 5.0){
    Serial.println("x5");
    motor.set_speed(s);
    motor.reverse_with_set_speed();
    value = analogRead(pot);
    voltvalue=cnst*value;
      Serial.println(s);

  //s=s-3.0;
  }
  Serial.println("x6");
   
  motor.motor_speed_zero();
  digitalWrite(E1,0);
}
else{
  Serial.println("x7");
  value = analogRead(pot);
  voltvalue=cnst*value;
  while(voltvalue >= lim1 && voltvalue <= lim2){
  Serial.println("x8");
  motor.stop_motor();
  digitalWrite(E1,0);
  value = analogRead(pot);
  voltvalue=cnst*value;
  }
  }
Serial.println("x9");
delay(50);
}
