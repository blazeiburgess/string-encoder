//
// Created by amilcar on 7/8/23.
//

#include "url.h"

// Encode an input string to be URL safe
/**
 * @brief Encodes a string to be URL safe
 * @param value The string to encode
 * @return The encoded string
 */
static std::string encode(const std::string& inputString) {
    std::string processedString;
    for (char character : inputString)
    {
        switch(character)
        {
            case '/': processedString += "%2F"; break;
            case ':': processedString += "%3A"; break;
            case '?': processedString += "%3F"; break;
            case '#': processedString += "%23"; break;
            case '[': processedString += "%5B"; break;
            case ']': processedString += "%5D"; break;
            case '@': processedString += "%40"; break;
            case '!': processedString += "%21"; break;
            case '$': processedString += "%24"; break;
            case '&': processedString += "%26"; break;
            case '\'': processedString += "%27"; break;
            case '(': processedString += "%28"; break;
            case ')': processedString += "%29"; break;
            case '*': processedString += "%2A"; break;
            case '+': processedString += "%2B"; break;
            case ',': processedString += "%2C"; break;
            case ';': processedString += "%3B"; break;
            case '=': processedString += "%3D"; break;
            default: processedString += character; break;
        }
    }
    return processedString;
}

static std::string decode(const std::string& inputString) {
    std::string processedString;
    for (int i=0; i<inputString.length(); i++){
        if (inputString[i] == '%'){
            if (inputString[i+1] == '2'){
                if (inputString[i+2] == 'F'){
                    processedString += "/";
                    i+=2;
                }
                else if (inputString[i+2] == '3'){
                    if (inputString[i+3] == 'A'){
                        processedString += ":";
                        i+=3;
                    }
                    else if (inputString[i+3] == 'F'){
                        processedString += "?";
                        i+=3;
                    }
                    else if (inputString[i+3] == 'D'){
                        processedString += "=";
                        i+=3;
                    }
                    else if (inputString[i+3] == 'B'){
                        processedString += ";";
                        i+=3;
                    }
                }
                else if (inputString[i+2] == '4'){
                    if (inputString[i+3] == '0'){
                        processedString += "@";
                        i+=3;
                    }
                    else if (inputString[i+3] == '1'){
                        processedString += "!";
                        i+=3;
                    }
                    else if (inputString[i+3] == '2'){
                        processedString += "$";
                        i+=3;
                    }
                    else if (inputString[i+3] == '3'){
                        processedString += "%";
                        i+=3;
                    }
                    else if (inputString[i+3] == '4'){
                        processedString += "&";
                        i+=3;
                    }
                    else if (inputString[i+3] == '5'){
                        processedString += "'";
                        i+=3;
                    }
                    else if (inputString[i+3] == '6'){
                        processedString += "(";
                        i+=3;
                    }
                    else if (inputString[i+3] == '7'){
                        processedString += ")";
                        i+=3;
                    }
                    else if (inputString[i+3] == '8'){
                        processedString += "*";
                        i+=3;
                    }
                    else if (inputString[i+3] == '9'){
                        processedString += "+";
                        i+=3;
                    }
                    else if (inputString[i+3] == 'A') {
                        processedString += ",";
                        i += 3;
                    }
                    else if (inputString[i+3] == 'B'){
                        processedString += ";";
                        i+=3;
                    }
                    else if (inputString[i+3] == 'C'){
                        processedString += "=";
                        i+=3;
                    }
                }
                else if (inputString[i+2] == '5'){
                    if (inputString[i+3] == 'B'){
                        processedString += "[";
                        i+=3;
                    }
                    else if (inputString[i+3] == 'D'){
                        processedString += "]";
                        i+=3;
                    }
                }
            }
        }
        else{
            processedString += inputString[i];
        }
    }
    return processedString;
}
