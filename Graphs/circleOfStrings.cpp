#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

void dfs(int s, vector <bool> &visited, stack <int> &vertexStack, vector <char> graph[]){
  visited[s] = true;
  for(auto k = graph[s].begin(); k != graph[s].end(); k++){
    if(!visited[(*k) - 'a']) dfs((*k)-'a',visited,vertexStack,graph);
  }
  vertexStack.push(s);
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, i;
    cin >> n;
    if(n == 0){
      cout << 1 << "\n";
      continue;
    }
    string arr[n];
    for(i = 0; i < n; i++) cin >> arr[i];

    vector <char> graph[26], reverseGraph[26];
    for(i = 0; i < n; i++){
      char a = arr[i].front();
      char b = arr[i].back();
      graph[a-'a'].push_back(b);
    }

    vector <int> inDegree(26,0), outDegree(26,0);
    vector <bool> visited(26,0), reverseVisited(26,0), notZeroOrder(26,0);
    for(i = 0; i < 26; i++){
      outDegree[i] = graph[i].size();
      if(outDegree[i] > 0) notZeroOrder[i] = true;
      for(auto k = graph[i].begin(); k != graph[i].end(); k++){
        inDegree[(*k) - 'a']++;
        reverseGraph[(*k)-'a'].push_back((char)(97+i));
        notZeroOrder[(*k)-'a'] = true;
      }
    }
    if(inDegree != outDegree){
      cout << 0 << "\n";
      continue;
    }

    stack <int> vertexStack;
    for(i = 0; i < 26; i++){
      if(!visited[i] && notZeroOrder[i]) dfs(i,visited,vertexStack, graph);
    }



    int highestOrderVertex = vertexStack.top();
    dfs(highestOrderVertex, reverseVisited, vertexStack, reverseGraph);
    if(visited != reverseVisited) cout << 0 << "\n";
    else cout << 1 << "\n";
  }
}
