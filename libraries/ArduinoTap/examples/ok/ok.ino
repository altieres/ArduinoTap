#include <ArduinoTap.h>

void setup() {
#ifdef ARDUINO
  Serial.begin(9600);
#endif
}

void loop() {
  plan(2);
  ok(true);
  ok(1, "foo");
  done_testing();
}


