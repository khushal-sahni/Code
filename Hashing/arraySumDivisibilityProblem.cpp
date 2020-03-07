#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n,k,i;
    cin >> n;
    int arr[n];
    for(i = 0; i < n; i++) cin >> arr[i];
    cin >> k;
    int divisibleNumbers = 1;

    if(n % 2 == 1){
      cout << "False\n";
      continue;
    }
    unordered_multiset <int> m;
    for(i = 0; i < n; i++){
      if(arr[i] % k == 0) divisibleNumbers = -divisibleNumbers;
      else{
        int d = arr[i]%k;
        auto it = m.find(k-d);
        if(it == m.end()) m.insert(d);
        else m.erase(it);
      }
    }

    if(divisibleNumbers == 1 && m.empty()) cout << "True\n";
    else cout << "False\n";

  }
}
