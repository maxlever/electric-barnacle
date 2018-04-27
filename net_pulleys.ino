/**
 * pulleys
 * master
 */
#include <Wire.h>
#include <Servo.h>


const int height = 500;
const int width = 500;
const int SPACER = 100;

// dist of each point from center
float distances[5][5];
// max dist from center
float maxDistance;
// density of points
// time iterator
float k = 0;

// type of movement: twinkling, wavy, splashy, etc 
float twinkleSpeed = .5;
float twinkleDensity = .05;
float twinklePattern(int x, int y, float k) {
  // need to define noise
//  return noise((x + k) * twinkleDensity, (y+k)*twinkleDensity)*255;
}

float waveSpeed = 2;
float waveDensity = 20;
float wavePattern(int x, int y, float k) {
  return (.5 + sin((waveDensity * (distances[x][y] + k) / maxDistance)) / 2) * 180;
}

// servos
int servoCount = 25;
int servoRow = 5;
Servo servo1, servo2, servo3, servo4, servo5, servo6, servo7, servo8, servo9,
      servo10, servo11, servo12, servo13, servo14, servo15, servo16, servo17, 
      servo18, servo19, servo20, servo21, servo22, servo23, servo24, servo25;
      
Servo servos[25] = {
      servo1, servo2, servo3, servo4, servo5, 
      servo6, servo7, servo8, servo9, servo10, 
      servo11, servo12, servo13, servo14, servo15, 
      servo16, servo17, servo18, servo19, servo20, 
      servo21, servo22, servo23, servo24, servo25
};
  
const int servoPins[25] = {// FILL THIS IN WITH REAL VALUES
  52,50,48,46,44,
  42,40,38,36,34,
  32,30,28,26,24,
  53,51,49,47,45,
  43,41,39,37,35
};
int pos = 0;

//  leds
int ledCount = 12;
int ledRow = 5;
const int ledPins[12] = { // CHECK
  2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13
  };


void setupServos() {
  for (int i = 0; i < servoCount; i++) {
    servos[i].attach(servoPins[i]);
    servos[i].write(80);
  }
}



void setup() {
  setupLEDs();
  setupServos();
  setupDistances();
}

void loop() {
//  k = k - waveSpeed;
//  for (int y = 0; y < 5; y += 1) {
//    for (int x = 0; x < 5; x += 1) {
//      writeServo(x, y, max(0, 170+k));
//      delay(50);
//    }
//  }
  raiseNet();
  delay(random(1, 450));
  retractNet();
  delay(random(1, 200));
  
  writeLights(100);

}
// change light given x,y position
void writeLight(int x, int y, int brightness) {
  analogWrite(ledPins[y * ledRow + x], random(1, 200));
}

// change all lights given brightness
void writeLights(int brightness) {
  for (int i = 0; i < ledCount; i++) {
    analogWrite(ledPins[i], brightness);
  }
}

int phase = 0;
// change all servos given position
void writeServos(int pos) {
    int start = 0;
    int finish = servoCount;
    for (int i = start; i < finish; i++) {
      servos[i].write(pos);
    }
}

// change servo given x, y
void writeServo(int x, int y, int pos) {
  servos[y * servoRow + x].write(pos);
}

void raiseNet() {
  for (pos = 180; pos <= 0; pos += 1) {
    writeServos(pos);
    delay(15);
  }
}

void retractNet() {
  for (pos = 180; pos >= 0; pos -= 1) {
    writeServos(pos);
    delay(15);
  }
}


void setupLEDs() {
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

}
void setupDistances() {
  maxDistance = dist(width/2, height/2, width, height);
  for (int y = 0; y < 5; y += 1) {
    for (int x = 0; x < 5; x += 1) {
      float distance = dist(2.5, 2.5, x, y);
      distances[x][y] = distance / maxDistance * 180;

    }
  }
  for (int i = 0; i < 5; i++) {
       for (int j = 0; j < 5; j++) {
           Serial.print("  ");Serial.print(distances[i][j]);
       }
       Serial.println();
   }
  Serial.println();
}

float dist(float x1, float y1, float x2, float y2) {
  return float(sqrt(sq(x1 - x2) + sq(y1 - y2)));
}

