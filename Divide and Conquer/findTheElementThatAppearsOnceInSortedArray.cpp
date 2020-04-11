#include <iostream>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int n,i;
    cin >> n;
    int arr[n];
    for(i = 0; i < n; i++) cin >> arr[i];
    int l = 0, r = n-1;

    while(l <= r){//check for 1 n
      if(l == r){
        cout << arr[l] << "\n";
        break;
      }
      int mid = l + (r-l)/2;
      if(arr[mid-1] == arr[mid]){
        if(mid % 2 != 0) l = mid + 1;
        else r = mid - 1;
      }
      else if(arr[mid + 1] == arr[mid]){
        if(mid % 2 != 0) r = mid - 1;
        else l = mid + 1;
      }
      else{
        cout << arr[mid] << "\n";
        break;
      }
    }

  }
}
