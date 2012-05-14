#include <ArduinoTap.h>

void setup() {
#ifdef ARDUINO
  Serial.begin(9600);
#endif
}

void loop() {
  skip_all("Goodbye");
  diag("We should never get here");
}


