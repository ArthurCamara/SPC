#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <cstring>
/*
 Solution for
http://br.spoj.com/problems/ENERGIA/ (In portuguese)
 The problem is as follows:
 Given a undirected graph, check if it's connected or not.
 Solution:
 
 */
using namespace std;

class GraphNode{
  int number_of_neighbors_;
public:
  void addEdgeFromHere(uint);
  int id_;
  GraphNode(uint x);
  vector<uint> neighbours;

};

bool operator== (const GraphNode &lhs, const GraphNode &rhs){
  return lhs.id_ == rhs.id_;
}

class Graph{
  int number_of_vertexes_;
  vector<GraphNode> vertexes_;
  
public:
  ~Graph();
  Graph();
  void DFS(uint v, bool visited[]);
  void addEdge(uint, uint);
  void addVertex(uint);
  bool isConnected();
  Graph reversePaths();
};

int main(int argc, char *argv[]) {
//  ifstream arq(getenv("MYARQ"));
//  cin.rdbuf(arq.rdbuf());
  uint number_of_edges, number_of_vertexes;
  uint x, y;
  cin>>number_of_edges;
  cin>>number_of_vertexes;
  Graph* g = new Graph;
  uint counter = 1;
  while (number_of_vertexes != 0) {
    g = new Graph;
    for(unsigned it = 1; it<=number_of_edges; ++it)
      g->addVertex(it);
    for(unsigned it = 0; it<number_of_vertexes; ++it) {
      cin>>x; cin>>y;
      g->addEdge(x, y);
      g->addEdge(y, x);
    }
    cout<<"Teste "<<counter<<endl;
    if(g->isConnected()){
      cout<<"normal"<<endl;
    }
    else
      cout<<"falha"<<endl;
    delete g;
    cin>>number_of_edges;
    cin>>number_of_vertexes;
    counter++;
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

void Graph::addEdge(uint x, uint y) {
  vertexes_[x-1].addEdgeFromHere(y);
}

void Graph::addVertex(uint x) {
  vertexes_.push_back(x);
  number_of_vertexes_++;
}

bool Graph::isConnected(){
  bool visited[number_of_vertexes_];
  memset(visited, 0, number_of_vertexes_);
  //DFS
  DFS(0, visited);
  for(unsigned it = 0; it<number_of_vertexes_; ++it){
    if(!visited[it])
      return false;
  }
  return true;
}

void Graph::DFS(uint v, bool visited[]){
  visited[v]=true;
  for(auto it = vertexes_[v].neighbours.begin(); it!=vertexes_[v].neighbours.end(); ++it) {
    if(!visited[*it-1]){
      DFS(*it-1, visited);
    }
  }
}


Graph::~Graph(){
  number_of_vertexes_ = 0;
  vector<GraphNode>().swap(vertexes_);
}