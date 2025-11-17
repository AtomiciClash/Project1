#include <Arduino.h>
#include <MeMCore.h>


MeDCMotor motor1(M1);
MeDCMotor motor2(M2);


void forward() {
  motor1.run(-100);
  motor2.run(100);
}

void backward() {
  motor1.run(100);
  motor2.run(-100);
}

void turnRight(){
  motor1.run(-100);
  motor2.run(-100);
}

void turnLeft(){
  motor1.run(100);
  motor2.run(100);
}

void stop(){
  motor1.stop();
  motor2.stop();
}
void setup() {
pinMode(A7,INPUT);
 while(analogRead(A7) != 0);
 forward();
 delay(4600); // First straight
 stop();
 delay(500);


 turnLeft(); // First right turn (Going backwards so it's left)
 delay(515);
 stop();
  delay(500);


 backward(); // Backwards driving!
 delay(3900);
 stop();
  delay(500);


 turnRight(); // Next Turn
 delay(503);
 stop();
  delay(500);


 forward(); // Last straight
 delay(4500);
 stop();
  delay(500);


  turnLeft(); // Turn for a flex
delay(1000);
stop();
}
void loop() {
 
}
