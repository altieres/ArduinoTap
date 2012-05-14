#include <ArduinoTap.h>

void setup() {
#ifdef ARDUINO
  Serial.begin(9600);
#endif
}

void loop() {
  plan(2);
  nok(false);
  nok(0, "foo");
  done_testing();
}


