#include <iostream>
#include <string>
using namespace std;

int strstr(string s, string x){
  int l1 = s.length(), l2 = x.length(), startingPosition = -1;
  int i, j = 0;
  for(i = 0; i < l1; i++){
    if(s[i] == x[j]){
      if(j == 0) startingPosition = i;
      j++;
    }
    else{
      if(i == (startingPosition + 1)){
        startingPosition = i + 1;
      }
      else{
        i = startingPosition;
      }

      j = 0;
    }
    if(j == l2) return (i - l2 + 1);
  }
  return -1;
}

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    string s,x;
    cin >> s >> x;
    cout << strstr(s,x) << "\n";
  }
}
