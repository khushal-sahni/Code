#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d",&arr[i] );
    sort(arr,arr+n);
    int count = 0;
    for(int i = n-1; i >= 2; i--){
      int l = 0,r = i-1;
      while(l != r){
        int s = arr[l] + arr[r];
        if(s == arr[i]){
          count++;
          l++; r++;
        }
        else if(s > arr[i]) r--;
        else l++;
      }
    }
    if(count) printf("%d\n",count );
    else printf("%d\n",-1 );
  }
}
