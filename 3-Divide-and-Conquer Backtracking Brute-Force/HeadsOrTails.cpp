#include <iostream>
#include <string>
#include <sstream>
#include <vector>


/*
 Solution to
 http://codeforces.com/problemset/problem/242/A
 */

using namespace std;

vector<unsigned> parseLine(string line) {
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
  
  vector<unsigned> input = parseLine(in);
  
  unsigned x = input[0];
  unsigned y = input[1];
  unsigned a = input[2];
  unsigned b = input[3];
  
  unsigned points_by_petya;
  unsigned points_by_vasya;
  
  vector<pair<unsigned, unsigned>> results;
  
  //Brute-force. Iterate from a to x and from b to y, and record how many times
  //vasya won.
  
  for(points_by_vasya = a; points_by_vasya <= x; ++points_by_vasya) {
   for(points_by_petya = b; points_by_petya <= y; ++points_by_petya) { 
      if (points_by_vasya > points_by_petya) {
        results.push_back(make_pair(points_by_petya, points_by_vasya));
      }
    }
  }
  cout<<results.size()<<endl;
  for (unsigned i =0 ; i<results.size(); ++i) {
    cout<<results[i].second<<" "<<results[i].first<<endl;
  }
  
}