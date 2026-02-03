//AsciiByteDecoder.h
#pragma once
#include "ByteDecoder.h"

class AsciiByteDecoder : public ByteDecoder {
protected:
    const char* decoderName() const override;
    std::string decodeByte(std::uint8_t b) const override;
};

//class AsciiByteDecoder inherits from the ByteDecoder class I made earlier.
//The protected 'const char* decoderName() const override;
//    std::string decodeByte(std::uint8_t b) const override;'
// part tells my compiler this bad boy knows how to decode some bytes but we dont have our logic yet.