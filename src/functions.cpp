#include "../include/Cell.h"
#include "../include/functions.h"
#include <cmath> // round function
#include <iostream>
using namespace std;

float avgBodyWeight(const unordered_map<int, Cell*>& map) {
    float total = 0.0;
    float average = 0.0;

    for(auto it = map.begin(); it != map.end(); it++) {
        Cell* cell = it->second;
        if(cell != nullptr && cell->getBodyWeight() != 0.0) {
            total += cell->getBodyWeight();
        }
    }
    average = total / 1000;

    // this is one of the reasons C++ is such a pain, it's soooooooo much simpler to do this 
    // in C or Java with format specifiers, all I'm doing here is limiting the return to 
    // 2 decimal places
    // float scale = pow(10.0, 2);
    // average = round(average * scale) / scale;

    return average;
}