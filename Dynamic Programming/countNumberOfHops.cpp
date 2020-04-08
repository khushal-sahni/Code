#include <iostream>
#include <cstring>
using namespace std;

int steps(int i, int dp[]){
  if(i == 0) return 1;
  if(i < 0) return 0;
  if(dp[i] != -1) return dp[i];

  return dp[i] = steps(i - 1, dp) + steps(i - 2, dp) + steps(i - 3, dp);
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    cout << steps(n,dp) << "\n";
  }
}
