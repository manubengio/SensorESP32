
// ver el tema del if end if, ahi vi que lo hacen en el .h marcelo


#include "sr04.h"
#include "leds.h"  // Incluir el archivo que contiene la lógica de los LEDs

extern int distance;  // Declarar la variable 'distance' que está definida en sr04.cpp



void Led_GYR(void) {
  // Llamar a la función que mide la distancia
  Sense_distance();  // Medir la distancia
  
  // Apagar todos los LEDs y el buzzer antes de establecer los nuevos estados
  digitalWrite(LEDG_PIN, LOW);
  digitalWrite(LEDY_PIN, LOW);
  digitalWrite(LEDR_PIN, LOW);
  

  // Control de LEDs y buzzer basado en la distancia
  if (distance > 50) {
    digitalWrite(LEDG_PIN, HIGH);  // Encender LED verde
  } 
  else if (distance > 20 && distance <= 50) {
    digitalWrite(LEDY_PIN, HIGH);  // Encender LED amarillo
  } 
  else if (distance <= 20) {
    digitalWrite(LEDR_PIN, HIGH);  // Encender LED rojo
    
  }
}

