#include <iostream>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int m,n;
    cin >> m >> n;
    if(m == n){
      cout << "-1\n";
      break;
    }
    int ans = m ^ n;
    int pos = 1;
    int shiff = 0;
    while(true){
      if(ans&(1<<shiff)){
        cout << pos << "\n";
        break;
      }
      pos++;
      shiff++;
    }
  }
}
