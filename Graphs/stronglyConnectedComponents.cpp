#include <vector>
#include <stack>
#include <iostream>
using namespace std;

void dfs(int s, vector <int> adj[], bool visited[], stack <int> &vertexStack){
  visited[s] = true;
  for(auto i = adj[s].begin(); i != adj[s].end(); i++) if(!visited[*i]) dfs(*i,adj,visited,vertexStack);
  vertexStack.push(s);
}

void pureDfs(int s, vector <int> adj[], bool visited[]){
  visited[s] = true;
  for(auto i = adj[s].begin(); i != adj[s].end(); i++) if(!visited[*i]) pureDfs(*i,adj,visited);
}

int kosaraju(int V, vector<int> adj[])
{
    stack <int> s;
    int i, j, count = 0;
    bool visited[V] = {0};
    for(i = 0; i < V; i++) if(!visited[i]) dfs(i,adj,visited,s);
    vector <int> transposeAdj[V];
    for(i = 0; i < V; i++) for(j = 0; j < adj[i].size(); j++) transposeAdj[adj[i][j]].push_back(i);
    bool transposeVisited[V] = {0};
    while(!s.empty()){
      i = s.top();
      s.pop();
      if(!transposeVisited[i]){
        count++;
        pureDfs(i,transposeAdj,transposeVisited);
      }
    }
    return count;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int a,b;
    cin >> a >> b;
    int m, n;
    vector <int> adj[a+1];
    for(int i = 0; i < b; i++){
      cin >> m >> n;
      adj[m].push_back(n);
    }
    cout << kosaraju(a,adj) << endl;
  }
  return 0;
}
