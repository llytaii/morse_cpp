#include <iostream>
#include <string>
#include "morse.hpp"

int main()
{
    std::string s{"hi lo"};
    morse::to_morse(s);
}