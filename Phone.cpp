#include <iostream>
#include "Phone.h"

using namespace std;

Phone :: Phone(string o, string mod, string lann, string lst, string bd, string bw, string bs, string dt, 
string ds, string dr, string fs, string pos) : oem(o), model(mod), launchAnnounced(lann), 
launchStatus(lst), bodyDimensions(bd), bodyWeight(bw), bodySim(bs), displayType(dt), 
displaySize(ds), displayResolution(dr), featuresSensors(fs), platformOS(pos){}

