#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <algorithm>

/*
 Solution for
http://br.spoj.com/problems/PEDAGIO/ (In portuguese)
 The problem is as follows:
 Given a undirected graph, a source and a maximum number of hops, say which
 nodes can be reached.
 Solution: BFS with a maximum distance.
 
 */
using namespace std;
typedef unsigned uint;

class GraphNode{
  int number_of_neighbors_;
public:
  void addEdgeFromHere(uint);
  int id_;
  int distance_;
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
  void BFS(uint, uint);
  void DFS(uint, uint, uint, bool[]);
  void addEdge(uint, uint);
  void addVertex(uint);
};


void BFS(int source){
  
}

int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(false);
  
//  ifstream arq(getenv("MYARQ"));
//  cin.rdbuf(arq.rdbuf());
  
  unsigned number_of_edges, number_of_vertexes;
  unsigned x, y;
  unsigned counter =1;
  string line;
  Graph* graph;
  unsigned src, maxhops;
  cin>>number_of_edges>>number_of_vertexes>>src>>maxhops;
  while (number_of_vertexes!=0 && number_of_edges !=0 && src!=0 && maxhops!= 0) {
    graph = new Graph;
    for(unsigned it = 0; it<number_of_edges; ++it)
      graph->addVertex(it);
    for(unsigned it = 0; it<number_of_vertexes; ++it) {
      cin>>x>>y;
      graph->addEdge(x-1, y-1);
      graph->addEdge(y-1, x-1);
    }
    cout<<"Teste "<<counter<<endl;
    graph->BFS(src-1, maxhops);
    cout<<endl<<endl;
    counter++;
    delete graph;
    cin>>number_of_edges>>number_of_vertexes>>src>>maxhops;
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
  distance_ = 0;
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

void Graph::DFS(uint s, uint maxhops, uint depth, bool visited[]){
  if(depth>maxhops)
    return;
  visited[s]=true;
  for(auto it = vertexes_[s].neighbours.begin(); it!= vertexes_[s].neighbours.end(); ++it){
    if(!visited[*it]) {
      DFS(*it, maxhops, depth+1, visited);
    }
  }
}

void Graph::BFS(uint s, uint maxhops){
  bool *visited = new bool[number_of_vertexes_];
  memset(visited, 0, number_of_vertexes_);
  queue<pair<int, int>> q;
  visited[s] = true;
  int distance = 0;
  q.push(make_pair(s, distance));
  pair<int, int> sl;
  while(!q.empty()) {
    sl = q.front();
    q.pop();
    for(auto it = vertexes_[sl.first].neighbours.begin(); it!=vertexes_[sl.first].neighbours.end(); ++it) {
      if(!visited[*it]){
        visited[*it]=true;
        vertexes_[*it].distance_ = sl.second+1;
        q.push(make_pair(*it, sl.second+1));
      }
    }
  }
  vector<uint> nodes;
  for(int it = 0; it<number_of_vertexes_; ++it){
    if(vertexes_[it].distance_<=maxhops && vertexes_[it].distance_>0){
      nodes.push_back(it+1);
    }
  }
  sort(nodes.begin(), nodes.end());
  for(int it = 0; it<nodes.size(); ++it){
    cout<<nodes[it]<<" ";
  }
}

