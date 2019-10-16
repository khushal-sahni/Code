#include <bits/stdc++.h>
using namespace std;

bool *visited; //pointer to array which stores info on who is marked (visited)
int *edgeTo; //pointer to array which keeps track of the predessor of each vertex while dfs
list <int> *adj; // adjacency list

void addEdge(int u, int v); //method to add two vertices
void DFS(int v);  //method to find DFS

int main(){
  int V = 4;
  visited = new bool[V];
  edgeTo = new int[V];
  adj = new list <int> [V];

  for(int i = 0; i < V; i++){
    edgeTo[i] = i;
  }

  addEdge(0,1);
  addEdge(0,2);
  addEdge(2,1);
  addEdge(0,2);
  addEdge(3,2);
  addEdge(3,3);

  DFS(2);
  cout << "\nHere comes the edgeTo array order wise\n";
  for(int i = 0; i < V; i++){
    cout << edgeTo[i] << " ";
  }
  return 0;

}

void addEdge(int u, int v){
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void DFS(int v){
  visited[v] = true;
  cout << v << " ";
  list <int>::iterator i;
  for(i = adj[v].begin(); i != adj[v].end(); i++){
    if(!visited[*i]){
      DFS(*i);
      edgeTo[*i] = v;
    }
  }
}
