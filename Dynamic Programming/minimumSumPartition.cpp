#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int cSum(int s, int i, int arr[], void *ptr, int n){
  int (*closestSum)[n+1] = static_cast<int (*)[n+1]>(ptr);
  if(closestSum[s][i] != -1) return closestSum[s][i];
  if(s == 0) return 0;
  if(i == 0) return 0;
  int a = 0,b = 0;

  if(s >= arr[i-1]){
    a = arr[i-1] + cSum(s-arr[i-1],i-1, arr,closestSum, n);
  }
  b = cSum(s,i-1, arr, closestSum,n);
  return closestSum[s][i] = max(a,b);
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n,i,sum = 0,x;
    cin >> n;
    int arr[n];
    for(i = 0; i < n; i++) cin >> arr[i];
    for(i = 0; i < n; i++) sum += arr[i];
    x = sum/2;
    // closest sum to this will be an integer sum obviously
    int closestSum[sum + 1][n + 1];
    memset(closestSum,-1,sizeof(closestSum));
    int a = cSum(x, n, arr, closestSum, n);
    int b = sum - a;
    cout << (b-a) << "\n";
  }
}
