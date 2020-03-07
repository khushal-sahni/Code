#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int n,k,i;
    cin >> n >> k;
    int arr[n];
    for(i = 0; i < n; i++) cin >> arr[i];

    unordered_map <int,int> m;
    for(i = 0; i < k; i++){
      if(i == n) break;
      if(m.find(arr[i]) == m.end()) m.insert(pair <int,int>(arr[i],1));
      else m[arr[i]]++;
    }
    cout << m.size() << " ";
    for(; i < n; i++){
      if(m.find(arr[i]) == m.end()) m.insert(pair <int,int>(arr[i],1));
      else m[arr[i]]++;
      m[arr[i-k]]--;
      if(m[arr[i-k]] == 0) m.erase(arr[i-k]);
      cout << m.size() << " ";
    }
    cout << "\n";
  }
}
