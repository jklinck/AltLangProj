// #define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#define CATCH_CONFIG_RUNNER


// git submodule add https://github.com/catchorg/Catch2.git

#include <catch2/catch_all.hpp>
#include <cmath>

#include "../include/Cell.h"
#include "../include/functions.h"
using namespace std;

// for comparing floats
bool areEqual(float a, float b, float tolerance = 1e-6) {
    return abs(a - b) < tolerance;
}

TEST_CASE("Make sure launchAnnounced is turned into an int, bodyWeight and displaySize are \
turned into floats.") {
    Cell* newCell = new Cell("a", "b", "1999", "c", "d", "190 g (6.70 oz)", "e", "f", "3.5 inches, 34.9 cm", "g", "h", "i");
    REQUIRE(newCell->getLaunchAnnounced() == 1999);
    REQUIRE(areEqual(newCell->getBodyWeight(), 190.0));
    REQUIRE(areEqual(newCell->getDisplaySize(), 3.5));
    delete newCell;
}

int main(int argc, char** argv) {
    Catch::Session session;
    int returnCode = session.run(argc, argv);
    return returnCode;
}





