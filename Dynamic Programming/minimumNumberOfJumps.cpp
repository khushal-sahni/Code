#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

long int minSteps(int i, long int minimumSteps[], int arr[], int n){
  if(minimumSteps[i] != -1) return minimumSteps[i];
  if(arr[i] == 0) return minimumSteps[i] = INT_MAX;
  long int minimumStep = INT_MAX;
  for(int j = 1; j <= arr[i]; j++){
    if(i+j == n-1) return minimumSteps[i] = 1;
    minimumStep = min(minimumStep,minSteps(i+j,minimumSteps,arr,n));
  }
  return minimumSteps[i] = 1 + minimumStep;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n,i;
    cin >> n;
    int arr[n];
    for(i = 0; i < n; i++) cin >> arr[i];
    long int minimumSteps[n];
    memset(minimumSteps,-1,sizeof(minimumSteps));
    long int minimumStep = minSteps(0,minimumSteps,arr,n);
    if(minimumStep > 1e7) cout << -1 << "\n";
    else cout << minimumStep << "\n";
  }
}
