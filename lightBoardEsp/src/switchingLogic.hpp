#pragma once

#include "machineState.hpp"
#include "mqtt.hpp"


namespace SwitchingLogic {
    static bool switch0_lastState = false;
    static bool switch1_lastState = false;
    static bool switch2_lastState = false;
    static bool switch3_lastState = false;
    static bool switch4_lastState = false;
    static bool switch5_lastState = false;
    static bool switch6_lastState = false;
    static bool picConnectionEstablished_lastState = false;

    void update () {
        if (MachineState::picConnectionEstablished && picConnectionEstablished_lastState) {
            if (switch0_lastState != MachineState::switch0) {
                MachineState::output0 = !MachineState::output0;
                Serial.println("[SL] Switching channel 0");
                MQTT_publishChannel0State();
            }

            if (switch1_lastState != MachineState::switch1) {
                MachineState::output1 = !MachineState::output1;
                Serial.println("[SL] Switching channel 1");
                MQTT_publishChannel1State();
            }

            if (switch2_lastState != MachineState::switch2) {
                MachineState::output2 = !MachineState::output2;
                Serial.println("[SL] Switching channel 2");
                MQTT_publishChannel2State();
            }

            if (switch3_lastState != MachineState::switch3) {
                MachineState::output3 = !MachineState::output3;
                Serial.println("[SL] Switching channel 3");
                MQTT_publishChannel3State();
            }

            if (switch4_lastState != MachineState::switch4) {
                MachineState::output4 = !MachineState::output4;
                Serial.println("[SL] Switching channel 4");
                MQTT_publishChannel4State();
            }

            if (switch5_lastState != MachineState::switch5) {
                MachineState::output5 = !MachineState::output5;
                Serial.println("[SL] Switching channel 5");
                MQTT_publishChannel5State();
            }

            if (switch6_lastState != MachineState::switch6) {
                MachineState::output6 = !MachineState::output6;
                Serial.println("[SL] Switching channel 6");
                MQTT_publishChannel6State();
            }
        } else if (MachineState::picConnectionEstablished && !picConnectionEstablished_lastState) {
            MQTT_publishChannel0State();
            MQTT_publishChannel1State();
            MQTT_publishChannel2State();
            MQTT_publishChannel3State();
            MQTT_publishChannel4State();
            MQTT_publishChannel5State();
            MQTT_publishChannel6State();
        }


        switch0_lastState = MachineState::switch0;
        switch1_lastState = MachineState::switch1;
        switch2_lastState = MachineState::switch2;
        switch3_lastState = MachineState::switch3;
        switch4_lastState = MachineState::switch4;
        switch5_lastState = MachineState::switch5;
        switch6_lastState = MachineState::switch6;
        picConnectionEstablished_lastState = MachineState::picConnectionEstablished;
    }
}