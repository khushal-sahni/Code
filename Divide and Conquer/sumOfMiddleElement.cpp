#include <iostream>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int n,i,j, counter = 0;
    long int sum = 0;
    cin >> n;
    int arr1[n],arr2[n];
    for(i = 0; i < n; i++) cin >> arr1[i];
    for(j = 0; j < n; j++) cin >> arr2[j];
    for(i = 0,j = 0; i < n && j < n;){
      counter++;
      if(arr1[i] < arr2[j]){
        if(counter == n) sum += arr1[i];
        else if(counter == n+1){
          sum += arr1[i];
          break;
        }
        i++;
      }
      else{
        if(counter == n) sum += arr2[j];
        else if(counter == n+1){
          sum += arr2[j];
          break;
        }
        j++;
      }

    }
    cout << sum << "\n";

  }
}
