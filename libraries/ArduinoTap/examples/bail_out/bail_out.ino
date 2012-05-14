#include <ArduinoTap.h>

void setup() {
#ifdef ARDUINO
  Serial.begin(9600);
#endif
}

void loop() {
  bail_out("Goodbye");
  diag("We should never get here");
}

