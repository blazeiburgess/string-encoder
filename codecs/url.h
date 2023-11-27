#ifndef STRING_ENCODER_URL_H
#define STRING_ENCODER_URL_H

#include <string>
#include "generic.h"

class URLCodec : Generic {
public:
    URLCodec() = default;
    ~URLCodec() = default;

    static std::string encode(const std::string& inputString);
    static std::string decode(const std::string& inputString);
};


#endif //STRING_ENCODER_URL_H
