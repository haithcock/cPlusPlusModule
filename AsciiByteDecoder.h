#pragma once
#include "ByteDecoder.h"

class AsciiByteDecoder : public ByteDecoder {
protected:
    const char* decoderName() const override;
    std::string decodeByte(std::uint8_t b) const override;
};
