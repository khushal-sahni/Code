#include <iostream>
using namespace std;

bool cyclic(int s, vector <int> adj[], bool visited[]){
  visited[s] = true;
  int count = 0;
  for(int i = 0; i < adj[s].size(); i++){
    if(!visited[adj[s][i]]){
      if(cyclic(adj[s][i], adj, visited)) return true;
    }
    else count++;
    if(count > 1) return true;
  }
  return false;
}

bool isCyclic(vector<int> adj[], int V)
{
  bool visited[V] = {0};
  for(int i = 0; i < V; i++){
    if(!visited[i]){
      if(cyclic(i,adj,visited)) return true;
    }
  }
   return false;
}
