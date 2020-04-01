#include <iostream>
#include <algorithm>
using namespace std;

int lengthSequence(int i, int length[], int arr[], int n){
  if(length[i] != 0) return length[i];
  int j = i + 1;
  int val = 0;
  for(;j < n; j++){
    if(arr[j] > arr[i]) val = max(val, lengthSequence(j,length,arr,n));
  }
  return length[i] = 1 + val;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, i, val = 0;
    cin >> n;
    int arr[n], length[n] = {0};
    for(i = 0; i < n; i++) cin >> arr[i];
    for(i = 0; i < n; i++){
      val = max(val, lengthSequence(i,length,arr,n));
    }
    cout << val << "\n";
  }
}
