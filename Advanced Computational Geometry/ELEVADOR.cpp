#include <iostream>
#include <fstream>
#include <cmath>

/*
 Solution for
http://br.spoj.com/problems/ELEVADOR/ (in portuguese)
Given a rectangle and two circles, check if you can put both
 circles in the same rectangle.
 */

using namespace std;
typedef unsigned uint;


int main(int argc, char *argv[]) {
  
  std::ios::sync_with_stdio(false);
  
//  ifstream arq(getenv("MYARQ"));
//  cin.rdbuf(arq.rdbuf());
  
  int L, C, R1, R2;
  cin>>L>>C>>R1>>R2;
  
  while(L!=0 && C!=0 && R1!=0 && R2!=0) {
    if(2*R1>L || 2*R2>L || 2*R1>C || 2*R2>C){
      cout<<"N"<<endl;
      cin>>L>>C>>R1>>R2;
      continue;
    }
    //Sum of both radius
    int R = R1+R2;
    //maximum distance
    float R_=sqrt(pow((L-R),2)+pow((C-R),2));
    
    if(R_>=R) cout<<"S"<<endl;
    else cout<<"N"<<endl;
    cin>>L>>C>>R1>>R2;
  }
  
  return 0;
}