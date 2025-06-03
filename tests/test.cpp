// #define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#define CATCH_CONFIG_RUNNER

// git submodule add https://github.com/catchorg/Catch2.git

#include <catch2/catch_all.hpp>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>

#include "../include/Cell.h"
#include "../include/functions.h"
using namespace std;

// for comparing floats
bool areEqual(float a, float b, float tolerance = 1e-6) {
    return abs(a - b) < tolerance;
}


// Cell() constructor, getLaunchAnnounced(), getBodyWeight(), getDisplaySize() 
TEST_CASE("Make sure launchAnnounced is turned into an int, bodyWeight and displaySize are \
turned into floats. This is just testing if the constructor is working corrrectly.") {
    Cell* newCell = new Cell("a", "b", "1999", "c", "d", "190 g (6.70 oz)", "e", "f", "3.5 inches, 34.9 cm", "g", "h", "i");
    REQUIRE(newCell->getLaunchAnnounced() == 1999);
    REQUIRE(areEqual(newCell->getBodyWeight(), 190.0));
    REQUIRE(areEqual(newCell->getDisplaySize(), 3.5));
    delete newCell;
}

// deletePhone() 
TEST_CASE("Make sure a phone is deleted.") {
    unordered_map<int, Cell*> map;
    map[1] = new Cell("a", "b", "1999", "c", "d", "190 g (6.70 oz)", "e", "f", "3.5 inches, 34.9 cm", "g", "h", "i");
    map[2] = new Cell("a", "b", "1999", "c", "d", "190 g (6.70 oz)", "e", "f", "3.5 inches, 34.9 cm", "g", "h", "i");
    deletePhone(2, map);
    REQUIRE(map.size() == 1);
    delete map[1];
    delete map[2];
}

// countPhonesByOem()
TEST_CASE("Count phones by OEM.") {
    unordered_map<int, Cell*> map;
    map[1] = new Cell("a", "b", "1999", "c", "d", "190 g (6.70 oz)", "e", "f", "3.5 inches, 34.9 cm", "g", "h", "i");
    map[2] = new Cell("a", "b", "1999", "c", "d", "190 g (6.70 oz)", "e", "f", "3.5 inches, 34.9 cm", "g", "h", "i");
    int num = countPhonesByOem(map, "a");
    REQUIRE(num == 2);
    delete map[1];
    delete map[2];
}

// avgBodyWeight(), getBodyWeight()
TEST_CASE("Return the average body weight of a phone.") {
    unordered_map<int, Cell*> map;
    map[1] = new Cell("a", "b", "1999", "c", "d", "190 g (6.70 oz)", "e", "f", "3.5 inches, 34.9 cm", "g", "h", "i");
    map[2] = new Cell("a", "b", "1999", "c", "d", "210 g (6.70 oz)", "e", "f", "3.5 inches, 34.9 cm", "g", "h", "i");
    float avgWeight = (map[1]->getBodyWeight() + map[2]->getBodyWeight()) / 2.0;
    float avgWeightFunction = avgBodyWeight(map, 2);
   
    REQUIRE(areEqual(avgWeightFunction, avgWeight));
    delete map[1];
    delete map[2];
}

// avgDisplaySize(), getDisplaySize()
TEST_CASE("Finds the average display size.") {
    unordered_map<int, Cell*> map;
    map[1] = new Cell("a", "b", "1999", "c", "d", "190 g (6.70 oz)", "e", "f", "3.5 inches, 34.9 cm", "g", "h", "i");
    map[2] = new Cell("a", "b", "1999", "c", "d", "210 g (6.70 oz)", "e", "f", "4.5 inches, 34.9 cm", "g", "h", "i");
    float avgSize = (map[1]->getDisplaySize() + map[2]->getDisplaySize()) / 2.0;
    float avgSizeFunction = avgDisplaySize(map, 2);

    REQUIRE(areEqual(avgSizeFunction, avgSize));
    delete map[1];
    delete map[2];
}

// addPhone()
TEST_CASE("Adds a phone to the phone map.") {
    unordered_map<int, Cell*> map;
    map[1] = new Cell("a", "b", "1999", "c", "d", "190 g (6.70 oz)", "e", "f", "3.5 inches, 34.9 cm", "g", "h", "i");
    map[2] = new Cell("a", "b", "1999", "c", "d", "210 g (6.70 oz)", "e", "f", "4.5 inches, 34.9 cm", "g", "h", "i");
    addPhone(2, map, "a", "b", "1999", "c", "d", "190 g (6.70 oz)", "e", "f", "3.5 inches, 34.9 cm", "g", "h", "i");
    REQUIRE(map.size() == 3);

    delete map[1];
    delete map[2];
    delete map[3];
}

// findPhoneByModel()
TEST_CASE("Finds a phone by it's model name.") {
    unordered_map<int, Cell*> map;
    map[1] = new Cell("a", "b", "1999", "c", "d", "190 g (6.70 oz)", "e", "f", "3.5 inches, 34.9 cm", "g", "h", "i");
    map[2] = new Cell("a", "z", "1999", "c", "d", "210 g (6.70 oz)", "e", "f", "4.5 inches, 34.9 cm", "g", "h", "i");
    Cell* findModel = findPhoneByModel(map, "z");
    string model = findModel->getModel();
    REQUIRE(model == "z");

    delete map[1];
    delete map[2];
}

int main(int argc, char** argv) {
    Catch::Session session;
    int returnCode = session.run(argc, argv);
    return returnCode;
}





