#include <iostream>
using namespace std;

int convertString(string s1){
  int l = s1.length(), sum = 0,d,i = 0;
  bool flag = false;
  if(s1[0] == '-'){
    flag = true;
    i = 1;
  }
  for(; i < l; i++){
    d = s1[i]-'0';
    if(d > -1 && d < 10){
      sum = sum * 10 + d;
    }
    else return -1;
  }
  if(flag) sum = -sum;
  return sum;
}

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    string s1;
    cin >> s1;
    cout << convertString(s1) << "\n";
  }
}
