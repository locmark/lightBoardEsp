#pragma once

#include <SoftwareSerial.h>
#include "machineState.hpp"

#define MYPORT_TX 14
#define MYPORT_RX 13

static SoftwareSerial uart;

void UART_init () {
    uart.begin(9600, SWSERIAL_8N1, MYPORT_RX, MYPORT_TX, false, 256);
    if (!uart) { // If the object did not initialize, then its configuration is invalid
        Serial.println("Invalid SoftwareSerial pin configuration, check config");
        while (1) { // Don't continue with invalid configuration
            delay (1000);
        }
    }
}

void UART_stop () {
    uart.end();
}

void UART_sendOutputs () {
    uint8_t outputs = 0x00;

    if (MachineState::output0) { outputs |= (1 << 0); }
    if (MachineState::output1) { outputs |= (1 << 1); }
    if (MachineState::output2) { outputs |= (1 << 2); }
    if (MachineState::output3) { outputs |= (1 << 3); }
    if (MachineState::output4) { outputs |= (1 << 4); }
    if (MachineState::output5) { outputs |= (1 << 5); }
    if (MachineState::output6) { outputs |= (1 << 6); }
    
    uart.enableRx(false);
    uart.write(outputs);
    uart.enableRx(true);
}


void UART_update () {
    UART_sendOutputs();

    delay(3);

    while (uart.available()) {
        uart.enableRx(false);
        uint8_t inputs = uart.read();
        uart.enableRx(true);
        if (inputs == 0xFF) { return; } // idk
        MachineState::switch0 = (inputs & (1 << 0)) ? true : false;
        MachineState::switch1 = (inputs & (1 << 1)) ? true : false;
        MachineState::switch2 = (inputs & (1 << 2)) ? true : false;
        MachineState::switch3 = (inputs & (1 << 3)) ? true : false;
        MachineState::switch4 = (inputs & (1 << 4)) ? true : false;
        MachineState::switch5 = (inputs & (1 << 5)) ? true : false;
        MachineState::switch6 = (inputs & (1 << 6)) ? true : false;

        MachineState::picConnectionEstablished = true;

        // Serial.println((int)inputs);
    }
    
}