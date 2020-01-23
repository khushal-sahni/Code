#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int n,i;
    scanf("%d",&n);
    int arr[n];
    for(i = 0; i < n; i++) scanf("%d",&arr[i]);
    int maxHeight = 0, supposedSum = 0, sum = 0, maxIndex = -1;
    i = 0;
    while(i < n){
      if(arr[i] >= maxHeight){
        sum += supposedSum;
        supposedSum = 0;
        maxHeight = arr[i];
        maxIndex = i;
      }
      else{
        supposedSum += (maxHeight - arr[i]);
      }
      i++;
    }
    i = n-1, maxHeight = 0, supposedSum = 0;
    while(i >= maxIndex){
      if(arr[i] >= maxHeight){
        sum += supposedSum;
        supposedSum = 0;
        maxHeight = arr[i];
      }
      else{
        supposedSum += (maxHeight - arr[i]);
      }
      i--;
    }
    printf("%d\n",sum);
  }
}
