#ifndef CELL_H
#define CELL_H

#include <string>
using namespace std;

class Cell{
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
  // Cell(string o, string mod, string lann, string lst, string bd, string bw, string bs, string dt, 
  // string ds, string dr, string fs, string pos);

  Cell(const string& o, const string& mod, const string& lann, const string& lst, const string& bd, 
  const string& bw, const string& bs, const string& dt, const string& ds, const string& dr, 
  const string& fs, const string& pos);

  // 1
  string getOem();
  void setOem(const string& oem);

  // 2
  string getModel();
  void setModel(const string& model);

  // 3
  int getLaunchAnnounced();
  void setLaunchAnnounced(int announced);
  int cleanLaunchAnnounced(const string& launch);

  // 4
  string getLaunchStatus();
  void setLaunchStatus(const string& status);
  string cleanLaunchStatus(const string& launch);

  // 5
  string getBodyDimensions();
  void setBodyDimensions(const string& dimensions);

  // 6
  float getBodyWeight();
  void setBodyWeight(float weight);
  float cleanBodyWeight(const string& weight);

  // 7
  string getBodySim();
  void setBodySim(const string& sim);
  string cleanBodySim(const string& cleanSim);

  // 8
  string getDisplayType();
  void setDisplayType(const string& type);

  // 9
  float getDisplaySize();
  void setDisplaySize(float size);
  float cleanDisplaySize(const string& size);

  // 10
  string getDisplayResolution();
  void setDisplayResolution(const string& resolution);
  string cleanDisplayResolution();

  // 11
  string getFeaturesSensors();
  void setFeaturesSensors(const string& features);
  string cleanFeaturesSensors();

  // 12
  string getPlatformOS();
  void setPlatformOS(const string& platform);
  string cleanPlatformOS(const string& platform);

  // ------------------------------------------------------------------------------------------------
  // other methods
  
  void toString() const;

};

#endif