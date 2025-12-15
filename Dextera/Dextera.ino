#include "tof.ino"
#include "touch.ino"

void setup() {
  tof_setup();
  touch_setup();
  delay(50);
}

void loop() {
  tof_loop();
  touch_loop();
  delay(50);
}