//=======================================================================
// File:                app.cpp
// Author:              Manuel Bengio (https://github.com/manubengio)
// Version:             1.0.0
// Date:                Febrero 2025
// Info:                Proyect template for Electrónica II

//=======================================================================

//--Includes
#include "app.h"

//--extern variables
extern bool communication;

//--Functions
void App_loop(void){
    
    int distance = Sense_distance();
    Led_GYR(distance);
    oled88_update(distance);

    if(communication){
    publish(distance);
    }

}


