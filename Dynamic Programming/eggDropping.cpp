#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

int dp[100][100];

int mTrials(int n, int k){
  if(n == 0 && k > 0) return INT_MAX;
  if(k == 0) return 0;
  if(dp[n][k] != -1) return dp[n][k];
  if(n == 1) return dp[n][k] = k;
  int val = 100;
  for(int i = 1; i <= k; i++){
     val = min(val, max(mTrials(n-1,i-1), mTrials(n,k - i) ));
  }
  return dp[n][k] = 1 + val;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n,k;
    cin >> n >> k;
    memset(dp,-1,sizeof(dp));
    cout << mTrials(n,k) << "\n";

  }
}
