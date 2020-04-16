#include <iostream>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int n, ans = 1;
    cin >> n;
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
      if(i % 2 == 1) dp[i] = dp[i/2]+1;
      else dp[i] = dp[i/2];
      ans += dp[i];
    }
    cout << ans << "\n";
  }
}
