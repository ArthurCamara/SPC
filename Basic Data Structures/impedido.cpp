#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <fstream>

/*
 Given the positions for strikers and defensers
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
//  ifstream arq(getenv("MYARQ"));
//  cin.rdbuf(arq.rdbuf());
  
  string in;
  getline(std::cin, in);
  vector<unsigned> strikersAndDefenders = parseLine(in);
  bool flag = false;
  while(1) {
    if(strikersAndDefenders[1]==1){
      cout<<"Y"<<endl;
      continue;
    }
    flag = false;
    getline(std::cin, in);
    vector<unsigned> strikers = parseLine(in);
    getline(std::cin, in);
    vector<unsigned> defensers = parseLine(in);
    sort(defensers.begin(), defensers.end());
    //Search for a striker after the second last defender
    unsigned secondLastPosition = *(defensers.begin()+1);
    for(vector<unsigned>::iterator it = strikers.begin(); it != strikers.end(); ++it) {
      if(*it < secondLastPosition) {
        flag = true;
        break;
      }
    }
    if(flag)
      cout<<"Y"<<endl;
    else
      cout<<"N"<<endl;
    getline(std::cin, in);
    vector<unsigned> strikersAndDefenders = parseLine(in);
    if (strikersAndDefenders[0] == 0) {
      break;
    }
  }
}
