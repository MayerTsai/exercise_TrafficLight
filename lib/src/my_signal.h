#ifndef MY_SIGNAL_H
#define MY_SIGNAL_H
#include <stdio.h>


const int RED = 0;
const int GREEN = 1;
const int YELLOW = 2;

typedef struct
{
  int G_pin;
  int Y_pin;
  int R_pin;
  int state; // 0: Red, 1: Green, 2: Yellow
} traffic_light;

void set_traffic_pin(traffic_light *x, int, int, int);
void set_traffic_state(traffic_light *x, int state);

#endif