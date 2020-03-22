#include <iostream>
#include <climits>
#include <queue>
#include <set>
using namespace std;

struct coord{
  int x,y, distance;
};

auto comp = [](coord a, coord b){
  return a.distance > b.distance;
};

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, i, j;
    cin >> n;
    int arr[n][n], cost[n][n];
    priority_queue <coord, vector <coord>, decltype(comp)> q(comp);
    coord c;
    for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
        cin >> arr[i][j];
        cost[i][j] = INT_MAX;
        c = {i,j,cost[i][j]};
        q.push(c);
      }
    }
    cost[0][0] = arr[0][0];
    long int costTotal = 0;
    c = {0,0,cost[0][0]};
    q.push(c);
    set <pair <int,int>> coordSet;
    while(coordSet.size() < (n*n)){
      auto element = q.top();
      int ex = element.x, ey = element.y;
      coordSet.insert(make_pair(ex,ey));
      if(ex < n-1 && coordSet.find(make_pair(ex+1,ey)) == coordSet.end() && cost[ex][ey] + arr[ex+1][ey] < cost[ex+1][ey]){
        cost[ex+1][ey] = cost[ex][ey] + arr[ex+1][ey];
        c = {ex+1,ey,cost[ex+1][ey]};
        q.push(c);
      }
      if(ex > 0 && coordSet.find(make_pair(ex-1,ey)) == coordSet.end() && cost[ex][ey] + arr[ex-1][ey] < cost[ex-1][ey]){
        cost[ex-1][ey] = cost[ex][ey] + arr[ex-1][ey];
        c = {ex-1,ey,cost[ex-1][ey]};
        q.push(c);
      }
      if(ey < n-1 && coordSet.find(make_pair(ex,ey+1)) == coordSet.end() && cost[ex][ey] + arr[ex][ey+1] < cost[ex][ey+1]){
        cost[ex][ey+1] = cost[ex][ey] + arr[ex][ey+1];
        c = {ex,ey+1,cost[ex][ey+1]};
        q.push(c);
      }
      if(ey > 0 && coordSet.find(make_pair(ex,ey-1)) == coordSet.end() && cost[ex][ey] + arr[ex][ey-1] < cost[ex][ey-1]){
        cost[ex][ey-1] = cost[ex][ey] + arr[ex][ey-1];
        c = {ex,ey-1,cost[ex][ey-1]};
        q.push(c);
      }

      q.pop();
    }
    cout << cost[n-1][n-1] << "\n";
  }
}
