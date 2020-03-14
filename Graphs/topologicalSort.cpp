#include <iostream>
using namespace std;

void postdfs(int s, vector <int> adj[], int &pos, bool visited[], int topoSortArr[]){
  visited[s] = true;
  for(auto i = adj[s].begin(); i != adj[s].end(); i++){
    if(!visited[*i]) postdfs(*i,adj,pos,visited,topoSortArr);
  }
  topoSortArr[pos] = s;
  pos--;
}

int* topoSort(int V, vector<int> adj[]) {
    int *topoSortArr = new int[V];
    int pos = V-1;
    bool visited[V] = {0};
    for(int i = 0; i < V; i++){
      if(!visited[i]) postdfs(i,adj,pos,visited,topoSortArr);
    }
    return topoSortArr;
}
