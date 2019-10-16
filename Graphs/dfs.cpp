#include <bits/stdc++.h>
using namespace std;

class Graph{
  int V;
  list <int> *adj; // Pointer to an array containing adjacency lists
  void DFSUtil(int v, bool visited[]);
public:
  Graph(int V);

  void addEdge(int v, int w);

  void DFS(int v);

  int *edgeTo; //pointer to array of edgeTo

};

Graph::Graph(int V){ // defining a functionn outside a class using scope resolution operator
  this->V = V;
  adj = new list<int> [V];
  edgeTo = new int [V];
  for(int i = 0; i < V; i++){
    edgeTo[i] = -1;
  }

}

void Graph::addEdge(int v, int w){
  adj[v].push_back(w);
  adj[w].push_back(v);
}

void Graph::DFSUtil(int v, bool visited[]){
  visited[v] = true;
  cout << v << " ";

  list <int>::iterator i;
  for( i = adj[v].begin(); i != adj[v].end(); i++){
    if(!visited[*i]){
      DFSUtil(*i, visited);
      edgeTo[*i] = v;
    }
  }
}

void Graph::DFS(int v){
  bool *visited = new bool[V];
  for(int i = 0; i < V; i++){
    visited[i] = false;
  }
  DFSUtil(v, visited);
}

int main(){
  Graph g(4);
  g.addEdge(0,1);
  g.addEdge(0,2);
  g.addEdge(2,1);
  g.addEdge(0,2);
  g.addEdge(3,2);
  g.addEdge(3,3);
  cout << "Following is Depth First Traversal \n";
  g.DFS(2);
  cout << "\nHere comes the edgeTo array order wise\n";
  for(int i = 0; i < 4; i++){
    cout  << g.edgeTo[i] << " ";
  }
  return 0;
}
