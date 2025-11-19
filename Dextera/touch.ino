#include <Wire.h>
#include <Adafruit_MPR121.h>

Adafruit_MPR121.h touchSensor = Adafruit_MPR121.h();

void touch_setup() {
  serial.begin(9600);
  wire.begin();
    if (!)
}