#ifndef PHONE_H
#define PHONE_H

#include <string>
using namespace std;

class Phone{
private:
  string oem;
  string model;
  int launchAnnounced;
  string launchStatus;
  string bodyDimensions;
  float bodyWeight;
  string bodySim;
  string displayType;
  float displaySize;
  string displayResolution;
  string featuresSensors;
  string platformOS;  

public:
  Phone(string o, string mod, string lann, string lst, string bd, string bw, string bs, string dt, 
  string ds, string dr, string fs, string pos);

  string getOem();
  string cleanOem();

  string getModel();
  string cleanModel();

  int getLaunchAnnounced();
  int cleanLaunchAnnounced(const string& launch);

  string getLaunchStatus();
  string cleanLaunchStatus(const string& launch);

  string getBodyDimensions();
  string cleanBodyDimensions();

  float getBodyWeight();
  float cleanBodyWeight(const string& weight);

  string getBodySim();
  string cleanBodySim(const string& cleanSim);

  string getDisplayType();
  string cleanDisplayType();

  float getDisplaySize();
  float cleanDisplaySize(const string& size);

  string getDisplayResolution();
  string cleanDisplayResolution();

  string getFeaturesSensors();
  string cleanFeaturesSensors();

  string getPlatformOS();
  string cleanPlatformOS(const string& platform);

};

#endif