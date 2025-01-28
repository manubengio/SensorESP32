#ifndef _sr04_h_
#define _sr04_h_

#include "sr04.h"
#include <Arduino.h>


long duration;  // Variable para almacenar el tiempo del pulso
int distance;   // Variable para almacenar la distancia

void Sense_distance(void){

// Enviar un pulso en el pin TRIG
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH);  // Mide el tiempo real de ida y vuelta;  // Este es un valor artificial para pruebas, lo puedes cambiar

  // Calcular la distancia en centímetros
  distance = duration * 0.0344 / 2;

  // Mostrar la distancia en el monitor serie
  Serial.print("Distancia simulada: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);  // Espera medio segundo antes de la siguiente medición
}

#endif