#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int main(int argc, char *argv[]) {
  unsigned numberOfElements;
  cin >> numberOfElements;
  while(numberOfElements!=0){
    vector<unsigned> itens;
    unsigned item;
    for(unsigned in = 0; in <numberOfElements; in++){
      cin>>item;
      itens.push_back(item);
    }
    sort(itens.begin(), itens.end());
    do{
      for (unsigned counter = 0; counter<numberOfElements; counter++)
        cout<<itens[counter]<<" ";
      cout<<endl;
    }while (next_permutation(itens.begin(), itens.end()));
    cout<<endl;
    cin>>numberOfElements;
  }
}