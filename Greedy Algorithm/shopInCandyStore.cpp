#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int n,k,i, minimumCost = 0, maximumCost = 0, counter;
    cin >> n >> k;
    int arr[n];
    for(i = 0; i < n; i++) cin >> arr[i];
    sort(arr,arr+n);

    counter = n/(1+k);

    if(n%(k+1) > 0) counter++;

    for(i = 0; i < counter; i++) minimumCost += arr[i];
    for(i = n-1; i > n-1-counter; i--) maximumCost += arr[i];
    cout << minimumCost << " " << maximumCost << "\n";
  }
}
