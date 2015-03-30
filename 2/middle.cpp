#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, char *argv[]) {
  int size;
  unsigned aux;
  cin >> size;
  vector<unsigned> cows;
  unsigned position;
  
  for (unsigned i =0; i<size; i++){
    cin>>aux;
    cows.push_back(aux);
  }
  sort(cows.begin(), cows.end());
  
  if (size % 2==1){
    position = size/2;
    cout<<cows[position];
  }
  else{
    position = size/2;
    aux = (cows[position]+cows[position-1])/2;
    cout<<aux<<endl;
  }
  
//  for (unsigned int i =0; i<cows.size(); i++){
//    cout<<cows[i]<<" ";
//  }
}