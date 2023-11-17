#include <catch2/catch.hpp>
#include <Gimnasio.cpp>

TEST_CASE("My first test with Catch2", "[fancy]")
{
    REQUIRE(0 == 0);
}

TEST_CASE("determinarClase")
{
    int S = 1, Y = 2, P = 3, St = 4, Z = 5, B = 6, M = 7;
    int v1 = 0, v2 = -2, v3 = 9;
    REQUIRE(determinarClase(int S) == "Spinning");
    REQUIRE(determinarClase(int Y) == "Yoga");
    REQUIRE(determinarClase(int P) == "Pilates");
    REQUIRE(determinarClase(int St) == "Stretching");
    REQUIRE(determinarClase(int Z) == "Zumba");
    REQUIRE(determinarClase(int B) == "Boxeo");
    REQUIRE(determinarClase(int M) == "Musculacion");

    REQUIRE(determinarClase(int v1) == "");
    REQUIRE(determinarClase(int v2) == "");
    REQUIRE(determinarClase(int v3) == "");
}
