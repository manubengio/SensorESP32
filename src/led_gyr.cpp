
#include "leds.h"



void Led_GYR(int distance) {

  // Apagar todos los LEDs y el buzzer antes de establecer los nuevos estados
  digitalWrite(LEDG_PIN, LOW);
  digitalWrite(LEDY_PIN, LOW);
  digitalWrite(LEDR_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

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
      delay(100);

      digitalWrite(LEDG_PIN, HIGH);
      digitalWrite(LEDY_PIN, HIGH);
      digitalWrite(LEDR_PIN, HIGH);
      digitalWrite(BUZZER_PIN, LOW);
      delay(100);
    }
  }
}