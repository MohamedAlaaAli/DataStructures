// 020-TestCase-2.cpp
// Source: https://github.com/catchorg/Catch2/blob/master/examples/020-TestCase-2.cpp

#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "../deque.h"
#include <vector>

TEST_CASE("Constructor", "[multi-file:2]")
{
    My_Deque<int> my_deque = My_Deque<int>();
    REQUIRE(my_deque.get_size() == 0);
}

TEST_CASE("Push front", "[multi-file:2]")
{
    My_Deque<int> my_deque = My_Deque<int>();
    my_deque.push_front(5);
    my_deque.push_front(0);
    REQUIRE(my_deque.get_size() == 2);
    REQUIRE(my_deque.end() == 5);
    REQUIRE(my_deque.begin() == 0);
}

TEST_CASE("Push front 2", "[multi-file:2]")
{
    My_Deque<int> my_deque = My_Deque<int>();
    my_deque.push_front(1);
    my_deque.push_front(2);
    my_deque.push_front(3);
    my_deque.push_front(4);
    std::vector<int> result = my_deque.toVector();
    REQUIRE(my_deque.get_size() == 4);
    REQUIRE(result[1] == 3);
    REQUIRE(result[2] == 2);
}

TEST_CASE("Push back", "[multi-file:2]")
{
    My_Deque<int> my_deque = My_Deque<int>();
    my_deque.push_back(5);
    my_deque.push_back(0);
    REQUIRE(my_deque.get_size() == 2);
    REQUIRE(my_deque.end() == 0);
    REQUIRE(my_deque.begin() == 5);
}

TEST_CASE("Push back 2", "[multi-file:2]")
{
    My_Deque<int> my_deque = My_Deque<int>();
    my_deque.push_back(1);
    my_deque.push_back(2);
    my_deque.push_back(3);
    my_deque.push_back(4);
    std::vector<int> result = my_deque.toVector();
    REQUIRE(my_deque.get_size() == 4);
    REQUIRE(result[1] == 2);
    REQUIRE(result[2] == 3);
}

TEST_CASE("pop front", "[multi-file:2]")
{
    My_Deque<int> my_deque = My_Deque<int>();
    my_deque.push_back(1);
    my_deque.push_back(2);
    my_deque.push_back(3);
    my_deque.push_back(4);
    int actual = my_deque.pop_front();
    int expected = 1;
    std::vector<int> result = my_deque.toVector();
    REQUIRE(my_deque.get_size() == 3);
    REQUIRE(actual == expected);
    REQUIRE(result[1] == 3);
}

TEST_CASE("pop back", "[multi-file:2]")
{
    My_Deque<int> my_deque = My_Deque<int>();
    my_deque.push_back(1);
    my_deque.push_back(2);
    my_deque.push_back(3);
    my_deque.push_back(4);
    int actual = my_deque.pop_back();
    int expected = 4;
    std::vector<int> result = my_deque.toVector();
    REQUIRE(my_deque.get_size() == 3);
    REQUIRE(actual == expected);
    REQUIRE(result[1] == 2);
}

TEST_CASE("clear", "[multi-file:2]")
{
    My_Deque<int> my_deque = My_Deque<int>();
    my_deque.push_back(1);
    my_deque.push_back(2);
    my_deque.push_back(3);
    my_deque.push_back(4);
    my_deque.clear();
    my_deque.push_front(5);
    my_deque.push_front(6);
    REQUIRE(my_deque.get_size() == 2);
    REQUIRE(my_deque.begin() == 6);
    REQUIRE(my_deque.end() == 5);
}

TEST_CASE("invalid cases", "[multi-file:2]")
{
    My_Deque<int> my_deque = My_Deque<int>();
    REQUIRE(my_deque.get_size() == 0);
    REQUIRE(my_deque.end() == -1);
    REQUIRE(my_deque.begin() == -1);
    REQUIRE(my_deque.pop_back() == -1);
    REQUIRE(my_deque.pop_front() == -1);
}

TEST_CASE("invalid cases 2", "[multi-file:2]")
{
    My_Deque<int> my_deque = My_Deque<int>();
    my_deque.push_back(1);
    my_deque.push_back(2);
    my_deque.push_back(3);
    my_deque.push_back(4);
    my_deque.clear();
    REQUIRE(my_deque.get_size() == 0);
    REQUIRE(my_deque.end() == -1);
    REQUIRE(my_deque.begin() == -1);
    REQUIRE(my_deque.pop_back() == -1);
    REQUIRE(my_deque.pop_front() == -1);
}

TEST_CASE("invalid cases 3", "[multi-file:2]")
{
    My_Deque<int> my_deque = My_Deque<int>();
    my_deque.push_back(1);
    my_deque.push_back(2);
    my_deque.push_back(3);
    my_deque.push_back(4);
    my_deque.pop_back();
    my_deque.pop_front();
    my_deque.pop_back();
    my_deque.pop_front();
    REQUIRE(my_deque.get_size() == 0);
    REQUIRE(my_deque.end() == -1);
    REQUIRE(my_deque.begin() == -1);
    REQUIRE(my_deque.pop_back() == -1);
    REQUIRE(my_deque.pop_front() == -1);
}