#include <iostream>
#include <algorithm>
using namespace std;

long int maximumSum(int i,long int mSum[], int n,long int arr[]){
  
  if(mSum[i] != 0) return mSum[i];
  long int maxSum = 0;
  int j = i+1;
  while(j < n){
    if(arr[j] > arr[i]){
      maxSum = max(maxSum, maximumSum(j,mSum,n,arr));
    }
    j++;
  }
  return mSum[i] = arr[i] + maxSum;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n,i;
    cin >> n;
    long int arr[n];
    for(i = 0; i < n; i++) cin >> arr[i];
    long int maxSum = 0;
    long int mSum[n] = {0};
    // for(i = 0; i < n; i++) cout << arr[i];
    for(i = 0; i < n; i++) maxSum = max(maxSum,maximumSum(i,mSum,n,arr));
    cout << maxSum << "\n";
  }
}
