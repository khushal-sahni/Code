#include <iostream>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int maxL = 0;
    int l = 0;
    while(n > 0){
      if(n%2 == 1) l++;
      else{
        if(l > maxL) maxL = l;
        l = 0;
      }
      n /= 2;
    }
    if(l > maxL) maxL  = l;
    cout << maxL << "\n";
  }
}
