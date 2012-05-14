#include <ArduinoTap.h>

void setup() {
#ifdef ARDUINO
  Serial.begin(9600);
#endif
}

void loop() {
  plan(3);
  is(42, 42);
  is(42, 42,  "foo");

  todo("good reason");
  is(0, 42,  "not equals");

  done_testing();
}


