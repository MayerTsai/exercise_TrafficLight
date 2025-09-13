#include <Arduino.h>
#include "my_signal.h"

const int G_pin = 2;
const int Y_pin = 3;
const int R_pin = 4;

#define _ROAD 3
int intersections = _ROAD;
traffic_light x[_ROAD];

const int Y = 2000;    // 黃燈時間
const int G = 5000;    // 綠燈時間
int current_light = 0; // 哪個路口綠燈 循環完+1
int current_state = 0;
unsigned long phase_start_time = 0;

void show_lights(int intersections, traffic_light *x);
void traffic_signal(int intersections, traffic_light *x);

void setup()
{
  for (int i = 0; i < intersections; i++)
    set_traffic_pin(&x[i], G_pin + i * 3, Y_pin + i * 3, R_pin + i * 3);
  for (int i = 0; i < intersections; i++)
    set_traffic_state(&x[i], RED);

  Serial.begin(9600);
  Serial.flush();
  Serial.println("Traffic Light Start");
}

void loop()
{
 
  traffic_signal(intersections, x);
}

void show_lights(int intersections, traffic_light *x)
{
  for (int i = 0; i < intersections; i++)
  {
    Serial.print(x[i].G_pin);
    Serial.print("(");
    Serial.print((x[i].state == GREEN) ? HIGH : LOW);
    Serial.print(")-");

    Serial.print(x[i].Y_pin);
    Serial.print("(");
    Serial.print((x[i].state == YELLOW) ? HIGH : LOW);
    Serial.print(")-");

    Serial.print(x[i].R_pin);
    Serial.print("(");
    Serial.print((x[i].state == RED) ? HIGH : LOW);
    Serial.print(")\t");
  }
  Serial.println();
}

void traffic_signal(int intersections, traffic_light *x)
{
  if (phase_start_time == 0)
  {
    phase_start_time = millis();
    current_state = GREEN;
    current_light = 0;
    set_traffic_state(&x[current_light], current_state);

    return;
  }

  unsigned long now = millis();
  for (int i = 0; i < intersections; i++)
  {
    if ((now - phase_start_time >= G) && (current_state == GREEN)) // 綠燈時間5s
    {
      //show_lights(intersections, x);
      current_state = YELLOW;
      set_traffic_state(&x[current_light], current_state);
    }
    else if ((now - phase_start_time >= G + Y) && (current_state == YELLOW))
    { 
      //show_lights(intersections, x);
      set_traffic_state(&x[current_light], RED);
      delay(200);
      current_light++;
      if (current_light >= intersections)
        current_light = 0;
      current_state = GREEN;
      //show_lights(intersections, x);
      set_traffic_state(&x[current_light], current_state);
      phase_start_time = now;
    }
  }
}
