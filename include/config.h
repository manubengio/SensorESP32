#ifndef _config_h_
#define _config_h_

//--Includes
#include <Arduino.h>

//--Software constants
#define SERIAL_BAUDRATE             19200


//--Structures
struct Settings {
    String ssid;
    String ssid_pass;
    int dist_green;
    int dist_yellow;
    int dist_red;
    int dist_buzzer;
    const char* mqtt_server = "192.168.76.240";  // Correcto
};

extern Settings settings;

//--Prototypes
void App_setup(void);
void App_loop(void);


#endif