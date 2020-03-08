#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int m,n,i;
    cin >> m >> n;
    int arr[m], arr1[n];
    for(i = 0; i < m; i++) cin >> arr[i];
    for(i = 0; i < n; i++) cin >> arr1[i];
    unordered_set <int> s;
    for(i = 0; i < m; i++) s.insert(arr[i]);
    bool isSubset = true;
    for(i = 0; i < n; i++){
      if(s.find(arr1[i]) == s.end()){
        isSubset = false;
        break;
      }
    }
    if(isSubset) cout << "Yes\n";
    else cout << "No\n";
  }
}
