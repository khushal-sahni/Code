#include <iostream>
using namespace std;

int searchBinary(int l, int r, int arr[], int k){
  if(l <= r){
    int mid = l + (r-l)/2;
    if(arr[mid] == k) return mid;
    if(arr[mid] > k) return searchBinary(l,mid-1,arr,k);
    return searchBinary(mid+1,r,arr,k);
  }
  else return -1;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n,i,k;
    cin >> n;
    int arr[n];
    for(i = 0; i < n; i++) cin >> arr[i];
    cin >> k;
    int l = 0, r = n-1, breakPoint;
    while(l <= r){
      int mid = l + (r-l)/2;//base case l == r
      if(l == r){
        breakPoint = l;
        break;
      }
      if(arr[mid] >= arr[0]){
        if(arr[mid+1] < arr[mid]){
          breakPoint = mid;
          break;
        }
        else l = mid + 1;
      }
      else{
        if(arr[mid-1] > arr[mid]){
          breakPoint = mid-1;
          break;
        }
        else r = mid-1;
      }
    }
    int a = searchBinary(0,breakPoint,arr,k), b = searchBinary(breakPoint + 1, n-1, arr, k);
    if(a != -1) cout << a << "\n";
    else cout << b << "\n";

  }
}
