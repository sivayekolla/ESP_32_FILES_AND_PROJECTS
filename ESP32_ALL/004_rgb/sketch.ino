int pins[] = {35, 32, 33};  // list of pins
int numPins = 3;            // number of pins

void setup() {
  for (int i = 0; i < numPins; i++) {
    pinMode(pins[i], OUTPUT);   // set each pin as output
  }
}

void loop() {
  for (int i = 0; i < numPins; i++) {
    digitalWrite(pins[i], HIGH); // turn ON current pin
    delay(500);
    digitalWrite(pins[i], LOW);  // turn OFF current pin
    delay(500);
  }
}
