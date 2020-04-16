#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int n,ans;
    cin >> n;
    ans = n;
    int pos = 0;
    while(n > 0){
      if(n % 2 == 1){
        n /= 2;
        pos++;
        if(n % 2 == 0){
          ans += pow(2,pos-1);
        }
        n /= 2;
        pos++;
      }
      else{
        n /= 2;
        pos++;
        if(n % 2 == 1){
          ans -= pow(2,pos-1);
        }
        n /= 2;
        pos++;
      }
    }
    cout << ans << "\n";

  }
}
