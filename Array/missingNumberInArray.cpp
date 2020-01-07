#include <iostream>
#include <cstring>
using namespace std;
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int n;
    scanf("%d",&n);
    int arr[n];
    memset(arr,0,sizeof(arr));
    for(int i = 0; i < n-1; i++){
      int d;
      scanf("%d",&d );
      arr[d-1] = 1;
    }
    for(int i = 0; i < n; i++){
      if(arr[i] == 0){
        printf("%d\n",i+1 );
        break;
      }
    }
  }
}
