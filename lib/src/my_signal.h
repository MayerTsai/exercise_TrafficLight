#include <stdio.h>
#ifndef MY_SIGNAL_H
#define MY_SIGNAL_H

#ifdef __cplusplus
extern "C"
{
#endif

  typedef struct
  {
    int G_pin;
    int Y_pin;
    int R_pin;
  } traffic_light;

  // 決定單一號誌的狀態
  // 回傳 0 代表紅燈, 1 代表綠燈, 2 代表黃燈
  // current_intersection: 我們正在檢查的號誌索引 (例如 0, 1, 2...)
  // active_intersection:  應該亮綠燈或黃燈的號誌索引
  // Y_time:                 用於控制黃燈狀態的計時器
  int my_light(int current_intersection, int active_intersection, int Y_time);
  void set_traffic_pin(traffic_light *x, int, int, int);

#ifdef __cplusplus
}
#endif
#endif