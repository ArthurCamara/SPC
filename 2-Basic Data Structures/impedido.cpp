#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

/*
Given the positions for strikers and deffensers 
in a soccer game, tell if any striker is 
prevented. (Meaning that the striker is beyond 
the second-last defender)
*/

using namespace std;

vector<unsigned> parseLine(string line){
  vector<unsigned> ret;
  unsigned n = 0;
  stringstream stream(line);
  while(stream >> n)
    ret.push_back(n);
  return ret;
}


int main(int argc, char *argv[]) {
  
}