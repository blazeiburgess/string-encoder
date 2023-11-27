#include "generic.h"

/**
 * @brief Encodes a given input string into a new string using a provided character-to-string mapping.
 *
 * @param inputString The string to be encoded.
 * @param encoding The character-to-string unordered map used for encoding. Each character in inputString
 *                 if present in the map will be replaced by its corresponding string in the map.
 *
 * @return std::string The encoded string. If a character in the inputString doesn't exist in the map,
 *                     it is added to the processed string as it is.
 */
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

/**
 * @brief Decodes a given input string into a new string using a provided string-to-character mapping.
 *
 * @param inputString The string to be decoded. If the string contains '&' character, it attempts to
 *                 decode the code between '&' and the next ';'. If no such ';' exists, the '&' character
 *                 is added to the processed string as it is.
 * @param decoding The string-to-character unordered map used for decoding. Each string matching the
 *                  pattern &...; in inputString where ... exists as a key in the map, it is replaced
 *                  by its corresponding character in the map.
 *
 * @return std::string The decoded string. If no matching pattern is found in the decoding map,
 *                      the pattern is added to the processed string as it is.
 */
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
