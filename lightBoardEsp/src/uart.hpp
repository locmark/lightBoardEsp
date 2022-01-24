#pragma once

#include <SoftwareSerial.h>
#include "uartFrames.hpp"
#include "pic.hpp"

#define MYPORT_TX 12
#define MYPORT_RX 13

static SoftwareSerial uart;

void UART_init () {
    uart.begin(115200, SWSERIAL_8N1, MYPORT_RX, MYPORT_TX, false, 256);
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

static uint16_t calcCRC (char* buff, unsigned int size) {
    uint16_t crc = 0;
    for (size_t i = 0; i < size; i++) {
        crc += *reinterpret_cast<uint8_t*>(&buff[i]);
    }

    return crc;
}

static void updateOutputBufferCRC () {
    uint16_t crc = calcCRC(outputBuffer.data, sizeof outputBuffer.data - 2); // -2 to omit crc and eof
    outputBuffer.frame.crc = crc;
}

static bool isInputBufferValid () {
    return (
        inputBuffer.frame.sof == SPI_SOF &&
        inputBuffer.frame.eof == SPI_EOF &&
        inputBuffer.frame.c1 == C1 &&
        inputBuffer.frame.c2 == C2 &&
        inputBuffer.frame.c3 == C3
        // TODO: add crc check
    );
}

static void shiftInputBuffer () {
    for (uint8_t i = 0; i < (sizeof inputBuffer.data) - 1; i++) {
        inputBuffer.data[i] = inputBuffer.data[i + 1];
    }
}

static void copyInputFrameData () {
    PIC::inputState = inputBuffer.frame.inputState;
    PIC::outputState = inputBuffer.frame.outputState;
    PIC::dimmer_1 = inputBuffer.frame.dimmer_1;
    PIC::dimmer_2 = inputBuffer.frame.dimmer_2;
    PIC::dimmer_3 = inputBuffer.frame.dimmer_3;
    PIC::dimmer_4 = inputBuffer.frame.dimmer_4;
    PIC::dimmer_5 = inputBuffer.frame.dimmer_5;
    PIC::dimmer_6 = inputBuffer.frame.dimmer_6;
    PIC::dimmer_7 = inputBuffer.frame.dimmer_7;
    PIC::current_1 = inputBuffer.frame.current_1;
    PIC::current_2 = inputBuffer.frame.current_2;
    PIC::current_3 = inputBuffer.frame.current_3;
    PIC::current_4 = inputBuffer.frame.current_4;
    PIC::current_5 = inputBuffer.frame.current_5;
    PIC::current_6 = inputBuffer.frame.current_6;
    PIC::current_7 = inputBuffer.frame.current_7;
}


void UART_update () {
    while (uart.available()) {
        shiftInputBuffer();
        uint8_t inputByte = uart.read();
        inputBuffer.data[sizeof inputBuffer.data - 1] = inputByte;
        // for (size_t j = 0; j < sizeof inputBuffer.data; j++)
        // {
        //     Serial.print((int)inputBuffer.data[j], HEX);
        //     Serial.print(' ');
        // }
        // Serial.print("\n");
        
        if (isInputBufferValid()) {
            // Serial.println("frame is valid!");
            copyInputFrameData();
        }
    }
    
}