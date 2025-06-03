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
    in the csv, which there are not, you should add some otherwise what is the point of 
    checking if there are duplicates
    */
    // phoneSet.insert(new Cell(oem, model, launchAnnounced, launchStatus, bodyDimensions, 
    // bodyWeight, bodySim, displayType, displaySize, displayResolution, featuresSensors, 
    // platformOS));

    mapCount++;

  } // end of while loop



    /*
    The functions below can be run to complete the following:
    1) Print a cell object to a string displaying all of it's column values.
    2) Get the average body weight of all phones. 
    3) Delete a phone from the phoneMap object.
    4) Get the average display size of a phone in the CSV file.
    5) Add a phone to the phoneMap.

    To use the functions below you need to uncomment them. Make sure you do not uncomment anything
    below the dotted line or you will really screw everything up. Seriously, don't do it.
    */

//   phoneMap[11]->toString();
//   cout << endl << "Average phone weight: " << avgBodyWeight(phoneMap) << endl;
//   cout << "Average display size: " << avgDisplaySize(phoneMap) << " inches" << endl;
//   cout << "Size before deleting phone object: " << phoneMap.size() << endl;
//   deletePhone(5, phoneMap);
//   cout << "Size after deleting phone object: " << phoneMap.size() << endl << endl;
//   addPhone(mapCount, phoneMap,"a","b","c","d","e","f","g","h","i","j","k","l");
//   Cell* newPhone =  phoneMap[phoneMap.size() + 2];
//   newPhone->toString();
  // cout << "Phones: " << countPhonesByOem(phoneMap, "Google") << endl;
  countPhonesByOem(phoneMap, "Google");


  // ----------------------------------------------------------------------------------------------

  myFile.close(); 

  //   deallocate all allocated memory for Cell objects
  for (auto& pair : phoneMap) {
        delete pair.second; // Delete each Cell object
  } 
  
  return 0;
}

