#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

/*
 Solution for
http://br.spoj.com/problems/NLOGONIA/ (In portuguese)
 The problem is as follows:
 Given a center node, check in which quadrant the other points
 are, or if they are on top of a dividing line.
 
 */

using namespace std;


string checkQuadrant(pair<int, int>& center, pair<int, int>& point){
  
  if(point.first > center.first && point.second > center.second) //x'>x and y'>y
    return "NE";
  if(point.first > center.first && point.second < center.second) //x'>x and y'<y
    return "SE";
  if(point.first < center.first && point.second > center.second) //x'<x and y'>y
    return "NO";
  if(point.first < center.first && point.second < center.second) //x' < x and y' < y
    return "SO";
  return "divisa";
}


typedef unsigned uint;
int main(int argc, char *argv[]) {
  
  std::ios::sync_with_stdio(false);
  
//  ifstream arq(getenv("MYARQ"));
//  cin.rdbuf(arq.rdbuf());
  
  int number_of_test_cases;
  cin>>number_of_test_cases;
  
  pair<int, int> dividing_point, aux;  
  
  while(number_of_test_cases!=0) {
    
    cin>>dividing_point.first>>dividing_point.second;
    
    for(int i = 0; i< number_of_test_cases; ++i) {
      cin>>aux.first>>aux.second;
      cout<<checkQuadrant(dividing_point, aux)<<endl;
    }
    cin>>number_of_test_cases;
  }
    
}
