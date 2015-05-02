#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>

/*
 Solution for
http://br.spoj.com/problems/PARPPROX/ (In portuguese)
 The problem is as follows:
 Given a list of nodes, find the minumum
distance between a pair of points.
there is a O(nlogn) solution, using divide-and-conquer.
It will be implemented eventually.
 
 */

using namespace std;

typedef pair<long, long> point;

double distance(point a, point b) {
  return sqrt(pow((float)a.first-b.first, 2)+ pow((float)a.second-b.second, 2));
}

typedef unsigned uint;
int main(int argc, char *argv[]) {
  
  std::ios::sync_with_stdio(false);
  
//  ifstream arq(getenv("MYARQ"));
//  cin.rdbuf(arq.rdbuf());
  
  int number_of_test_cases;
  cin>>number_of_test_cases;
  
  if(number_of_test_cases <= 1) {
    cout<<"0.000"<<endl;
  }
  
  long x, y;
  vector<point> points;
  
  for (int i = 0;  i< number_of_test_cases; ++i) {
    cin>>x>>y;
    points.push_back(make_pair(x, y));
  }
  
  //It can be done in O(n^2, by pair-checking every couple of points.
  //But, it's possible to be done in O(nlogn), by division-and-conquer
  //For timing issues, and due to the small dimension of the problem, a O(n^2)
  //Solution will be implemented.
  
  double minDistance = INFINITY;
  for(int it = 0; it<points.size(); ++it) {
    for(int it2 = it+1; it2<points.size(); ++it2) {
      double a = distance(points[it], points[it2]);
      if(a < minDistance)
        minDistance = a;
    }
  }
  printf("%.3f\n", minDistance);
}
