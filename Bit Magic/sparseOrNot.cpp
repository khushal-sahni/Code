#include <iostream>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    if((n & (n << 1)) == 0) cout << 1 << "\n";
    else cout << 0 << "\n";
  }
}
