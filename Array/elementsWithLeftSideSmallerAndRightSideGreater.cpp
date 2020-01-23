#include <iostream>
using namespace std;

int findNumber(int arr[], int n){
  int rightMin[n], minimum = arr[n-1],i;
  for(i = n-1; i >= 0; i--){
    if(arr[i] < minimum) minimum = arr[i];
    rightMin[i] = minimum;
  }
  int maximum = arr[0];
  for(i = 1; i < n-1; i++){
    if(arr[i] >= maximum){
      if(arr[i] <= rightMin[i+1]) return arr[i];
      else maximum = arr[i];
    }
  }
  return -1;
}

int main(){
  int t;
  scanf("%d",&t );
  while(t--){
    int n,i;
    scanf("%d",&n);
    int arr[n];
    for(i = 0; i < n; i++) scanf("%d",&arr[i]);
    printf("%d\n",findNumber(arr,n));
  }
}
