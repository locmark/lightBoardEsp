#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "uartFrames.hpp"
#include "secrets.hpp"

constexpr const char* mqtt_broker = "192.168.1.20";
constexpr const char* topic = "lightBoard/test";
constexpr int mqtt_port = 1883;

static WiFiClient espClient;
static PubSubClient client(espClient);

static void callback (char* topic, byte* payload, unsigned int length) {
    Serial.print("Message arrived in topic: ");
    Serial.println(topic);
    Serial.print("Message:");
    for (int i = 0; i < length; i++) {
        Serial.print((char) payload[i]);
    }
    Serial.println();
    Serial.println("-----------------------");
}

void MQTT_init () {
    // mqtt setup
    client.setServer(mqtt_broker, mqtt_port);
    client.setCallback(callback);
    while (!client.connected()) {
        String client_id = "esp8266-client-";
        client_id += String(WiFi.macAddress());
        Serial.printf("[mqtt] The client %s connects to the public mqtt broker\n", client_id.c_str());
        if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
            Serial.println("[mqtt] connected");
        } else {
            Serial.print("[mqtt] failed with state ");
            Serial.println(client.state());
            delay(2000);
        }
    }

    client.subscribe(topic);
}

static uint8_t mqttSendCounter = 0;

void MQTT_update () {
    client.loop();
    switch (mqttSendCounter) {
        case 0: client.publish("lightBoard/relay/0", bitRead(inputBuffer.frame.outputState, 0) ? "true" : "false"); break;
        case 1: client.publish("lightBoard/relay/1", bitRead(inputBuffer.frame.outputState, 0) ? "true" : "false"); break;
        case 2: client.publish("lightBoard/relay/2", bitRead(inputBuffer.frame.outputState, 0) ? "true" : "false"); break;
        case 3: client.publish("lightBoard/relay/3", bitRead(inputBuffer.frame.outputState, 0) ? "true" : "false"); break;
        case 4: client.publish("lightBoard/relay/4", bitRead(inputBuffer.frame.outputState, 0) ? "true" : "false"); break;
        case 5: client.publish("lightBoard/relay/5", bitRead(inputBuffer.frame.outputState, 0) ? "true" : "false"); break;
        case 6: client.publish("lightBoard/relay/6", bitRead(inputBuffer.frame.outputState, 0) ? "true" : "false"); break;

        case 7: client.publish("lightBoard/switch/0", bitRead(inputBuffer.frame.inputState, 0) ? "true" : "false"); break;
        case 8: client.publish("lightBoard/switch/1", bitRead(inputBuffer.frame.inputState, 0) ? "true" : "false"); break;
        case 9: client.publish("lightBoard/switch/2", bitRead(inputBuffer.frame.inputState, 0) ? "true" : "false"); break;
        case 10: client.publish("lightBoard/switch/3", bitRead(inputBuffer.frame.inputState, 0) ? "true" : "false"); break;
        case 11: client.publish("lightBoard/switch/4", bitRead(inputBuffer.frame.inputState, 0) ? "true" : "false"); break;
        case 12: client.publish("lightBoard/switch/5", bitRead(inputBuffer.frame.inputState, 0) ? "true" : "false"); break;
        case 13: client.publish("lightBoard/switch/6", bitRead(inputBuffer.frame.inputState, 0) ? "true" : "false"); break;

        case 14: client.publish("lightBoard/dimmer/0", String(inputBuffer.frame.dimmer_1).c_str()); break;
        case 15: client.publish("lightBoard/dimmer/1", String(inputBuffer.frame.dimmer_2).c_str()); break;
        case 16: client.publish("lightBoard/dimmer/2", String(inputBuffer.frame.dimmer_3).c_str()); break;
        case 17: client.publish("lightBoard/dimmer/3", String(inputBuffer.frame.dimmer_4).c_str()); break;
        case 18: client.publish("lightBoard/dimmer/4", String(inputBuffer.frame.dimmer_5).c_str()); break;
        case 19: client.publish("lightBoard/dimmer/5", String(inputBuffer.frame.dimmer_6).c_str()); break;
        case 20: client.publish("lightBoard/dimmer/6", String(inputBuffer.frame.dimmer_7).c_str()); break;

        case 21: client.publish("lightBoard/current/0", String(inputBuffer.frame.current_1).c_str()); break;
        case 22: client.publish("lightBoard/current/1", String(inputBuffer.frame.current_2).c_str()); break;
        case 23: client.publish("lightBoard/current/2", String(inputBuffer.frame.current_3).c_str()); break;
        case 24: client.publish("lightBoard/current/3", String(inputBuffer.frame.current_4).c_str()); break;
        case 25: client.publish("lightBoard/current/4", String(inputBuffer.frame.current_5).c_str()); break;
        case 26: client.publish("lightBoard/current/5", String(inputBuffer.frame.current_6).c_str()); break;
        case 27: client.publish("lightBoard/current/6", String(inputBuffer.frame.current_7).c_str()); break;
    }

    mqttSendCounter++;

    if (mqttSendCounter >= 27) {
        mqttSendCounter = 0;
    }
}
