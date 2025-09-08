#include <stdio.h>
#include <Arduino.h>
#include "my_signal.h"
// #include "my_light.h"

// const int G_pin = 2;
// const int Y_pin = 3;
// const int R_pin = 4;
// int V_set;

// 使用標準 C 函式定義，並採用 my_signal.h 中更具描述性的參數名稱
int my_light(int current_intersection, int Y_time, int active_intersection)
{
  // 核心邏輯：判斷目前正在處理的路口，是否就是應該亮燈的那個路口
  if (current_intersection != active_intersection)
    return 0;
  else if (Y_time > 0)
    return 2; // 黃燈
  else
    return 1; // 綠燈 (Y_time 為 0 或 1)
}

void set_traffic_pin(traffic_light *ptr_light, int g, int y, int r)
{
  ptr_light->G_pin = g;
  ptr_light->Y_pin = y;
  ptr_light->R_pin = r;
  pinMode(g, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(r, OUTPUT);
}
