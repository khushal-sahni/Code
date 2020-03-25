#include <iostream>
#include <queue>
using namespace std;


int main(){
  int t;
  cin >> t;
  while(t--){
    int n, i, j, a, b;
    int numberOfThrows[30] = {0};
    bool visited[30] = {0};
    vector <int> graph[30], destination(30);
    for(i = 0; i < 30; i++) destination[i] = i;

    cin >> n;
    for(i = 0; i < n; i++){
      cin >> a >> b;
      destination[a-1] = b-1;
    }

    for(i = 0; i < 29; i++){
      for(j = 1; j <= 6; j++){
        if(i + j < 30) graph[i].push_back(destination[i+j]);
      }
    }

    queue <int> q;
    q.push(0);
    visited[0] = true;
    numberOfThrows[0] = 0;
    while(!q.empty()){
      int vertex = q.front();
      if(vertex == 29) break;
      for(auto k = graph[vertex].begin(); k != graph[vertex].end(); k++){
        if(!visited[*k]){
          visited[*k] = true;
          numberOfThrows[*k] = numberOfThrows[vertex] + 1;
          q.push(*k);
        }
      }
      q.pop();
    }
    cout << numberOfThrows[29] << "\n";

  }
}
