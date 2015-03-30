#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
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
  string in;
  getline(std::cin, in);
  vector<unsigned> itens = parseLine(in);
  unsigned numberOfElements = itens[0];
  itens.erase(itens.begin());
  bool counter = true;

  while(1){
    sort(itens.begin(), itens.end());
    do {
      for(unsigned counter = 0; counter<numberOfElements; counter++)
        cout<<itens[counter]<<" ";
      cout<<endl;
    } while(next_permutation(itens.begin(), itens.end()));

    getline(std::cin, in);
    itens = parseLine(in);
    numberOfElements = itens[0];
    if(numberOfElements == 0)
      break;
    cout<<endl;
    itens.erase(itens.begin());
  }
}
