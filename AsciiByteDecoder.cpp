#include "AsciiByteDecoder.h"

const char* AsciiByteDecoder::decoderName() const {
    return "ASCII/control decoder";
}

std::string AsciiByteDecoder::decodeByte(std::uint8_t b) const {
    // Common control characters
    switch (b) {
        case 0x00: return "NUL";
        case 0x07: return "BEL";
        case 0x08: return "BS";
        case 0x09: return "TAB";
        case 0x0A: return "LF";
        case 0x0D: return "CR";
        case 0x1B: return "ESC";
        case 0x20: return "SPACE";
        case 0x7F: return "DEL";
        default: break;
    }

    // Printable ASCII range 0x21 ('!') to 0x7E ('~')
    if (b >= 0x21 && b <= 0x7E) {
        std::string s;
        s += "'";
        s += static_cast<char>(b);
        s += "'";
        return s;
    }

    return "UNKNOWN";
}
