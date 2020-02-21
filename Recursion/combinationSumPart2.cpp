#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

set <vector <int>> s;

void countWays(int arr[], int sum, int i, int n, vector <int> v){
  if(sum < arr[i]) return;
  if(sum == arr[i]){
    v.push_back(arr[i]);
    s.insert(v);
    return;
  }
  v.push_back(arr[i]);
  if(i < n-1) countWays(arr,sum-arr[i],i+1,n,v);
  v.pop_back();
  if(i < n-1) countWays(arr,sum,i+1,n,v);
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n,i,sum;
    cin >> n;
    int arr[n];
    for(i = 0; i < n; i++) cin >> arr[i];
    cin >> sum;
    sort(arr,arr+n);
    vector <int> v;
    s.clear();
    countWays(arr,sum,0,n,v);
    if(s.empty()) cout << "Empty";
    else{
      for(auto k = s.begin(); k != s.end(); k++){
        v = *k;
        cout << "(";
        for(int k = 0; k < v.size()-1; k++) cout << v[k] << " ";
        cout << v.back() << ")";
      }
    }
    cout << "\n";
  }
}
