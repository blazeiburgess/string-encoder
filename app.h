#ifndef URL_ENCODED_APP_H
#define URL_ENCODED_APP_H

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>
#include "codecs/html.h"

class App {
public:
    App(int argc, char** argv);
    ~App() = default;

    static std::string url_encode(const std::string &value);
    static std::string url_decode(std::string str);
    void run() const;
    bool invalidArgumentCount = false;

private:
    std::string actionType;
    int numberOfArguments;
    int startIndex;
    std::vector<std::string> arguments;
    HTMLCodec htmlCodec;
};


#endif //URL_ENCODED_APP_H
