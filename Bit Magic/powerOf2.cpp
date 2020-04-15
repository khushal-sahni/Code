#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    long int n;
    cin >> n;
    if(n == 0){
      cout << "NO\n";
      break;
    }
    if((n & (n-1)) == 0) cout << "YES\n";
    else cout << "NO\n";
  }
  // cout << log2(8);
}
