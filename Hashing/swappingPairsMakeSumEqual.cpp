#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int m,n,i;
    float sum1 = 0,sum2 = 0;
    bool found = false;
    cin >> n >> m;
    int arr1[n], arr2[m];
    for(i = 0; i < n; i++) cin >> arr1[i];
    for(i = 0; i < m; i++) cin >> arr2[i];
    unordered_set <int> s;
    for(i = 0; i < n; i++){
      sum1 += arr1[i];
      s.insert(arr1[i]);
    }
    for(i = 0; i < m; i++){
      sum2 += arr2[i];
    }
    float y = (sum2-sum1)/2;
    int x = static_cast <int> (y);
    if(x != y){
      cout << -1 << "\n";
      continue;
    }
    for(i = 0; i < m; i++){
      if(s.find(arr2[i]-x) != s.end()){
        cout << 1 << "\n";
        found = true;
        break;
      }
    }
    if(!found) cout << -1 << "\n";
  }
}
