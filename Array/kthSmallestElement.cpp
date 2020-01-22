#include <iostream>
#include <utility>
#include <cstdlib>
using namespace std;

int partitionArray(int arr[], int k, int leftIndex, int rightIndex){
  int randomIndex = leftIndex + (rand() % (rightIndex - leftIndex + 1));
  swap(arr[leftIndex],arr[randomIndex]);
  int element = arr[leftIndex], i = leftIndex+1, rightPointer = rightIndex;
  while(i <= rightPointer){
    if(arr[i] > element){
      swap(arr[i],arr[rightPointer]);
      rightPointer--;
    }
    else{
      i++;
    }
  }
  swap(arr[leftIndex],arr[i-1]);
  if(i == k) return arr[i-1];
  else if(i < k) return partitionArray(arr,k,i,rightIndex);
  else return partitionArray(arr,k,leftIndex,i-2);
}

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int n,k,i;
    scanf("%d",&n);
    int arr[n];
    for(i = 0; i < n; i++) scanf("%d",&arr[i] );
    scanf("%d",&k);
    printf("%d\n",partitionArray(arr,k,0,n-1));
  }
}
