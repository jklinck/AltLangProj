#include <iostream>  // cout
#include <fstream>  // ifstream
#include <sstream>  // stringstream
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "../include/Phone.h"
using namespace std;

int main(){
  
  unordered_map<int, Phone*> phoneMap;
  unordered_set<Phone*> phoneSet;

  ifstream myFile;
  myFile.open("data/cells.csv");
  string line = ""; 
  string oem = "", model = "", launchAnnounced = "", launchStatus = "", bodyDimensions = "";
  string bodyWeight = "", bodySim = "", displayType = "", displaySize = "", displayResolution = "";
  string featuresSensors = "", platformOS = "";
  int lineCount = 1, location = 0, mapCount = 2;
  int begin = 0, end = 0;

  // read the columns names in 
  getline(myFile, line);

  while(getline(myFile, line)) {
    stringstream lineStream(line);

    // get oem ----------------------------------------------------------
    location = line.find(',');
    oem  = line.substr(0, location);
    line = line.substr(location + 1, line.length());
    
    // get model
    location = line.find(',');
    model = line.substr(0, location);
    line = line.substr(location + 1, line.length());

    // get launchAnnounced ----------------------------------------------
    if(line[0] == '"') {
      line = line.substr(1, line.length());
      end = line.find('"');
      launchAnnounced = line.substr(0, end);
      line = line.substr(end + 2, line.length());
    }
    else{
      location = line.find(',');
      launchAnnounced = line.substr(0, location);
      line = line.substr(location + 1, line.length());
    }
    
    // get launchStatus -------------------------------------------------
    if(line[0] == '"') {
      line = line.substr(1, line.length());
      end = line.find('"');
      launchStatus = line.substr(0, end);
      line = line.substr(end + 2, line.length());
    }
    else{
      location = line.find(',');
      launchStatus = line.substr(0, location);
      line = line.substr(location + 1, line.length());
    }

    // get bodyDimensions -----------------------------------------------
    location = line.find(',');
    bodyDimensions = line.substr(0, location);
    line = line.substr(location + 1, line.length());

    // get bodyWeight ---------------------------------------------------
    location = line.find(',');
    bodyWeight = line.substr(0, location);
    line = line.substr(location + 1, line.length());

    // bet bodySim ------------------------------------------------------
    if(line[0] == '"') {
      line = line.substr(1, line.length());
      end = line.find('"');
      bodySim = line.substr(0, end);
      line = line.substr(end + 2, line.length());
    }
    else{
      location = line.find(',');
      bodySim = line.substr(0, location);
      line = line.substr(location + 1, line.length());
    }

    // get displayType --------------------------------------------------
    if(line[0] == '"') {
      line = line.substr(1, line.length());
      end = line.find('"');
      displayType = line.substr(0, end);
      line = line.substr(end + 2, line.length());
    }
    else{
      location = line.find(',');
      displayType = line.substr(0, location);
      line = line.substr(location + 1, line.length());
    }

    // get displaySize --------------------------------------------------
    if(line[0] == '"') {
      line = line.substr(1, line.length());
      end = line.find('"');
      displaySize = line.substr(0, end);
      line = line.substr(end + 2, line.length());
    }
    else{
      location = line.find(',');
      displaySize = line.substr(0, location);
      line = line.substr(location + 1, line.length());
    }

    // get displayResolution --------------------------------------------
    if(line[0] == '"') {
      line = line.substr(1, line.length());
      end = line.find('"');
      displayResolution = line.substr(0, end);
      line = line.substr(end + 2, line.length());
    }
    else{
      location = line.find(',');
      displayResolution = line.substr(0, location);
      line = line.substr(location + 1, line.length());
    }

    // get featuresSensors ----------------------------------------------
    if(line[0] == '"') {
      line = line.substr(1, line.length());
      end = line.find('"');
      featuresSensors = line.substr(0, end);
      line = line.substr(end + 2, line.length());
    }
    else{
      location = line.find(',');
      featuresSensors = line.substr(0, location);
      line = line.substr(location + 1, line.length());
    }

    //  get platformOS
    if(line[0] == '"') {
      line = line.substr(1, line.length());
      end = line.find('"');
      platformOS = line.substr(0, end);
    }
    else{
      platformOS = line;
    }

    // Phone* current = new Phone(oem, model, launchAnnounced, launchStatus, bodyDimensions, 
    // bodyWeight, bodySim, displayType, displaySize, displayResolution, featuresSensors, 
    // platformOS);
    
      // phoneMap[mapCount] = new Phone(oem, model, launchAnnounced, launchStatus, bodyDimensions, 
      // bodyWeight, bodySim, displayType, displaySize, displayResolution, featuresSensors, 
      // platformOS);

    phoneSet.insert(new Phone(oem, model, launchAnnounced, launchStatus, bodyDimensions, 
    bodyWeight, bodySim, displayType, displaySize, displayResolution, featuresSensors, 
    platformOS));

    // if(mapCount == 49) {
    //   cout << "Oem: " << phoneMap[mapCount]->getOem() << endl;
    //   cout << "Model: " << phoneMap[mapCount]->getModel() << endl;
    //   cout << "Launch announced: " << phoneMap[mapCount]->getLaunchAnnounced() << endl;
    //   cout << "Launch status: " << phoneMap[mapCount]->getLaunchStatus() << endl;
    //   cout << "bodyDimensions: " << phoneMap[mapCount]->getBodyDimensions() << endl;
    //   cout << "bodyWeight: " << phoneMap[mapCount]->getBodyWeight() << endl;
    //   cout << "bodySim: " << phoneMap[mapCount]->getBodySim() << endl;
    //   cout << "displayType: " << phoneMap[mapCount]->getDisplayType() << endl;
    //   cout << "displaySize: " << phoneMap[mapCount]->getDisplaySize() << endl;
    //   cout << "displayResolution: " << phoneMap[mapCount]->getDisplayResolution() << endl;
    //   cout << "featuresSensors: " << phoneMap[mapCount]->getFeaturesSensors() << endl;
    //   cout << "platformOS: " << phoneMap[mapCount]->getPlatformOS() << endl;
    //   cout << endl;
    // }

    mapCount++;

    // if(mapCount == 60) {
    //   break;
    // }
  } // end of while loop

  cout << "Set size = " << phoneSet.size() << endl;
  
  myFile.close();  
  
  return 0;
}
