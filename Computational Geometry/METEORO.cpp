#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>
/*
 Solution for
 http://br.spoj.com/problems/METEORO/ (in portugese)
 
 given a up-left coordinate (P1) and a lower-right coordinates(P2),
 check if a given list of coordinates are within the bounds of the 
 rectangle formed by P1 and P2. Print the total number of "hits"
 
 */

using namespace std;
typedef unsigned uint;

bool checkIfWithinBounds(int x1, int y1, int x2, int y2, int x0, int y0) {
  return (x0>=x1 && x0<=x2 && y0<=y1 && y0>=y2);
}


int main(int argc, char *argv[]) {
  
  std::ios::sync_with_stdio(false);
  
  // ifstream arq(getenv("MYARQ"));
  // cin.rdbuf(arq.rdbuf());
  
  int x1, x2, y1, y2, x0, y0, n, hits, test=1;
  cin>>x1>>y1>>x2>>y2;
  while (!(x1==0 && x2==0 && y1==0 && y2==0)) {
    hits = 0;
    cin>>n;
    for(int i =0; i<n; ++i) {
      cin>>x0>>y0;
      if(checkIfWithinBounds(x1, y1, x2, y2, x0, y0)){
        hits++;
      }
    }
    cout<<"Teste "<<test<<endl<<hits<<endl<<endl;
    test++;
    cin>>x1>>y1>>x2>>y2;
  }
}