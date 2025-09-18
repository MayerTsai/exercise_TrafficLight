#include <stdio.h>
#include <Arduino.h>
#include "my_signal.h"

void set_traffic_pin(traffic_light *ptr_light, int g, int y, int r)
{
  ptr_light->G_pin = g;
  ptr_light->Y_pin = y;
  ptr_light->R_pin = r;
  pinMode(g, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(r, OUTPUT);
}

void set_traffic_state(traffic_light *x, int state)
{
  x->state = state;
  digitalWrite(x->R_pin, (state == RED) ? HIGH : LOW);
  digitalWrite(x->G_pin, (state == GREEN) ? HIGH : LOW);
  digitalWrite(x->Y_pin, (state == YELLOW) ? HIGH : LOW);
}
