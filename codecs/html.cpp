#include <unordered_map>
#include "html.h"

std::string HTMLCodec::encode(const std::string& inputString) {
    std::unordered_map<char, std::string> htmlEncoding = {
            {'<', "&lt;"},
            {'>', "&gt;"},
            {'&', "&amp;"},
            {'"', "&quot;"},
            {'\'', "&apos;"},
            {' ', "&nbsp;"},
    };

    return Generic::encode(inputString, htmlEncoding);
}

std::string HTMLCodec::decode(const std::string &inputString) {
    std::string processedString;
    std::unordered_map<std::string, char> decodeMap = {
            {"amp", '&'},
            {"apos", '\''},
            {"lt",  '<'},
            {"gt",  '>'},
            {"nbsp", ' '},
            {"quot", '"'},
    };

    return Generic::decode(inputString, decodeMap);
}
