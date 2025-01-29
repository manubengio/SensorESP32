#ifndef _leds_h_
#define _leds_h_

#include <Arduino.h>

#define LEDG_PIN 4  // Pin GPIO para LED VERDE
#define LEDY_PIN 16  // Pin GPIO para LED AMARILLO
#define LEDR_PIN 17  // Pin GPIO para LED ROJO
#define BUZZER_PIN 5   // Pin para BUZZER


void Led_GYR(void);
void Sense_distance(void);


#endif