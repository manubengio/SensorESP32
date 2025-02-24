#ifndef _sr04_h_
#define _sr04_h_

#include <Arduino.h>
#include "leds.h"

#define TRIG_PIN 23  // Pin GPIO para TRIGa
#define ECHO_PIN 22  // Pin GPIO para ECHO


int Sense_distance(void);

#endif