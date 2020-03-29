#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int n, k, i, counter = 0;
    cin >> n >> k;
    int arr[n];
    for(i = 0; i < n; i++) cin >> arr[i];
    sort(arr,arr+n);
    for(i = 0; i < n; i++){
      k -= arr[i];
      if( k >= 0) counter++;
      else break;
    }
    cout << counter << "\n";
  }
}
