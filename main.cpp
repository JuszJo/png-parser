#include <iostream>

#include "png-parser.h"

int main() {
    const char* image = "image.png";

    std::ifstream file = loadPNG(image);

    if(!file) {
        std::cerr << "file did not open successfully\n";

        return 0;
    }

    bool isValidPNG = validateSignature(file);

    if(!isValidPNG) {
        std::cerr << "file is not a valid PNG\n";

        return 0;
    }

    while(file) {
        // PNGChunk chunk = readChunk(file);
        
        // if(std::string(chunk.type, 4) == "IHDR") {
        //     parseIHDR(chunk);
        // }
        // else if(std::string(chunk.type, 4) == "IDAT") {
        //     // Append to raw data for later decompression
        //     rawData.insert(rawData.end(), chunk.data.begin(), chunk.data.end());
        // }
        // else if(std::string(chunk.type, 4) == "IEND") {
        //     break;
        // }
    }


    return 0;
}