#include <iostream>
#include <set>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, i;
    cin >> n;
    int arr[n];
    for(i = 0; i < n; i++) cin >> arr[i];
    set <int> s;
    for(i = 0; i < n; i++){
      if(s.find(arr[i]) == s.end()) s.insert(arr[i]);
      else s.erase(arr[i]);
    }
    cout << (*s.begin()) << "\n";
  }
}
