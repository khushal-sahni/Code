#include <iostream>
#include <utility>
using namespace std;

void rearrange(int val, int i, int n, int arr[]){
  int z = i;
  if(i < n/2) i = 2*i + 1;
  else i = 2 * (n - i -1);
  while(true){
    swap(val,arr[i]);
    if(i == z) break;
    if(i < n/2) i = 2*i + 1;
    else i = 2 * (n - i -1);
  }
}

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int n;
    scanf("%d",&n);
    int arr[n],i;
    for(i = 0; i < n; i++){
      scanf("%d",&arr[i]);
    }
    rearrange(arr[0],0,n,arr);
    for(i = 1; i < n-2; i += 2){
      if (arr[i] > arr[i+2]){
        rearrange(arr[i],i,n,arr);
      }
    }
    for(i = 0; i < n-2; i += 2){
      if(arr[i] < arr[i+2]){
        rearrange(arr[i],i,n,arr);
      }
    }
    for(i = 0; i < n; i++) printf("%d ",arr[i]);
    printf("\n");
  }
}
