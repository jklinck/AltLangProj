#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <unordered_map>
#include "../include/Cell.h"
using namespace std;

// returns the average body weight of all phones in the csv file
float avgBodyWeight(const unordered_map<int, Cell*>& map);

// deletes a from from the map
void deletePhone(int phone, unordered_map<int, Cell*>& phoneMap);

void addPhone(int mapCount, unordered_map<int, Cell*>& phoneMap, const string& oem, const string& model, 
    const string& launchAnnounced, const string& launchStatus, const string& bodyDimensions, 
    const string& bodyWeight, const string& bodySim, const string& displayType, 
    const string& displaySize, const string& displayResolution, const string& featuresSensors, 
    const string& platformOS);

float avgDisplaySize(const unordered_map<int, Cell*>& map);

Cell* findPhoneByModel(const unordered_map<int, Cell*>& map, const string& model);

void countPhonesByOem(const unordered_map<int, Cell*>& map, const string& oem);


#endif