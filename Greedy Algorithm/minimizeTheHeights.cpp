#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int k,n,i;
    cin >> k >> n;
    int arr[n];
    for(i = 0; i < n; i++) cin >> arr[i];

    sort(arr,arr+n);
    int minimum = arr[0], maximum = arr[n-1];
    if(maximum - minimum > k){



      int beginVal = minimum + k, endVal = maximum - k;
      if(beginVal > endVal) {
        maximum = beginVal;
        minimum = endVal;
      }
      else{
        maximum = endVal;
        minimum = beginVal;
      }

      for(i = 1; i < n-1; i++){
        if((arr[i] + k - endVal) < (beginVal -( arr[i] - k)) ){
          if(maximum < (arr[i] + k)) maximum = arr[i] + k;

        }
        else{
          if(minimum > (arr[i] - k)) minimum = arr[i] - k;

        }
      }

    }
    cout << (maximum-minimum) << "\n";


  }
}
