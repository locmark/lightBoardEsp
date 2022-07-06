#include <ESP8266WiFi.h>
#include "uart.hpp"
#include "mqtt.hpp"
#include "ota.hpp"
#include "secrets.hpp"
#include "switchingLogic.hpp"

void connectToWifi () {
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Connecting to WiFi..");

        // if wifi is not working for some reason, keep normal functionality working
        SwitchingLogic::update();
    }
}

void setup() {
    Serial.begin(115200);
    
    connectToWifi();
    
    OTA_init();
    UART_init();
    MQTT_init();
}

void loop() {
    if (WiFi.status() != WL_CONNECTED) {
        connectToWifi();
    }

    OTA_update();
    UART_update();
    MQTT_update();
    SwitchingLogic::update();

    delay(5);  
}