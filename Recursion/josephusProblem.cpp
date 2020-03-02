#include <iostream>
using namespace std;

int josephus(int n, int k){
  int arr[n],i,key = 0,prev,next = 0,size = n;
  for(i = 1; i < n-1; i++) arr[i] = ((i+1) * n) + i-1;
  arr[i] = i-1;
  arr[0] = n + i;

  while(size > 1){

    for(i = 1; i < k; i++) key = arr[key]/n;
    prev = arr[key]%n;
    next = arr[key]/n;
    arr[prev] = next*n + (arr[prev]%n);
    arr[next] = (arr[next]/n)*n + prev;
    size--;
    key = next;
  }

  return next+1;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n,k;
    cin >> n >> k;
    cout << josephus(n,k) << "\n";
  }
}
