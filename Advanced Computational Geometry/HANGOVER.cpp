#include <iostream>
#include <fstream>
//#include <algorithm>
//#include <vector>
//#include <math.h>
//#include <cstdlib>
/*
 Solution for
 http://www.spoj.com/problems/HANGOVER/
 
 */

using namespace std;
typedef unsigned uint;

int main(int argc, char *argv[]) {
  
  std::ios::sync_with_stdio(false);
  
  //  ifstream arq(getenv("MYARQ"));
  //  cin.rdbuf(arq.rdbuf());
  
  double c, values[300] = {0.0};
  //precomputing the possible values
  
  for(int i = 2; values[i-2]<=5.2; ++i)
    values[i-1]=values[i-2]+1/(double)i;
  
  cin>>c;
  while (c>0.00) {
    for(int i = 1; i<300; ++i) {
      if(values[i]>=c) {
        cout<<i<<" card(s)"<<endl;
        break;
      }
    }
    cin>>c;
  }
  
  return 0;
}