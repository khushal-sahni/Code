#include <iostream>
#include <stack>
using namespace std;
int main(){
  int t;
  scanf("%d\n",&t);
  while(t--){
    int n,i;
    scanf("%d\n",&n);
    long int arr[n],arr1[n];
    for(i = 0; i < n; i++) scanf("%ld",&arr[i]);
    stack <long int> s;
    bool f = false;
    for(i = n-1; i >= 0; i--){
        f = false;
        while(!s.empty()){
          if(s.top() > arr[i]){
            arr1[i] = s.top();
            s.push(arr[i]);
            f = true;
            break;
          }
          else s.pop();
        }
        if(!f){
          arr1[i] = -1;
          s.push(arr[i]);
        }
    }
    for(i = 0; i < n; i++) cout << arr1[i] << " ";
    cout << "\n";
  }
}
