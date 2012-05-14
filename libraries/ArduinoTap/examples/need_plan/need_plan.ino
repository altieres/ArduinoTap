#include <ArduinoTap.h>

void setup() {
#ifdef ARDUINO
  Serial.begin(9600);
#endif
}

void loop() {
  pass("foo");
  diag("We should never get here");
}


