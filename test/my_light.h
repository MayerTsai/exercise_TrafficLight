#ifndef MY_LIGHT_H
#define MY_LIGHT_H

#include <stdio.h>
#include "my_signal.h"

#ifdef __cplusplus
extern "C"
{
#endif

  void traffic_signal(int road_count, traffic_light *ptr_light);

#ifdef __cplusplus
}
#endif

#endif