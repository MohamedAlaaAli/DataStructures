// 020-TestCase-2.cpp
// Source: https://github.com/catchorg/Catch2/blob/master/examples/020-TestCase-2.cpp

#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../p1.h"

vector<string> dictionary = {
    "tarp",
    "given",
    "score",
    "refund",
    "only",
    "trap",
    "work",
    "earn",
    "course",
    "pepper",
    "part"
};

TEST_CASE("Test1", "[multi-file:2]")
{
    bool result = ransom_note("", "");
    REQUIRE(result == true);
}

TEST_CASE("Test2", "[multi-file:2]")
{
    bool result = ransom_note("", "");
    REQUIRE(result == true);
}

TEST_CASE("Test3", "[multi-file:2]")
{
    bool result = ransom_note("aa", "ab");
    REQUIRE(result == false);
}

TEST_CASE("Test4", "[multi-file:2]")
{
    bool result = ransom_note("aa", "aab");
    REQUIRE(result == true);
}

TEST_CASE("Test5", "[multi-file:2]")
{
    bool result = ransom_note("abc", "aab");
    REQUIRE(result == false);
}