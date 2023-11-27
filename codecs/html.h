#ifndef URL_ENCODED_HTML_H
#define URL_ENCODED_HTML_H


#include<string>
#include <iostream>
#include "generic.h"

class HTMLCodec : public Generic {
public:
    HTMLCodec() = default;
    ~HTMLCodec() = default;

    static std::string encode(const std::string& inputString);
    static std::string decode(const std::string& inputString);
    CharacterEncoding characterMappings[6] = {
            {'<', "&lt;"},
            {'>', "&gt;"},
            {'&', "&amp;"},
            {'"', "&quot;"},
            {'\'', "&apos;"},
            {' ', "&nbsp;"}
    };
private:

};


#endif //URL_ENCODED_HTML_H
