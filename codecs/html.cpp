#include "html.h"

std::string HTMLCodec::encode(const std::string& inputString) {
    std::string processedString;
    for (char character : inputString)
    {
        switch(character)
        {
            case '<': processedString += "&lt;"; break;
            case '>': processedString += "&gt;"; break;
            case '&': processedString += "&amp;"; break;
            case '"': processedString += "&quot;"; break;
            case '\'': processedString += "&apos;"; break;
            case ' ': processedString += "&nbsp;"; break;
            default: processedString += character; break;
        }
    }
    return processedString;
}

std::string HTMLCodec::decode(const std::string& inputString) {
    std::string processedString;
    for (int i=0; i<inputString.length(); i++){
        if (inputString[i] == '&'){
            if (inputString[i+1] == 'a'){
                if (inputString[i+2] == 'm'){
                    processedString += "&";
                    i+=3;
                }
                else if (inputString[i+2] == 'p'){
                    processedString += "'";
                    i+=3;
                }
            }
            else if (inputString[i+1] == 'l'){
                processedString += "<";
                i+=3;
            }
            else if (inputString[i+1] == 'g'){
                processedString += ">";
                i+=3;
            } else if (inputString[i+1] == 'n'){
                processedString += " ";
                i+=5;
            } else if (inputString[i+1] == 'q'){
                processedString += "\"";
                i+=5;
            }
        }
        else{
            processedString += inputString[i];
        }
    }
    return processedString;
}
