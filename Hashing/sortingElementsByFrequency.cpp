#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(pair <int,int> a,pair <int,int> b){
  if(a.first > b.first) return true;
  else if(a.first == b.first) return (a.second < b.second);
  else return false;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n,i;
    cin >> n;
    int arr[n];
    for(i = 0; i < n; i++) cin >> arr[i];

    unordered_map <int,int> m;
    for(i = 0; i < n; i++){
      if(m.find(arr[i]) != m.end()) m[arr[i]]++;
      else m.insert(pair<int,int>(arr[i],1));
    }

    vector <pair <int,int>> v;
    for(auto k = m.begin(); k != m.end(); k++) v.push_back(pair <int,int> (k->second,k->first));
    sort(v.begin(),v.end(),comp);

    for(i = 0; i < v.size(); i++){
      int count = v[i].first;
      while(count--) cout << v[i].second << " ";
    }
    cout << "\n";
  }
}
