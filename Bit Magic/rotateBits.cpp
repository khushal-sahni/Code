#include <iostream>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int n,d;
    cin >> n >> d;
    d = d % 16;
    int a = ((((1 << (16-d)) - 1) & n) << d) + (n >> (16-d));
    int b = ((((1 << d) - 1) &  n) << (16-d)) + (n >> d);
    cout << a;
    cout << "\n";
    cout << b;
    cout << "\n";
  }
}
