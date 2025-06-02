#include <cstdlib>
#include <iostream>
#include <regex>
#include <string>
#include "../include/Phone.h"

using namespace std;

/*
launchAnnouced >> int
bodyWeight >> float
displaysize >> float

*/

Phone :: Phone(string o, string mod, string lann, string lst, string bd, string bw, string bs, string dt, 
string ds, string dr, string fs, string plat) : oem(o), model(mod), launchAnnounced(cleanLaunchAnnounced(lann)), 
launchStatus(cleanLaunchStatus(lst)), bodyDimensions(bd), bodyWeight(cleanBodyWeight(bw)), bodySim(cleanBodySim(bs)), displayType(dt), 
displaySize(cleanDisplaySize(ds)), displayResolution(dr), featuresSensors(fs), platformOS(cleanPlatformOS(plat)){
}

// 1. oem methods -----------------------------------------------
string Phone :: getOem() {
    return this->oem;
}

string Phone :: cleanOem() {
    // may not need this as nothing is invalid here
    return this->oem;
}

// 2. model methods ---------------------------------------------
string Phone :: getModel() {
    return this->model;
}

string Phone :: cleanModel() {
    // may not need this as nothing is invalid here
    return this->model;
}

// 3. launchAnnounced methods -----------------------------------
int Phone :: getLaunchAnnounced() {
    return this->launchAnnounced;
}

int Phone :: cleanLaunchAnnounced(const string& launch) {
    regex yearRegex(R"(\b(\d{4})\b)");
    smatch match;

    if (regex_search(launch, match, yearRegex)) {
        return stoi(match[1].str());
    }
    else {
        return 0;
    }
}

// 4. launchStatus methods --------------------------------------
string Phone :: getLaunchStatus() {
    return this->launchStatus;
}

string Phone :: cleanLaunchStatus(const string& status) {
    regex wordRegex(R"(\b(Discontinued|Cancelled|Available\.\sReleased\s\d{4})\b)");
    smatch match;

    if(regex_search(status, match, wordRegex)) {
        return match[1].str();
    }
    else{
        return "-";
    }
}


// 5. bodyDimensions methods ------------------------------------
string Phone :: getBodyDimensions() {
    return this->bodyDimensions;
}

string Phone :: cleanBodyDimensions() {
    // may not need this as nothing is invalid here
    return this->bodyDimensions;
}

// 6. bodyWeight methods ----------------------------------------
float Phone :: getBodyWeight() {
    return this->bodyWeight;
}

float Phone :: cleanBodyWeight(const string& weight) {
    regex regexGrams(R"(\b(\d{2,3})\b)");
    smatch match;

    if(regex_search(weight, match, regexGrams)) {
        return strtof(match[1].str().c_str(), nullptr);
    }
    else{
        return 0.0;
    }
}

// 7. bodySim methods -------------------------------------------
string Phone :: getBodySim() {
    return this->bodySim;
}

string Phone :: cleanBodySim(const string& cleanSim) {
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

// 8. displayType methods ---------------------------------------
string Phone :: getDisplayType() {
    return this->displayType;
}

string Phone :: cleanDisplayType() {
    // may not need this as nothing is invalid here
    return this->displayType;
}

// 9. displaySize methods ---------------------------------------
float Phone :: getDisplaySize() {
    return this->displaySize;
}

float Phone :: cleanDisplaySize(const string& size) {
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

// 10. displayResolution methods ---------------------------------
string Phone :: getDisplayResolution() {
    return this->displayResolution;
}

string Phone :: cleanDisplayResolution() {
    // may not need this as nothing is invalid here
    return this->displayResolution;
}

// 11. featuresSensors methods -----------------------------------
string Phone :: getFeaturesSensors() {
    return this->featuresSensors;
}

string Phone :: cleanFeaturesSensors() {
    //  not necessay as there isn't any data in the csv that is just numbers
    return this->featuresSensors;
}

// 12. platformOS methods ----------------------------------------
string Phone :: getPlatformOS() {
    return this->platformOS;
}

string Phone :: cleanPlatformOS(const string& platform) {
    regex beforeFirstComma(R"([^,]+)");
    smatch match;
    
    if(regex_search(platform, match, beforeFirstComma)) {
        return match[0].str();
    }
    else{
        return "-";
    }
}

