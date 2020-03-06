#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;


int main(){
  int t;
  cin >> t;
  while(t--){
    int n,k,i,p,q,r;
    cin >> n >> k;
    int arr[n];
    for(i = 0; i < n; i++) cin >> arr[i];
    set <multiset <int>> megaSet;

    for(p = 0; p < n-2; p++){
      for(q = p+1; q < n-1; q++){
        unordered_set <int> s;
        s.clear();
        for(r = q+1; r < n; r++){
          int fourth = k-(arr[p]+arr[q]+arr[r]);
          if(s.find(fourth) != s.end()){
            multiset <int> miniSet;
            miniSet.insert(arr[p]); miniSet.insert(arr[q]); miniSet.insert(arr[r]);miniSet.insert(fourth);
            if(megaSet.find(miniSet) == megaSet.end()) megaSet.insert(miniSet);
          }
          else s.insert(arr[r]);
        }
      }
    }

    if(megaSet.empty()) cout << -1;
    else{
      for(auto x = megaSet.begin(); x != megaSet.end(); x++){
        for(auto y = (*x).begin(); y != (*x).end(); y++){
          cout << *y << " ";
        }
        cout << "$";
      }
    }
    cout << "\n";
  }
}
