#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int n,m,x,i;
    cin >> n >> m >> x;
    int arr1[n], arr2[m];
    for(i = 0; i < n; i++) cin >> arr1[i];
    for(i = 0; i < m; i++) cin >> arr2[i];
    unordered_set <int> s2;
    for(i = 0; i < m; i++) s2.insert(arr2[i]);
    set <pair <int,int>> s;
    for(i = 0; i < n; i++) if(s2.find(x-arr1[i]) != s2.end()) s.insert(pair <int,int>(arr1[i],x-arr1[i]));
    if(s.empty()){
      cout << "-1\n";
      continue;
    }
    auto k = s.begin();
    for(; k != --s.end(); k++){
      cout << k->first << " " << k->second << ", ";
    }
    cout << k->first << " " << k->second << "\n";
  }
}
