#include <cstdlib>  // for strtof method
#include <iostream>
#include <regex>
#include <string>
#include "../include/Cell.h"

using namespace std;

// constructor
Cell :: Cell(string o, string mod, string lann, string lst, string bd, string bw, string bs, string dt, 
string ds, string dr, string fs, string plat) : oem(o), model(mod), launchAnnounced(cleanLaunchAnnounced(lann)), 
launchStatus(cleanLaunchStatus(lst)), bodyDimensions(bd), bodyWeight(cleanBodyWeight(bw)), bodySim(cleanBodySim(bs)), displayType(dt), 
displaySize(cleanDisplaySize(ds)), displayResolution(dr), featuresSensors(fs), platformOS(cleanPlatformOS(plat)){
}

// 1. oem methods ---------------------------------------------------------------------------------
string Cell::getOem() {
    return this->oem;
}

void Cell::setOem(const string& oem){
    this->oem = oem;
}

// 2. model methods -------------------------------------------------------------------------------
string Cell::getModel() {
    return this->model;
}

void Cell::setModel(const string& model) {
    this->model = model;
}

// 3. launchAnnounced methods ---------------------------------------------------------------------
int Cell::getLaunchAnnounced() {
    return this->launchAnnounced;
}

void Cell::setLaunchAnnounced(int announced) {
    this->launchAnnounced = announced;
}

int Cell::cleanLaunchAnnounced(const string& launch) {
    regex yearRegex(R"(\b(\d{4})\b)");
    smatch match;

    if (regex_search(launch, match, yearRegex)) {
        return stoi(match[1].str());
    }
    else {
        return 0;
    }
}

// 4. launchStatus methods ------------------------------------------------------------------------
string Cell::getLaunchStatus() {
    return this->launchStatus;
}

void Cell::setLaunchStatus(const string& status) {
    this->launchStatus = status;
}

string Cell::cleanLaunchStatus(const string& status) {
    regex wordRegex(R"(\b(Discontinued|Cancelled|Available\.\sReleased\s\d{4})\b)");
    smatch match;

    if(regex_search(status, match, wordRegex)) {
        return match[1].str();
    }
    else{
        return "-";
    }
}

// 5. bodyDimensions methods ----------------------------------------------------------------------
string Cell::getBodyDimensions() {
    return this->bodyDimensions;
}

void Cell::setBodyDimensions(const string& dimensions) {
    this->bodyDimensions = dimensions;
}

// 6. bodyWeight methods --------------------------------------------------------------------------
float Cell::getBodyWeight() {
    return this->bodyWeight;
}

void Cell::setBodyWeight(float weight) {
    this->bodyWeight = weight;
}

float Cell::cleanBodyWeight(const string& weight) {
    regex regexGrams(R"(\b(\d{2,3})\b)");
    smatch match;

    if(regex_search(weight, match, regexGrams)) {
        return strtof(match[1].str().c_str(), nullptr);
    }
    else{
        return 0.0;
    }
}

// 7. bodySim methods -----------------------------------------------------------------------------
string Cell::getBodySim() {
    return this->bodySim;
}

void Cell::setBodySim(const string& sim) {
    this->bodySim = sim;
}

string Cell::cleanBodySim(const string& cleanSim) {
    // regex yesNo("^(?!Yes$)(?!No$).*");  this is my original
    regex yesNo("^(Yes|No)$");
    smatch match;

    if(regex_search(cleanSim, match, yesNo)) {
        return "-";
    }
    else{
        return cleanSim;
    }
}

// 8. displayType methods -------------------------------------------------------------------------
string Cell::getDisplayType() {
    return this->displayType;
}

void Cell::setDisplayType(const string& type) {
    this->displayType = type;
}

// 9. displaySize methods -------------------------------------------------------------------------
float Cell::getDisplaySize() {
    return this->displaySize;
}

void Cell::setDisplaySize(float size) {
    this->displaySize = size;
}

float Cell::cleanDisplaySize(const string& size) {
    regex sizeFloat(R"(\b(\d{1,2}\.\d{1,2})\b)");
    smatch match;
    char* end;

    if(regex_search(size, match, sizeFloat)) {
        return strtof(match[0].str().c_str(), &end);
    }
    else{
        return 0.0;
    }
}

// 10. displayResolution methods ------------------------------------------------------------------
string Cell::getDisplayResolution() {
    return this->displayResolution;
}

void Cell::setDisplayResolution(const string& resolution) {
    this->displayResolution = resolution;
}

// 11. featuresSensors methods -------------------------------------------------------------------
string Cell::getFeaturesSensors() {
    return this->featuresSensors;
}

void Cell::setFeaturesSensors(const string& features) {
    this->featuresSensors = features;
}

// 12. platformOS methods -------------------------------------------------------------------------
string Cell::getPlatformOS() {
    return this->platformOS;
}

void Cell::setPlatformOS(const string& platform) {
    this->platformOS = platform;
}

string Cell::cleanPlatformOS(const string& platform) {
    if (platform.empty() || all_of(platform.begin(), platform.end(), ::isspace)) {
        return "-";
    }

    regex beforeFirstComma(R"([^,]+)");
    smatch match;
    
    if(regex_search(platform, match, beforeFirstComma)) {
        return match[0].str();
    }
    else{
        return "-";
    }
}

// ------------------------------------------------------------------------------------------------
// other methods

/*
This method it will automatically print the first entry in the CSV file. If you would like to 
print a different line YOU will need to manually change the parameter in the 
method. The call will look like this `phoneMap[2]->toString`, you will need to manually change 
the 2 in the brackets to whatever number you would like to substitute.
*/
void Cell :: toString() {
    cout << "Oem: " << this->oem << endl;
    cout << "Model: " << this->model << endl;
    cout << "Launch announce: " << this->launchAnnounced << endl;
    cout << "Launch status: " << this->launchStatus << endl;
    cout << "Body dimensions: " << this->bodyDimensions << endl;
    cout << "Body weight: " << this->bodyWeight << endl;
    cout << "Body sim: " << this->bodySim << endl;
    cout << "Display type: " << this->displayType << endl;
    cout << "Display size: " << this->displaySize << endl;
    cout << "Display resolution: " << this->displayResolution << endl;
    cout << "Features sensors: " << this->featuresSensors << endl;
    cout << "Plaftorm OS: " << this->platformOS << endl;
}

    


