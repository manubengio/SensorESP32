#include "sr04.h"
#include <Arduino.h>


long duration;  // Variable para almacenar el tiempo del pulso
int distance; //Variable para almacenar la distancia

int Sense_distance(void){

// Enviar un pulso en el pin TRIG
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH);  // Mide el tiempo real de ida y vuelta;  

  // Calcular la distancia en centímetros
  distance = duration * 0.0344 / 2;

  // Mostrar la distancia en el monitor serie
  Serial.print("Distancia simulada: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);  // Espera medio segundo antes de la siguiente medición
  return distance;
}

