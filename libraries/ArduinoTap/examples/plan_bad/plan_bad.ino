#include <ArduinoTap.h>

void setup() {
#ifdef ARDUINO
  Serial.begin(9600);
#endif
}

void loop() {
  plan(5);
  pass("foo");
  pass("bad");
  done_testing();
}

