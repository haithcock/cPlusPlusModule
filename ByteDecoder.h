//ByteDecoder.h

#pragma once
#include <cstdint>
#include <string>
#include <vector>

class ByteDecoder {
public:
    virtual ~ByteDecoder() = default;

    bool loadFile(const std::string& path);
    void decodeAll();
    bool writeReport(const std::string& outPath) const;

protected:
    virtual std::string decodeByte(std::uint8_t b) const = 0;
    virtual const char* decoderName() const = 0;

private:
    std::vector<std::uint8_t> bytes_;
    std::vector<std::string> decoded_;
};

//This file defines the abstract interface for the decoder. 
// class ByteDecoder is a base class that isnt supposed to be insantiated directly while 'virtual ~ByteDecoder() = default;' 
//     makes the class safe for inheritance.


//Public Functions: 'bool loadFile, voide decodeAll, and bool writeReport' load, decode, and write


//virtual functions are just the parts for abstraction. 

//    std::vector<std::uint8_t> bytes_;
//    std::vector<std::string> decoded_; are just private data and this is a shared state that the base class earlier owns.