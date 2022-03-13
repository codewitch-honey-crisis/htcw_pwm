#include <Arduino.h>
#include <pwm.hpp>
#include <gfx_cpp14.hpp>
using namespace arduino;
using namespace gfx;
pwm<5000,8,32> p;
void setup() {
  
  Serial.begin(115200);
}

void loop() {
  decltype(p)::pixel_type px;
  px.channelr<0>((rand()%100)/99.0);
  p.point({0,0},px);
  delay(200);
}