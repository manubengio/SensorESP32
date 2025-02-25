//=======================================================================
// File:                led_gyr.cpp
// Author:              Manuel Bengio (https://github.com/manubengio)
// Version:             1.0.0
// Date:                Febrero 2025
// Info:                Proyect template for Electrónica II

//=======================================================================

#include "leds.h"



void Led_GYR(int distance) {

  // Turn OFF Leds
  digitalWrite(LEDG_PIN, LOW);
  digitalWrite(LEDY_PIN, LOW);
  digitalWrite(LEDR_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  // Control of LED lighting based on distance 
  if (distance <= 20) {
    digitalWrite(LEDG_PIN, HIGH);  
  }
  if (distance <= 15) {
    digitalWrite(LEDY_PIN, HIGH);  
  }
  if (distance <= 10) {
    digitalWrite(LEDR_PIN, HIGH);  
  }
  
  
  if (distance <= 5) {
    for (int i = 0; i < 3; i++) {  // Blinking
      digitalWrite(LEDG_PIN, LOW);
      digitalWrite(LEDY_PIN, LOW);
      digitalWrite(LEDR_PIN, LOW);
      digitalWrite(BUZZER_PIN, HIGH);
      delay(100);

      digitalWrite(LEDG_PIN, HIGH);
      digitalWrite(LEDY_PIN, HIGH);
      digitalWrite(LEDR_PIN, HIGH);
      digitalWrite(BUZZER_PIN, LOW);
      delay(100);
    }
  }
}