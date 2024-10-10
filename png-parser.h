#pragma once

#include <iostream>
#include <cstdint>
#include <vector>

struct PNGChunk {
    uint32_t length;
    char type[4];
    std::vector<uint8_t> data;
    uint32_t crc;
}

struct IHDRChunk {
    uint32_t width;                 // Width:              4 bytes
    uint32_t height;                // Height:             4 bytes
    uint8_t bitDepth;               // Bit depth:          1 byte
    uint8_t colorType;              // Color type:         1 byte
    uint8_t compressionMethod;      // Compression method: 1 byte
    uint8_t filterMethod;           // Filter method:      1 byte
    uint8_t interlaceMethod;        // Interlace method:   1 byte
}