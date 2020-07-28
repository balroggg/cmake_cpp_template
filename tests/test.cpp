#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

int sum(int a, int b)
{
    return a+b;
}

TEST_CASE("sum"){
  REQUIRE(sum(0,0) == 0);
  REQUIRE(sum(0,1) == 1);
}

