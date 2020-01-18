#include <iostream>
using namespace std;

long int mergeSort(int arr[], int l, int r){
  int mid = l+(r-l)/2,i,j,k = l;
  long int count = 0;
  if(l < r){
    count += mergeSort(arr,l,mid);
    count += mergeSort(arr,mid+1,r);
    int left[mid - l + 1], right[r - mid];
    for(i = 0; i <= mid-l; i++) left[i] = arr[l+i];
    for(i = 0; i < r-mid; i++) right[i] = arr[mid+1+i];
    i = mid-l;
    j = r-(mid+1);
    while(i >= 0 && j >= 0){
      if(left[i] > right[j]){
        count += j+1;
        i--;
      }
      else{
        j--;
      }
    }
    for(i = 0,j = 0;i <= mid-l && j < r-mid; ){
      if(left[i] > right[j]){
        arr[k] = right[j];
        k++; j++;
      }
      else{
        arr[k] = left[i];
        i++; k++;
      }
    }
    while(i <= mid-l){
      arr[k] = left[i];
      i++; k++;
    }
    while(j < r-mid){
      arr[k] = right[j];
      j++; k++;
    }
    return count;
  }
  return 0;
}

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int n,i;
    long int count = 0;
    scanf("%d",&n);
    int arr[n];
    for(i = 0; i < n; i++) scanf("%d",&arr[i]);
    count = mergeSort(arr,0,n-1);
    printf("%ld\n",count);

  }
}
