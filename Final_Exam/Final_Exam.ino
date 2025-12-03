
#include <Arduino.h>
#include <MeMCore.h>


MeDCMotor motor1(M1);
MeDCMotor motor2(M2);
MeRGBLed led(0,30); 
MeUltrasonicSensor ultraSonic(PORT_3);

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
 Serial.begin(9600);
 led.setpin(13);
pinMode(A7,INPUT);
 while(analogRead(A7) != 0);

}

void loop() {
  int tick = 0;
Serial.print("Distance: ");
  Serial.print(ultraSonic.distanceCm());
  Serial.println(" cm");
  delay(100);


if (ultraSonic.distanceCm() < 10){
  
if (tick == 0){
    turnLeft();
    delay(520);
    tick = tick + 1;
  } else if (tick == 1){
    turnRight();
    delay(520);
    tick = tick - 1;
}

}
forward();
}
