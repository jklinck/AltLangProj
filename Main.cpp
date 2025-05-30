#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>
using namespace std;

struct Phone{
  string oem;
  string model;
  string launchAnnounced;
  string launchStatus;
  string bodyDimensions;
  string bodyWeight;
  string bodySim;
  string displayType;
  string displaySize;
  string displayResoltuion;
  string featuresSensors;
  string platformOS;  
};

int main(){
  
  unorder_map<int, Phone> map;
  ifstream file("cells.csv");
  string line;

  getline(file, line);

  

  return 0;
}
