#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <numeric>
#include <math.h>
#include <string>

/*
 Solution to
 http://www.spoj.com/problems/CANDY/
 */

using namespace std;

int main(int argc, char *argv[]) {
//  ifstream arq(getenv("MYARQ"));
//  cin.rdbuf(arq.rdbuf());
  string in;
  getline(std::cin, in);
  int n = stoi(in);
  vector<int> candies;
  while(n!=-1) {
    for (int i = 0 ; i<n; ++i) {
      getline(std::cin, in);
      candies.push_back(stoi((in)));
    }
    //Check if thay can be divided.
    int sum = accumulate(candies.begin(), candies.end(), 0);
    if(sum%n!=0){
      cout<<"-1"<<endl;
      getline(std::cin, in);
      candies.clear();
      n = stoi(in);
      continue;
    }
    int candies_in_each_box = sum/n;

    int number_of_movements = 0;
    for(int i=0; i<n; ++i) {
      if(candies[i]>candies_in_each_box) {
        number_of_movements += (candies[i]-candies_in_each_box);
      }
    }
    cout<<number_of_movements<<endl;
    getline(std::cin, in);
    candies.clear();
    n = stoi(in);
  }
  
  return 0;
  
}