#include <MeMCore.h>

MeDCMotor motor1(M1);
MeDCMotor motor2(M2);
MeLineFollower lineFinder(PORT_2);
MeRGBLed led(0,30); 
 void forward() {
  motor1.run(-80);
  motor2.run(80);
  led.setColor(0,255,0);
  led.show();
}

void backward() {
  motor1.run(80);
  motor2.run(-80);
  led.setColor(0,255,0);
  led.show();
}

void turnRight(){
  motor1.run(-80);
  motor2.run(0);
  led.setColor(0,255,0);
  led.show();
}

void turnLeft(){
  motor1.run(0);
  motor2.run(80);
  led.setColor(0,255,0);
  led.show();
}

void stop(){
  motor1.stop();
  motor2.stop();
  led.setColor(255,0,0);
  led.show();
}

void setup()

{
pinMode(A7,INPUT);
 while(analogRead(A7) != 0);
 
  Serial.begin(9600);

}

 

//black = blue light off = 0

//white = blue light on = 1

 

void loop()

{

 

  if (lineFinder.readSensor1()==0 && lineFinder.readSensor2()==0)

    {

      Serial.println("Sensor 1 on black and Sensor2 on black");
      forward();
      delay(1);
      //stop();

    }

  else if (lineFinder.readSensor1()==1 && lineFinder.readSensor2()==0)

   {

     Serial.println("Sensor 1 on white and Sensor 2 on black");
     stop();
     turnRight();
     delay(1);
     //stop();
    }

  else if (lineFinder.readSensor1()==0 && lineFinder.readSensor2()==1)

    {

    Serial.println("Sensor 1 on Black and Sensor 2 on White");
      stop();
      turnLeft();
      delay(1);
      //stop();
     
    }
  else //(lineFinder.readSensor1()==1 && lineFinder.readSensor2()==1)

    {

    Serial.println("Sensor 1 on White and Sensor 2 on White");
      backward();
      delay(1);
      //stop();
    }



}