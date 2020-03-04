#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int n,m,i,d;
    cin >> n >> m;
    int arr[m];
    multiset <int> s;
    for(i = 0; i < n; i++){
      cin >> d;
      s.insert(d);
    }
    for(i = 0; i < m; i++) cin >> arr[i];

    vector <int> v;
    for(i = 0; i < m;){
      auto it = s.find(arr[i]);
      if(it != s.end()){
        v.push_back(arr[i]);
        s.erase(it);
      }
      else i++;
    }
    for(auto it = s.begin(); it != s.end(); it++) v.push_back(*it);
    for(i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << "\n";
  }
}
