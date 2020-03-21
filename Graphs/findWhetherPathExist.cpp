#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int n, i, j, sourcei, sourcej;
    cin >> n;
    int arr[n][n];
    for(i = 0; i < n; i++) for(j = 0; j < n; j++) cin >> arr[i][j];
    for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
        if(arr[i][j] == 1){
          sourcei = i;
          sourcej = j;
        }
      }
    }
    queue <pair <int,int>> q;
    bool foundPath = false;
    bool visited[n][n];
    memset(visited,0,sizeof(visited));
    q.push(make_pair(sourcei,sourcej));
    while(!q.empty()){
      auto ryuu = q.front();
      i = ryuu.first;
      j = ryuu.second;
      visited[i][j] = true;
      if(arr[i][j] == 2){
        foundPath = true;
        break;
      }
      if(i < n-1 && !visited[i+1][j] && arr[i+1][j] != 0) q.push(make_pair(i+1,j));
      if(i > 0 && !visited[i-1][j] && arr[i-1][j] != 0) q.push(make_pair(i-1,j));
      if(j < n-1 && !visited[i][j+1] && arr[i][j+1] != 0) q.push(make_pair(i,j+1));
      if(j > 0 && !visited[i][j-1] && arr[i][j-1] != 0) q.push(make_pair(i,j-1));
      q.pop();
    }
    if(foundPath) cout << 1 << "\n";
    else cout << 0 << "\n";

  }
}
