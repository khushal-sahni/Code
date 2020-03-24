#include <iostream>
#define INF 1e7
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int v, i, j, k;
    cin >> v;
    int cost[v][v], minimumCost[v][v];
    for(i = 0; i < v; i++){
      for(j = 0; j < v; j++){
       cin >> cost[i][j];
       minimumCost[i][j] = cost[i][j];
     }
    }

    for(i = 0; i < v; i++){
      for(j = 0; j < v; j++){
        for(k = 0; k < v; k++){
          if(minimumCost[j][i] + minimumCost[i][k] < minimumCost[j][k]) minimumCost[j][k] = minimumCost[j][i] + minimumCost[i][k];
        }
      }
    }

    for(i = 0; i < v; i++){
      for(j = 0; j < v; j++){
        if(minimumCost[i][j] == INF) cout << "INF ";
        else cout << minimumCost[i][j] << " ";
      }
      cout << "\n";
    }

  }
}
