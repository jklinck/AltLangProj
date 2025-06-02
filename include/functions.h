#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <unordered_map>
#include "../include/Cell.h"
using namespace std;

// returns the average body weight of all phones in the csv file
float avgBodyWeight(const unordered_map<int, Cell*>& map);

#endif