#include <iostream>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int a,b,ans, sum = 0;
    cin >> a >> b;
    ans = a ^ b;
    while(ans > 0){
      sum += (ans%2);
      ans /= 2;
    }
    cout << sum << "\n";
  }
}
