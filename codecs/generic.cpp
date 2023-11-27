#include "generic.h"

std::string Generic::encode(const std::string &inputString, std::unordered_map<char, std::string> encoding) {
    std::string processedString;
    for (char character : inputString)
    {
        if(encoding.count(character))
            processedString += encoding[character];
        else
            processedString += character;
    }
    return processedString;
}

std::string Generic::decode(const std::string &inputString, std::unordered_map<std::string, char> decoding) {
    std::string processedString;

    size_t i = 0;
    while(i < inputString.length()){
        if (inputString[i] == '&'){
            size_t end = inputString.find(';', i);
            if (end == std::string::npos){
                processedString += inputString[i++];
            }
            else {
                std::string escapeCode = inputString.substr(i+1, end - i - 1);
                auto it = decoding.find(escapeCode);
                if (it != decoding.end()){
                    processedString += it->second;
                }
                else{
                    processedString += "&" + escapeCode + ";";
                }
                i = end + 1;
            }
        }
        else{
            processedString += inputString[i++];
        }
    }
    return processedString;
}
