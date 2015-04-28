#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <cstring>
/*
 Solution for
 http://br.spoj.com/problems/IREVIR/ (In portuguese)
 The problem is as follows:
 Given a directed graph, check if it's connected or not.
 
 Discussion: 
  There is two easy ways to solve this.
  1 - Do a DFS (or even BFS) on each vertex. 
      If the search algorithm can't visit any 
      other vertex, the graph is not connected.
      This is O(V(V+E))
  2 - Use a Strongly Connected Component
      If there is a single connected component,
      The answer is True. Else, False.
      This is O(V+E)
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
  void DFS(uint v, bool visited[]);
  
public:
  ~Graph();
  Graph();
  void addEdge(uint, uint);
  void addVertex(uint);
  bool isConnected();
  Graph reversePaths();
};

int main(int argc, char *argv[]) {
//  ifstream arq(getenv("MYARQ"));
//  cin.rdbuf(arq.rdbuf());
  uint number_of_edges, number_of_vertexes;
  uint x, y, bidirectional;
  cin>>number_of_edges;
  cin>>number_of_vertexes;
  Graph* g = new Graph;
  while (number_of_vertexes != 0) {
    g = new Graph;
    for(unsigned it = 1; it<=number_of_edges; ++it)
      g->addVertex(it);
    for(unsigned it = 0; it<number_of_vertexes; ++it) {
      cin>>x; cin>>y, cin>>bidirectional;
      if(bidirectional==1)
        g->addEdge(x, y);
      else {
        g->addEdge(x, y);
        g->addEdge(y, x);
      }
    }
    cout<<g->isConnected()<<endl;
    delete g;
    cin>>number_of_edges;
    cin>>number_of_vertexes;
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
  //first walking
  DFS(0, visited);
  
  for(unsigned it = 0; it<number_of_vertexes_; ++it){
    if(!visited[it])
      return false;
  }
  
  //Invert all graph's nodes
  Graph gt = reversePaths();
  memset(visited, 0, number_of_vertexes_);
  gt.DFS(0, visited);
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

Graph Graph::reversePaths(){
  Graph gt;
  for (unsigned it = 0; it< number_of_vertexes_; ++it)
    gt.addVertex(it+1);
  for (auto it = vertexes_.begin(); it!=vertexes_.end(); ++it)
    for (auto it2 = it->neighbours.begin(); it2 != it->neighbours.end(); ++it2)
      gt.addEdge(*it2, it->id_);
  return gt;
}


Graph::~Graph(){
  number_of_vertexes_ = 0;
  vector<GraphNode>().swap(vertexes_);
}