#pragma once

#include <iostream>
#include <cstdint>
#include <vector>
#include <fstream>

struct PNGChunk {
    uint32_t length;
    char type[4];
    std::vector<uint8_t> data;
    uint32_t crc;
};

struct IHDRChunk {
    uint32_t width;                 // Width:              4 bytes
    uint32_t height;                // Height:             4 bytes
    uint8_t bitDepth;               // Bit depth:          1 byte
    uint8_t colorType;              // Color type:         1 byte
    uint8_t compressionMethod;      // Compression method: 1 byte
    uint8_t filterMethod;           // Filter method:      1 byte
    uint8_t interlaceMethod;        // Interlace method:   1 byte
};

bool validateSignature(std::ifstream& file) {
    uint8_t signature[8];

    file.read(reinterpret_cast<char*>(signature), 8);

    const uint8_t PNG_SIGNATURE[8] = {137, 80, 78, 71, 13, 10, 26, 10};

    for(int i = 0; i < 8; i++) if(signature[i] != PNG_SIGNATURE[i]) return false;

    return true;
}

std::ifstream loadPNG(const char* filename) {
    std::ifstream file(filename, std::ios::binary);

    return file;
}