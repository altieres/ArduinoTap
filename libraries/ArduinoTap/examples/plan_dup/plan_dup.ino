#include <ArduinoTap.h>

void setup() {
#ifdef ARDUINO
  Serial.begin(9600);
#endif
}

void loop() {
  plan(42);
  plan(42);
  diag("We should never get here");
}

