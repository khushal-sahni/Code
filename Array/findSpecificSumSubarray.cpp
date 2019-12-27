#include <iostream>
using namespace std;

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int n,s;
    scanf("%d %d",&n,&s);
    int arr[n];
    int l = 0,r = 0,sum = 0,found = 0;
    for(int i = 0; i < n; i++) scanf("%d",&arr[i]);
    while(r < n){
      sum += arr[r];
      if(sum == s){
        cout << l+1 << " " << r+1 << "\n";
        found = 1;
        break;
      }
      else if(sum > s){
        while(sum > s){
          sum -= arr[l];
          l++;
        }
        if(sum == s){
          cout << l+1 << " " << r+1 << "\n";
          found = 1;
          break;
        }
      }
      r++;
    }
    if(!found) cout << -1 << "\n";

  }
}
