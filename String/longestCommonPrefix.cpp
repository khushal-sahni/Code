#include <iostream>
#include <string>
using namespace std;

void longestCommon(string arr[], int n){
  string prefix = arr[0];
  for(int i = 1; i < n; i++){

    int l1 = prefix.length(), l2 = arr[i].length();
    bool breakDone = false;
    if(l1 < l2){
      for(int j = 0; j < l1; j++){
        if(prefix[j] != arr[i][j]){
          prefix = prefix.substr(0,j);
          break;
        }
      }
    }
    else{
      for(int j = 0; j < l2; j++){
        if(arr[i][j] != prefix[j]){
          prefix = prefix.substr(0,j);
          breakDone = true;
          break;
        }
      }
      if(!breakDone) prefix = arr[i];
    }

  }
  if(prefix == "") cout << -1 << "\n";
  else cout << prefix << "\n";

}

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int n,i;
    scanf("%d",&n);
    string arr[n];
    for(i = 0; i < n; i++) cin >> arr[i];
    longestCommon(arr,n);
  }
}
