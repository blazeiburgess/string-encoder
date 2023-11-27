#include "app.h"

App::App(int argc, char **argv) {
    arguments.reserve(argc);
    for (int i = 0; i < argc; ++i) {
        arguments.emplace_back(argv[i]);
    }
    numberOfArguments = argc;

    if (numberOfArguments < 2) {
        std::cout << "No arguments passed in."
                  << "\n\nValid types are:\n  - urlencode\n  - urldecode" <<  std::endl;
        invalidArgumentCount = true;
    }

    if (numberOfArguments > 2) {
        actionType = arguments[1];
        startIndex = 2;
    } else {
        actionType = "urlencode";
        startIndex = 1;
    }

    if (actionType != "urlencode" && actionType != "urldecode" && actionType != "htmlencode" && actionType != "htmldecode") {
        std::cout << "Invalid action type: " << actionType
                  << "\n\nValid types are:\n  - urlencode\n  - urldecode" <<  std::endl;
        invalidArgumentCount = true;
    }
}

void App::run() const {
    int argumentIndex = startIndex;
    for (argumentIndex; argumentIndex < numberOfArguments; argumentIndex++) {
        std::string arg = arguments[startIndex];
        std::string processed;

        if (actionType == "urlencode") {
            processed = url_encode(arg);
        } else if (actionType == "urldecode") {
            processed = url_decode(arg);
        } else if (actionType == "htmlencode") {
            processed = htmlCodec.encode(arg);
        } else if (actionType == "htmldecode") {
            processed = htmlCodec.decode(arg);
        } else {
            std::cout << "Invalid action type: " << actionType
                      << "\n\nValid types are:\n  - urlencode\n  - urldecode" <<  std::endl;
        }

        std::cout << processed << std::endl;
    }
}

/**
 * @brief Encodes a string to be URL safe
 * @param value The string to encode
 * @return The encoded string
 */
std::string App::url_encode(const std::string &value) {
    std::ostringstream escaped;
    escaped.fill('0');
    escaped << std::hex;

    for (std::string::const_iterator i = value.begin(), n = value.end(); i != n; ++i) {
        std::string::value_type c = (*i);

        // Keep alphanumeric and other accepted characters intact
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            escaped << c;
            continue;
        }

        // Any other characters are percent-encoded
        escaped << std::uppercase;
        escaped << '%' << std::setw(2) << int((unsigned char) c);
        escaped << std::nouppercase;
    }

    return escaped.str();
}

/**
 * @brief Decodes a URL encoded string
 * @param str The URL encoded string
 * @return The decoded string
 */
std::string App::url_decode(std::string str) {
    std::string ret;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != '%')
        {
            ret += str[i];
        }
        else
        {
            char* end;
            int j = std::strtoul(str.substr(i+1,2).c_str(), &end, 16); // using strtoul here
            if (*end) {
                throw std::runtime_error("Conversion error in url_decode");
            }
            ret += static_cast<char>(j);
            i += 2;
        }
    }
    return ret;
}