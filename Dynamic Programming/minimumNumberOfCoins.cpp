#include <iostream>
using namespace std;

void func(int &n, int denom){
  int counter = n/denom;
  for(int i = 0; i < counter; i++) cout << denom << " ";
  n = n%denom;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    func(n,2000);
    func(n,500);
    func(n,200);
    func(n,100);
    func(n,50);
    func(n,20);
    func(n,10);
    func(n,5);
    func(n,2);
    func(n,1);
    cout << "\n";
  }
}
