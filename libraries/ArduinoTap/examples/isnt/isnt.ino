#include <ArduinoTap.h>

void setup() {
#ifdef ARDUINO
  Serial.begin(9600);
#endif
}

void loop() {
  plan(3);
  isnt(-42, 42);
  isnt(-42, 42,  "foo");

  todo("good reason");
  isnt(42, 42,  "equals");

  done_testing();
}


