#include "ByteDecoder.h"
#include <fstream>

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

