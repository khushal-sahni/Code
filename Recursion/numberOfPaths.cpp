#include <iostream>
using namespace std;

int numberOfPaths(int i, int j, int m, int n){
  if(i == m-1 && j == n-1) return 1;
  int sum = 0;
  if(i < m-1)sum += numberOfPaths(i+1,j,m,n);
  if(j < n-1)sum += numberOfPaths(i,j+1,m,n);
  return sum;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int m, n;
    cin >> m >> n;
    cout << numberOfPaths(0,0,m,n) << " \n";
  }
}
