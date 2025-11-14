#include <Arduino.h>
#include <MeMCore.h>

//LOOOKOKOKOK
MeDCMotor motor1(M1);
MeDCMotor motor2(M2);


void forward() {
  motor1.run(100);
  motor2.run(100);
}

void backward() {
  motor1.run(-100);
  motor2.run(-100);
}

void turnRight(){
  motor1.run(100);
  motor2.run(-100);
}

void turnLeft(){
  motor1.run(-100);
  motor2.run(100);
}
void setup() {
  turnleft();
  
}

void loop() {
 
}
