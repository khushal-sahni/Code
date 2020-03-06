#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int p,q,r,i;
    cin >> p >> q >> r;
    long  int arr1[p],arr2[q],arr3[r];
    bool found = false;
    for(i = 0; i < p; i++) cin >> arr1[i];
    for(i = 0; i < q; i++) cin >> arr2[i];
    for(i = 0; i < r; i++) cin >> arr3[i];
    unordered_set <long int> s1;
    unordered_set  <long int> s2;
    set <long int> s;
    for(i = 0; i < p; i++) s1.insert(arr1[i]);
    for(i = 0; i < q; i++)if(s1.find(arr2[i]) != s1.end()) s2.insert(arr2[i]);
    for(i = 0; i < r; i++)if(s2.find(arr3[i]) != s2.end()) s.insert(arr3[i]);
    if(s.empty()) cout << -1;
    else {
      for(auto k = s.begin(); k != s.end(); k++) cout << *k << " ";
    }
    cout << "\n";
  }
}
