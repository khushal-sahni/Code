#include <iostream>
using namespace std;
int ascendingSearch(int arr[], int l, int r, int key){
  while(l <= r){
    int mid = l + (r - l) / 2;
    if(arr[mid] == key) return mid;
    else if(arr[mid] < key) l = mid+1;
    else r = mid - 1;
  }
  return -1;
}
int descendingSearch(int arr[], int l, int r, int key){
  while(l <= r){
    int mid = l + (r - l) / 2;
    if(arr[mid] == key) return mid;
    else if(arr[mid] > key) l = mid+1;
    else r = mid - 1;
  }
  return -1;
}
int findBitonicPoint(int arr[], int l, int r){
  int mid = l + (r - l)/2;
  if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
    return mid;
  }
  else if(arr[mid] > arr[mid-1] && arr[mid] < arr[mid+1]){
    findBitonicPoint(arr,mid,r);
  }
  else if(arr[mid] < arr[mid-1] && arr[mid] > arr[mid+1]){
    findBitonicPoint(arr,l,mid);
  }
}
int searchBitonic(int arr[], int n, int key, int bp){
  if(key > arr[bp]) return -1;
  else if(key == arr[bp]) return bp;
  else {
    int temp = ascendingSearch(arr,0,bp-1,key);
    if(temp != -1) return temp;
    return descendingSearch(arr,bp+1,n-1,key);
  }
}
int main(){
  int arr[] = {1, 2, 4, 5, 9, 8, 4, 0, -5};
  int key = 4;
  int n = sizeof(arr)/sizeof(arr[0]);
  int bp = findBitonicPoint(arr,0,n-1);
  int x = searchBitonic(arr,n,key,bp);
  if(x == -1) cout << "Element not found";
  else cout << "Element found at index " << x;
  return 0;

}
