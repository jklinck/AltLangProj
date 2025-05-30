#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>
#include "../include/Phone.h"
using namespace std;

int main(){
  
  unordered_map<int, Phone> map;
  ifstream file("../data/cells.csv");
  string line;

  getline(file, line);

  // while(getline(file, line)){


  // }

  file.close();  
  
  cout << "test" << endl;  

  return 0;
}
