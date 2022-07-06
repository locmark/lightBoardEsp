#pragma once

#include <stdint.h>

#define SPI_SOF 0xAA
#define SPI_EOF 0xBB
#define C1  0xCC
#define C2  0xDD
#define C3  0xEE

// PIC -> ESP
#define COMMAND_DEVICE_STATE 0x10

// ESP -> PIC
#define COMMAND_SET_OUTPUT 0x50
#define COMMAND_SET_DIMMER 0x51

#pragma pack(push, 1)
struct OutputBufferFrame {
    uint8_t sof;
    uint8_t com;
    uint8_t d1;
    uint8_t c1;
    uint8_t d2;
    uint8_t d3;
    uint8_t c2;
    uint8_t d4;
    uint16_t crc;
    uint8_t eof;
};
#pragma pack(pop)

union OutputBuffer {
    struct OutputBufferFrame frame;
    char data[sizeof (struct OutputBufferFrame)];
};

union OutputBuffer outputBuffer;

#pragma pack(push, 1)
struct InputBufferFrame {
    uint8_t sof;
    uint8_t com;
    uint8_t inputState;
    uint8_t outputState;
    uint8_t c1;
    uint8_t dimmer_1;
    uint8_t dimmer_2;
    uint8_t dimmer_3;
    uint8_t dimmer_4;
    uint8_t dimmer_5;
    uint8_t dimmer_6;
    uint8_t dimmer_7;
    uint8_t c2;
    uint16_t current_1;
    uint16_t current_2;
    uint16_t current_3;
    uint16_t current_4;
    uint16_t current_5;
    uint16_t current_6;
    uint16_t current_7;
    uint8_t c3;
    uint16_t crc;
    uint8_t eof;
};
#pragma pack(pop)

union InputBuffer {
    struct InputBufferFrame frame;
    char data[sizeof (struct InputBufferFrame)];
};


union InputBuffer inputBuffer;