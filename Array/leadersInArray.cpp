#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int n,i;
    scanf("%d",&n);
    int arr[n];
    for(i = 0; i < n; i++) scanf("%d",&arr[i]);
    int rightMax = arr[n-1];
    stack <int> s;
    for(i = n-1; i >= 0; i--){
      if(arr[i] >= rightMax){
        s.push(arr[i]);
        rightMax = max(rightMax,arr[i]);
      }
    }
    while(!s.empty()){
      printf("%d ",s.top());
      s.pop();
    }
    printf("\n");
  }
}
