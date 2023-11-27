#ifndef STRING_ENCODER_GENERIC_H
#define STRING_ENCODER_GENERIC_H

#include <string>
#include <unordered_map>

struct CharacterEncoding {
    char character;
    std::string encoding;
};

class Generic {
public:
    Generic() = default;
    ~Generic() = default;

    static std::string encode(const std::string& inputString, std::unordered_map<char, std::string> encoding);
    static std::string decode(const std::string& inputString, std::unordered_map<std::string, char> decoding);
};


#endif //STRING_ENCODER_GENERIC_H
