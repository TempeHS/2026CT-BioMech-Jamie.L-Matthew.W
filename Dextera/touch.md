I am trying to download the library installation but failed as all the libraries that I found are all outdated. I still have yet to find the library.

Progress:
Tried to make the sensors detect that something is touching the holes:

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

Code didn't work so I asked copilot for help