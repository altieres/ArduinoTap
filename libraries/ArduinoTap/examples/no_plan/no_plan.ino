#include <ArduinoTap.h>

void setup() {
#ifdef ARDUINO
  Serial.begin(9600);
#endif
}

void loop() {
  no_plan();
  ok(true, "foo");
  done_testing(1);
}


