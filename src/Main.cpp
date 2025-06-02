#include <iostream>  // for cout
#include <fstream>  // for ifstream, for opening files
#include <sstream>  // for stringstream, for reading files
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "../include/Cell.h"
#include "../include/functions.h"
using namespace std;

int main(){
  
  unordered_map<int, Cell*> phoneMap;
  unordered_set<Cell*> phoneSet;

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
    
    phoneMap[mapCount] = new Cell(oem, model, launchAnnounced, launchStatus, bodyDimensions, 
    bodyWeight, bodySim, displayType, displaySize, displayResolution, featuresSensors, 
    platformOS);

    /*
    the set below just exists for testing purposes to check if there were any duplicates
    in the csv, which there are not
    */
    // phoneSet.insert(new Cell(oem, model, launchAnnounced, launchStatus, bodyDimensions, 
    // bodyWeight, bodySim, displayType, displaySize, displayResolution, featuresSensors, 
    // platformOS));

    mapCount++;

  } // end of while loop

//   phoneMap[11]->toString();
  cout << "The average weight of the phone's is: " << avgBodyWeight(phoneMap) << endl;
  
  myFile.close();  
  
  return 0;
}
