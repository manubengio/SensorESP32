
#include "sr04.h" // Incluir el archivo que contiene la logica del sensor ultrasonico
#include "leds.h"  // Incluir el archivo que contiene la lógica de los LEDs

extern int distance;  // Declarar la variable 'distance' que está definida en sr04.cpp



void Led_GYR(void) {
  // Medir la distancia
  Sense_distance();  

  // Apagar todos los LEDs y el buzzer antes de establecer los nuevos estados
  digitalWrite(LEDG_PIN, LOW);
  digitalWrite(LEDY_PIN, LOW);
  digitalWrite(LEDR_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  if (distance > 20) {
    // No encender nada si la distancia es mayor a 20 cm
    return;
  }

  // Control de LEDs según la distancia
  if (distance <= 20) {
    digitalWrite(LEDG_PIN, HIGH);  // Encender LED verde
  }
  if (distance <= 15) {
    digitalWrite(LEDY_PIN, HIGH);  // Encender LED amarillo
  }
  if (distance <= 10) {
    digitalWrite(LEDR_PIN, HIGH);  // Encender LED rojo
  }
  
  // Si la distancia es menor o igual a 5 cm, hacer parpadear LEDs y activar buzzer
  if (distance <= 5) {
    for (int i = 0; i < 3; i++) {  // Parpadeo de 3 veces
      digitalWrite(LEDG_PIN, LOW);
      digitalWrite(LEDY_PIN, LOW);
      digitalWrite(LEDR_PIN, LOW);
      digitalWrite(BUZZER_PIN, HIGH);
      delay(200);

      digitalWrite(LEDG_PIN, HIGH);
      digitalWrite(LEDY_PIN, HIGH);
      digitalWrite(LEDR_PIN, HIGH);
      digitalWrite(BUZZER_PIN, LOW);
      delay(200);
    }
  }
}