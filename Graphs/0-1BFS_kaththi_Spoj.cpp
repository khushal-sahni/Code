#include<bits/stdc++.h>
using namespace std;
using li = long int;
using lli  = long long int;

#define eb emplace_back
#define mt make_tuple
#define mp make_pair
#define f first
#define s second

int main(){
  ios_base::sync_with_stdio(false);
  int _;
  cin >> _;
  while(_--){
    int r,c,i,j;
    bool flag;
    cin >> r >> c;
    char map[r][c];
    for(i = 0; i < r; ++i) for(j = 0; j < c; ++j) cin >> map[i][j];
    int dist[r][c];
    for(i = 0; i < r; ++i) for(j = 0; j < c; ++j) dist[i][j] = INT_MAX;
    deque <pair <int, int>> d;
    dist[0][0] = 0;
    d.push_front(mp(0,0));
    while(!d.empty()){
      auto x = d.front();
      d.pop_front();
      if(x.f == r-1 && x.s == c-1) break;
      if(x.f < r-1){
        flag = map[x.f+1][x.s] != map[x.f][x.s] ? true:false;
        if(dist[x.f+1][x.s] > (dist[x.f][x.s]+flag)){
          dist[x.f+1][x.s] = dist[x.f][x.s]+flag;
          if(flag) d.push_back(mp(x.f+1,x.s));
          else d.push_front(mp(x.f+1,x.s));
        }
      }
      if(x.f > 0){
        flag = map[x.f-1][x.s] != map[x.f][x.s] ? true:false;
        if(dist[x.f-1][x.s] > (dist[x.f][x.s]+flag)){
          dist[x.f-1][x.s] = dist[x.f][x.s]+flag;
          if(flag) d.push_back(mp(x.f-1,x.s));
          else d.push_front(mp(x.f-1,x.s));
        }
      }
      if(x.s < c-1){
        flag = map[x.f][x.s+1] != map[x.f][x.s] ? true:false;
        if(dist[x.f][x.s+1] > (dist[x.f][x.s]+flag)){
          dist[x.f][x.s+1] = dist[x.f][x.s]+flag;
          if(flag) d.push_back(mp(x.f,x.s+1));
          else d.push_front(mp(x.f,x.s+1));
        }
      }
      if(x.s > 0){
        flag = map[x.f][x.s-1] != map[x.f][x.s] ? true:false;
        if(dist[x.f][x.s-1] > (dist[x.f][x.s]+flag)){
          dist[x.f][x.s-1] = dist[x.f][x.s]+flag;
          if(flag) d.push_back(mp(x.f,x.s-1));
          else d.push_front(mp(x.f,x.s-1));
        }
      }

    }
    cout << dist[r-1][c-1] << "\n";

  }
}
