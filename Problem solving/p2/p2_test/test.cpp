// 020-TestCase-2.cpp
// Source: https://github.com/catchorg/Catch2/blob/master/examples/020-TestCase-2.cpp

#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../p2.h"

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

TEST_CASE("1_resco", "[multi-file:2]")
{
    set<string> result = word_amalgamation(dictionary, "resco");
    REQUIRE(result.size() == 1);
    REQUIRE(result.find("score") != result.end());
}

TEST_CASE("2_oresuc", "[multi-file:2]")
{
    set<string> result = word_amalgamation(dictionary, "oresuc");
    REQUIRE(result.size() == 1);
    REQUIRE(result.find("course") != result.end());
}

TEST_CASE("3_nfudre", "[multi-file:2]")
{
    set<string> result = word_amalgamation(dictionary, "nfudre");
    REQUIRE(result.size() == 1);
    REQUIRE(result.find("refund") != result.end());
}

TEST_CASE("4_aptr", "[multi-file:2]")
{
    set<string> result = word_amalgamation(dictionary, "aptr");
    REQUIRE(result.size() == 3);
    REQUIRE(result.find("part") != result.end());
    REQUIRE(result.find("tarp") != result.end());
    REQUIRE(result.find("trap") != result.end());
}

TEST_CASE("5_sett", "[multi-file:2]")
{
    set<string> result = word_amalgamation(dictionary, "sett");
    REQUIRE(result.size() == 0);
}