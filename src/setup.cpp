//=======================================================================
// File:                setup.cpp
// Author:              Manuel Bengio (https://github.com/manubengio)
// Version:             1.0.0
// Date:                Febrero 2025
// Info:                Proyect template for Electrónica II
//=======================================================================

#include "setup.h"


bool communication;

void App_setup(void){

    Serial.begin(SERIAL_BAUDRATE);

    //--PINS
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    pinMode(LEDG_PIN, OUTPUT);
    pinMode(LEDY_PIN, OUTPUT);
    pinMode(LEDR_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    
    

    oled88_init();
    oled88_test();
    oled88_bienvenida();
    oled88_clear();
    communication = comm_init();
    oled88_clear();
}