#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int n,m,i;
    scanf("%d",&n);
    long int arr[n];
    for(i = 0; i < n; i++) scanf("%ld",&arr[i]);
    scanf("%d",&m);
    sort(arr,arr+n);
    long int minimumDifference = arr[n-1] - arr[0];
    for(i = 0; i < n-(m-1); i++){
      if((arr[i+m-1]-arr[i]) < minimumDifference){
        minimumDifference = arr[i+m-1]-arr[i];
      }
    }
    printf("%ld\n",minimumDifference);
  }
}
