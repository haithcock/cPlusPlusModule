#include "AsciiByteDecoder.h"

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    // Usage:
    //   ./byte_decoder input.bin output.txt
    if (argc != 3) {
        std::cerr << "Usage: " << (argc > 0 ? argv[0] : "byte_decoder")
                  << " <input_file> <output_file>\n";
        return 1;
    }

    const std::string inputPath = argv[1];
    const std::string outputPath = argv[2];

    AsciiByteDecoder decoder;

    if (!decoder.loadFile(inputPath)) {
        std::cerr << "Error: could not open input file: " << inputPath << "\n";
        return 2;
    }

    decoder.decodeAll();

    if (!decoder.writeReport(outputPath)) {
        std::cerr << "Error: could not write output file: " << outputPath << "\n";
        return 3;
    }

    std::cout << "Done. Wrote decoded output to: " << outputPath << "\n";
    return 0;
}
