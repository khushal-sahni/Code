#include <iostream>
#include <cstring>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n,i;
    float sum = 0;
    cin >> n;
    int arr[n];
    for(i = 0; i < n; i++) cin >> arr[i];
    for(i = 0; i < n; i++) sum += arr[i];
    if(sum/2 != (int)(sum/2) || n == 1){
      cout << "NO\n";
      continue;
    }
    int x = sum/2;
    bool sumPossible[x + 1][n + 1];
    memset(sumPossible,0,sizeof(sumPossible));

    for(i = 0; i <= x; i++){
      for(int j = 0; j <= n; j++){
        if(i == 0) sumPossible[i][j] = true;
        else if (j == 0) sumPossible[i][j] = false;
        else if(i - arr[j-1] >= 0 ) sumPossible[i][j] = (sumPossible[i-arr[j-1]][j-1] || sumPossible[i][j-1] );
        else sumPossible[i][j] = sumPossible[i][j-1];
      }
    }



    if(sumPossible[x][n]) cout << "YES\n";
    else cout << "NO\n";
  }
}
