#include <Servo.h>

Servo servo1, servo2, servo3, servo4;
int fsrAnalog = 0;
int position = 0;

int p1, p2, p3, p4;
int t = 0;
int dt = 1;


void setup()
{
  Serial.begin(9600);
  servo1.attach(13);
  servo2.attach(12);
  servo3.attach(11);
  servo4.attach(10);
  
}

void loop()
{
  changeServos();
  delay(10);

  setServo(servo1, t % 180, "servo1:");
  setServo(servo2, (t - 100) % 180, "servo2:");
  setServo(servo3, (t - 200) % 180, "servo3:");
  setServo(servo4, (t - 300) % 180, "servo4:");
  
  t += dt;
  delay(10);
}

void setServo(Servo s, int p, String n) {
  if(p > 0) {
    s.write(p);
    Serial.println(n + " " + p);
  }
}


void changeT() {
  t += dt;
}

void changeServos(){
  servo1.write(p1);
  servo2.write(p2);
  servo3.write(p3);
  servo4.write(p4);
}

