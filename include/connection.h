#ifndef _CONNECTION_H_
#define _CONNECTION_H_

// Includes
#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "oled.h"

// Store constant variables in flash memory
constexpr char ssid[] = "Samsung S22 DE56";
constexpr char password[] = "12345678";
constexpr char mqtt_server[] = "192.168.1.15";

// Function declarations
bool comm_init(void);
void publish(int);

#endif
