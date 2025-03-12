//=======================================================================
// File:                persist.cpp
// Author:              Marcelo Castello (https://github.com/mcastellogh)
// Editor:              Manuel Bengio    (https://github.com/manubengio)
// Licence:             GPLV3+
// Version:             1.0.1
// Date:                Noviembre 2024 (Original) Marzo 2025 (Edition)
// Info:                Part of project for Electrónica II
//=======================================================================

#include "persist.h"

Preferences persist;

Settings settings;

void save_settings(void)
{

    persist.begin("settings");
    persist.putInt("dist_green",settings.dist_green);
    persist.putInt("dist_yellow",settings.dist_yellow);
    persist.putInt("dist_red",settings.dist_red);
    persist.putInt("dist_buzzer",settings.dist_buzzer);
    persist.end();

    //--Verify results
    Serial.println("settings saved:");
    Serial.println(settings.ssid);
    Serial.println(settings.ssid_pass);
    Serial.println(settings.dist_green);
    Serial.println(settings.dist_yellow);
    Serial.println(settings.dist_red);
    Serial.println(settings.dist_buzzer);
}

void load_settings(void)
{
    //--Open storage area
    persist.begin("settings");
    settings.ssid = persist.getString("ssid", DEFAULT_SSID); //-- Always the default variable, create function putString to use it
    settings.ssid_pass = persist.getString("ssid_pass", DEFAULT_SSID_PASS);
    settings.dist_green = persist.getInt("dist_green", DEFAULT_DIST_GREEN);
    settings.dist_yellow = persist.getInt("dist_yellow", DEFAULT_DIST_YELLOW);
    settings.dist_red = persist.getInt("dist_red", DEFAULT_DIST_RED);
    settings.dist_buzzer = persist.getInt("dist_buzzer", DEFAULT_DIST_BUZZER);
    //--Close storage area
    persist.end();

    //--Verify results
    Serial.println("settings readed:");
    Serial.print("ssid: ");
    Serial.println(settings.ssid);
    Serial.print("ssid_pass: ");
    Serial.println(settings.ssid_pass);
    Serial.print("dist_green: ");
    Serial.println(settings.dist_green);
    Serial.print("dist_yellow: ");
    Serial.println(settings.dist_yellow);
    Serial.print("dist_red: ");
    Serial.println(settings.dist_red);
    Serial.print("dist_buzzer: ");
    Serial.println(settings.dist_buzzer);
}