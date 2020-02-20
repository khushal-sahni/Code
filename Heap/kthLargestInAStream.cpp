#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void swim(vector <int> &arr, int i){
  while(i > 0 && arr[i]<arr[(i-1)/2]){
    swap(arr[i],arr[(i-1)/2]);
    i = (i-1)/2;
  }
}

void sink(vector <int> &arr, int i, int n){
  while((2*i + 1) < n){
    int j = 2*i + 1;
    if(j < n-1 && arr[j] > arr[j+1]) j++;
    if(arr[i] > arr[j]) swap(arr[i],arr[j]);
    i = j;
  }
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int k, n, i;
    cin >> k >> n;
    vector <int> v(n);
    for(i = 0; i < n; i++) cin >> v[i];
    for(i = 0; i < k-1; i++){
      cout << -1 << " ";
      swim(v,i);
    }
    swim(v,i);
    cout << v[0] << " ";
    for(i = k; i < n; i++){
      if(v[i] > v[0]){
        swap(v[0],v[i]);
        sink(v,0,k);
      }
      cout << v[0] << " ";
    }
    cout << "\n";
  }
}
