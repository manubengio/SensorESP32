#ifndef _CONNECTION_H_
#define _CONNECTION_H_

// Includes
#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "oled.h"
#include "config.h"
#include "persist.h"

// Function declarations
bool comm_init(void);
void publish(int);
void processPayload(String);
void callback(char* topic, byte* payload, unsigned int length);


#endif
