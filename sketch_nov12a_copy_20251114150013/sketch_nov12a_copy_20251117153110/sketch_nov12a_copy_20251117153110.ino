#include <Arduino.h>
#include <MeMCore.h>


MeDCMotor motor1(M1);
MeDCMotor motor2(M2);
MeRGBLed led(0,30); 

void forward() {
  motor1.run(-100);
  motor2.run(100);
  led.setColor(0,255,0);
  led.show();
}

void backward() {
  motor1.run(100);
  motor2.run(-100);
  led.setColor(0,255,0);
  led.show();
}

void turnRight(){
  motor1.run(-100);
  motor2.run(-100);
  led.setColor(0,255,0);
  led.show();
}

void turnLeft(){
  motor1.run(100);
  motor2.run(100);
  led.setColor(0,255,0);
  led.show();
}

void stop(){
  motor1.stop();
  motor2.stop();
  led.setColor(255,0,0);
  led.show();
}
void setup() {
 led.setpin(13);
pinMode(A7,INPUT);
 while(analogRead(A7) != 0);
 forward();
 delay(4900); // First straight
 stop();
 delay(3000);


 turnLeft(); // First right turn (Going backwards so it's left)
 delay(545);
 stop();
  delay(3000);


 backward(); // Backwards driving!
 delay(3900);
 stop();
  delay(3000);


 turnRight(); // Next Turn
 delay(540);
 stop();
  delay(3000);


 forward(); // Last straight
 delay(5100);
 stop();
  delay(3000);


  turnLeft(); // Turn for a flex
delay(1000);
stop();
}
void loop() {
 
}
