const int ledPins[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < sizeof(ledPins) / sizeof(int); i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  randomLights();
  delay(1000);
}

void randomLights() {
  for (int led : ledPins) {
    long r = random(10);
    digitalWrite(led, (r > 5) ? HIGH : LOW);
  }
  
}

