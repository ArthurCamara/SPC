#include <iostream>
#include <fstream>
#include <cmath>

/*
 Solution for
http://br.spoj.com/problems/DVORONOI/ (in portuguese)
Given four points of a Tetrahedron, find it's volume.
 Using the mixed product (determinant of the matrix)
 */

using namespace std;
typedef unsigned uint;


typedef struct vec{
  int x, y ,z;
} vec;

vec operator-(vec& v1, vec& v2){
  vec ans;
  ans.x = v1.x-v2.x;
  ans.y = v1.y-v2.y;
  ans.z = v1.z-v2.z;
  return ans;
}

int main(int argc, char *argv[]) {
  
  std::ios::sync_with_stdio(false);
  
//  ifstream arq(getenv("MYARQ"));
//  cin.rdbuf(arq.rdbuf());
  
  int T;
  cin>>T;
  vec a, b, c, d;
  vec P, Q, R;
  while(T--) {
    cin>>a.x>>a.y>>a.z;
    cin>>b.x>>b.y>>b.z;
    cin>>c.x>>c.y>>c.z;
    cin>>d.x>>d.y>>d.z;
    
    P = a-d;
    Q = b-d;
    R = c-d;
    
    double det = abs(P.x*(Q.y*R.z - Q.z*R.y)-
                    P.y*(Q.x*R.z - Q.z*R.x)+
                    P.z*(Q.x*R.y - Q.y*R.x));
    printf("%.6f\n", det/6);
  }
  
  return 0;
}