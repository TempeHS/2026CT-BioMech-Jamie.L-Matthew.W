void setup(){
  tof_setup();
  touch_setup();
}

void loop(){
  tof_loop();
  touch_loop();
  delay(67);
}