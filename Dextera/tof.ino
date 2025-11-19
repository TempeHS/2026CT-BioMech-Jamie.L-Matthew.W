#include "Seeed_vl53l0x.h"

VL53L0X sensor;

void tof_setup() {
  Serial.begin(9600);
  Wire.begin();

  Serial.println("VL53L0X test start");

  if (!sensor.init()) {
    Serial.println("ERROR: VL53L0X not found. Check I2C connection!");
    while (1);
  }
  sensor.setTimeout(500);
  Serial.println("VL53L0X initialized");
}

void tof_loop() {
  uint16_t distance = sensor.readRangeSingleMillimeters();

  if (sensor.timeoutOccurred()) {
    Serial.println("Timeout!");
  } else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" mm");
  }
  if (distance < 50) {
  Serial.print("Object detected closer than 50mm! Distance: ");
  Serial.print(distance);
  Serial.println(" mm");
}
delay(300);
}

