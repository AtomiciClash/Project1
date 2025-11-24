#include <MeMCore.h>

MeLineFollower lineFinder(PORT_2);

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

void setup()

{

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

    }

  else if (lineFinder.readSensor1()==1 && lineFinder.readSensor2()==0)

   {

     Serial.println("Sensor 1 on white and Sensor 2 on black");
     turnRight();
    }

  else if (lineFinder.readSensor1()==0 && lineFinder.readSensor2()==1)

    {

    Serial.println("Sensor 1 on Black and Sensor 2 on White");
      turnLeft();
    }
  else //(lineFinder.readSensor1()==1 && lineFinder.readSensor2()==1)

    {

    Serial.println("Sensor 1 on White and Sensor 2 on White");
    stop();
    }

delay(1000);

}