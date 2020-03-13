#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool cyclic(int s, bool visited[], vector <int> adj[], vector <bool> ancestors){
  visited[s] = true;
  ancestors[s] = true;
  for(auto i = adj[s].begin(); i != adj[s].end(); i++){
    if(ancestors[*i]) return true;
    if(!visited[*i]) if(cyclic(*i,visited,adj,ancestors)) return true;
  }
  return false;
}

bool isCyclic(int V, vector<int> adj[])
{
  bool visited[V] = {0};
  vector <bool> ancestors(V,0);
  for(int i = 0; i < V; i++) if(!visited[i] && cyclic(i,visited,adj, ancestors)) return true;
  return false;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int v,e;
    cin >> v >> e;
    vector <int> adj[v];
    for(int i = 0; i < e; i++){
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
    }
    cout << isCyclic(v,adj) << endl;
  }
}
