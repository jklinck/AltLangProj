#ifndef PHONE_H
#define PHONE_H

#include <string>
using namespace std;

class Phone{
private:
  string oem;
  string model;
  string launchAnnounced;
  string launchStatus;
  string bodyDimensions;
  string bodyWeight;
  string bodySim;
  string displayType;
  string displaySize;
  string displayResolution;
  string featuresSensors;
  string platformOS;  

public:
  Phone(string o, string mod, string lann, string lst, string bd, string bw, string bs, string dt, 
  string ds, string dr, string fs, string pos);

  string getOem();

};

#endif