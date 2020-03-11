#include <iostream>
#include <queue>
using namespace std;

void bfs(int s, vector<int> adj[], bool vis[], int N)
{
    memset(vis,0,N);
    queue <int> q;
    q.push(s);
    while(!q.empty()){
      int d = q.front();
      vis[d] = true;
      cout << d << " ";
      for(auto i = adj[d].begin(); i != adj[d].end(); i++){
        if(!vis[*i]){
          q.push(*i);
          vis[*i] = true;
        }
      }
      q.pop();
    }

}
