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


    return 0;
}