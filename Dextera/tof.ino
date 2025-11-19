#include <Adafruit_VL53L0X.h>

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
  Serial.begin(9600);
  Wire.begin(); // I2C
  Serial.println("VL53L0X example");

  if (!lox.begin()) {
    Serial.println("ERROR: VL53L0X not found. Check I2C connection and address.");
    while (1) delay(1000);
  }
  Serial.println("VL53L0X initialized");
}

void loop() {
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false); // blocking single-shot

  if (measure.RangeStatus != 4) { // 4 = out of range
    Serial.print("Distance (mm): ");
    Serial.println(measure.RangeMilliMeter);
  } else {
    Serial.println("Out of range");
  }

  delay(200); // adjust sample rate as needed
}


void tof_loop() {
    VL53L0X_RangingMeasurementData_t RangingMeasurementData;
    VL53L0X_Error Status = VL53L0X_ERROR_NONE;

    memset(&RangingMeasurementData, 0, sizeof(VL53L0X_RangingMeasurementData_t));
    Status = VL53L0X.PerformSingleRangingMeasurement(&RangingMeasurementData);
    if (VL53L0X_ERROR_NONE == Status) {
        if (RangingMeasurementData.RangeMilliMeter >= 2000) {
            SERIAL.println("out of range!!");
        } else {
            SERIAL.print("Measured distance:");
            SERIAL.print(RangingMeasurementData.RangeMilliMeter);
            SERIAL.println(" mm");
        }
    } else {
        SERIAL.print("mesurement failed !! Status code =");
        SERIAL.println(Status);
    }

    delay(300);
}


