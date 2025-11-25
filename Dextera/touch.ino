#include <Wire.h>
#include <Adafruit_MPR121.h>

Adafruit_MPR121 cap; // correct constructor

void touch_setup() {
  Serial.begin(9600);
  while (!Serial) { delay(10); }

  Serial.println("MPR121 touch sensor test");
  Wire.begin();

  if (!cap.begin(0x5A)) {
    Serial.println("Yo shi ain't working");
    Serial.println("Run I2C scanner if needed.");
    while (true) delay(1000);
  }
  Serial.println("Yo shi is now working");
}

uint16_t lastTouched = 0;

void touch_loop() {
  uint16_t touched = cap.touched();

  if (touched != lastTouched) {
    Serial.print("Touched pads: ");
    bool any = false;
    for (uint8_t i = 0; i < 12; i++) {
      if (touched & (1 << i)) {
        Serial.print(i);
        Serial.print(" ");
        any = true;
      }
    }
    if (!any) Serial.print("none");
    Serial.println();
    lastTouched = touched;
  }

  delay(100);
}
