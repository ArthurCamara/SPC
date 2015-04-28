#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>
#include <cstring>
#include <unordered_map>
#include <algorithm>

/*
 Solution for
http://br.spoj.com/problems/ORKUT/ (In portuguese)
 The problem is as follows:
Given a list of users of a social network, and the list of friends for each one,
Returns the topological sorting.
input sample:

5
Joao Maria Tadeu Jose Ricardo
Joao 2 Maria Ricardo
Maria 1 Tadeu
Jose 1 Joao
Tadeu 0
Ricardo 0
3
Joao Maria Renata
Maria 1 Joao
Joao 1 Renata
Renata 1 Maria
0
 
 */
using namespace std;
typedef unsigned uint;

class GraphNode{
  int number_of_neighbors_;
public:
  void addEdgeFromHere(uint);
  int id_;
  GraphNode();
  GraphNode(uint x);
  vector<uint> neighbours;
  
};

bool operator== (const GraphNode &lhs, const GraphNode &rhs){
  return lhs.id_ == rhs.id_;
}

class Graph{
  int number_of_vertexes_;
  unordered_map<int, GraphNode> vertexes_;
  
public:
  ~Graph();
  Graph();
  void addEdge(uint, uint);
  void addVertex(uint);
  bool isCyclic();
  bool isCyclicUtil(int v, bool visited[], bool *recStack);
  stack<int> TopologicalSort();
  void TopologicalSortUtil(int s, bool visited[], stack<int> &Stack);
};


int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(false);
  
//  ifstream arq(getenv("MYARQ"));
//  cin.rdbuf(arq.rdbuf());
  
  unsigned number_of_edges;
  unsigned counter =1;
  string line;
  Graph* graph;
  cin>>number_of_edges;
  string name;
  unordered_map<uint, string> map;
  unordered_map<string, uint> inverted_map;
  uint nvertexes;
  while (number_of_edges!=0) {
    for(uint it =0; it<number_of_edges; ++it){
      cin>>name;
      map.insert(make_pair(it, name));
      inverted_map.insert(make_pair(name, it));
    }
    graph = new Graph;
    for(unsigned it = 0; it<number_of_edges; ++it)
      graph->addVertex(it);
    for(unsigned it = 0; it<number_of_edges; ++it){
      cin>>name>>nvertexes;
      uint v = inverted_map[name];
      for(uint it2 = 0; it2 < nvertexes; ++it2) {
        cin>>name;
        graph->addEdge(inverted_map[name], v);
      }
    }
    cout<<"Teste "<<counter<<endl;
    if (graph->isCyclic()){
      cout<<"impossivel";
    }
    else{
      stack<int> L = graph->TopologicalSort();
      while(!L.empty()){
        cout<<map[L.top()]<<" ";
        L.pop();
      }
    }
    cout<<endl<<endl;
    counter++;
    delete graph;
    cin>>number_of_edges;
  }
}

Graph::Graph(){
  number_of_vertexes_= 0;
}

void GraphNode::addEdgeFromHere(uint x) {
  neighbours.push_back(x);
}

GraphNode::GraphNode(uint x){
  id_ = x;
  number_of_neighbors_ = 0;
}

GraphNode::GraphNode(){
  
}

void Graph::addEdge(uint x, uint y) {
  vertexes_[x].addEdgeFromHere(y);
}

void Graph::addVertex(uint x) {
  vertexes_.insert(make_pair(x, GraphNode(x)));
  number_of_vertexes_++;
}

Graph::~Graph(){
  number_of_vertexes_ = 0;
  unordered_map<int, GraphNode>().swap(vertexes_);
}

bool Graph::isCyclicUtil(int v, bool *visited, bool *recStack){
  if(!visited[v]){
    visited[v] = true;
    recStack[v]=true;
    for(auto it = vertexes_[v].neighbours.begin(); it!=vertexes_[v].neighbours.end(); ++it){
      if(!visited[*it] && isCyclicUtil(*it, visited, recStack)){
        return true;
      }
      else if(recStack[*it]){
        return true;
      }
    }
  }
  recStack[v] = false;
  return false;
}

bool Graph::isCyclic(){
  bool *visited = new bool[number_of_vertexes_];
  bool *recSack = new bool[number_of_vertexes_];
  memset(visited, 0, number_of_vertexes_);
  memset(recSack, 0, number_of_vertexes_);
  for(uint it = 0; it< number_of_vertexes_; ++it){
    if(isCyclicUtil(it, visited, recSack)){
      return true;
    }
  }
  return false;
}

void Graph::TopologicalSortUtil(int s, bool *visited, stack<int> &Stack){
  visited[s] = true;
  for(auto it = vertexes_[s].neighbours.begin(); it!=vertexes_[s].neighbours.end(); ++it){
    if(!visited[*it]){
      TopologicalSortUtil(*it, visited, Stack);
    }
  }
  Stack.push(s);
}
stack<int> Graph::TopologicalSort(){
  stack<int> L;
  bool *visited = new bool[number_of_vertexes_];
  memset(visited, 0, number_of_vertexes_);
  for(int it = 0; it<number_of_vertexes_; ++it){
    if(!visited[it]){
      TopologicalSortUtil(it, visited, L);
    }
  }
  return L;
}