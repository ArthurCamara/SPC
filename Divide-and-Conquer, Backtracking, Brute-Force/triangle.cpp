#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <numeric>
#include <math.h>

/*
 Solution to
 http://codeforces.com/problemset/problem/18/A
 */

using namespace std;

vector<int> parseLine(string line) {
  vector<int> ret;
  int n = 0;
  stringstream stream(line);
  while(stream >> n)
    ret.push_back(n);
  return ret;
}

//float degreeBetweenPoints(pair<int, int> a, pair<int, int> b) {
//  int x_diff = a.first-b.first;
//  int y_diff = a.second-b.second;
//  float x = atan2(y_diff, x_diff) * (180 / M_PI);
//  if(x<0) return x*-1;
//  return x;
//}

bool isRight(vector<int> points) {
  int d1,d2, d3;
  d1 = pow(points[3]-points[1], 2) +pow(points[2]-points[0], 2);
  d2 = pow(points[5]-points[3], 2) +pow(points[4]-points[2], 2);
  d3 = pow(points[5]-points[1], 2) +pow(points[4]-points[0], 2);
	if(sqrt(d1)<sqrt(d2)+sqrt(d3) && sqrt(d2)<sqrt(d1)+sqrt(d3) && sqrt(d3)<sqrt(d1)+sqrt(d2))
  if(d1+d2==d3 || d1+d3==d2 || d2+d3==d1){
    return true;
  }
  return false;
}
int main(int argc, char *argv[]) {
//    ifstream arq(getenv("MYARQ"));
//    cin.rdbuf(arq.rdbuf());
  string in;
  getline(std::cin, in);
  vector<int> points = parseLine(in);
  if(isRight(points)){
    cout<<"RIGHT\n"<<endl;
    return 0;
  }
  for (unsigned i = 0; i<6; i++){
    points[i]++;
    if(isRight(points)){
      cout<<"ALMOST\n"<<endl;
      return 0;
    }
    points[i]-=2;
    if(isRight(points)){
      cout<<"ALMOST\n"<<endl;
      return 0;
    }
    points[i]++;
  }
  cout<<"NEITHER"<<endl;
  
}