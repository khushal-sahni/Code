#include <iostream>
#include <utility>
using namespace std;
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int n,i;
    scanf("%d",&n);
    int arr[n];
    for(i = 0; i < n; i++) scanf("%d",&arr[i]);
    int l = 0, r = n-1;
    i = 0;
    while(i <= r){
      if(arr[i] == 0){
        swap(arr[l],arr[i]);
        l++;
        i++;
      }
      else if(arr[i] == 2){
        swap(arr[r],arr[i]);
        r--;
      }
      else i++;
    }
    for(i = 0; i < n; i++) printf("%d ",arr[i]);
    printf("\n");
  }
}
