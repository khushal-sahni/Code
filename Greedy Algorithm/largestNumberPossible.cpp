#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int n,s;
    string val = "";
    cin >> n >> s;
    if(s == 0){
      cout << -1 << "\n";
      continue;
    }
    while(n--){
      if(s >= 9){
        val += '9';
        s -= 9;
      }
      else{
        val += (char)('0'+s);
        if(s) s = 0;
      }
    }
    if(s != 0) cout << -1 << "\n";
    else cout << val << "\n";
  }
}
