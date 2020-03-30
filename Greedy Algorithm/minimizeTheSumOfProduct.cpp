#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int n, i;
    cin >> n;
    int A[n],B[n];
    for(i = 0; i < n; i++) cin >> A[i];
    for(i = 0; i < n; i++) cin >> B[i];
    sort(A,A+n);
    sort(B,B+n,greater <int> ());

    long long int sum = 0;
    for(i = 0; i < n; i++){
      sum += A[i]*B[i];
    }
    cout << sum << "\n";
  }
}
