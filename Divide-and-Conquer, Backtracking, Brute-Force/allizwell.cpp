#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <numeric>
#include <math.h>
#include <string>

/*
 Solution to
http://www.spoj.com/problems/ALLIZWEL/
 */

using namespace std;


bool Search(vector<vector<char> > &s, vector<vector<bool> > &m, int x, int y, int n, int n_columns, int n_lines){
  char next_match;
  switch (n) {
    case 0:
       next_match='A';
      break;
    case 1:
      next_match='L';
      break;
    case 2:
      next_match='L';
      break;
    case 3:
      next_match='I';
      break;
    case 4:
      next_match='Z';
      break;
    case 5:
      next_match='Z';
      break;
    case 6:
      next_match='W';
      break;
    case 7:
      next_match='E';
      break;
    case 8:
      next_match='L';
      break;
    case 9:
      next_match='L';
      break;
    default:
      return true;
      break;
  }
  if(x<0 || y<0)
    return false;
  bool result = false;
  m[x][y]=true;
  if(s[x][y]==next_match){
    if(n==9){
      return true;
    }
    n++;
    for(int i = -1; i<2; ++i) {
      for (int j = -1; j<2; ++j) {
        if(x+i >= 0 && y+j >= 0 && x+i<n_lines && y+j < n_columns){
          if(!m[x+i][y+j]){
            result = result || Search(s, m, x+i, y+j, n, n_columns, n_lines);
            if (result == true)
              return true;
          }
        }
      }
    }
    m[x][y]=false;
    return result;
  }
  m[x][y]=false;
  return false;
}

vector<int> parseLine(string line) {
  vector<int> ret;
  unsigned n = 0;
  stringstream stream(line);
  while(stream >> n)
    ret.push_back(n);
  return ret;
}

int main(int argc, char *argv[]) {
//  ifstream arq(getenv("MYARQ"));
//  cin.rdbuf(arq.rdbuf());
  string in;
  getline(std::cin, in);
  while(in.size()<1){
    getline(std::cin, in);
  }
  int N = stoi(in);
  string whatToSearch = "ALLIZZWELL";
  vector<vector<int> > matrix;
  while(N>0){
    getline(cin, in);
    while(in.size()<1){
      getline(std::cin, in);
    }
    vector<int> input = parseLine(in);
    int n_lines = input[0];
    int n_columns = input[1];
    vector<vector<bool> > matrix(n_lines, vector<bool>(n_columns, false));
    vector<vector<char> > search(n_lines, vector<char>());
    for(unsigned i = 0; i<n_lines; ++i) {
      getline(cin, in);
      while(in.size()<1){
        getline(std::cin, in);
      }
      copy(in.begin(), in.end(), back_inserter(search[i]));
    }
    bool flag = false;
    for(int i = 0; i<n_lines; ++i) {
      for (int j = 0; j<n_columns; ++j){
        bool r = Search(search, matrix, i, j, 0, n_columns, n_lines);
        if(r){
          flag = true;
          break;
        }
      }
      if(flag){
        break;
      }
    }
    if(flag)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
    N--;
  }

  

  return 0;
}
