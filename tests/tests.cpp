#include "catch2/catch.hpp"
#include "morse.hpp"


TEST_CASE("[to_upper]")
{
    std::string s1{"test"};
    morse::to_upper(s1);
    std::string s2{"Hello World!"};
    morse::to_upper(s2);
    std::string s3{"HELLOABC?"};
    morse::to_upper(s3);

    REQUIRE( s1 == "TEST");
    REQUIRE( s2 == "HELLO WORLD!");
    REQUIRE( s3 == "HELLOABC?");
}

TEST_CASE("[is_morse]")
{
    std::string s1{".- --"};
    std::string s2{"Hello World!"};
    std::string s3{"h-.-- ?"};

    REQUIRE( morse::is_morse(s1) == true);
    REQUIRE( morse::is_morse(s2) == false);
    REQUIRE( morse::is_morse(s3) == false);
}

TEST_CASE("[to_morse]")
{
    std::string s1{"hi"};
    std::string s2{"DIES IST EIN TEST!"};
    std::string s3{"noch ein grosser test"};

    REQUIRE( morse::to_morse(s1) == ".... ..");
    REQUIRE( morse::to_morse(s2) == "-.. .. . ... / .. ... - / . .. -. / - . ... - -.-.--");
    REQUIRE( morse::to_morse(s3) == "-. --- -.-. .... / . .. -. / --. .-. --- ... ... . .-. / - . ... -");
}