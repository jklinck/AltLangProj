#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>
#include "../include/Phone.h"
using namespace std;

int main(){
  
  unordered_map<int, Phone*> phoneMap;

  ifstream myFile;
  myFile.open("data/cells.csv");
  string line = ""; 
  string oem = "", model = "", launchAnnounced = "", launchStatus = "", bodyDimensions = "";
  string bodyWeight = "", bodySim = "", displayType = "", displaySize = "", displayResolution = "";
  string featuresSensors = "", platformOS = "";
  int lineCount = 1, location = 0, mapCount = 1;;

  getline(myFile, line);

  while(getline(myFile, line)) {

    location = line.find(',');
    oem  = line.substr(0, location);
    line = line.substr(location + 1, line.length());

    location = line.find(',');
    model = line.substr(0, location);
    line = line.substr(location + 1, line.length());

    location = line.find(',');
    launchAnnounced = line.substr(0, location);
    line = line.substr(location + 1, line.length());

    location = line.find(',');
    launchStatus = line.substr(0, location);
    line = line.substr(location + 1, line.length());

    location = line.find(',');
    bodyDimensions = line.substr(0, location);
    line = line.substr(location + 1, line.length());

    location = line.find(',');
    bodyWeight = line.substr(0, location);
    line = line.substr(location + 1, line.length());

    location = line.find(',');
    bodySim = line.substr(0, location);
    line = line.substr(location + 1, line.length());

    location = line.find(',');
    displayType = line.substr(0, location);
    line = line.substr(location + 1, line.length());

    location = line.find(',');
    displaySize = line.substr(0, location);
    line = line.substr(location + 1, line.length());

    location = line.find(',');
    displayResolution = line.substr(0, location);
    line = line.substr(location + 1, line.length());

    location = line.find(',');
    featuresSensors = line.substr(0, location);
    line = line.substr(location + 1, line.length());

    location = line.find(',');
    platformOS = line.substr(0, location);
    line = line.substr(location + 1, line.length());

    phoneMap[mapCount] = new Phone(oem, model, launchAnnounced, launchStatus, bodyDimensions, 
    bodyWeight, bodySim, displayType, displaySize, displayResolution, featuresSensors, 
    platformOS);


    cout << "Oem: " << phoneMap[1]->getOem() << endl;
    cout << "Model: " << model << endl;
    cout << "Launch announced: " << launchAnnounced << endl;
    cout << "Launch status: " << launchStatus << endl;
    cout << "bodyDimensions: " << bodyDimensions << endl;
    cout << "bodyWeight: " << bodyWeight << endl;
    cout << "bodySim: " << bodySim << endl;
    cout << "displayType: " << displayType << endl;
    cout << "displaySize: " << displaySize << endl;
    cout << "displayResolution: " << displayResolution << endl;
    cout << "featuresSensors: " << featuresSensors << endl;
    cout << "platformOS: " << platformOS << endl;
    cout << endl;

    lineCount++;
    mapCount++;
    if(lineCount == 2) {
      break;
    }
  }
  

  // int mapCount = 1;
  // ifstream file("../data/cells.csv");
  // string line;

  // getline(file, line);

  // while(getline(file, line)){

   
  //   mapCount++;
  // }

  // string oem = phoneMap[mapCount]->getOem();
  // cout << phoneMap[mapCount]->getOem() << endl;  

  myFile.close();  
  

  return 0;
}
