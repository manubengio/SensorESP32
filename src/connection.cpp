//=======================================================================

// File:                connection.cpp
// Author:              Manuel Bengio (https://github.com/manubengio)
// Version:             1.0.0
// Date:                Febrero 2025
// Info:                Proyect template for Electrónica II

//=======================================================================

#include "connection.h"

//--Instances
WiFiClient espClient;
PubSubClient client(espClient);

//--extern variables
extern int distance;


// The callback function will be called automatically when a message is received on the subscribed topic
void callback(char* topic, byte* payload, unsigned int length)
{
    Serial.print("Message received on topic: ");
    Serial.println(topic);

    // Convert the payload into a string
    String message;
    for (unsigned int i = 0; i < length; i++)
    {
        message += (char)payload[i];
    }
    Serial.println("Received payload: " + message);

    // Call processPayload() with the received message
    processPayload(message);
}

void processPayload(String message)
{
    // Parse JSON
    JsonDocument doc;
    DeserializationError error = deserializeJson(doc, message);

    if (error)
    {
        Serial.print("Error parsing JSON: ");
        Serial.println(error.c_str());
        return;
    }

    // Extract distance values
    settings.dist_green = doc["dist_green"];
    settings.dist_yellow = doc["dist_yellow"];
    settings.dist_red = doc["dist_red"];
    settings.dist_buzzer = doc["dist_buzzer"];

    Serial.println("Received values:");
    Serial.print("Green Distance: ");
    Serial.println(settings.dist_green);
    Serial.print("Yellow Distance: ");
    Serial.println(settings.dist_yellow);
    Serial.print("Red Distance: ");
    Serial.println(settings.dist_red);
    Serial.print("Buzzer Distance: ");
    Serial.println(settings.dist_buzzer);

    save_settings();
}



bool comm_init(void)
{
    WiFi.begin(settings.ssid, settings.ssid_pass);
    Serial.print("Conectando a WiFi...");

    unsigned long startAttemptTime = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 5000)
    {
        delay(500);
        Serial.print(".");
    }

    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.println("\nConectado a WiFi!");
        IPAddress ip = WiFi.localIP();
        oled88_connected_wifi(ip);
        Serial.println(ip);

        client.setServer(settings.mqtt_server, 1883);
        client.setCallback(callback);
        Serial.print("Conectando a MQTT...");

        if (client.connect("ESP32Client"))
        {
            Serial.println(" Conectado a Mosquitto!");
            client.publish("Distance", "Hola desde ESP32!");
            if (client.subscribe("Parking"))
            {
                Serial.println("Suscrito al tema 'Parking'");
                save_settings();
            }
            else
            {
                Serial.println("Fallo suscripción tema 'Parking'");
                oled88_info("No suscripto a 'Parking'");
            }
        }
        else
        {
            Serial.print(" Falló, error=");
            Serial.print(client.state());
            return false;
        }
        return true;
    }
    else
    {
        Serial.println("\nError: No se pudo conectar a WiFi.");
        oled88_info("Error de conexion");
        return false;
    }
}

void publish(int distance)
{
    client.loop(); // Maintain active MQTT connection

    JsonDocument doc;
    doc["sensor"] = "SR04";
    doc["distance"] = distance;

    // JSON to STRING
    char jsonBuffer[200];
    serializeJson(doc, jsonBuffer);

    // Publish MQTT
    client.publish("Distance", jsonBuffer);
    Serial.println("Mensaje enviado a MQTT: ");
    Serial.println(jsonBuffer); // Show JSON on serie monitor
}



