#include "connection.h"
#include "oled.h"

//--Instances
WiFiClient espClient;
PubSubClient client(espClient);


//--extern variables
extern int distance;

bool comm_init(void)
{
    WiFi.begin(ssid, password);
    Serial.print("Conectando a WiFi...");
    
    unsigned long startAttemptTime = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 5000) {
        delay(500);
        Serial.print(".");
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\nConectado a WiFi!");
        IPAddress ip = WiFi.localIP();
        oled88_connected_wifi(ip);
        Serial.println(ip);

        client.setServer(mqtt_server, 1883);
        Serial.print("Conectando a MQTT...");

        if (client.connect("ESP32Client")) {
            Serial.println(" Conectado a Mosquitto!");
            client.publish("Distance", "Hola desde ESP32!");
        } else {
            Serial.print(" Falló, error=");
            Serial.print(client.state());
            return false;
        }
        return true;
    } else {
        Serial.println("\nError: No se pudo conectar a WiFi.");
        oled88_info("Error de conexion");
        return false;

    }
}


void publish(int distance) {
    client.loop();  // Mantiene la conexión MQTT activa
    
    JsonDocument doc;
    doc["sensor"] = "SR04";
    doc["distance"] = distance;

    // Convertir JSON a cadena
    char jsonBuffer[200];
    serializeJson(doc, jsonBuffer);

    // Publicar en MQTT
    client.publish("Distance", jsonBuffer);
    Serial.println("Mensaje enviado a MQTT: ");
    Serial.println(jsonBuffer);  // Mostrar el JSON en el monitor serie
}
