#include <Wire.h>
#include <Adafruit_MPR121.h>

Adafruit_MPR121 cap;

void setup() {
  Serial.begin(115200);
  delay(1000);

  Wire.begin();
  if (!cap.begin(0x5A)) {  // check init (0x5A is common MPR121 address)
    Serial.println("MPR121 not found, check wiring");
    while (1)
      delay(1000);
  }
  Serial.println("stuff is initialized");
}

uint16_t lastTouched = 0;

void loop() {
  uint16_t touched = cap.touched();

  if (touched != lastTouched) {
    Serial.print("Touched pads: ");
    bool any = false;
    for (uint8_t i = 0; i < 12; i++) {
      if (touched & (1 << i)) {
        if (any)
          Serial.print(", ");
        Serial.print(i);
        any = true;
      }
    }
    if (!any)
      Serial.print("none");
    Serial.println(" stop touching me");
    lastTouched = touched;
  }

  delay(100);
}