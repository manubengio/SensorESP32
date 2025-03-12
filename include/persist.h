#ifndef _persist_h_
#define _persist_h_

#include <Preferences.h>
#include "config.h"
#include "connection.h"

//--Variables default values
#define DEFAULT_DIST_GREEN    20
#define DEFAULT_DIST_YELLOW  15
#define DEFAULT_DIST_RED    10
#define DEFAULT_DIST_BUZZER    5
#define DEFAULT_SSID        "Galaxy S22 DE56"
#define DEFAULT_SSID_PASS   "12345678"



void save_settings(void);
void load_settings(void);

#endif
