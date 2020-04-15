#include <iostream>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int pos = 1;
    int num = 1;
    if(n == 0){
      cout << "0\n";
      continue;
    }
    while(num <= n){
      if(n&num){
        cout << pos << "\n";
        break;
      }
      num *= 2;
      pos++;
    }
  }
}
