#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstdlib>
/*
 Solution for
 http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2500
 
 */

#define PI acos(-1.0)
using namespace std;
typedef unsigned uint;

int main(int argc, char *argv[]) {
  
  std::ios::sync_with_stdio(false);
  
//  ifstream arq(getenv("MYARQ"));
//  cin.rdbuf(arq.rdbuf());
  
  int number_of_tests, number_of_commands;
  double x, y, theta;
  cin>>number_of_tests;
  string c;
  double steps;
  while (number_of_tests--) {
    cin>>number_of_commands;
    theta = 0;
    x = 0;
    y = 0;
    while (number_of_commands--) {
      cin>>c>>steps;
      if(c == "lt"){
        theta += steps;
        theta = fmod(theta, 360);
      }
      else if(c == "rt"){
        theta -= steps;
        theta = fmod(theta, 360);
      }
      //move forward
      else if(c == "fd") {
        x += (steps * cos(theta * PI / 180));
        y += (steps * sin(theta * PI / 180));
      }
      else {
        x -= (steps * cos(theta * PI / 180));
        y -= (steps * sin(theta * PI / 180));
      }
    }
    printf ("%0.lf\n", sqrt (x * x + y * y));
  }
  return 0;
}