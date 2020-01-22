#include <iostream>
#include <utility>
using namespace std;

void swapArray(long int arr[], int startingPosition, int endingPosition){
  while(startingPosition < endingPosition){
    swap(arr[startingPosition],arr[endingPosition]);
    startingPosition++;
    endingPosition--;
  }
}

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int n,k,i;
    scanf("%d %d",&n,&k);
    long int arr[n];
    for(i = 0; i < n; i++) scanf("%ld",&arr[i]);
    i = 0;
    while(i < n){
      if((i+k-1) < n){
        swapArray(arr,i,i+k-1);
        i += k;
      }
      else{
        swapArray(arr,i,n-1);
        i = n;
      }
    }
    for(i = 0; i < n; i++) printf("%ld ",arr[i] );
    printf("\n");
  }
}
