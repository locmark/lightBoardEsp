#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

#include "uart.hpp"

void OTA_init() {
    ArduinoOTA.onStart([]() {
        UART_stop();
        String type;
        if (ArduinoOTA.getCommand() == U_FLASH) {
            type = "sketch";
        }
        else { // U_FS
            type = "filesystem";
        }

        // NOTE: if updating FS this would be the place to unmount FS using FS.end()
        Serial.println("[OTA] Start updating " + type);
    });

    ArduinoOTA.onEnd([]() { 
        Serial.println("\n[OTA] End"); 
    });

    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) { 
        Serial.printf("[OTA] Progress: %u%%\r\n", (progress / (total / 100))); 
    });

    ArduinoOTA.onError([](ota_error_t error) {
        Serial.printf("[OTA] Error[%u]: ", error);
        if (error == OTA_AUTH_ERROR) {
            Serial.println("[OTA] Auth Failed");
        }
        else if (error == OTA_BEGIN_ERROR) {
            Serial.println("[OTA] Begin Failed");
        }
        else if (error == OTA_CONNECT_ERROR) {
            Serial.println("[OTA] Connect Failed");
        }
        else if (error == OTA_RECEIVE_ERROR) {
            Serial.println("[OTA] Receive Failed");
        }
        else if (error == OTA_END_ERROR) {
            Serial.println("[OTA] End Failed");
        }
    });

    ArduinoOTA.begin();
    Serial.println("[OTA] Ready");
    Serial.print("[OTA] IP address: ");
    Serial.println(WiFi.localIP());
}

void OTA_update () {
    ArduinoOTA.handle();
}