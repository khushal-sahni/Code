#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int main(){
  int t;
  scanf("%d",&t );
  while(t--){
    int n;
    scanf("%d",&n );
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d",&arr[i] );
    int fmax = INT_MIN,sum = 0;
    for(int i = 0; i < n; i++){
      sum += arr[i];
      if(sum < 0){
        sum = 0;
        fmax = max(arr[i],fmax);
      }
      else{
        fmax = max(fmax,sum);
      }
    }
    printf("%d\n",fmax);
  }
}

//slightly alternate and faster solution

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int main(){
  int t;
  scanf("%d",&t );
  while(t--){
    int n;
    scanf("%d",&n );
    int arr[n];
    int fmax = INT_MIN,sum = 0,s;
    for(int i = 0; i < n; i++){
      scanf("%d",&s );
      sum += s;
      if(sum < 0){
        sum = 0;
        fmax = max(s,fmax);
      }
      else{
        fmax = max(fmax,sum);
      }
    }
    printf("%d\n",fmax);
  }
}
