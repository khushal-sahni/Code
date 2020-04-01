#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

long long int minOps(int n, long long int minimumOps[]){
  if(minimumOps[n] != -1) return minimumOps[n];
  if(n % 2 != 0) return minimumOps[n] = minOps(n-1,minimumOps)+1;
  return minimumOps[n] = min(minOps(n/2,minimumOps)+1,minOps(n-1,minimumOps)+1);
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    long long int minimumOps[10001];
    memset(minimumOps,-1,sizeof(minimumOps));
    minimumOps[1] = 1;
    minimumOps[0] = 0;
    cout << minOps(n,minimumOps) << "\n";
  }
}
