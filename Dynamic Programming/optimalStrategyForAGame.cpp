#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int sum[101][101];
int maxSum[101][101];

int mSum(int i, int j, int arr[]){
  //base case i == j ensure i < j
  if(i == 0) return 0;
  if(i == j) return maxSum[i][j] = arr[i-1];
  if(maxSum[i][j] != -1) return maxSum[i][j];
  return maxSum[i][j] =  max( arr[i-1] + sum[i+1][j] - mSum(i+1,j,arr), arr[j-1] + sum[i][j-1] - mSum(i,j-1,arr) );
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, i, j;
    cin >> n;
    int arr[n];
    for(i = 0; i < n; i++) cin >> arr[i];
    memset(sum,-1,sizeof(sum));
    memset(maxSum,-1,sizeof(maxSum));
    for(i = 0; i <= n; i++){
      for(j = i; j <= n; j++){
        if(j == 0) sum[i][j] = 0;
        else if(i == j) sum[i][j] = arr[i-1];
        else sum[i][j] = sum[i][j-1] + arr[j-1];
      }
    }

    cout << mSum(1,n,arr) << "\n";
  }
}
