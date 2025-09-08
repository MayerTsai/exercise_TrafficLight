#include <Arduino.h>
#include <stdio.h>
#include "my_light.h"
#include "my_signal.h"

const int G_pin = 2;
const int Y_pin = 3;
const int R_pin = 4;

int MY_LOOP = 0;
bool button = false; // 按鈕

#define _ROAD 3
int intersections = _ROAD;
traffic_light x[_ROAD];
void setup()
{
  for (int i = 0; i < intersections; i++)
  {
    set_traffic_pin(&x[i], G_pin + i * 3, Y_pin + i * 3, R_pin + i * 3);
  }
}

void loop()
{
  traffic_signal(intersections, x);
  delay(1000);
}
