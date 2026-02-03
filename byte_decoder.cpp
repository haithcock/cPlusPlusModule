//byte_decoder.cpp

#include "ByteDecoder.h"
#include <fstream>
#include <iomanip>
#include <ios>
#include <ostream>

bool ByteDecoder::loadFile(const std::string& path) {
    std::ifstream in(path, std::ios::binary);
    if (!in) {
        return false;
    }
    bytes_.clear();
    char ch = 0;
    while (in.get(ch)) {
        bytes_.push_back(
            static_cast<std::uint8_t>(static_cast<unsigned char>(ch))
        );
    }
    return true;
}
//This bad boy opens a file in binary mode and reads byte by byte. 
//THEN stores each byte into bytes_ returns true if successful or false if it fails. 



void ByteDecoder::decodeAll() {
    decoded_.clear();
    decoded_.reserve(bytes_.size());

    for (std::size_t i = 0; i < bytes_.size(); ++i) {
        decoded_.push_back(decodeByte(bytes_[i]));
    }
}

bool ByteDecoder::writeReport(const std::string& outPath) const {
    std::ofstream out(outPath);
    if (!out) {
        return false;
    }

    out << "Byte Decoder Output\n";
    out << "Decoder: " << decoderName() << "\n";
    out << "Total bytes: " << bytes_.size() << "\n\n";
    out << "Format: [offset] 0xBYTE  DECIMAL  DECODED\n";
    out << "------------------------------------------\n";

    for (std::size_t i = 0; i < bytes_.size(); ++i) {
        // offset
        out << "["
            << std::setw(8) << std::setfill('0') << std::hex << i
            << std::dec << std::setfill(' ') << "] ";

        // hex byte
        out << "0x" << std::uppercase << std::hex
            << std::setw(2) << std::setfill('0')
            << static_cast<int>(bytes_[i])
            << std::nouppercase << std::dec << std::setfill(' ')
            << "   ";

        // decimal byte
        out << std::setw(3) << static_cast<int>(bytes_[i]) << "     ";

        // decoded token
        if (i < decoded_.size()) {
            out << decoded_[i];
        } else {
            out << "(not decoded)";
        }
        out << "\n";
    }

    return true;
}