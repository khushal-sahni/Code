#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int n,i;
    cin >> n;
    long int arr1[n], arr2[n];
    for(i = 0; i < n; i++) cin >> arr1[i];
    for(i = 0; i < n; i++) cin >> arr2[i];
    unordered_multiset <long int> s;
    for(i = 0; i < n; i++) s.insert(arr1[i]);
    for(i = 0; i < n; i++){
      auto it = s.find(arr2[i]);
      if(it != s.end()) s.erase(it);
    }
    if(s.empty()) cout << 1 << "\n";
    else cout << 0 << "\n";
  }
}
