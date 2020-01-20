#include <iostream>
using namespace std;

int findPoint(int leftSum, int rightSum, int leftPointer, int rightPointer, int arr[]){
  while(leftPointer <= rightPointer){
    if(leftSum > rightSum){
      rightSum += arr[rightPointer];
      rightPointer--;
    }
    else if(rightSum > leftSum){
      leftSum += arr[leftPointer];
      leftPointer++;
    }
    else{
      if(leftPointer == rightPointer) return leftPointer+1;
      leftSum += arr[leftPointer];
      leftPointer++;
      rightSum += arr[rightPointer];
      rightPointer--;
    }
  }
  return -1;
}

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int n,i;
    scanf("%d",&n);
    int arr[n];
    for(i = 0; i < n; i++) scanf("%d",&arr[i]);
    printf("%d\n",findPoint(0,0,0,n-1,arr) );
  }
}
