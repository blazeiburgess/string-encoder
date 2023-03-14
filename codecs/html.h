#ifndef URL_ENCODED_HTML_H
#define URL_ENCODED_HTML_H


#include <string>
#include <iostream>

class HTMLCodec {
public:
    HTMLCodec() = default;
    ~HTMLCodec() = default;

    static std::string encode(const std::string& inputString);
    static std::string decode(const std::string& inputString);
private:

};


#endif //URL_ENCODED_HTML_H
