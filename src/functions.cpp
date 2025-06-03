#include "../include/Cell.h"
#include "../include/functions.h"
#include <cmath> // round function
#include <iostream>
#include <unordered_map>
using namespace std;

float avgBodyWeight(const unordered_map<int, Cell*>& map, int size) {
    float total = 0.0;
    float average = 0.0;

    for(auto it = map.begin(); it != map.end(); it++) {
        Cell* cell = it->second;
        if(cell != nullptr && cell->getBodyWeight() != 0.0) {
            total += cell->getBodyWeight();
        }
    }
    average = total / size;

    float scale = pow(10.0, 2);
    average = round(average * scale) / scale;

    return average;
}

void deletePhone(int phone, unordered_map<int, Cell*>& phoneMap) {
    phoneMap.erase(phone);
}

void addPhone(int mapCount, unordered_map<int, Cell*>& phoneMap, const string& oem, const string& model, 
    const string& launchAnnounced, const string& launchStatus, const string& bodyDimensions, 
    const string& bodyWeight, const string& bodySim, const string& displayType, 
    const string& displaySize, const string& displayResolution, const string& featuresSensors, 
    const string& platformOS) {
    Cell* cell = new Cell(oem, model, launchAnnounced, launchStatus, bodyDimensions, bodyWeight, 
    bodySim, displayType, displaySize, displayResolution, featuresSensors, platformOS);

    mapCount++;
    phoneMap[mapCount] = cell;
}

float avgDisplaySize(const unordered_map<int, Cell*>& map, int size) {
    float total = 0.0;
    float average = 0.0;

    for(auto it = map.begin(); it != map.end(); it++) {
        Cell* cell = it->second;
        if(cell != nullptr && cell->getDisplaySize() != 0.0) {
            total += cell->getDisplaySize();
        }
    }
    average = total / size;

    float scale = pow(10.0, 2);
    average = round(average * scale) / scale;

    return average;
}

Cell* findPhoneByModel(const unordered_map<int, Cell*>& map, const string& model) {
    for (const auto& pair : map) { 
        if (pair.second->getModel() == model) { 
            return pair.second; 
        }
    }
    return nullptr; 
}

int countPhonesByOem(const unordered_map<int, Cell*>& map, const string& oem) {
    int count = 0;
    for (const auto& pair : map) {
        if (pair.second->getOem() == oem) { 
            count++;
            cout << "Counting phone ID: " << pair.first << " with OEM: " << oem << endl;
        }
    }
    cout << "Total count for OEM " << oem << ": " << count << endl;
    return count;
}
