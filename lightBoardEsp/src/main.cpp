#include <ESP8266WiFi.h>
#include "uart.hpp"
#include "mqtt.hpp"
#include "ota.hpp"
#include "secrets.hpp"


void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.println("Connecting to WiFi..");
  }
  
  OTA_init();
  UART_init();
  MQTT_init();
}

void loop() {
  OTA_update();
  UART_update();
  MQTT_update();

  delay(5);  
}