/*********************************************************************************
 * 
 *                       ELECTRONICA II UTN - FRRO                                *
 * 
 * *******************************************************************************/

//===================[File header]================================================
// File:                app.cpp
// Author:              Manuel Bengio (https://github.com/manubengio)
// Version:             1.0.0
// Date:                Febrero 2025
// Info:                Proyect template for Electrónica II

//====================[Use & storage]============================================
// PCB:                 NodeMCU 
// Plataforma:          ESP8266  
// Use:                 Template
// Folder:              template_EII_V1
// Proyect name:        template_EII_V1

//====================[ToDo]=====================================================     
//        
//
//
//====================[Bugs]=====================================================     
//     
//                   
//
//====================[Commits]==================================================     
//
// Last commit: First commit 
//
//===================[End file header]===========================================


//--Includes
#include "app.h"


//--Functions
void App_loop(void){
    
    int distance = Sense_distance();
    Led_GYR(distance);
    oled88_update(distance);
}


