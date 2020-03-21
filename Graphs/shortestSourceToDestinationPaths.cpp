#include <iostream>
#include <queue>
#include <cstring>
using namespace std;


int main(){
  int t;
  cin >> t;
  while(t--){
    int n,m,i,j,x,y, count = 0;
    cin >> n >> m;
    int arr[n][m], steps[n][m];
    bool visited[n][m];
    memset(visited,0,sizeof(visited));
    memset(steps,0,sizeof(steps));
    for(i = 0; i < n; i++) for(j = 0; j < m; j++) cin >> arr[i][j];
    cin >> x >> y;

    queue <pair <int,int>> q;
    q.push(make_pair(0,0));
    steps[0][0] = 0;
    while(!q.empty()){
      auto node = q.front();
      int pp = node.first, qq = node.second;
      if(pp == x && qq == y) break;
      visited[pp][qq] = true;
      if(pp < n-1 && arr[pp+1][qq] == 1 && !visited[pp+1][qq]){
        steps[pp+1][qq] = steps[pp][qq] + 1;
        q.push(make_pair(pp+1,qq));
      }
      if(pp > 0 && arr[pp-1][qq] == 1 && !visited[pp-1][qq]){
        steps[pp-1][qq] = steps[pp][qq] + 1;
        q.push(make_pair(pp-1,qq));
      }
      if(qq < m-1 && arr[pp][qq+1] == 1 && !visited[pp][qq+1]){
        steps[pp][qq+1] = steps[pp][qq] + 1;
        q.push(make_pair(pp,qq+1));
      }
      if(qq > 0 && arr[pp][qq-1] == 1 && !visited[pp][qq-1]){
        steps[pp][qq-1] = steps[pp][qq] + 1;
        q.push(make_pair(pp,qq-1));
      }
      q.pop();
    }
    if(x == 0 && y == 0){
      if(arr[0][0] == 1) cout << 0 << "\n";
      else cout << -1 << "\n";
      continue;
    }
    if(steps[x][y] == 0 || arr[0][0] == 0) cout << -1;
    else cout << steps[x][y];
    cout << "\n";

  }
}
