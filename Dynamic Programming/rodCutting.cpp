#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int n,x,y,z;
    cin >> n >> x >> y >> z;
    int dp[n+1] = {0};
    for(int i = 1; i <= n; i++){
      int m = -4001;
      if(i >= x) m = max(m, 1 + dp[i - x]);
      if(i >= y) m = max(m, 1 + dp[i - y]);
      if(i >= z) m = max(m, 1 + dp[i - z]);
      dp[i] = m;
      
    }
    cout << dp[n] << "\n";
  }
}
