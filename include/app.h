#ifndef _app_h_
#define _app_h_

//--Includes
#include <Arduino.h>
#include "config.h"
#include "oled.h"
#include "sr04.h"
#include "leds.h"


//--Prototypes
void App_loop(void);
void generate_random_measures(void);

#endif