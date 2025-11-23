#include <Wire.h>
#include <Adafruit_MPR121.h>

Adafruit_MPR121.h touchSensor = Adafruit_MPR121.h();

void touch_setup() {
  Serial.begin(9600);
  while (!Serial) { delay(10); }

  Serial.println("MRP121 touch sensor test")
  wire.begin();

  if (!cap.begin(0x5A)) {
    Serial.println("Error: Yo shi not working.");
    Serial.println("Run I2C scanner if needed.");
    while (true) delay (1000);
  }
  Serial.println("Yo shi is working");
}

uint16_t lastTouched = 0;

void touch_loop() {
  uint16_t touched = cap.touched();

  if (touched)
}