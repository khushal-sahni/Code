#include <iostream>
using namespace std;
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int n,i;
    scanf("%d", &n);
    int arr[n];
    for(i = 0; i < n; i++) scanf("%d",&arr[i]);
    bool stocksRising = false, foundProfit = false;
    i = 1;
    while(i < n){
      if(!stocksRising){
        if(arr[i] > arr[i-1]){
          stocksRising = true;
          foundProfit = true;
          printf("(%d ",i-1);
        }
      }
      else{
        if(arr[i] < arr[i-1]){
          stocksRising = false;
          printf("%d) ",i-1);
        }
      }
      i++;
    }
    if(!foundProfit) printf("No Profit");
    if(stocksRising) printf("%d) ",n-1);
    printf("\n");
  }
}
