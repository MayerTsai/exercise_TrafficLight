#include <Arduino.h>
#include "my_signal.h"

const int G_pin = 2;
const int Y_pin = 3;
const int R_pin = 4;

int MY_LOOP = 0;
bool button = false; // 按鈕

#define _ROAD 3
int intersections = _ROAD;
traffic_light x[_ROAD];

int R_traffic = 0;
int G_traffic = 0;
int Y_traffic = 0;
int light_status = 0;         // 哪個路口綠燈 循環完+1
int intersections_status = 0; // 每次循環++
const int Y = 2;              // 黃燈時間
const int G = 5;              // 綠燈時間
int Y_Time = 0;
int G_Time = 0; // 綠燈狀態

void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < intersections; i++)
  {
    set_traffic_pin(&x[i], G_pin + i * 3, Y_pin + i * 3, R_pin + i * 3);
  }
}

void loop()
{
  // traffic_signal(intersections, x);
  Serial.println();
  Serial.println("--------------------------------------------------------");
  for (int i = 0; i < intersections; i++)
  {
    int state = my_light(i, Y_Time, light_status); // my_light = 0紅 1綠 2黃

    switch (state)
    {
    case 0:
      R_traffic = 1;
      G_traffic = 0;
      Y_traffic = 0;
      break;
    case 1:
      R_traffic = 0;
      G_traffic = 1;
      Y_traffic = 0;
      break;
    default:
      R_traffic = 0;
      G_traffic = 0;
      Y_traffic = 1;

      break;
    }
    digitalWrite(x[i].G_pin, G_traffic);
    digitalWrite(x[i].Y_pin, Y_traffic);
    digitalWrite(x[i].R_pin, R_traffic);

    Serial.print(x[i].G_pin);
    Serial.print("(");
    Serial.print(G_traffic);
    Serial.print(")-");

    Serial.print(x[i].Y_pin);
    Serial.print("(");
    Serial.print(Y_traffic);
    Serial.print(")-");

    Serial.print(x[i].R_pin);
    Serial.print("(");
    Serial.print(R_traffic);
    Serial.print(")\t");
  }

  G_Time++;
  if ((G_Time >= G) && (Y_Time <= Y)) // 綠燈時間5s
  {
    Y_Time++;
  }
  if (Y_Time > Y)
  {
    Y_Time = 0;
    G_Time = 0;
    light_status++;
    if (light_status >= intersections)
      light_status = 0;
  }

  delay(1000);
}
