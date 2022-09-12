#pragma once

#include <algorithm>
#include <array>
#include <string>
#include <sstream>
#include <tuple>

/*    simple functions that translates from and to morse                         */
/*    be aware that for morse a '/' is used for splitting words e.g. ".- / ..-"  */
/*    and ' ' for letters e.g. ".- ..-"                                          */

namespace morse
{
    // available functions
    inline std::string translate(std::string &message); // automatically detects whether string is latin or morse and translates it
    inline std::string to_morse(std::string &message);
    inline std::string to_latin(std::string &message);

    //helper functions
    inline void to_upper(std::string &message);
    inline bool is_morse(std::string &message);
    inline void ltrim(std::string &s);
    inline void rtrim(std::string &s);


    // dictionary // TODO: Bimap
    inline const std::array<std::pair<std::string, std::string>, 58>
        morse_dict = {{{"A", ".-"},
                       {"B", "-..."},
                       {"C", "-.-."},
                       {"D", "-.."},
                       {"E", "."},
                       {"F", "..-."},
                       {"G", "--."},
                       {"H", "...."},
                       {"I", ".."},
                       {"J", ".---"},
                       {"K", "-.-"},
                       {"L", ".-.."},
                       {"M", "--"},
                       {"N", "-."},
                       {"O", "---"},
                       {"P", ".--."},
                       {"Q", "--.-"},
                       {"R", ".-."},
                       {"S", "..."},
                       {"T", "-"},
                       {"U", "..-"},
                       {"V", "...-"},
                       {"W", ".--"},
                       {"X", "-..-"},
                       {"Y", "-.--"},
                       {"Z", "--.."},
                       {"Ö", "---."},
                       //{"ß", "...--.."}, doesnt work?
                       {"Ü", "..--"},
                       {"Ä", ".-.-"},
                       {"CH", "----"},
                       {".", ".-.-.-"},
                       {":", "---..."},
                       {",", "--..--"},
                       {";", "-.-.-."},
                       {"?", "..--.."},
                       {"!", "-.-.--"},
                       {"-", "-....-"},
                       {"_", "..--.-"},
                       {"(", "-.--."},
                       {")", "-.--.-"},
                       {"=", "-...-"},
                       {"+", ".-.-."},
                       {"/", "-..-."},
                       {"@", ".--.-."},
                       {" ", "/"},
                       {"1", ".----"},
                       {"2", "..---"},
                       {"3", "...--"},
                       {"4", "....-"},
                       {"5", "....."},
                       {"6", "-...."},
                       {"7", "--..."},
                       {"8", "---.."},
                       {"9", "----."},
                       {"0", "-----"},
                       {"SOS", "...---..."}}};


    // implementations
    void to_upper(std::string &message)
    {
        for (char& c : message)
            if (c >= 'a' && c <= 'z')
                c -= 32;
    }

    bool is_morse(std::string &message)
    {
        for (auto c : message)
            if (c != ' ' && c != '-' && c != '.' && c != '/')
                return false;

        return true;
    }

    std::string to_morse(std::string &message)
    {
        to_upper(message);
        std::string result;
        for (char c : message)
            for (auto &entry : morse_dict)
                if (entry.first == std::string{c})
                    result += entry.second + ' ';

        rtrim(result);
        return result;
    }

    std::string to_latin(std::string &message)
    {
        std::stringstream ss{message};
        std::string result;
        std::string tmp;

        while (ss >> tmp)
        {
            for (auto &entry : morse_dict)
                if (entry.second == result)
                    result += entry.first;
            continue;

            result += "UNKOWN";
        }

        return result;
    }

    std::string translate(std::string &message)
    {
        if (is_morse(message))
            return to_latin(message);
        else
            return to_morse(message);
    }

    void ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !std::isspace(ch);
        }));
    }

    void rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), s.end());
    }
}
