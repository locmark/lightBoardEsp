#pragma once
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "secrets.hpp"
#include "uart.hpp"
#include "machineState.hpp"
#include "mqttConfig.hpp"

static WiFiClient espClient;
static PubSubClient client(espClient);

void MQTT_publishChannel0State () {
    if(!client.publish(channel0_state, MachineState::output0 ? "ON" : "OFF")) {
        Serial.println("[mqtt] publishing channel 0 state failed");
    }
}

void MQTT_publishChannel1State () {
    if(!client.publish(channel1_state, MachineState::output1 ? "ON" : "OFF")) {
        Serial.println("[mqtt] publishing channel 1 state failed");
    }
}

void MQTT_publishChannel2State () {
    if(!client.publish(channel2_state, MachineState::output2 ? "ON" : "OFF")) {
        Serial.println("[mqtt] publishing channel 2 state failed");
    }
}

void MQTT_publishChannel3State () {
    if(!client.publish(channel3_state, MachineState::output3 ? "ON" : "OFF")) {
        Serial.println("[mqtt] publishing channel 3 state failed");
    }
}

void MQTT_publishChannel4State () {
    if(!client.publish(channel4_state, MachineState::output4 ? "ON" : "OFF")) {
        Serial.println("[mqtt] publishing channel 4 state failed");
    }
}

void MQTT_publishChannel5State () {
    if(!client.publish(channel5_state, MachineState::output5 ? "ON" : "OFF")) {
        Serial.println("[mqtt] publishing channel 5 state failed");
    }
}

void MQTT_publishChannel6State () {
    if(!client.publish(channel6_state, MachineState::output6 ? "ON" : "OFF")) {
        Serial.println("[mqtt] publishing channel 6 state failed");
    }
}

static void callback (char* topic, unsigned char* payload, unsigned int length) {
    Serial.print("[mqtt] Message arrived in topic: ");
    Serial.println(topic);
    Serial.print("[mqtt] Message:");
    for (unsigned int i = 0; i < length; i++) {
        Serial.print((char)payload[i]);
    }
    Serial.println();
    
    if (strcmp(topic, channel0_command) == 0) {
        MachineState::output0 = (payload[1] == 'N'); // detects "ON" / "OFF"
        MQTT_publishChannel0State();
    }

    if (strcmp(topic, channel1_command) == 0) {
        MachineState::output1 = (payload[1] == 'N'); // detects "ON" / "OFF"
        MQTT_publishChannel1State();
    }

    if (strcmp(topic, channel2_command) == 0) {
        MachineState::output2 = (payload[1] == 'N'); // detects "ON" / "OFF"
        MQTT_publishChannel2State();
    }

    if (strcmp(topic, channel3_command) == 0) {
        MachineState::output3 = (payload[1] == 'N'); // detects "ON" / "OFF"
        MQTT_publishChannel3State();
    }

    if (strcmp(topic, channel4_command) == 0) {
        MachineState::output4 = (payload[1] == 'N'); // detects "ON" / "OFF"
        MQTT_publishChannel4State();
    }

    if (strcmp(topic, channel5_command) == 0) {
        MachineState::output5 = (payload[1] == 'N'); // detects "ON" / "OFF"
        MQTT_publishChannel5State();
    }

    if (strcmp(topic, channel6_command) == 0) {
        MachineState::output6 = (payload[1] == 'N'); // detects "ON" / "OFF"
        MQTT_publishChannel6State();
    }
}

static void publishAutodiscoveryMsgs () {
    if(!client.publish(channel0_config, channel0_config_body)) {
        Serial.println("[mqtt] publishing channel 0 autodiscovery failed");
    }
    if(!client.publish(channel1_config, channel1_config_body)) {
        Serial.println("[mqtt] publishing channel 1 autodiscovery failed");
    }
    if(!client.publish(channel2_config, channel2_config_body)) {
        Serial.println("[mqtt] publishing channel 2 autodiscovery failed");
    }
    if(!client.publish(channel3_config, channel3_config_body)) {
        Serial.println("[mqtt] publishing channel 3 autodiscovery failed");
    }
    if(!client.publish(channel4_config, channel4_config_body)) {
        Serial.println("[mqtt] publishing channel 4 autodiscovery failed");
    }
    if(!client.publish(channel5_config, channel5_config_body)) {
        Serial.println("[mqtt] publishing channel 5 autodiscovery failed");
    }
    if(!client.publish(channel6_config, channel6_config_body)) {
        Serial.println("[mqtt] publishing channel 6 autodiscovery failed");
    }

}

static void connectClient () {
    if (!client.connected()) {
        String client_id = "esp8266-client-";
        client_id += String(WiFi.macAddress());
        Serial.printf("[mqtt] The client %s connects to the public mqtt broker\n", client_id.c_str());
        if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
            Serial.println("[mqtt] connected");

            client.subscribe(channel0_command);
            client.subscribe(channel1_command);
            client.subscribe(channel2_command);
            client.subscribe(channel3_command);
            client.subscribe(channel4_command);
            client.subscribe(channel5_command);
            client.subscribe(channel6_command);

            publishAutodiscoveryMsgs();

        } else {
            Serial.print("[mqtt] failed with state ");
            Serial.println(client.state());
            delay(2000);
        }
    }
}

void MQTT_init () {
    // mqtt setup
    client.setServer(mqtt_broker, mqtt_port);
    client.setCallback(callback);
    
    connectClient();
}

void MQTT_update () {
    bool isConnected = client.loop();

    if (!isConnected) {
        connectClient();
    }
}
