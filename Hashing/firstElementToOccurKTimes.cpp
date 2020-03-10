#include <iostream>
#include <unordered_map>
using namespace std;

int element (int arr[], int n, int k){
  unordered_map <int, int> m;
  for(int i = 0; i < n; i++){
    if(m.find(arr[i]) == m.end()) m.insert(pair <int,int>(arr[i],1));
    else m[arr[i]]++;
  }
  for(int i = 0; i < n; i++){
    if(m[arr[i]] == k) return arr[i];
  }
  return -1;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n,k,i;
    cin >> n >> k;
    int arr[n];
    for(i = 0; i < n; i++) cin >> arr[i];
    cout << element(arr,n,k) << "\n";
  }
}
