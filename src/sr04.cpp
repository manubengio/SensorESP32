//=======================================================================
// File:                sr04.cpp
// Author:              Manuel Bengio (https://github.com/manubengio)
// Version:             1.0.0
// Date:                Febrero 2025
// Info:                Proyect template for Electrónica II
//=======================================================================


#include "sr04.h"



long duration;  
int distance; 

int Sense_distance(void){

// Send pulse on pin TRIG
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH);  // Measures real-time round-trip time;  

  // Calculate distance in centimeters
  distance = duration * 0.0344 / 2;

  // Show distance
  Serial.print("Distancia simulada: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);  
  return distance;
}

