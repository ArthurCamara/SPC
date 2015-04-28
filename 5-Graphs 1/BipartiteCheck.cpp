#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <queue>
#include <cstring>

/*
 Solution for
 http://br.spoj.com/problems/MESA/ (In portuguese)
 The problem is as follows:
 Given a undirected graph, check if it's connected or not.
 Solution:
 
 */
using namespace std;

bool isBipartide(vector<vector<bool> >& graph, unsigned number_of_edges){
  int colorArray[number_of_edges];
  memset(colorArray, -1, number_of_edges);
  int src = 0;
  colorArray[src]=1;
  queue<int> q;
  q.push(src);
  
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    
    for(unsigned i = 0; i < number_of_edges; ++i) {
      if(graph[u][i] && colorArray[i] == -1) {
        colorArray[i]=1-colorArray[u];
        q.push(i);
      }
      else if(graph[u][i] && colorArray[i]==colorArray[u])
        return false;
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(false);
  
  ifstream arq(getenv("MYARQ"));
  cin.rdbuf(arq.rdbuf());
  
  unsigned number_of_edges, number_of_vertexes;
  unsigned x, y;
  vector<vector<bool> > graph;
  unsigned counter =1;
  string line;
  vector<int> parsedLine;
  while (!cin.eof() && cin.good()) {
    cin>>number_of_edges>>number_of_vertexes;
    graph.resize(number_of_edges);
    for(unsigned it = 0; it<number_of_edges; ++it)
      graph[it].resize(number_of_edges);
    for(unsigned it = 0; it<number_of_vertexes; ++it) {
      cin>>x>>y;
      graph[x-1][y-1]=true;
      graph[y-1][x-1]=true;
    }
    cout<<"Instancia "<<counter<<endl;
    if(isBipartide(graph, number_of_edges)){
      cout<<"sim"<<endl;
    }
    else
      cout<<"nao"<<endl;
    counter++;
    vector<vector<bool> >().swap(graph);
  }
}