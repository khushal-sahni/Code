#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int n,l,r,sum;
    cin >> n >> l >> r;
    sum = n;
    int k = l-1;
    int val = pow(2,k);
    while(k < r){
      if(n&(1<<k)) sum -= val;
      else sum += val;
      k++;
      val *= 2;
    }
    cout << sum << "\n";
  }
}
