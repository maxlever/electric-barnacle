

/**
   Servos
*/
#include <Servo.h>
int servoCount = 5;
Servo servo1, servo2, servo3, servo4, servo5;
Servo servos[5] = { servo1, servo2, servo3, servo4, servo5 };
int servoPins[5] = { 12, 8, 7, 4, 2 };
int servoRangeUpper[5] = { 80, 90, 100, 100, 100 };
int servoRangeLower[5] = { 40, 40, 60, 60, 60 };
int pos = 0;

/**
   LEDs
*/
int ledCount = 5;
const int ledPins[5] = { 10, 9, 6, 5, 3 };

/**
   sensor
*/
const int anPin = 1;
long anVolt, mm, inches;

/**
   communication
*/
#include <Wire.h>


void setup() {
  Serial.begin(9600);

  setupServos();
  setupLEDs();
  //  setupSensor();
  //  setupComm();

}

void setupServos() {
  for (int i = 0; i < servoCount; i++) {
    servos[i].attach(servoPins[i]);
    Serial.println(servoPins[i]);
    Serial.println(servos[i].read());
    servos[i].write(80);
  }
}

void setupLEDs() {
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

}

void loop() {
  //    read_sensor();
  //    print_range();
  //    if (inches > 20 && inches < 40) {

  //    }
  
  raiseCirra();
  delay(random(1, 450));
  retractCirra();
  delay(random(1, 200));

}

void loopServos() {

}

void writeServos(int pos) {
    for (int i = 0; i < servoCount; i++) {
      if (pos >= servoRangeLower[i] and pos <= servoRangeUpper[i]) {
        servos[i].write(pos);
      }
    }
}

void raiseCirra() {
  for (pos = 40; pos <= 100; pos += 1) {
    writeServos(pos);
    writeLights((pos - 40) * 4);
    delay(30);
  }
}
void lightCirra() {
  
}

void writeLights(int brightness) {
  for (int i = 0; i < ledCount; i++) {
    analogWrite(ledPins[i], brightness);
  }
}

void retractCirra() {
  for (pos = 100; pos >= 40; pos -= 1) {
    writeServos(pos);
    delay(30);
  }
}

void dimCirra() {
  
}

void read_sensor () {
  anVolt = analogRead(anPin);
  mm = anVolt * 5; //Takes bit count and converts it to mm 
  inches = mm / 25.4; //Takes mm and converts it to inches
}
void print_range () {
  Serial.println(inches);
}
